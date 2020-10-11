#include "videoplayer.hpp"

VideoPlayer::VideoPlayer(QWidget *parent)
	: Phonon::VideoWidget(parent)
{
	mediaVideo = new Phonon::MediaObject(this);
	mediaVideo->setProperty("PlaybackTracking", true);

	mediaAudio = new Phonon::MediaObject(this);
	mediaAudio->setProperty("PlaybackTracking", true);

	audio = new Phonon::AudioOutput(Phonon::VideoCategory, this);
	Phonon::createPath(mediaVideo, this);
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
}

bool VideoPlayer::load(const QString &videoUri, const QString &audioUri)
{
	mediaVideo->setCurrentSource(Phonon::Mrl(videoUri));
	mediaVideo->play();

	mediaAudio->setCurrentSource(Phonon::Mrl(audioUri));
	mediaAudio->play();

	return mediaVideo->state() != Phonon::ErrorState;
}

void VideoPlayer::setVolume(int volume)
{
	audio->setVolume(volume / 100.0);
}