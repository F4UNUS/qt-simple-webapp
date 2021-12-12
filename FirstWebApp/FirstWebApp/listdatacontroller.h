#ifndef LISTDATACONTROLLER_H
#define LISTDATACONTROLLER_H

#include <QList>
#include <QString>
#include <httprequesthandler.h>
#include <user.h>
#include <mysqldao.h>

using namespace stefanfrings;

class ListDataController : public HttpRequestHandler
{
    Q_OBJECT
    Q_PROPERTY(QList<User> users READ users WRITE setUsers NOTIFY usersChanged)
    QList<User> m_users;
    MySqlDAO mySqlDao;

public:
    explicit ListDataController(QObject *parent = nullptr);

    void service(HttpRequest& request, HttpResponse& response);

    const QList<User> &users() const;
    void setUsers(const QList<User> &newUsers);
signals:
    void usersChanged();
};

#endif // LISTDATACONTROLLER_H
