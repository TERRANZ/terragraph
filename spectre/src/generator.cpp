#include "generator.h"
#include <QRegExp>
#include <QApplication>

const QString Generator::FullName = "\\$F";
const QString Generator::ShortName = "\\$f";
const QString Generator::Directory = "\\$d";
const QString Generator::Name = "\\$n";
const QString Generator::Extension = "\\$e";

Generator::Generator(QObject *parent)
    : QObject(parent)
{
    m_Process = new QProcess(this);
    m_Codec = QTextCodec::codecForName("IBM 866");

    connect(m_Process, SIGNAL(readyReadStandardOutput()), this, SLOT(readResult()));
    connect(m_Process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SIGNAL(finished(int,QProcess::ExitStatus)));
}

Generator::~Generator()
{
    if(m_Process->state() != QProcess::NotRunning)
    {
        m_Process->kill();
    }
}

QString Generator::command()
{
    return m_Path;
}

void Generator::setPath(QString value)
{
    m_Path = value;
}

QString Generator::params()
{
    return m_Params;
}

void Generator::setParams(QString value)
{
    m_Params = value;
}

void Generator::setWorkingDirectory(QString value)
{
    m_WorkingDirectory = value;
}

QString Generator::workingDirectory()
{
    return m_WorkingDirectory;
}

void Generator::setCodec(QTextCodec *codec)
{
    if(codec == 0)
        return;
    m_Codec = codec;
}

QTextCodec * Generator::codec()
{
    return m_Codec;
}

bool Generator::isRunning()
{
    if(m_Process->state() == QProcess::NotRunning)
        return false;
    return true;
}

bool Generator::start(QString fileName)
{
    QRegExp regExp("^(.*[\\\\/])(.*)(\\..*)?$");
    if(!regExp.exactMatch(fileName))
    {
        emit writeResult("error file name.");
        return false;
    }

    QString params = replace(m_Params, regExp);
    QString workingDirectory = replace(m_WorkingDirectory, regExp);

    QString fullPath = QString("%2 %3").arg(m_Path).arg(params);
    emit writeResult(QString("%1> %2").arg(workingDirectory).arg(fullPath));
    m_Process->setWorkingDirectory(workingDirectory);

    m_Process->start(fullPath);
    return true;
}

void Generator::stop()
{
    m_Process->kill();
}

void Generator::readResult()
{
    emit writeResult(m_Codec->toUnicode(m_Process->readAllStandardOutput()));
}



QString Generator::replace(const QString &string, const QRegExp &regExp)
{
    QString result = string;
    result.replace(QRegExp(FullName), regExp.cap(0));
    result.replace(QRegExp(ShortName), regExp.cap(2) + regExp.cap(3));
    result.replace(QRegExp(Directory), regExp.cap(1));
    result.replace(QRegExp(Name), regExp.cap(2));
    result.replace(QRegExp(Extension), regExp.cap(3));
    return result;
}
