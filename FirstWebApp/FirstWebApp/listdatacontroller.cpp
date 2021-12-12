#include "listdatacontroller.h"

ListDataController::ListDataController(QObject *parent) : HttpRequestHandler(parent)
{

}

void ListDataController::service(HttpRequest &request, HttpResponse &response)
{
    if (mySqlDao.connect()) {
        setUsers(mySqlDao.getUsers());

        response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
        response.write("<html><body>");

        response.write("<table border='1' cellspacing='0'>");
        response.write("<tr><td>");
        response.write("Id");
        response.write("</td><td>");
        response.write("Name");
        response.write("</td></tr>");
        foreach (User user, m_users) {
            response.write("<tr><td>");
            response.write(QString::number(user.id()).toLatin1());
            response.write("</td><td>");
            response.write(user.name().toLatin1());
            response.write("</td></tr>");
        }
        response.write("</table>");

        response.write("</body></header>",true);
    } else {
        response.write("Error connect to Data Base");
    }
}

const QList<User> &ListDataController::users() const
{
    return m_users;
}

void ListDataController::setUsers(const QList<User> &newUsers)
{
    if (m_users == newUsers)
        return;
    m_users = newUsers;
    emit usersChanged();
}
