#include "geometry.h"
#include <math.h>

vec2 vec2_make(double x, double y)
{
  vec2 vec;
  vec.x = x;
  vec.y = y;
  return vec;
}

vec2 vec2_rotate(vec2 vec, double theta)
{
  int r = sqrt(vec.x*vec.x + vec.y*vec.y);
  double x = r*sin(theta);
  double y = r*cos(theta);
  return vec2_make(x, y);
}

rec rec_make_orth(double x, double y, double w, double h)
{
  rec r;
  r.tl = vec2_make(x, y);
  r.tr = vec2_make(x + w, y);
  r.br = vec2_make(x + w, y + h);
  r.bl = vec2_make(x, y + h);
  return r;
}

rec rec_make(vec2 tl, vec2 tr, vec2 br, vec2 bl)
{
  rec r;
  r.tl = tl;
  r.tr = tr;
  r.br = br;
  r.bl = bl;
  return r;
}

rec rec_rotate(rec r, double theta)
{
  rec rc;
  rc.tl = vec2_rotate(r.tl, theta);
  rc.tr = vec2_rotate(r.tr, theta);
  rc.br = vec2_rotate(r.br, theta);
  rc.bl = vec2_rotate(r.bl, theta);
  return rc;
}
