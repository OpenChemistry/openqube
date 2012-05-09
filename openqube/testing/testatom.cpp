
#include <iostream>

#include "molecule.h"
#include "atom.h"

#include <Eigen/Geometry>

using std::cout;
using std::cerr;
using std::endl;

using OpenQube::Atom;
using OpenQube::Molecule;

using Eigen::Vector3d;

namespace {

template<typename A, typename B>
void checkResult(const A& result, const B& expected, bool &error)
{
  if (result != expected) {
    cerr << "Error, expected result " << expected << ", got " << result << endl;
    error = true;
  }
}

}

short testAtomConst(const Molecule& mol, size_t index)
{
  return mol.atom(index).atomicNumber();
}

int testatom(int , char *[])
{
  bool error = false;
  cout << "Testing the atom class..." << endl;

  Molecule mol;
  Atom a = mol.addAtom(Vector3d(0.0, 1.0, 0.0), 1);

  checkResult(a.isValid(), true, error);
  checkResult(a.isHydrogen(), true, error);
  checkResult(a.atomicNumber(), 1, error);
  a.setAtomicNumber(69);
  checkResult(a.isHydrogen(), false, error);
  checkResult(a.atomicNumber(), 69, error);
  checkResult(a.pos(), Vector3d(0.0, 1.0, 0.0), error);
  a.setPos(Vector3d(1.0, 1.0, 1.0));
  checkResult(a.pos(), Vector3d(1.0, 1.0, 1.0), error);

  Atom a2 = mol.atom(1);
  checkResult(a2.isValid(), false, error);
  checkResult(a2.isHydrogen(), false, error);
  a2.setAtomicNumber(1);
  checkResult(a2.isHydrogen(), false, error);
  a2.setPos(Vector3d(1.0, 1.0, 1.0));
  checkResult(a2.pos(), Vector3d::Zero(), error);

  cout << "Number of atoms = " << mol.numAtoms() << endl;

  Atom carbon = mol.addAtom(Vector3d::Zero(), 6);

  cout << "Number of atoms = " << mol.numAtoms() << endl;

  const Atom carbonCopy = mol.atom(1);
  checkResult(carbon.atomicNumber(), carbonCopy.atomicNumber(), error);
  checkResult(carbon.atomicNumber(), testAtomConst(mol, 1), error);
  carbon.setAtomicNumber(7);
  checkResult(carbon.atomicNumber(), carbonCopy.atomicNumber(), error);

  mol.print();

  return error ? 1 : 0;
}
