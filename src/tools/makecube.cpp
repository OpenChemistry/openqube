
#include <iostream>
#include <stdio.h>

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
#include <QtCore/QDebug>

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

static const double BOHR_TO_ANGSTROM = 0.529177249;
static const double ANGSTROM_TO_BOHR = 1.0 / BOHR_TO_ANGSTROM;

int main(int argc, char *argv[])
{

  //The QM output file
  QString filename = argv[1];

  BasisSet *m_basis;
  m_basis = OpenQube::BasisSetLoader::LoadBasisSet(filename);

  OpenQube::Cube *m_qube;
  m_qube = new OpenQube::Cube;
  //h2
  //Vector3d min = Vector3d(-5.0,-5.0,-5.0);
  //Vector3d max = Vector3d( 5.166667, 5.166667, 5.166667);
  //water
  Vector3d min = Vector3d(-3.0,-3.0,-3.0);
  Vector3d max = Vector3d( 3.0, 3.0, 3.0);
  Vector3i points = Vector3i(61,61,61);
  
  //Vector3d min = Vector3d(-2.5,-2.5,-2.5);
  //Vector3d max = Vector3d( 3.0, 3.0, 3.0);
  //Vector3i points = Vector3i(11,11,11);

  //Angstrom!!!!
  m_qube->setLimits(min*BOHR_TO_ANGSTROM,max*BOHR_TO_ANGSTROM,points);
  m_basis->blockingCalculateCubeMO(m_qube,5);
  
  //cube header
  printf("OpenQube\ncubefile\n");
  int nat=m_basis->moleculeRef().numAtoms();

  //this is necessary because I cannot predict what
  //the spacing algorithm does
  min=m_qube->position(0)*ANGSTROM_TO_BOHR;
  Vector3d spacing = m_qube->spacing()*ANGSTROM_TO_BOHR;

  printf("%4d %11.6f %11.6f %11.6f\n",nat,min.x(),min.y(),min.z());
  printf("%4d %11.6f %11.6f %11.6f\n",points.x(),spacing.x(),0.0,0.0);
  printf("%4d %11.6f %11.6f %11.6f\n",points.y(),0.0,spacing.y(),.0);
  printf("%4d %11.6f %11.6f %11.6f\n",points.z(),0.0,0.0,spacing.z());
  

  //atoms
  for (int iatom=0;iatom<m_basis->moleculeRef().numAtoms();iatom++)
  {
    printf("%4d %11.6f %11.6f %11.6f %11.6f\n",
        m_basis->moleculeRef().atomAtomicNumber(iatom),
        0.0,
        m_basis->moleculeRef().atomPos(iatom).x(),
        m_basis->moleculeRef().atomPos(iatom).y(),
        m_basis->moleculeRef().atomPos(iatom).z());
  }

  //print the qube values
  int linecount=0;
  for(int i=0;i<m_qube->data()->size();i++)
  {
    if(i%points.z()==0 && i>0)
    {
      linecount=0;
      printf("\n");
    }
    printf("%12.5e",m_qube->data()->at(i));
    //line wrapping
    linecount++;
    if(linecount%6==0 && i>0)
      printf("\n");
    else
      printf(" ");
  }
  printf("\n");
  

  return 0;
}
