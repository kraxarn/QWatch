#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
	QCoreApplication::setOrganizationName("kraxarn");
	QCoreApplication::setApplicationName("QWatch");
	QCoreApplication::setApplicationVersion("0.1");

	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return QApplication::exec();
}
