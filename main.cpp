#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <entropymodel.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    EntropyModel entropyModel;
    engine.rootContext()->setContextProperty("entropyModel", &entropyModel);
    engine.load(QUrl(QStringLiteral("../Entropy/main.qml")));
    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }
    return app.exec();
}
