#include "footer.hpp"

Footer::Footer(QWidget *parent)
	: QToolBar(parent)
{
	setMovable(false);

	auto layout = new QVBoxLayout();
	layout->addWidget(mediaControls());

	auto layoutWidget = new QWidget(this);
	layoutWidget->setLayout(layout);
	addWidget(layoutWidget);
}

QWidget *Footer::progressSlider()
{
	auto layout = new QHBoxLayout();

	currentTimestamp = new QLabel("00:00", this);
	currentTimestamp->setMinimumWidth(40);
	currentTimestamp->setAlignment(Qt::AlignRight);
	layout->addWidget(currentTimestamp, 0, Qt::AlignRight);

	progress = new QSlider(Qt::Horizontal, this);
	layout->addWidget(progress, 1);

	currentLength = new QLabel("00:00", this);
	currentLength->setMinimumWidth(40);
	currentLength->setAlignment(Qt::AlignLeft);
	layout->addWidget(currentLength, 0, Qt::AlignLeft);

	auto layoutWidget = new QWidget(this);
	layoutWidget->setLayout(layout);
	return layoutWidget;
}

QWidget *Footer::mediaControls()
{
	auto layout = new QToolBar();

	playPause = layout->addAction(Icon::get("media-playback-start"), "Play");

	layout->addSeparator();
	layout->addAction(Icon::get("media-skip-backward"), "Previous");
	layout->addAction(Icon::get("media-playback-stop"), "Stop");
	layout->addAction(Icon::get("media-skip-forward"), "Next");

	layout->addSeparator();
	layout->addWidget(progressSlider());

	layout->addSeparator();
	layout->addWidget(toolButton("audio-volume-high"));
	layout->addWidget(volumeControl());

	return layout;
}

QToolButton *Footer::toolButton(const QString &icon)
{
	auto button = new QToolButton(this);
	button->setIcon(Icon::get(icon));
	return button;
}

QWidget *Footer::volumeControl()
{
	auto slider = new QSlider(Qt::Horizontal, this);
	slider->setMinimum(0);
	slider->setMaximum(20);
	slider->setValue(20);
	slider->setMaximumWidth(200);
	QSlider::connect(slider, &QSlider::valueChanged, this, &Footer::volumeValueChanged);
	return slider;
}

void Footer::volumeValueChanged(int value)
{
	emit volumeChanged(value * 5);
}

void Footer::setDuration(qint64 time)
{
	currentLength->setText(Utils::formatTime(time));
	progress->setMaximum((int) (time / 60));
}

void Footer::setPosition(qint64 time)
{
	currentTimestamp->setText(Utils::formatTime(time));
	progress->setValue((int) (time / 60));
}

void Footer::setPlaying(bool playing)
{
	playPause->setIcon(Icon::get(QString("media-playback-%1").arg(playing ? "pause" : "start")));
	playPause->setText(playing ? "Pause" : "Play");
}

