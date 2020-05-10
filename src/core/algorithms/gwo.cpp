#include <stdexcept>
#include <core/algorithms/gwo.h>

namespace dnn_opt
{
namespace core
{
namespace algorithms
{

void gwo::optimize()
{
  int size = get_solutions()->size();

  for (int i = 0; i < size; i++)
  {
   update_positions(i);
  }
  update_params();
  update_elite();
}

solution* gwo::get_best()
{
return _alpha;
}

void gwo::set_params(std::vector<float> &params)
{

}

void gwo::reset()
{
get_solutions()->generate();
for (int j = 0; j < _dim; j++)
{
 _a[j] = 2.0;
}
}

void gwo::update_params()
{
  for (int j = 0; j < _dim; j++)
  {
   _a[j] -= 0.01;
   _A[j] = 2 * _a[j] * _r1[j] - _a[j];
   _C[j] = 2 * _r2[j];
  }
}
void gwo::update_positions(int idx)
{
  auto* current = get_solutions()->get(idx)->get_params();

  for (int j = 0; j < _dim; j++)
  {

    _Da[j] = abs(_C[j] * _alpha->get_params()[j] - current[j]);
    _X1[j] = _alpha->get_params()[j] - _A[j] * _Da[j];
    _Db[j] = abs(_C[j] * _beta->get_params()[j] - current[j]);
    _X2[j] = _beta->get_params()[j] - _A[j] * _Db[j];
    _Dd[j] = abs(_C[j] * _delta->get_params()[j] - current[j]);
    _X3[j] = _delta->get_params()[j] - _A[j] * _Da[j];

    current[j] = (_X1[j] + _X2[j] + _X3[j]) / 3;
  }
}
void gwo::update_elite()
{
  float size = get_solutions()->size();

  for(int i = 0; i < size; i++)
  {

    solution* current = get_solutions()->get(i);

    if (current->is_better_than(_alpha, is_maximization()))
    {
      _alpha->assign(current);
    }
    else if (current->is_better_than(_beta, is_maximization()))
    {
      _beta->assign(current);
    }
    else if (current->is_better_than(_delta, is_maximization()))
    {
      _delta->assign(current);
    }
  }
}

void gwo::init()
{

  _alpha = get_solutions()->get(0);
  _beta = get_solutions()->get(1);
  _delta = get_solutions()->get(2);
  _dim = get_solutions()->get_dim();
  _a = new float[_dim];
  _r1 = new float[_dim];
  _r2 = new float[_dim];
  _A = new float[_dim];
  _C = new float[_dim];
  _Da = new float[_dim];
  _Db = new float[_dim];
  _Dd = new float[_dim];
  _X1 = new float[_dim];
  _X2 = new float[_dim];
  _X3 = new float[_dim];
  _generator->generate(_dim, _r1);
  _generator->generate(_dim, _r2);

  for (int j = 0; j < _dim; j++)
  {
   _a[j] = 2.0;
   _A[j] = 2 * _a[j] * _r1[j] - _a[j];
   _C[j] = 2 * _r2[j];
  }

}

gwo::~gwo()
{
 delete _generator;
 delete[] _r1;
 delete[] _r2;
 delete[] _A;
 delete[] _C;
 delete[] _Da;
 delete[] _Db;
 delete[] _Dd;
 delete[] _X1;
 delete[] _X2;
 delete[] _X3;
 delete[] _a;
}

} // namespace algorithms
} // namespace core
} // namespace dnn_opt
