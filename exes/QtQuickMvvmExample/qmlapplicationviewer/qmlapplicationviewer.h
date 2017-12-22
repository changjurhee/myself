#ifndef QMLAPPLICATIONVIEWER_H
#define QMLAPPLICATIONVIEWER_H

#include <QQuickView>

class QmlApplicationViewer : public QQuickView
{
	Q_OBJECT

	public:
		enum ScreenOrientation{
			ScreenOrientationLockPortrait,
			ScreenOrientationLockLandscape,
			ScreenOrientationAuto
		};

		explicit QmlApplicationViewer(QWidget *parent = 0);
		virtual ~QmlApplicationViewer();

		static QmlApplicationViewer *create();

		void setMainQmlFile(const QString &file);
		void addImportPath(const QString &path);

		void setOrientation(ScreenOrientation orientation);

		void showExpanded();

	private:
		class QmlApplicationViewerPrivate *d;
};

QApplication *createApplication(int &argc, char **argv);

#endif // QMLAPPLICATIONVIEWER_H
