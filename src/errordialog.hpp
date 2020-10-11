#pragma once

#include <QDialog>
#include <QLabel>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>

class ErrorDialog: public QDialog
{
Q_OBJECT

public:
	ErrorDialog(const QString &message, const QString &details, QWidget *parent = nullptr);
};


