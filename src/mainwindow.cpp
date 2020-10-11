#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	// Custom dark theme
	QFile styleFile(":/res/style/Dark.qss");
	styleFile.open(QIODevice::ReadOnly);
	QApplication::setStyle("fusion");
	setStyleSheet(styleFile.readAll());
	styleFile.close();

	// Custom font
	QFontDatabase::addApplicationFont(":/res/font/NotoSans-Regular.ttf");
	QFontDatabase::addApplicationFont(":/res/font/NotoSansMono-Regular.ttf");

	// Window properties
	setWindowIcon(Icon::get("logo:app"));
	resize(1280, 720);

	// Media player stuff
	videoPlayer = new VideoPlayer(this);
	VideoPlayer::connect(videoPlayer, &VideoPlayer::error, this, &MainWindow::showError);
	VideoPlayer::connect(videoPlayer, &VideoPlayer::positionChanged, this, &MainWindow::positionChanged);
	VideoPlayer::connect(videoPlayer, &VideoPlayer::stateChanged, this, &MainWindow::playerStateChanged);

	// Footer
	footer = new Footer(this);
	addToolBar(Qt::BottomToolBarArea, footer);
	Footer::connect(footer, &Footer::volumeChanged, videoPlayer, &VideoPlayer::setVolume);

	// Sidebar
	auto contextWindow = new ContextWindow(this);
	addDockWidget(Qt::RightDockWidgetArea, contextWindow);
	ContextWindow::connect(contextWindow, &ContextWindow::playMedia, this, &MainWindow::playMedia);

	// Finish setup
	setCentralWidget(videoPlayer);
}

void MainWindow::playMedia(const MediaInformation &info)
{
	videoPlayer->load(info.videoUrl, info.audioUrl);
	footer->setDuration(info.duration);
}

void MainWindow::showError(const QString &message, const QString &details)
{
	(new ErrorDialog(message, details, this))->show();
}

void MainWindow::positionChanged(qint64 position)
{
	footer->setPosition(position);
}

void MainWindow::playerStateChanged(Phonon::State state)
{
	footer->setPlaying(state == Phonon::PlayingState);
}
