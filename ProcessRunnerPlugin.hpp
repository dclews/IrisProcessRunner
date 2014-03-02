#ifndef IRISPROCESSRUNNER_HPP
#define IRISPROCESSRUNNER_HPP

#include <QObject>
#include <QtPlugin>

#include <iris/CommandPlugin.hpp>
#include "ProcessRunnerFactory.hpp"

namespace iris
{
    class ProcessRunnerPlugin : public QObject, public CommandPlugin
    {
    private:
        Q_OBJECT
        Q_PLUGIN_METADATA(IID CommandPlugin_iid FILE "plugin.json")
        Q_INTERFACES(CommandPlugin)
    public:
        ProcessRunnerPlugin();
        // CommandPlugin interface
        ~ProcessRunnerPlugin();
        QList<CommandPluginFactory*> commands() const;
    };
}

#endif // IRISPROCESSRUNNER_HPP
