#ifndef MYSQLDAO_H
#define MYSQLDAO_H

#include <QObject>
#include <QList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include "user.h"

class MySqlDAO : public QObject
{
    Q_OBJECT
private:
    QSqlDatabase db;
public:
    explicit MySqlDAO(QObject *parent = nullptr);

    bool connect();//пожкдючение к базе

    QList <User> getUsers();

signals:

};

#endif // MYSQLDAO_H
