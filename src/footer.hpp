#pragma once

#include "font.hpp"
#include "icon.hpp"

#include <QToolBar>
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QToolButton>

class Footer: public QToolBar
{
Q_OBJECT

public:
	explicit Footer(QWidget *parent);

private:
	QWidget *progressSlider();
	QWidget *mediaControls();
	QWidget *volumeControl();
	QToolButton *toolButton(const QString &icon);

	// Progress
	QSlider *progress;
	QLabel *currentTimestamp;
	QLabel *currentLength;

	// Controls
	QAction *playPause;
};

