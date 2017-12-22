#include <QDir>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView> //Not using QQmlApplicationEngine because many examples don't have a Window{}
#define DECLARATIVE_EXAMPLE_MAIN(NAME) int main(int argc, char* argv[]) \
{\
    QGuiApplication app(argc,argv);\
    app.setOrganizationName("QtProject");\
    app.setOrganizationDomain("qt-project.org");\
    app.setApplicationName(QFileInfo(app.applicationFilePath()).baseName());\
    QQuickView view;\
    if (qgetenv("QT_QUICK_CORE_PROFILE").toInt()) {\
        QSurfaceFormat f = view.format();\
        f.setProfile(QSurfaceFormat::CoreProfile);\
        f.setVersion(4, 4);\
        view.setFormat(f);\
    }\
    view.connect(view.engine(), &QQmlEngine::quit, &app, &QCoreApplication::quit);\
    new QQmlFileSelector(view.engine(), &view);\
    view.setSource(QUrl("qrc:///" #NAME ".qml")); \
    if (view.status() == QQuickView::Error)\
        return -1;\
    view.setResizeMode(QQuickView::SizeRootObjectToView);\
    if (QGuiApplication::platformName() == QLatin1String("qnx") || \
          QGuiApplication::platformName() == QLatin1String("eglfs")) {\
        view.showFullScreen();\
    } else {\
        view.show();\
    }\
    return app.exec();\
}

