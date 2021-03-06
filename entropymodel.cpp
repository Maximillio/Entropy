#include "entropymodel.h"

EntropyModel::EntropyModel()
{
    m_windowHeight = 800;
    m_windowWidth  = 1024;
    m_frameDelay   = 15;   
    m_itemSize     = 50;
    m_isRunning    = false;
    m_itemSpeed    = 100;
    m_engine       = std::unique_ptr<EntropyEngine>(new EntropyEngine(m_windowHeight, m_windowWidth, m_itemSpeed));
    m_frameClock   = std::unique_ptr<QTimer>(new QTimer(this));
    connect(m_frameClock.get(), SIGNAL(timeout()), this, SLOT(updateData()));
    connect(this, SIGNAL(m_itemSpeedChanged(int)), &(*m_engine), SLOT(onSpeedChanged(int)));
    m_timeBefore   = high_resolution_clock::now();
    m_timeAfter    = high_resolution_clock::now();
    setIsRunning(true);
    m_frameClock->start(m_frameDelay);
}

EntropyModel::~EntropyModel()
{
    m_frameClock->stop();
}

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
            return m_engine->getItem(index.row()).x();
        }
        if (role == (Qt::UserRole + 2))
        {
            return m_engine->getItem(index.row()).y();
        }
        if (role == (Qt::UserRole + 3))
        {
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

float EntropyModel::windowWidth() const
{
    return m_windowWidth;
}

float EntropyModel::windowHeight() const
{
    return m_windowHeight;
}

void EntropyModel::updateData()
{
    m_timeBefore = high_resolution_clock::now();
    m_timeElapsed = duration_cast<duration<double>>(m_timeBefore - m_timeAfter);
    if (m_isRunning)
    {
        m_engine->update(m_timeElapsed.count());
    }
    dataChanged(index(0),index(m_engine->itemsCount() - 1));
    m_timeAfter = high_resolution_clock::now();
}

int EntropyModel::itemSize() const
{
    return m_itemSize;
}

bool EntropyModel::isRunning() const
{
    return m_isRunning;
}

void EntropyModel::setIsRunning(bool isRunning)
{
    m_isRunning = isRunning;
    emit m_isRunningChanged(m_isRunning);
}

int EntropyModel::itemCount() const
{
    return m_engine->itemsCount();
}

void EntropyModel::createItem(int _x, int _y)
{
    if (((_x - m_itemSize/2) > 0)
        && ((_x + m_itemSize/2) < m_windowWidth)
        && ((_y - m_itemSize/2) > 0)
        && ((_y + m_itemSize/2) < m_windowHeight))
    {
        beginInsertRows(QModelIndex(),0,0);
        this->insertRow(0);
        m_engine->createItem(_x - m_itemSize/2, _y - m_itemSize/2, m_itemSize);
        endInsertRows();
        emit itemCountChanged(itemCount());
    }
}

void EntropyModel::destroyItem(int _x, int _y)
{

    int index = m_engine->destroyItem(_x, _y);
    if (index >= 0)
    {
        beginRemoveRows(QModelIndex(), index, index);
        removeRow(index);
        endRemoveRows();
    }
    emit itemCountChanged(itemCount());
}

bool EntropyModel::isItem(int _x, int _y)
{
    return m_engine->checkIfCoorinatesMatchItem(_x, _y);
}

void EntropyModel::changeItemColor(int _x, int _y)
{
    m_engine->changeItemColor(_x, _y);
}

void EntropyModel::clearAll()
{
    beginRemoveRows(QModelIndex(), 0, itemCount() - 1);
    removeRows(0, itemCount() - 1);
    endRemoveRows();
    m_engine->destroyAll();
    emit itemCountChanged(itemCount());
}

int EntropyModel::itemSpeed() const
{
    return m_itemSpeed;
}

void EntropyModel::setItemSpeed(int itemSpeed)
{
    m_itemSpeed = itemSpeed;
    emit m_itemSpeedChanged(m_itemSpeed);
}




