#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_getLayout->addWidget(m_getUrlLine);
    m_getLayout->addWidget(m_getButton);

    m_mainLayout->addLayout(m_getLayout);
    m_mainLayout->addWidget(m_responseText);
    this->setLayout(m_mainLayout);

    connect(m_getButton, &QPushButton::clicked, [=](){
        auto *reply = m_networkManager->get(QNetworkRequest(m_getUrlLine->text()));
        connect(reply, &QNetworkReply::finished, [=](){
            if (reply->rawHeader("Content-Type").contains("json")) {
                m_jsonHighlighter = new JSONHighlighter(m_responseText->document());
                m_responseText->setPlainText(QJsonDocument::fromJson(reply->readAll()).toJson());
            } else {
                m_responseText->setPlainText(reply->readAll());
            }
        });

        connect(reply, static_cast<void(QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error),
                [=](QNetworkReply::NetworkError code){
            QMessageBox::critical(this, "Error", "Network error: " + code);
        });
    });

    connect(m_getUrlLine, &QLineEdit::returnPressed, [=](){
        m_getButton->click();
    });
}
