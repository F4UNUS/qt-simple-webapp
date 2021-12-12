#ifndef USER_H
#define USER_H

#include <QObject>
#include <QString>

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    int m_id;

    QString m_name;

public:
    explicit User(QObject *parent = nullptr);
    User(const User &other);
    User(int id, QString name);

    int id() const;
    void setId(int newId);

    const QString &name() const;
    void setName(const QString &newName);

    User& operator=(const User &other);

    bool operator==(const User &other);

signals:
    void idChanged();
    void nameChanged();
};

#endif // USER_H
