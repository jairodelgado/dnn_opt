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

#ifndef DNN_OPT_COPT_READERS_CSV_READER
#define DNN_OPT_COPT_READERS_CSV_READER

#include <copt/base/reader.h>
#include <core/readers/csv_reader.h>

namespace dnn_opt
{
namespace copt
{
namespace readers
{

/**
 * @brief
 * This class is intended to fetch training patterns from a file.
 * The file must have the following structure:
 *
 *      - In the first line three integers separated by a space: number 
 *      of training patterns p, in dimension n and out dimension m.
 *      - In the following p lines, each line represents a pattern 
 *      containing n floats separated by a space as in, followed by m 
 *      floats as expected out.
 *
 * @author Jairo Rojas-Delgado <jrdelgado@uci.cu>
 * @version 1.0
 * @date June, 2016
 */
class csv_reader : public virtual reader,
                   public virtual core::readers::csv_reader
{
public:

  /**
   * @copydoc core::readers::csv_reader::make
   */
  static csv_reader* make(std::string file_name, int in_dim, int out_dim, char sep = ',', bool header = false);

  /**
   * @copydoc core::readers::csv_reader
   */
  ~csv_reader();

protected:

  /**
   * @brief Load from file.
   */
  void load();

  /**
   * @copydoc core::readers::csv_reader
   */
  csv_reader(std::string file_name, int in_dim, int out_dim, char sep = ',', bool header = false);

};

} // namespace readers
} // namespace copt
} // namespace dnn_opt

#endif
