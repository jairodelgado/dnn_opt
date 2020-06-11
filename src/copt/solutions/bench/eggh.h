/*
Copyright (c) 2018, Jairo Rojas-Delgado <jrdelgado@uci.cu>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
* Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
* Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
* Neither the name of the <organization> nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef DNN_OPT_COPT_SOLUTIONS_BENCH_EGG_H
#define DNN_OPT_COPT_SOLUTIONS_BENCH_EGG_H

#include <core/solutions/bench/eggh.h>
#include <copt/base/generator.h>
#include <copt/base/solution.h>

namespace dnn_opt
{
namespace copt
{
namespace solutions
{
namespace bench
{

/**
 * @copydoc core::solutions::bench::eggh
 *
 * @author Alejandro Ruiz Madruga <amadruga@estudiantes.uci.cu>
 * @date March, 2020
 * @version 1.0
 */
class eggh : public virtual solution,
             public virtual core::solutions::bench::eggh
{
public:

    /**
     * @brief Returns an instance of the eggh class.
     *
     * @param generator an instance of a generator class. The
     * generator is used to initialize the parameters of this solution.
     *
     * @param size is the number of parameters for this solution. Default is 1024.
     *
     * @return an instance of eggh class.
     */
  static eggh* make(generator* generator, unsigned int size = 1024);

  virtual ~eggh();

protected:

  virtual float calculate_fitness();

  /**
   * @brief This is the basic contructor for this class.
   * @param generator an instance of a generator class.
   *
   * @param size is the number of parameters for this solution. Default is 1024.
   */
  eggh(generator* generator, unsigned int size = 1024);

};

} // namespace bench
} // namespace solutions
} // namespace copt
} // namespace dnn_opt

#endif