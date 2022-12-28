#include <opencv2/imgproc.hpp>
#include "geometry.h"
#include <iostream>

void draw_rec(cv::Mat& img, rec r, cv::Scalar col, int thickness)
{
  cv::Point tl = cv::Point(r.tl.x, r.tl.y);
  cv::Point tr = cv::Point(r.tr.x, r.tr.y);
  cv::Point br = cv::Point(r.br.x, r.br.y);
  cv::Point bl = cv::Point(r.bl.x, r.bl.y);
  
  cv::line(img, tl, tr, col, thickness);
  cv::line(img, tr, br, col, thickness);
  cv::line(img, br, bl, col, thickness);
  cv::line(img, bl, tl, col, thickness);
}

void draw_line(cv::Mat&img, vec2 from, vec2 to, cv::Scalar col, int thickness)
{
  cv::Point p1 = cv::Point(from.x, from.y);
  cv::Point p2 = cv::Point(to.x, to.y);
  cv::line(img, p1, p2, col, thickness);
}

void draw_vector(cv::Mat&img, vec2 from, vec2 to, cv::Scalar col, int thickness)
{
  cv::Point p1 = cv::Point(from.x, from.y);
  cv::Point p2 = cv::Point(to.x, to.y);
  cv::arrowedLine(img, p1, p2, col, thickness);
}
