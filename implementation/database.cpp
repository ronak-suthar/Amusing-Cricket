#include"../headers/database.h"
#include<iostream>

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

void database::execute_query(const std::string &query)
{
    if (mysql_query(this->conn, query.c_str()))
    {
        std::cout << "ERROR : " << mysql_error(this->conn) << "\n";
    }
    else
    {
        std::cout << "Transaction Successfull\n";
        std::cout << "Press Any key to go back to menu\n";
        getchar();
    }
}
database::~database(void)
{
    mysql_close(this->conn);
}


