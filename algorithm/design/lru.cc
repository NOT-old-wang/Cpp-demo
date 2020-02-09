/*
一、什么是 LRU 算法
就是一种缓存淘汰策略。

计算机的缓存容量有限，如果缓存满了就要删除一些内容，给新内容腾位置。
但问题是，删除哪些内容呢？我们肯定希望删掉哪些没什么用的缓存，
而把有用的数据继续留在缓存里，方便之后继续使用。
那么，什么样的数据，我们判定为「有用的」的数据呢？

LRU 缓存淘汰算法就是一种常用策略。LRU 的全称是 Least Recently Used
也就是说我们认为最近使用过的数据应该是是「有用的」
很久都没用过的数据应该是无用的，内存满了就优先删那些很久没用过的数据。

二、LRU 算法描述
LRU 算法实际上是让你设计数据结构：首先要接收一个 capacity 参数作为缓存的最大容量
然后实现两个 API，一个是 put(key, val) 方法存入键值对
另一个是 get(key) 方法获取 key 对应的 val，如果 key 不存在则返回 -1。
get 和 put 方法必须都是 O(1)O(1) 的时间复杂度
*/

#include <iostream>
#include <list>
#include <string>
#include <unordered_map>
#include <utility>

class Lru {
 public:
  Lru(int capacity) : capacity_(capacity){};

  void Put(int key, int val) {
    auto itr = cache_map_.find(key);
    if (itr == cache_map_.end()) {
      if (cache_.size() == capacity_) {
        cache_map_.erase(cache_.back().first);
        cache_.pop_back();
      }
      cache_.push_front(std::make_pair(key, val));
      cache_map_[key] = cache_.begin();
    } else {
      cache_.erase(itr->second);
      cache_.push_front(std::make_pair(key, val));
      cache_map_[key] = cache_.begin();
    }
  }

  int Get(int key) {
    auto itr = cache_map_.find(key);
    if (itr == cache_map_.end()) {
      return -1;
    }
    cache_.erase(itr->second);
    std::pair<int, int> pair_value = *(itr->second);
    cache_.push_front(pair_value);
    return pair_value.second;
  }

 private:
  int capacity_;
  std::list<std::pair<int, int>> cache_;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cache_map_;
};

void Print(Lru lru, int number) {
  for (int i = 1; i <= number; i++) {
    std::cout << lru.Get(i) << std::endl;
  }
}

int main(int argc, const char** argv) {
  Lru my_lru(2);
  // Print(my_lru, 4);

  my_lru.Put(1, 11);
  // Print(my_lru, 4);

  my_lru.Put(2, 22);
  // Print(my_lru, 4);
  my_lru.Put(3, 33);
  my_lru.Get(2);
  my_lru.Put(4, 44);
  Print(my_lru, 4);
}