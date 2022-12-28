#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>

#include "draw.h"

typedef struct world world;
typedef int* object;
struct world
{
  object* objects;
  int nobjs;
  int x;
  int y;
  int width;
  int height;
};



int* object_make(int x, int y, int r, int col)
{
  int* obj = (int *) malloc(sizeof(int) * 4);
  obj[0] = x;
  obj[1] = y;
  obj[2] = r;
  obj[3] = col;
  return obj;
}

world* world_make_default()
{
  world* w = (world*) malloc(sizeof(world));
  w->nobjs = 2;
  w->objects = (int**) malloc(2 *  sizeof(object));
  w->objects[0] = object_make(100, 100, 20, 0);
  w->objects[1] = object_make(500, 500, 50, 127);
  w->x = 0;
  w->y = 0;
  w->width = 600;
  w->height = 600;
  return w;
}

cv::Mat world_draw(world * w)
{
  cv::Mat img(w->width, w->height, CV_8UC1, cv::Scalar(255));
  for (int i = 0; i < w->nobjs; i++) {
    object obj = w->objects[i];
    cv::Point center(obj[0], obj[1]);
    printf("Drawing object at (%d, %d)<%d,%d>\n", obj[0], obj[1], obj[2], obj[3]);
    cv::circle(img, center, obj[2], obj[3], 5);
  }
  return img;
}

typedef struct camera camera;
struct camera
{
  double theta;
  int x;
  int y;
  int f;
  int sensor_size;
};

camera camera_make(double theta, int x, int y, int f, int sensor_size)
{
  camera cam;
  cam.theta = theta;
  cam.x = x;
  cam.y = y;
  cam.f = f;
  cam.sensor_size = sensor_size;
  return cam;
}

void draw_camera_in_world(cv::Mat& img, world* world, camera cam)
{
  rec r = rec_make_orth(cam.x, cam.y, cam.sensor_size, 20);
  r = rec_rotate(r, cam.theta);
  draw_rec(img, r, cv::Scalar(0), 2);

  double S = sin(cam.theta);
  double C = cos(cam.theta);
  vec2 fv;
  if (C == 0) {
    fv = vec2_make(-cam.f, 0);
  } else {
    double T = S / C;
    double dx = sqrt(cam.f*cam.f / (T*T + 1));
    double dy = T * dx;
    
    /* TODO: Make y go from the reverse */
    fv = vec2_make(dx, -dy);
    printf("dx: %f, dy: %f\n", dx, dy);
  }
  
  
  vec2 lp = vec2_subtract(r.bl, fv);
  vec2 rp = vec2_subtract(r.br, fv);
  draw_line(img, lp, rp, cv::Scalar(0), 2);
}


int main()
{
  printf("Creating world...\n");
  world* w = world_make_default();
  
  printf("Drawing world...\n");
  cv::Mat img = world_draw(w);

  camera cam = camera_make(M_PI/4, 20, 550, 10, 40);
  draw_camera_in_world(img, w, cam);
  
  printf("Displaying world...\n");
  while (cv::waitKey(1) != 'q') {
    cv::imshow("World", img);
  }
  return 0;
}
