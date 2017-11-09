#include "entropymodel.h"

EntropyModel::EntropyModel()
{
    m_engine = std::unique_ptr<EntropyEngine>(new EntropyEngine());
}

/*bool EntropyModel::canFetchMore(const QModelIndex &parent) const
{
    Q_UNUSED (parent);
    static int currentFetchItem = 0;
    if (m_engine)
    {
        if (currentFetchItem < m_engine->itemsCount())
        {
            ++currentFetchItem;
            return true;
        }
        else
        {
            currentFetchItem = 0;
            return false;
        }
    }
    return false;
}*/

int EntropyModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED (parent);
    if (m_engine)
    {
        return m_engine->itemsCount();
    }
    return 0;
}

QVariant EntropyModel::data(const QModelIndex &index, int role) const
{
    if (m_engine)
    {
        if (role == (Qt::UserRole + 1))
        {
            qDebug() << m_engine->getItem(index.row()).x();
            return m_engine->getItem(index.row()).x();
        }
        if (role == (Qt::UserRole + 2))
        {
            qDebug() << m_engine->getItem(index.row()).y();
            return m_engine->getItem(index.row()).y();
        }
        if (role == (Qt::UserRole + 3))
        {
            qDebug() << m_engine->getItem(index.row()).color();
            return QColor(m_engine->getItem(index.row()).color());
        }
    }
    return 0;
}

QHash<int, QByteArray> EntropyModel::roleNames() const
{
    QHash<int, QByteArray> role;
    role[Qt::UserRole + 1] = "xValue";
    role[Qt::UserRole + 2] = "yValue";
    role[Qt::UserRole + 3] = "colorValue";

    return role;
}

float EntropyModel::windowWight() const
{
    return m_windowWight;
}

float EntropyModel::windowHeight() const
{
    return m_windowHeight;
}

