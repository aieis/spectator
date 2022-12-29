#include <opencv2/core.hpp>
#include "geometry.h"
void draw_rec(cv::Mat& img, rec r, cv::Scalar col, int thickness);
void draw_line(cv::Mat& img, vec2 from, vec2 to, cv::Scalar col, int thickness);
void draw_vector(cv::Mat& img, vec2 from, vec2 to, cv::Scalar col, int thickness);
void draw_dashed_line(cv::Mat& img, vec2 from, vec2 to, cv::Scalar col, int thickness);
