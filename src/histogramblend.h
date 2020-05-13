#ifndef HISTOGRAMBLEND_H
#define HISTOGRAMBLEND_H

#include <Eigen/Dense>
#include <QImage>
#include <opencv2/core/mat.hpp>
#include "iohandler.h"

class HistogramBlender
{
public:
    HistogramBlender();

    void blend(Sequence& a, Sequence& b,
               const std::vector<cv::Mat> &errMask,
               std::vector<cv::Mat> &outBlend);

private:
    void computeMeanAndStd(const cv::Mat &img, float *mean, float *std);
    void assembleMinErrorImg(const cv::Mat &Oai, const cv::Mat &Obi,
                             const cv::Mat &errMask, cv::Mat &minErrorImg);
    void histogramTransform(const cv::Mat &inputImg, float *inputMean, float *inputStd,
                            float *refMean, float *refStd, cv::Mat &outputImg);
};

#endif // HISTOGRAMBLEND_H
