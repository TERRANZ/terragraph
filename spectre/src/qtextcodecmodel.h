#ifndef QTEXTCODECMODEL_H
#define QTEXTCODECMODEL_H

#include <QAbstractListModel>

Q_DECLARE_METATYPE(QTextCodec *)

class QTextCodecModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles
    {
        DataRole = Qt::UserRole
    };

public:
    explicit QTextCodecModel(QObject *parent = 0);

    int indexOfMib(int mib);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    static QList<int> m_CodecList;

};

#endif // QTEXTCODECMODEL_H
