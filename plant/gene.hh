// Gene header file
// Copyright 2021, Parker Patterson. All rights reserved.

#ifndef GENE_H_
#define GENE_H_

#include <iostream>
#include <vector>
#include <string>
#include "./phytochemicals.h"

using namespace std;

#define NUM_NUTS 6 // number of different nutrients

class Gene : {
public:
  string GetName() {return name_;}
  string GetDescrip() const {return descrip_;}
  void SetName(string name) {name_ = name;}
  void SetDescrip(string descrip) {descrip_ = descrip;}
protected:
  string name_;
  string descrip_;
};

// Phytochemical genes

class ChemGene : public Gene {

};

class NectarGene : public ChemGene {
protected:
  unsigned short aroma_;
public:
  unsigned short GetAroma() const {return aroma_}
};

NectarGene::NectarGene(unsigned short aroma){
  aroma_ = aroma;
}

class PolysacGene : public ChemGene {
protected:
  unsigned int length_;
public:
  unsigned int GetLength() const {return length_;}
};



// organelle genes

class OrganelleGene : public Gene {
public:
  unsigned short* GetNutRqmts() const {return nut_rqmts_;}
  void SetNutRqmt(int i, unsigned short val);
protected:
  unsigned short nut_rqmts_[NUM_NUTS];
};

OrganelleGene::SetNutRqmt(int i, unsigned short val){
  if (i >= NUM_NUTS){
    cout << "error setting nutrient value" << endl;
    return;
  }
  nut_rqmts_[i] = val;
}

class VacuoleGene : public OrganelleGene {
  // determines characteristics of vacuole
public:
  unsigned GetSize() const {return size_;}
  bool IsSupport() const {return support_;}
  bool IsStorage() const {return storage_;}
  void SetSize(int size) {size_ = size;}
  void SetSupport (bool support) {support_ = support;}
  void SetStorage (bool storage) {storage_ = storage;}
protected:
  unsigned size_;
  bool support_;
  bool storage_;
  unsigned short nut_reqmts_[NUM_NUTS];
};

class EnergyGene : public OrganelleGene {
  double GetEfficiency() const {return efficiency_;}
  void SetEfficiency(double efficiency) {efficiency_ = efficiency;}
protected:
  float efficiency_;
};

class ChloroplastGene : public EnergyGene {
public:
  unsigned char* GetColor() const {return colors_;}
  void SetColor(unsigned short colors[3]);
protected:
  unsigned short colors_[3]; // rgb
};

ChloroplastGene::SetColor(unsigned short colors[3]){
  for (int i = 0; i < 3; i++){
    colors_[i] = colors[i];
  }
}

class MitochondrionGene : public EnergyGene {
};

class ERGene : public OrganelleGene {
  Phytochemical* GetChem() const {return &chem_;}
  void SetChem(Phytochemical chem) {chem_ = chem;}
protected:
  Phytochemical chem_;
};

class CellWallGene : public OrganelleGene {
public:
  bool IsLignified() const {return lignified_;}
  void SetLignified(bool lignified) {lignified_ = lignified;} 
protected:
  bool lignified_;
};

// cell genes

class CellGene : public Gene {

};

// tissue genes

class TissueGene : public Gene {

};

// organ genes

class OrganGene : public Gene {

};

#endif // GENE_H_
