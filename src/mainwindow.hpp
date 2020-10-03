#pragma once

#include "icon.hpp"

#include <QMainWindow>
#include <QMediaPlayer>
#include <QVideoWidget>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);

private:
	QMediaPlayer *mediaPlayer;
	QVideoWidget *videoWidget;
};
