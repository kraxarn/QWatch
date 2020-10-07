#pragma once

#include "icon.hpp"
#include "footer.hpp"
#include "font.hpp"
#include "contextwindow.hpp"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QFile>
#include <QApplication>
#include <QFontDatabase>
#include <QMessageBox>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);

private:
	QMediaPlayer *video;
	QVideoWidget *videoWidget;

	Footer *footer;

	void playMedia(const QString &videoUrl, const QString &audioUrl);

	void playerError(QMediaPlayer::Error error);
	void playerPosition(quint64 position);
};
