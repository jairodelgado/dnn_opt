#include <math.h>
#include <algorithm>
#include <core/solutions/bench/rosenbrock.h>

namespace dnn_opt
{
namespace core
{
namespace solutions
{
namespace bench
{

rosenbrock* rosenbrock::make(generator* generator, unsigned int size)
{
  auto* result = new rosenbrock(generator, size);

  result->init();

  return result;
}

float rosenbrock::calculate_fitness()
{
  int n = size();
  float* params = get_params();

  solution::calculate_fitness();

  float result = 0;

  for(int i = 0; i < n; i++)
  {
    result += params[i] * sin(sqrt(fabs(params[i])));
  }

  return -1 * result / n;
}

solution* rosenbrock::clone()
{
  rosenbrock* clon = make(get_generator(), size());

  std::copy_n(get_params(), size(), clon->get_params());

  return clon;
}

rosenbrock::rosenbrock(generator* generator, unsigned int size )
: solution(generator, size)
{

}

rosenbrock::~rosenbrock()
{

}

} // namespace brench
} // namespace solutions
} // namespace core
} // namespace dnn_opt
