#pragma once

#include <QDebug>
#include <QApplication>
#include <QSizePolicy>

#include <phonon/Global>
#include <phonon/AudioOutput>
#include <phonon/MediaObject>
#include <phonon/Mrl>
#include <phonon/SeekSlider>
#include <phonon/VideoWidget>
#include <phonon/VolumeSlider>

class VideoPlayer: public Phonon::VideoWidget
{
Q_OBJECT

public:
	explicit VideoPlayer(QWidget *parent);

	bool load(const QString &videoUri, const QString &audioUri);
	void setVolume(int volume);

signals:
	void error(const QString &message, const QString &details);
	void positionChanged(qint64 position);
	void stateChanged(Phonon::State state);

private:
	Phonon::MediaObject *mediaVideo = nullptr;
	Phonon::MediaObject *mediaAudio = nullptr;

	Phonon::AudioOutput *audio = nullptr;
};