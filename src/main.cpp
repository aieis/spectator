#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <math.h>

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
  cam.f = f;
  cam.sensor_size = sensor_size;
  return cam;
}

void draw_camera_in_world(world* world, camera cam)
{
  // double S = sin(cam.theta);
  // double C = cos(cam.theta);
  
  // //draw camera box
  // int r = cam.sensor_size;
  // int ctx = r * S;
  // int cty = r * C;
}


int main()
{
  printf("Creating world...\n");
  world* w = world_make_default();
  printf("Drawing world...\n");
  cv::Mat img = world_draw(w);
  printf("Displaying world...\n");
  while (cv::waitKey(1) != 'q') {
    cv::imshow("World", img);
  }
  return 0;
}