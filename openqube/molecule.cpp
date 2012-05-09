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

#include <QtCore/QDebug>

using Eigen::Vector3d;

namespace OpenQube {

Molecule::Molecule()
{
  qDebug() << "Making an OQ molecule...";
}

Molecule::~Molecule()
{
}

Atom Molecule::addAtom(const Eigen::Vector3d &pos, short atomicNumber)
{
  // Increment the vectors containing atomic properties.
  Avogadro::Core::Atom a =
    Avogadro::Core::Molecule::addAtom(static_cast<unsigned char>(atomicNumber));
  a.setPosition3d(pos);
  qDebug() << "Atom count after add " << atomCount() << " of " << atomicNumber;
  return Atom(this, size() - 1);
}

const Atom Molecule::atom(size_t index) const
{
  // The const_cast is needed to create the temporary. As we are returning
  // a const Atom object and Atom is const safe this should be fine.
  if (index < size())
    return Atom(const_cast<Molecule *>(this), index);
  else
    return Atom(0, 0);
}

Atom Molecule::atom(size_t index)
{
  if (index < size())
    return Atom(this, index);
  else
    return Atom(0, 0);
}

short Molecule::atomAtomicNumber(size_t index) const
{
  if (index < size())
    return atomicNumbers()[index];
  else
    return 0;
}

void Molecule::setAtomAtomicNumber(size_t index, short atomicNumber)
{
  if (index < size())
    atomicNumbers()[index] = atomicNumber;
}

Vector3d Molecule::atomPos(size_t atomIndex) const
{
  if (atomIndex < atomPositions3d().size())
    return atomPositions3d()[atomIndex];
  else
    return Vector3d::Zero();
}

void Molecule::setAtomPos(size_t atomIndex, const Eigen::Vector3d& pos)
{
  if (atomIndex < atomPositions3d().size())
    atomPositions3d()[atomIndex] = pos;
}

void Molecule::clearAtoms()
{
  qDebug() << "We need to implement clearAtoms...";
}

void Molecule::print() const
{
  qDebug() << "Number of atoms:" << atomCount();
}

} // End namespace
