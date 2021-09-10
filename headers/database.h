#ifndef DATABASE_H
#define DATABASE_H
#include<mysql/mysql.h>
#include<string>

class database{
    const char *server,*user,*password,*databaseName;
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    public:
    database(void);
    MYSQL* establish_connection(void);
    void execute_query(const std::string&);
    ~database(void);
};
#endif