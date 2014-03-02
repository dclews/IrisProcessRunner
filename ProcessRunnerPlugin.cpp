#include "ProcessRunnerPlugin.hpp"
#include "ProcessRunnerFactory.hpp"

namespace iris
{
    ProcessRunnerPlugin::ProcessRunnerPlugin()
    {
    }

    ProcessRunnerPlugin::~ProcessRunnerPlugin()
    {
    }

    QList<CommandPluginFactory*> ProcessRunnerPlugin::commands() const
    {
        QList<CommandPluginFactory*> commands;
        commands << new ProcessRunnerFactory;
        return commands;
    }
}
