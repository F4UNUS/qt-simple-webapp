#include "user.h"

User::User(QObject *parent) : QObject(parent)
{

}

User::User(const User &other) :
    QObject(other.parent()),
    m_id(other.id()),
    m_name(other.name())
{
}

User::User(int id, QString name)
{
    m_id = id;
    m_name = name;
}

int User::id() const
{
    return m_id;
}

void User::setId(int newId)
{
    if (m_id == newId)
        return;
    m_id = newId;
    emit idChanged();
}

const QString &User::name() const
{
    return m_name;
}

void User::setName(const QString &newName)
{
    if (m_name == newName)
        return;
    m_name = newName;
    emit nameChanged();
}

User &User::operator=(const User &other)
{
    m_id = other.id();
    m_name = other.name();
    return *this;
}

bool User::operator==(const User &other)
{
    return (id() == other.id()) && (name() == other.name());
}

