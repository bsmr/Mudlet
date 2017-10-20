#ifndef UPDATER_H
#define UPDATER_H

#include "dblsqd/feed.h"
#include "dblsqd/update_dialog.h"
#include "../3rdparty/sparkle-glue/AutoUpdater.h"

#include "pre_guard.h"
#include <QObject>
#include "post_guard.h"

class TUpdateDialog : public dblsqd::UpdateDialog
{
public:
    explicit TUpdateDialog(dblsqd::Feed* feed, Type type = dblsqd::UpdateDialog::Type::OnUpdateAvailable,
                           QWidget* parent = nullptr, QSettings* settings = new QSettings())
    : UpdateDialog(feed, type, parent, settings)
    {
    }

private:
    void startUpdate() override;
};

class Updater : public QObject
{
    Q_OBJECT

public:
    Q_DISABLE_COPY(Updater)
    explicit Updater(QObject* parent = nullptr);
    void doUpdates();

private:
    dblsqd::Feed* feed;
    TUpdateDialog* updateDialog;

//#ifdef Q_OS_MACOS
    AutoUpdater* updater;
//#endif

    void setupOnLinux();
    void untarOnLinux(const QString& fileName) const;

signals:

public slots:

    void updateBinaryOnLinux() const;

    void setupOnMacOS();
};

#endif // UPDATER_H
