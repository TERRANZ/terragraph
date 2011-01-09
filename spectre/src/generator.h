#ifndef GENERATOR_H
#define GENERATOR_H

#include <QObject>
#include <QProcess>
#include <QString>
#include <QTextCodec>

class Generator: public QObject
{
    Q_OBJECT

public:
    explicit Generator(QObject *parent = 0);
    virtual ~Generator();

    QString command();
    void setPath(QString value);

    QString params();
    void setParams(QString value);

    void setWorkingDirectory(QString value);
    QString workingDirectory();

    void setCodec(QTextCodec *codec);
    QTextCodec *codec();

    bool isRunning();

public slots:
    bool start(QString fileName);
    void stop();
    void readResult();

signals:
    void writeResult(QString text);
    void finished(int code, QProcess::ExitStatus exitStatus);

private:
    QString replace(const QString &string, const QRegExp &regExp);

private:
    QProcess *m_Process;
    QString m_Path;
    QString m_Params;
    QString m_WorkingDirectory;
    QTextCodec *m_Codec;

    static const QString FullName;
    static const QString ShortName;
    static const QString Directory;
    static const QString Name;
    static const QString Extension;
};

#endif // GENERATOR_H
