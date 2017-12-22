#include <QApplication>
#include <QQuickView>
#include "qmlapplicationviewer/qmlapplicationviewer.h"
#include "ViewModel/MainViewModel.h"

Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));
    
    QmlApplicationViewer viewer;
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    
    MainModel mainModel;
    
    viewer.rootContext()->setContextProperty("model", new MainViewModel(mainModel));
    viewer.setMainQmlFile(QLatin1String("qml/QtQuickMvvmExample/MainView.qml"));
    viewer.showExpanded();
    
    return app->exec();
}
