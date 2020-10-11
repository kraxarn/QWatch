#pragma once

#include <QString>

typedef struct {
	QString videoUrl, audioUrl, videoType, audioType;
	qint64 duration;
} MediaInformation;