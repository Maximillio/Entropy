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
public:
    EntropyModel();
    ~EntropyModel();
    //bool canFetchMore(const QModelIndex &parent) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    //int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    float windowWidth() const;
    float windowHeight() const;
signals:
   void m_windowHeightChanged(const float& _windowHeight);
   void m_windowWidthChanged(const float& _windowWight);
public slots:
   void updateData();
private:
    std::unique_ptr<EntropyEngine>    m_engine;
    std::unique_ptr<QTimer>           m_frameClock;
    duration<double>                  m_timeElapsed;
//    time_t                            m_timer;
    high_resolution_clock::time_point m_timeBefore;
    high_resolution_clock::time_point m_timeAfter;
    float m_windowHeight = WINDOW_HEIGHT;
    float m_windowWidth  = WINDOW_WIDTH;
};

#endif // ENTROPYMODEL_H
