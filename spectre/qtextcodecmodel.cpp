#include "qtextcodecmodel.h"

#include <QTextCodec>

QList<int> QTextCodecModel::m_CodecList;

QTextCodecModel::QTextCodecModel(QObject *parent) :
    QAbstractListModel(parent)
{
    if(m_CodecList.isEmpty())
        m_CodecList = QTextCodec::availableMibs();
}

int QTextCodecModel::indexOfMib(int mib)
{
    return m_CodecList.indexOf(mib);
}

int QTextCodecModel::rowCount(const QModelIndex &parent) const
{
    return m_CodecList.count();
}

QVariant QTextCodecModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= m_CodecList.count())
        return QVariant();

    QTextCodec *codec = 0;

    switch(role)
    {
    case Qt::DisplayRole:
        codec = QTextCodec::codecForMib(m_CodecList[index.row()]);
        return codec->toUnicode(codec->name());
    case DataRole:
        codec = QTextCodec::codecForMib(m_CodecList[index.row()]);
        QVariant result;
        result.setValue(codec);
        return result;
    }
    return QVariant();
}
