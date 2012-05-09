
#include <iostream>

#include "molecule.h"
#include "atom.h"

using std::cout;
using std::cerr;
using std::endl;

using OpenQube::Atom;
using OpenQube::Molecule;

using Eigen::Vector3d;

template<typename A, typename B>
bool checkResult(const A& result, const B& expected)
{
  if (result != expected) {
    cerr << "Error, expected result " << expected << ", got " << result << endl;
    return false;
  }
  return true;
}

int testmolecule(int , char *[])
{
  bool error = false;
  cout << "Testing the molecule class..." << endl;

  Molecule mol;
  mol.addAtom(Vector3d(0.0, 1.0, 0.0), 1);

  if (!checkResult(mol.numAtoms(), 1))
    error = true;

  cout << "Number of atoms = " << mol.numAtoms() << endl;

  return error ? 1 : 0;
}
