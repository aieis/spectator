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
  double C = cos(theta);
  double S = sin(theta);
  double x = C*vec.x - S*vec.y;
  double y = S*vec.x + C*vec.y;
  return vec2_make(x, y);
}

vec2 vec2_subtract(vec2 v1, vec2 v2)
{
  return vec2_make(v1.x-v2.x, v1.y-v2.y);
}

vec2 vec2_add(vec2 v1, vec2 v2)
{
  return vec2_make(v1.x + v2.x, v1.y + v2.y);
}

vec2 vec2_extend_line(vec2 from, vec2 to, double length)
{
  vec2 bound = vec2_subtract(to, from);
  double m = bound.y / bound.x;
  double dx = sqrt(length * length / (m*m + 1));
  double dy = m*dx;
  vec2 bound_to = vec2_make(from.x + dx, from.y + dy);
  return bound_to;
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

  vec2 center = vec2_make((r.tl.x + r.br.x)/2, (r.tl.y + r.br.y)/2);
  vec2 tl = vec2_subtract(r.tl, center);
  vec2 tr = vec2_subtract(r.tr, center);
  vec2 br = vec2_subtract(r.br, center);
  vec2 bl = vec2_subtract(r.bl, center);
  
  rec rc;
  rc.tl = vec2_add(vec2_rotate(tl, theta), center);
  rc.tr = vec2_add(vec2_rotate(tr, theta), center);
  rc.br = vec2_add(vec2_rotate(br, theta), center);
  rc.bl = vec2_add(vec2_rotate(bl, theta), center);
  return rc;
}
