#ifndef ENTROPYMODEL_H
#define ENTROPYMODEL_H

#include <entropyengine.h>
#include <QAbstractListModel>
#include <memory>
#include <QDebug>
#include <QColor>
#include <QTimer>

class EntropyModel : public QAbstractListModel
{
    Q_PROPERTY(float windowHeight
               MEMBER m_windowHeight
               READ windowHeight
               NOTIFY m_windowHeightChanged
               CONSTANT)
    Q_PROPERTY(float windowWidth
               MEMBER m_windowWight
               READ windowWidth
               NOTIFY m_windowWidthChanged
               CONSTANT)
public:
    EntropyModel();
    ~EntropyModel();
    //bool canFetchMore(const QModelIndex &parent) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    //int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;
    float windowWight() const;
    float windowHeight() const;
signals:
   void m_windowHeightChanged(const float& _windowHeight);
   void m_windowWidthChanged(const float& _windowWight);
public slots:
   void updateData();
private:
    std::unique_ptr<EntropyEngine> m_engine;
    std::unique_ptr<QTimer>        m_frameClock;
    const float m_windowHeight = WINDOW_HEIGHT;
    const float m_windowWight  = WINDOW_WIDTH;
};

#endif // ENTROPYMODEL_H
