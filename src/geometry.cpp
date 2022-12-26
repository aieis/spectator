#include "geometry.h"

vec2 vec2_make(double x, double y)
{
  return (vec2) {.x = x, .y=y};
}

vec2 vec2_rotate(vec2 vec, double theta)
{
  int r = sqrt(vec.x*vec.x + vec.y*vec.y);
  double x = r*sin(theta);
  double y = r*cos(theta);
  return (vec){.x = x, .y = y};
}

rec rec_make_orth(double x, double y, double w, double h)
{
  return (rec)
    {.tl = vec2_make(x, y),
     .tr = vec2_make(x + w, y),
     .br = vec2_make(x + w, y + h),
     .bl = vec2_make(x, y + h)
    };
}

rec rec_make(vec2 tl, vec2 tr, vec2 br, vec2 bl)
{
  return (rec) {.tl = tl, .tr = tr, .br = br, .bl = bl};
}

rec rec_rotate(rec r, double theta)
{
  return (rec)
    {.tl = vec2_rotate(r.tl, theta),
     .tr = vec2_rotate(r.tr, theta),
     .br = vec2_rotate(r.br, theta),
     .bl = vec2_rotate(r.bl, theta)
    };
}
