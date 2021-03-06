#include <math.h>
#include <algorithm>
#include <core/solutions/bench/schwefel.h>

namespace dnn_opt
{
namespace core
{
namespace solutions
{
namespace bench
{

schwefel* schwefel::make(generator* generator, unsigned int size)
{
  auto* result = new schwefel(generator, size);

  result->init();

  return result;
}

float schwefel::calculate_fitness()
{
  int n = size();
  float* params = get_params();
  float result = 0;

  solution::calculate_fitness();

  for(int i = 0; i < n; i++)
  {
    result += params[i] * sin(sqrt(fabs(params[i])));
  }

  result = -1.0f * result / n;

  return result;
}

solution* schwefel::clone()
{
  schwefel* clon = make(get_generator(), size());

  std::copy_n(get_params(), size(), clon->get_params());

  return clon;
}

schwefel::schwefel(generator* generator, unsigned int size )
: solution(generator, size)
{

}

schwefel::~schwefel()
{

}

} // namespace bench
} // namespace solutions
} // namespace core
} // namespace dnn_opt
