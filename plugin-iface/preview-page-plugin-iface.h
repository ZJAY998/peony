#ifndef PREVIEWPAGEPLUGINIFACE_H
#define PREVIEWPAGEPLUGINIFACE_H

#include <QPluginLoader>
#include <QtPlugin>
#include <QString>
#include "plugin-iface.h"

#define PreviewPagePluginIface_iid "org.ukui.peony-qt.plugin-iface.PreviewPagePluginIface"

namespace Peony {

class PreviewPagePluginIface : public PluginInterface
{
public:
    enum PreviewType {
        Attribute,
        Text,
        Pictrue,
        PDF,
        OfficeDoc,
        Other
    };

    virtual QWidget *createPreviewPage(const QString &uri, PreviewType type) = 0;
    virtual void startPreview() = 0;
    virtual void cancel() = 0;
    virtual void closePreviewPage() = 0;
};

}

Q_DECLARE_INTERFACE(Peony::PreviewPagePluginIface, PreviewPagePluginIface_iid)

#endif // PREVIEWPAGEPLUGINIFACE_H
