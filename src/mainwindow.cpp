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
	video = new QMediaPlayer(this);
	videoWidget = new QVideoWidget(this);
	video->setVideoOutput(videoWidget);
	audio = new QMediaPlayer(this);

	QMediaPlayer::connect(video, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error),
		this, &MainWindow::playerError);

	// Footer
	footer = new Footer(this);
	addToolBar(Qt::BottomToolBarArea, footer);

	Footer::connect(footer, &Footer::volumeChanged, [this](int volume)
	{
		this->audio->setVolume(volume);
	});

	// Sidebar
	auto contextWindow = new ContextWindow(this);
	addDockWidget(Qt::RightDockWidgetArea, contextWindow);
	ContextWindow::connect(contextWindow, &ContextWindow::playMedia, this, &MainWindow::playMedia);

	// Finish setup
	setCentralWidget(videoWidget);
}

void MainWindow::playMedia(const QString &videoUrl, const QString &audioUrl)
{
	video->setMedia(QUrl(videoUrl));
	audio->setMedia(QUrl(audioUrl));
	video->play();
	audio->play();
}

void MainWindow::playerError(QMediaPlayer::Error error)
{
	QString errorMsg;

	switch (error)
	{
		case QMediaPlayer::ResourceError:
			errorMsg = "Failed to resolve media";
			break;

		case QMediaPlayer::FormatError:
			errorMsg = "Media codec isn't supported";
			break;

		case QMediaPlayer::NetworkError:
			errorMsg = "Network error";
			break;

		case QMediaPlayer::AccessDeniedError:
			errorMsg = "Permission denied";
			break;

		case QMediaPlayer::ServiceMissingError:
			errorMsg = "Valid playback service not found";
			break;

		default:
			errorMsg = "Unknown error";
			break;
	}


	QMessageBox::warning(this, "Player error", errorMsg);
}
