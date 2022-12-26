typedef struct vec2 vec2;
typedef struct vec3 vec3;
typedef struct rec rec;

struct vec2
{
  double x;
  double y;
};

struct vec3
{
  double x;
  double y;
  double z;
};

struct rec
{
  vec2 tl;
  vec2 tr;
  vec2 br;
  vec2 bl;
};

vec2 vec2_make(double x, double y);
vec2 vec2_rotate(vec2 vec, double theta);
rec rec_make_orth(double x, double y, double w, double h);
rec rec_make(vec2 tl, vec2 tr, vec2 br, vec2 bl);
rec rec_rotate(rec r, double theta);
