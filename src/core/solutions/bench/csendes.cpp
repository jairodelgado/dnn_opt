#include <math.h>
#include <algorithm>
#include <core/solutions/bench/csendes.h>

namespace dnn_opt
{
namespace core
{
namespace solutions
{
namespace bench
{

csendes* csendes::make(generator *generator, unsigned int size)
{
  auto* result = new csendes(generator, size);

  result->init();

  return result;
}

float csendes::calculate_fitness()
{
  float result = 0;
  float* params = get_params();
  int n = size();

  solution::calculate_fitness();
  
  for(int i = 0; i < n; i++)
  {
    result += pow(params[i], 6.0f) * (2.0f + sin(1.0f / params[i]));
  }
  
  return result;
}

solution* csendes::clone()
{
  csendes* clon = make(get_generator(), size());

  std::copy_n(get_params(), size(), clon->get_params());

  return clon;
}

csendes::csendes(generator* generator, unsigned int size)
: solution(generator, size)
{

}

csendes::~csendes()
{

}

} // namespace bench
} // namespace solutions
} // namespace core
} // namespace dnn_opt
