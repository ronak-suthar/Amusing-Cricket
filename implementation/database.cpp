#include "../headers/database.h"
#include "../headers/menu.h"
#include <iostream>

database::database(void)
{

    database::databaseName = "CRICKET";
    database::server = "localhost";
    database::user = "root";
    database::password = "ronak@db";
    database::conn = database::establish_connection();
}
MYSQL *database::establish_connection(void)
{
    MYSQL *connection = mysql_init(NULL); // mysql instance

    //connect database
    if (!mysql_real_connect(connection, this->server, this->user, this->password, this->databaseName, 0, NULL, 0))
    {
        std::cout << "Connection Error: " << mysql_error(connection) << std::endl;
        exit(1);
    }
    return connection;
}
bool database::execute_query(const std::string &query)
{
    try
    {
        if (mysql_query(this->conn, query.c_str()))
        {
            throw 0;
        }
        else
        {
            return true;
        }
    }
    catch (int e)
    {
        std::cout << "ERROR : " << mysql_error(this->conn) << "\n";
        return false;
    }
}
void database::getData(void)
{
    print("Empty base class Virtual Method");
}
void database::insertData(void)
{
    print("Empty base class Virtual Method");
}
void database::updateData(void)
{
    print("Empty base class Virtual Method");
}
void database::removeData(void)
{
    print("Empty base class Virtual Method");
}
void database::viewData(void)
{
    print("Empty base class Virtual Method");
}
database::~database(void)
{

    mysql_close(this->conn);
}
