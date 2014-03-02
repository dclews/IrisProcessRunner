#include "ProcessRunner.hpp"
#include <QDebug>
#include <QProcess>

namespace iris
{
    ProcessRunner::ProcessRunner()
    {
    }

    void ProcessRunner::commandFinished(int exitCode)
    {
        QString finished = "Command \"" + execCommand + "\" finished with exit code " + QString::number(exitCode);
        qDebug() << finished;

        while(pr.canReadLine())
        {
            readOutput();
        }
        emit(printLine(target, finished));
        emit(commandDone(exitCode));
    }
    void ProcessRunner::exec()
    {
        qDebug() << "[PR] run()";
        qDebug() << "[Bot] Starting process " << execCommand;

        parameters.removeFirst(); //Remove !EXEC
        parameters.removeFirst(); //Remove execCmd

        connect(&pr, SIGNAL(readyRead()), this, SLOT(readOutput()));
        connect(&pr, SIGNAL(error(QProcess::ProcessError)), this, SLOT(printError(QProcess::ProcessError)));
        connect(&pr, SIGNAL(finished(int)), this, SLOT(commandFinished(int)));
        pr.start(execCommand, parameters);
    }

    void ProcessRunner::setCommand(IrcCommand* command)
    {
        this->execCommand = command->parameters().at(1);
        ASyncCommand::setCommand(command);
    }

    QString ProcessRunner::syntax()
    {
        return QString("EXEC <command> (<args...>)");
    }

    void ProcessRunner::readOutput()
    {
        qDebug() << "[PR] Read()";
        emit(printLine(target, QString(pr.readLine())));
    }

    void ProcessRunner::printError(QProcess::ProcessError perr)
    {
        QString error = "[ERROR] Command: " + execCommand + " Process ";
        switch(perr)
        {
            case QProcess::FailedToStart: error += "failed to start."; break;
            case QProcess::Crashed: error += "crashed."; break;
            case QProcess::Timedout: error += "timed out."; break;
            case QProcess::WriteError: error += "encountered a write error."; break;
            case QProcess::ReadError: error += "encountered a read error."; break;
            case QProcess::UnknownError: error += "encountered an unknown error."; break;
        }
        emit(printLine(target, error));
    }
}
