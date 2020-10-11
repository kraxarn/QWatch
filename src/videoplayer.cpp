#include "videoplayer.hpp"

VideoPlayer::VideoPlayer(QWidget *parent)
	: QWidget(parent)
{

	mediaVideo = new Phonon::MediaObject(this);
	mediaVideo->setProperty("PlaybackTracking", true);

	mediaAudio = new Phonon::MediaObject(this);
	mediaAudio->setProperty("PlaybackTracking", true);

	audio = new Phonon::AudioOutput(Phonon::VideoCategory, this);
	video = new Phonon::VideoWidget(this);

	Phonon::createPath(mediaVideo, video);
	Phonon::createPath(mediaAudio, audio);

	Phonon::MediaObject::connect(mediaVideo, &Phonon::MediaObject::tick, [this](qint64 time)
	{
		emit this->positionChanged(time);
	});

	Phonon::MediaObject::connect(mediaVideo, &Phonon::MediaObject::stateChanged,
		[this](Phonon::State newState, Phonon::State)
		{
			emit this->stateChanged(newState);
		});

	setVisible(false);
}

bool VideoPlayer::load(const QString &videoUri, const QString &audioUri)
{
	mediaVideo->setCurrentSource(Phonon::Mrl(videoUri));
	mediaVideo->play();

	mediaAudio->setCurrentSource(Phonon::Mrl(audioUri));
	mediaAudio->play();

	setVisible(true);

	return mediaVideo->state() != Phonon::ErrorState;
}

void VideoPlayer::setVolume(int volume)
{
	audio->setVolume(volume / 100.0);
}

Phonon::SeekSlider *VideoPlayer::getSeekSlider()
{
	return new Phonon::SeekSlider(mediaVideo, this);
}

Phonon::VolumeSlider *VideoPlayer::getVolumeSlider()
{
	return new Phonon::VolumeSlider(audio, this);
}
