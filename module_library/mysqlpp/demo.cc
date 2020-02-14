#include <mysql++.h>
#include <iostream>
#include <string>

class DataBaseHelper {
 public:
  DataBaseHelper(std::string data_base, std::string server, std::string usr,
                 std::string password)
      : data_base_(data_base), server_(server), usr_(usr), password_(password) {
    connect_ = std::make_shared<mysqlpp::Connection>(false);
  }
  bool Connect() {
    if (connect_->connect(data_base_.c_str(), server_.c_str(), usr_.c_str(),
                          password_.c_str())) {
      return true;
    }
    return false;
  }

  bool Add(std::string s) { return Operator(s); }

  bool Delete(std::string s) { return Operator(s); }

  bool Update(std::string s) { return Operator(s); }

  mysqlpp::StoreQueryResult Serach(std::string s) {
    mysqlpp::Query query = connect_->query();
    query << s;
    return query.store();
  }

 private:
  bool Operator(std::string s) {
    mysqlpp::Query query = connect_->query();
    query << s;
    return query.exec();
  }

  std::shared_ptr<mysqlpp::Connection> connect_;

  std::string data_base_;
  std::string server_;
  std::string usr_;
  std::string password_;
};

int main(int argc, char *argv[]) {
  DataBaseHelper data_base_helper("mysqlpp_demo", "127.0.0.1", "root", "123");
  if (!data_base_helper.Connect()) {
    std::cout << "database can't connect." << std::endl;
    return -1;
  }

  // 删
  data_base_helper.Delete("delete from demo");
  // 增
  data_base_helper.Add(
      "insert into demo(name, date, sex) values('lao wang', '4-10', "
      "'male');");
  data_base_helper.Add(
      "insert into demo values('lao han', '12-12', "
      "'female');");
  // 改
  data_base_helper.Update(
      "update demo set name = 'lao ge', date = '8-16' where name = "
      "'lao han';");
  // 查
  mysqlpp::StoreQueryResult res =
      data_base_helper.Serach("select date from demo where name = 'lao ge';");
  std::cout << "lao ge's birthday: " << res[0]["date"] << std::endl;
}
