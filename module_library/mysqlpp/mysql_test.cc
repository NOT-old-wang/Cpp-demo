#include <mysql.h>
#include <stdio.h>

int main(int argc, const char **argv) {
  MYSQL connect;
  int res = 0;
  mysql_init(&connect);
  printf("mysql test\n");
  char *host = "127.0.0.1";
  char *user = "root";
  char *passward = "123";
  char *database = "test";
  if (mysql_real_connect(&connect, host, user, passward, database, 0, NULL,
                         CLIENT_FOUND_ROWS)) {
    printf("connect success!\n");
    res = mysql_query(&connect, "insert into test values('user','123456')");
    if (res) {
      printf("error\n");
    } else {
      printf("OK\n");
    }
    mysql_close(&connect);
  } else {
    fprintf(stderr, "error: %s", mysql_error(&connect));
    printf("connect failed!\n");
  }
  return 0;
}
