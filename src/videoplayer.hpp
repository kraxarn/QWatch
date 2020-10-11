#pragma once

#include <QDebug>
#include <QApplication>

#include <phonon/Global>
#include <phonon/AudioOutput>
#include <phonon/MediaObject>
#include <phonon/Mrl>
#include <phonon/SeekSlider>
#include <phonon/VideoWidget>
#include <phonon/VolumeSlider>

class VideoPlayer: public QWidget
{
Q_OBJECT

public:
	explicit VideoPlayer(QWidget *parent);

	bool load(const QString &videoUri, const QString &audioUri);
	void setVolume(int volume);

	Phonon::SeekSlider *getSeekSlider();
	Phonon::VolumeSlider *getVolumeSlider();

signals:
	void error(const QString &message, const QString &details);
	void positionChanged(qint64 position);
	void stateChanged(Phonon::State state);

private:
	Phonon::MediaObject *mediaVideo = nullptr;
	Phonon::MediaObject *mediaAudio = nullptr;

	Phonon::AudioOutput *audio = nullptr;
	Phonon::VideoWidget *video = nullptr;
};