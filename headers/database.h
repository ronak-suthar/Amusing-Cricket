#ifndef DATABASE_H
#define DATABASE_H
#include<mysql/mysql.h>
#include<string>

class database{
    public:
    
    const char *server,*user,*password,*databaseName;
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    
    database(void);

    MYSQL* establish_connection(void);
    bool execute_query(const std::string&);

    virtual void insertData(void);
    virtual void updateData(void);
    virtual void removeData(void);
    virtual void viewData(void);

    virtual ~database(void);
};

#endif