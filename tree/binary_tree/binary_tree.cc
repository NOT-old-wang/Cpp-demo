#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <thread>
#include <chrono>

/*
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 从上到下, 从左到右打印树
void Print(const TreeNode* tree) {
  std::cout << "tree: " << std::endl;
  if (tree == nullptr) {
    std::cout << "tree is empty." << std::endl;
    return;
  }
  std::queue<TreeNode*> tree_queue;
  tree_queue.push(const_cast<TreeNode*>(tree));
  while (!tree_queue.empty()) {
    TreeNode* temp = tree_queue.front();
    std::cout << temp->val << ", ";
    if (temp->left != nullptr) tree_queue.push(temp->left);
    if (temp->right != nullptr) tree_queue.push(temp->right);
    tree_queue.pop();
  }
  std::cout << std::endl;
  std::cout << std::endl;
}

/*
对 TreeNode 进行操作的类
*/
class TreeOperator {
 public:
  TreeOperator() : tree_(nullptr) {}

  // 遍历模式: 前序, 中序, 后序
  enum class TraversalMode : uint8_t { NONE, DLR, LDR, LRD };
  // 遍历方式: 递归, 迭代, 栈
  enum class TraversalMethod : uint8_t { RECURSION, ITERATION, STACK };
  /*
  输入: {1, 2, 3, 4, 5, 6, 7}
  创建如下树:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
  */
  void CreateTree(std::vector<int> values) {
    // tree_ = new TreeNode(values[0]);
    // TreeNode* work = tree_;
    // for (auto value : values) {
    //   work->left =
    // }
    tree_ = new TreeNode(1);
    TreeNode* work = tree_;
    work->left = new TreeNode(2);
    work->right = new TreeNode(3);
    work->left->left = new TreeNode(4);
    work->left->right = new TreeNode(5);
    work->right->left = new TreeNode(6);
    work->right->right = new TreeNode(7);
  }

  TreeNode* Tree() { return tree_; }
  // 遍历
  void Traversal(TraversalMode mode) {
    switch (mode) {
      case TraversalMode::DLR:
        return PreorderTraversal();
      case TraversalMode::LDR:
        return InorderTraversal();
      case TraversalMode::LRD:
        return PostorderTraversal();
      default:
        std::cerr << "no this traversal mode." << std::endl;
    }
  }

 private:
  //  TreeNode* Traversal(TraversalMethod method) {
  //   switch (method) {
  //     case TraversalMode::DLR:
  //     case TraversalMode::LDR:
  //     case TraversalMode::LRD:
  //   }
  // }

  /* DLR 前序遍历
  首先访问根结点,然后遍历左子树,最后遍历右子树
  以下树的前序遍历为 1,2,4,5,3,6,7
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
  */
/**
 * 前序遍历栈方式
 * 1、若栈非空输出根节点，并出栈
 * 2、将右节点压栈（如果存在）
 * 3、将左节点压栈（如果存在）
 * 4、重复第1步直到栈空
 */
  void PreorderTraversal() const {
    if (tree_ == nullptr) return;
   std::cout << "DLR traversal: " << std::endl;
    std::vector<int> tree_nums;
    std::stack<TreeNode*> tree_stack;
    tree_stack.push(tree_);
    while (!tree_stack.empty()) {
      TreeNode* head = tree_stack.top();
      tree_stack.pop();
      tree_nums.emplace_back(head->val);
      if (head->right != nullptr) {
        tree_stack.push(head->right);
      }
      if (head->left != nullptr) {
        tree_stack.push(head->left);
      }
    }
    for (int num : tree_nums) {
      std::cout << num << ", ";
    }
   std::cout << std::endl;
   std::cout << std::endl;
  }
//  void PreorderTraversal() const {
//   std::cout << "DLR traversal: " << std::endl;
//   PreorderTraversal(tree_);
//   std::cout << std::endl;
//   std::cout << std::endl;
// }
  
  void PreorderTraversal(TreeNode* tree) const {
    if (tree == nullptr) return;
    std::cout << tree->val << ", ";
    PreorderTraversal(tree->left);
    PreorderTraversal(tree->right);
    return;
  }

  /* LDR 中序遍历
  首先遍历左子树, 然后访问根结点, 最后遍历右子树
  以下树的中序遍历为 4,2,5,1,6,3,7
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
  */
  void InorderTraversal() const {
    if (tree_ == nullptr) return;
    std::cout << "LDR traversal: " << std::endl;
    std::vector<int> tree_nums;
    std::stack<TreeNode*> tree_stack;
    TreeNode* head = tree_;
    while (nullptr != head || !tree_stack.empty()) {
      while (nullptr != head) {
        tree_stack.push(head);
        head = head->left;
      }
      head = tree_stack.top();
      tree_stack.pop();
      tree_nums.emplace_back(head->val);
      head = head->right;
    }
    for (auto num : tree_nums) {
      std::cout << num << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }
//  void InorderTraversal() const {
//    TreeNode* work = tree_;
//    std::cout << "LDR traversal: " << std::endl;
//    InderTraversal(work);
//    std::cout << std::endl;
//    std::cout << std::endl;
//  }

  void InderTraversal(TreeNode* tree) const {
    if (tree == nullptr) return;
    InderTraversal(tree->left);
    std::cout << tree->val << ", ";
    InderTraversal(tree->right);
    return;
  }

  /* LRD 后序遍历
  首先遍历左子树，然后遍历右子树，最后访问根结点
  以下树的后序遍历为 4,5,2,6,7,3,1
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
  */
  void PostorderTraversal() const {
    if (tree_ == nullptr) return;
    std::cout << "LRD traversal: " << std::endl;
    std::vector<int> tree_nums;
    std::stack<TreeNode*> tree_stack;
    TreeNode* last = nullptr;
    TreeNode* head = tree_;
    tree_stack.push(head);
    head = head->left;
    while (!tree_stack.empty()) {
      while (head != nullptr) {
        tree_stack.push(head);
        head = head->left;
      }
      while (!tree_stack.empty()) {
        head = tree_stack.top();
        if (head->right == last || head->right == nullptr) {
          last = head;
          tree_nums.emplace_back(head->val);
          tree_stack.pop();
        } else if (head->right != nullptr) {
          head = head->right;
          break;
        }
      }
    }
    for (auto num : tree_nums) {
      std::cout << num << ", ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
  }
  
//  void PostorderTraversal() const {
//    TreeNode* work = tree_;
//    std::cout << "LRD traversal: " << std::endl;
//    PostorderTraversal(work);
//    std::cout << std::endl;
//    std::cout << std::endl;
//  }

  void PostorderTraversal(TreeNode* tree) const {
    if (tree == nullptr) return;
    PostorderTraversal(tree->left);
    PostorderTraversal(tree->right);
    std::cout << tree->val << ", ";
    return;
  }

  TreeNode* tree_;
};

int main(int argc, const char** argv) {
  TreeOperator tree_operator;
  tree_operator.CreateTree({1, 2, 3, 4, 5, 6, 7});
  Print(tree_operator.Tree());

  tree_operator.Traversal(TreeOperator::TraversalMode::LRD);
}
