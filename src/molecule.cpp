/******************************************************************************

  This source file is part of the OpenQube project.

  Copyright 2011 Kitware, Inc.

  This source code is released under the New BSD License, (the "License").

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

******************************************************************************/

#include "molecule.h"
#include "atom.h"

using Eigen::Vector3d;

namespace OpenQube {

Molecule::Molecule() : m_atomPositions(1), m_conformer(0)
{
}

Molecule::~Molecule()
{
}

Atom Molecule::addAtom(const Eigen::Vector3d &pos, short atomicNumber)
{
  // Increment the vectors containing atomic properties.
  m_atoms.push_back(Atom(this, m_atoms.size()));
  m_atomicNumbers.push_back(atomicNumber);
  for (size_t i = 0; i < m_atomPositions.size(); ++i)
    m_atomPositions[i].push_back(pos);
  return m_atoms.back();
}

const Atom Molecule::atom(size_t index) const
{
  if (index < m_atoms.size())
    return m_atoms[index];
  else
    return Atom(0, 0);
}

Atom Molecule::atom(size_t index)
{
  if (index < m_atoms.size())
    return m_atoms[index];
  else
    return Atom(0, 0);
}

short Molecule::atomAtomicNumber(size_t index) const
{
  if (index < m_atoms.size())
    return m_atomicNumbers[index];
  else
    return 0;
}

void Molecule::setAtomAtomicNumber(size_t index, short atomicNumber)
{
  if (index < m_atoms.size())
    m_atomicNumbers[index] = atomicNumber;
}

Vector3d Molecule::atomPos(size_t atomIndex) const
{
  if (atomIndex < m_atomPositions[m_conformer].size())
    return m_atomPositions[m_conformer][atomIndex];
  else
    return Vector3d::Zero();
}

void Molecule::setAtomPos(size_t atomIndex, const Eigen::Vector3d& pos)
{
  if (atomIndex < m_atomPositions[m_conformer].size())
    m_atomPositions[m_conformer][atomIndex] = pos;
}

} // End namespace
