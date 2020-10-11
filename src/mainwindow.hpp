#pragma once

#include "icon.hpp"
#include "footer.hpp"
#include "font.hpp"
#include "contextwindow.hpp"
#include "videoplayer.hpp"
#include "errordialog.hpp"
#include "mediainformation.hpp"

#include <QMainWindow>
#include <QFile>
#include <QApplication>
#include <QFontDatabase>
#include <QMessageBox>
#include <QSplitter>

class MainWindow: public QMainWindow
{
Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);

private:
	VideoPlayer *videoPlayer;
	Footer *footer;

	void playMedia(const MediaInformation &info);
	void showError(const QString &message, const QString &details);
	void createLayout();

	void positionChanged(qint64 position);
	void playerStateChanged(Phonon::State state);
};
