#ifndef GPOS_H
#define GPOS_H

#include "guide.h"
#include <QObject>
#include <memory>

class GPos : public Guide
{
public:
    GPos(std::shared_ptr<QImage> prevFrame, std::shared_ptr<QImage> currFrame, std::shared_ptr<QImage> g_mask);
    virtual ~GPos();

protected:
    std::shared_ptr<QImage> getGuide();
    std::shared_ptr<QImage> getMotion(); //for G_temp

private:
    std::shared_ptr<QImage> m_guide;
    std::shared_ptr<QImage> m_motion;

    void createPos();
};

#endif // GPOS_H
