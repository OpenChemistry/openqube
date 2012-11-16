/******************************************************************************

  This source file is part of the OpenQube project.

  Copyright 2008-2010 Marcus D. Hanwell

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#ifndef GAUSSIANFCHK_H
#define GAUSSIANFCHK_H

#include <QtCore/QIODevice>
#include <Eigen/Core>
#include <vector>

class QString;

namespace OpenQube
{
class GaussianSet;

class GaussianFchk
{
  enum scf  { rhf, uhf, rohf, Unknown };

public:
  GaussianFchk(const QString &filename, GaussianSet *basis);
  ~GaussianFchk();
  void outputAll();
private:
  QIODevice *m_in;
  void processLine();
  void load(GaussianSet* basis);
  std::vector<int> readArrayI(unsigned int n);
  std::vector<double> readArrayD(unsigned int n, int width = 0);
  bool readDensityMatrix(unsigned int n, int width = 0);
  bool readSpinDensityMatrix(unsigned int n, int width = 0);

  int m_electrons;
  int m_electronsA;
  int m_electronsB;
  unsigned int m_numBasisFunctions;
  std::vector<int> m_aNums;
  std::vector<double> m_aPos;
  std::vector<int> m_shellTypes;
  std::vector<int> m_shellNums;
  std::vector<int> m_shelltoAtom;
  std::vector<double> m_a;
  std::vector<double> m_c;
  std::vector<double> m_csp;
  std::vector<double> m_orbitalEnergy;
  std::vector<double> m_alphaOrbitalEnergy;
  std::vector<double> m_betaOrbitalEnergy;
  std::vector<double> m_MOcoeffs;
  std::vector<double> m_alphaMOcoeffs;
  std::vector<double> m_betaMOcoeffs;
  Eigen::MatrixXd m_density;     /// Total density matrix
  Eigen::MatrixXd m_spinDensity; /// Spin density matrix
  scf m_scftype;
};

} // End namespace openqube

#endif
