#include "mysqldao.h"

MySqlDAO::MySqlDAO(QObject *parent) : QObject(parent)
{

}

bool MySqlDAO::connect()
{
    db = QSqlDatabase::addDatabase("QMARIADB");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("test_webapp_db");
    db.setUserName("root");
    db.setPassword("password");

    return db.open();
}

QList<User> MySqlDAO::getUsers()
{
    QSqlQuery query("SELECT * FROM users");
    int idIndex = query.record().indexOf("id");
    int nameIndex = query.record().indexOf("name");
    QList<User> users;

    while (query.next()) {
        users.append(User(query.value(idIndex).toInt(), query.value(nameIndex).toString()));
    }

    return users;
}

