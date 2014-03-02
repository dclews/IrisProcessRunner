#ifndef PROCESSRUNNER_HPP
#define PROCESSRUNNER_HPP

#include <QObject>
#include <QStringList>
#include <QProcess>
#include <iris/ASyncCommand.hpp>

namespace iris
{
    class ProcessRunner : public ASyncCommand
    {
    private:
        Q_OBJECT
        QProcess pr;
        QString execCommand;
        QStringList execArgs;
    public:
        explicit ProcessRunner();

    signals:
        void printLine(QString nick, QString line);
        void commandDone(int exitCode);

    public slots:
        void readOutput();
        void printError(QProcess::ProcessError perr);
        // ASyncCommand interface
        QString syntax();
        void commandFinished(int exitCode);
        void exec();
        //@Override
        void setCommand(IrcCommand* command);
    };
}

#endif // PROCESSRUNNER_HPP
