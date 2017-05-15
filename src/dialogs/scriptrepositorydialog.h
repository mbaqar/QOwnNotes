#pragma once

#include "masterdialog.h"
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QSplitter>
#include <QTreeWidgetItem>

namespace Ui {
class ScriptRepositoryDialog;
}

class ScriptRepositoryDialog : public MasterDialog
{
    Q_OBJECT

public:
    explicit ScriptRepositoryDialog(QWidget *parent = 0);
    ~ScriptRepositoryDialog();

private slots:
    void on_searchScriptEdit_returnPressed();

    void slotReplyFinished(QNetworkReply *);

    void on_scriptTreeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);

private:
    Ui::ScriptRepositoryDialog *ui;
    QNetworkAccessManager *_networkManager;
    QString _codeSearchUrl;
    QSplitter *_mainSplitter;

    void searchScript();

    void setupMainSplitter();

    void parseCodeSearchReply(const QByteArray &arr) const;

    void storeSettings();

    void parseInfoQMLReply(const QByteArray &arr) const;
};