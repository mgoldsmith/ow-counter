#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QStandardPaths>
#include <QQmlContext>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QStandardPaths::displayName(QStandardPaths::DocumentsLocation) + QString("ow-counter"));

    if (!db.open())
       {
          qDebug() << "Error: connection with database fail";
          return -1;
       }
       else
       {
          qDebug() << "Database: connection ok";
       }

    QSqlTableModel srModel(Q_NULLPTR, db);
    srModel.setTable("sr");
    srModel.setEditStrategy(QSqlTableModel::OnFieldChange);
    srModel.select();

    engine.rootContext()->setContextProperty("srModel", &srModel);

    return app.exec();
}
