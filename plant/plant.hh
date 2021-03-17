// Plant header file
// Copyright 2021, Parker Patterson. All rights reserved.

#ifndef PLANT_H_
#define PLANT_H_

#include <iostream>
#include "./organs.h"
#include "./gene.h"

using namespace std;

class Plant {
protected:
  int water_, sugar_, co2_, n_, p_, k_;
  vector<Organ> organs_;
  vector<int> organ_qtys_;
  vector<OrganelleGene*> organelle_genes_;
  vector<CellGene*> cell_genes_;
  vector<TissueGene*> tissue_genes;
  vector<OrganGene*> organ_genes_;
};

#endif // PLANT_H_
