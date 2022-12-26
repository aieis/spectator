#include <opencv/imgproc.hpp>
#include "geometry.h"

void draw_rec(cv::Mat& img, rec r, cv::Scalar col, int thickness)
{
  cv::Point tl = cv::Point(r.tl.x, r.tl.y);
  cv::Point tr = cv::Point(r.tr.x, r.tr.y);
  cv::Point br = cv::Point(r.br.x, r.br.y);
  cv::Point bl = cv::Point(r.bl.x, r.bl.y);
    
  cv::line(img, tl, tr, col, thickness);
  cv::line(img, tr, br, col, thickness);
}