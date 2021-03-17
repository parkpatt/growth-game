// Cells header file
// Copyright 2021, Parker Patterson. All rights reserved.

#ifndef CELLS_H_
#define CELLS_H_

#include <iostream>
#include <string>
#include "./plantpart.h"
#include "./organelles.h"

using namespace std;

class Cell : public PlantPart {
public:
  vector<Organelle> GetOrganelles() const {return organelles_;}
  CellGene* GetGenes() const {return genes_;}
  unsigned short* GetNutRqmts() const {return nut_rqmts_;}
protected:
  vector<Organelle> organelles_;
  CellGene* genes_;
  unsigned short nut_rqmts_[NUM_NUTS]; // NUM_NUTS defined in gene.hh
  unsigned short nuts_avail_[NUM_NUTS];
  double efficiency_;
};

class Meristem : public Cell {
  // stem cell
  // differentiates into either Parenchyma or Structural
};

class Parenchyma : public Meristem {
  // main cell type
  // can be Secretor, Producer, or Exchanger
};

class Secretor : public Parenchyma {

};

class Producer : public Parenchyma {
  // cells that produce something
  // can be SugarProducer or ChemProducer
};

class SugarProducer : public Producer {

};

class ChemProducer : public Producer {

};

class Extractor : public Parenchyma {
  // cells that extract something from their environment
  // can be GasExtractor, MineralExtractor or WaterExtractor
};

class GasExtractor: public Extractor {
  
};

class MineralExtractor : public Extractor {

};

class WaterExtractor : public Extractor {

};

class Transporter : public Parenchyma {

};

class Structural : public Cell {
  // structural cell type
  // may be Collenchyma or Sclerenchyma
protected:
  unsigned short strength_;
public:
  unsigned short GetStrength() const {return strength_;}
};

class Collenchyma : public Structural {

};

class Sclerenchyma : public Structural {

};

#endif // CELLS_H_
