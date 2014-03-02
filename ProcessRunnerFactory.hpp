#ifndef PROCESSRUNNERFACTORY_HPP
#define PROCESSRUNNERFACTORY_HPP

#include <QObject>
#include <iris/CommandPluginFactory.hpp>

class CommandPlugin;

namespace iris
{
    class ProcessRunner;
    class ProcessRunnerFactory : public QObject, public CommandPluginFactory
    {
        Q_OBJECT
    public:
        explicit ProcessRunnerFactory();
    public slots:
        ASyncCommand* newCommand();
        QString syntax();
        bool isListener();
    };
}


#endif // PROCESSRUNNERFACTORY_HPP
