#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QPlainTextEdit>
#include <QMessageBox>

#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonDocument>
#include <JSONHighlighter.hpp>

#include <QDebug>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

private:
    QVBoxLayout *m_mainLayout   = new QVBoxLayout();

    QHBoxLayout *m_getLayout    = new QHBoxLayout();
    QLineEdit   *m_getUrlLine   = new QLineEdit();
    QPushButton *m_getButton    = new QPushButton("GET");

    QPlainTextEdit   *m_responseText = new QPlainTextEdit();
    JSONHighlighter  *m_jsonHighlighter;

    QNetworkAccessManager *m_networkManager = new QNetworkAccessManager(this);
};

#endif // MAINWINDOW_HPP
