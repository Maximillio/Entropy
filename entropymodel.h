#ifndef ENTROPYMODEL_H
#define ENTROPYMODEL_H

#include <entropyengine.h>
#include <memory>
#include <chrono>
#include <ctime>
#include <ratio>
#include <QAbstractListModel>
#include <QDebug>
#include <QColor>
#include <QTimer>

using namespace std::chrono;

class EntropyModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(float windowHeight
               MEMBER m_windowHeight
               READ windowHeight
               NOTIFY m_windowHeightChanged)
    Q_PROPERTY(float windowWidth
               MEMBER m_windowWidth
               READ windowWidth
               NOTIFY m_windowWidthChanged)
    Q_PROPERTY(int itemSpeed
               MEMBER m_itemSpeed
               READ itemSpeed
               WRITE setItemSpeed
               NOTIFY m_itemSpeedChanged)
    Q_PROPERTY(int itemSize
               MEMBER m_itemSize
               READ itemSize)
    Q_PROPERTY(bool isRunning
               MEMBER m_isRunning
               READ isRunning
               WRITE setIsRunning
               NOTIFY m_isRunningChanged)
    Q_PROPERTY(int itemCount
               READ itemCount
               NOTIFY itemCountChanged)
public:
    EntropyModel();
    ~EntropyModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    //Getters
    float windowWidth() const;
    float windowHeight() const;
    int   itemSpeed() const;
    bool  isRunning() const;
    int   itemCount() const;
    int   itemSize() const;
    //Setters
    void setItemSpeed(int itemSpeed);
    void setIsRunning(bool isRunning);



signals:
   void m_windowHeightChanged(const float& _windowHeight);
   void m_windowWidthChanged(const float& _windowWight);
   void m_itemSpeedChanged(const int& _itemSpeed);
   void m_isRunningChanged(const bool& _isRunning);
   void itemCountChanged(const int& _itemCount);
public slots:
   bool isItem(int _x, int _y);
   void createItem(int _x, int _y);
   void destroyItem(int _x, int _y);
   void changeItemColor(int _x, int _y);
   void clearAll();
private slots:
   void updateData();
private:
    int                               m_frameDelay;
    std::unique_ptr<EntropyEngine>    m_engine;
    std::unique_ptr<QTimer>           m_frameClock;
    duration<double>                  m_timeElapsed;
    high_resolution_clock::time_point m_timeBefore;
    high_resolution_clock::time_point m_timeAfter;
    float m_windowHeight;
    float m_windowWidth;
    int   m_itemSpeed;
    int   m_itemSize;
    bool  m_isRunning;
};

#endif // ENTROPYMODEL_H
