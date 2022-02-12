#include "json_start.h"

#include <debug.h>

#include <KPluginFactory>

K_PLUGIN_FACTORY_WITH_JSON(json_startFactory, "json_start.json", registerPlugin<json_start>(); )

json_start::json_start(QObject *parent, const QVariantList& args)
    : KDevelop::IPlugin(QStringLiteral("json_start"), parent)
{
    Q_UNUSED(args);

    qCDebug(PLUGIN_JSON_START) << "Hello world, my plugin is loaded!";
}

// needed for QObject class created from K_PLUGIN_FACTORY_WITH_JSON
#include "json_start.moc"
