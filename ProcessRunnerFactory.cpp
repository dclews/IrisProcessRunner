#include "ProcessRunnerFactory.hpp"
#include "ProcessRunner.hpp"

namespace iris
{
    ProcessRunnerFactory::ProcessRunnerFactory()
    {
    }
    ASyncCommand* ProcessRunnerFactory::newCommand()
    {
        return new ProcessRunner;
    }
    QString ProcessRunnerFactory::syntax()
    {
        return QString("EXEC <command> (<args...>)");
    }
    bool ProcessRunnerFactory::isListener()
    {
        return false;
    }
}
