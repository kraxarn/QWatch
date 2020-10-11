#pragma once

#include <QString>

typedef struct
{
	QString title;

	QString videoUrl;
	QString audioUrl;

	QString videoType;
	QString audioType;

	qint64 duration;
} MediaInformation;