
#include <iostream>

#include "molecule.h"
#include "atom.h"
#include "gamessus.h"
#include "gaussianset.h"
#include "basisset.h"
#include "basissetloader.h"
#include "cube.h"

#include <Eigen/Geometry>

#include <QtCore/QStringList>
#include <QtCore/QString>

using std::cout;
using std::cerr;
using std::endl;

using OpenQube::Atom;
using OpenQube::Molecule;
using OpenQube::GAMESSUSOutput;
using OpenQube::BasisSet;
using OpenQube::GaussianSet;

using Eigen::Vector3d;
using Eigen::Vector3i;


int main(int argc, char *argv[])
{

  cout << "Testing GAMESS reader" << endl;

  GaussianSet *gaussian = new GaussianSet;
  QString filename="/Users/albert/Development/openqube/testfiles/rhf.gamess";
  GAMESSUSOutput gamout(filename, gaussian);

  gamout.outputAll();

  //BasisSet *m_basis;
  //m_basis = OpenQube::BasisSetLoader::LoadBasisSet(filename);

  OpenQube::Cube *m_qube;
  Vector3d min = Vector3d(-10.0,-10.0,-10.0);
  Vector3d max = Vector3d( 10.0, 10.0, 10.0);
  Vector3i points = Vector3i(1000,1000,1000);
  Vector3i dim = Vector3i(1000,1000,1000);
  double spacing = 0.01;


  m_qube->setLimits(min,max,points);


  return 0;
}
