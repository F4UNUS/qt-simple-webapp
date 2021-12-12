#include <QCoreApplication>
#include <QDebug>
#include <QSettings>
#include "httplistener.h"
#include "httprequesthandler.h"
#include <QFile>
#include "listdatacontroller.h"

using namespace stefanfrings;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qputenv("QT_MESSAGE_PATTERN", QByteArray("[%{type}] - %{message}"));//настрйока формата вывода

    QString filename = "../FirstWebApp/etc/webapp.ini";//путь к ini файлу

    QFile file(filename);
    if (file.exists()) {
        qInfo() << "file was finded";
        QSettings *listenerSettings = new QSettings(filename, QSettings::IniFormat, &a);
        listenerSettings->beginGroup("listener");//забираем настрйоки listner из .ini файла

        new HttpListener(listenerSettings, new ListDataController(&a), &a);
    } else {
        qFatal("file not exists");
    }

    return a.exec();
}
