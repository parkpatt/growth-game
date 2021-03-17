// Organelles header file
// Copyright 2021, Parker Patterson. All rights reserved.

#ifndef ORGANELLES_H_
#define ORGANELLES_H_

#include <iostream>
#include <vector>
#include "./gene.h"
#include "./plantpart.h"

using namespace std;

class Organelle : public PlantPart {
  // subclasses are Nucleus, Vacuole, Chloroplast, Mitochondrion, and ER
public:
  unsigned short* GetNutReqmts() const {return nut_reqmts_;}
  virtual OrganelleGene* GetGenes() = 0;
protected:
  OrganelleGene* genes_; // pointer to one gene object
  unsigned short nut_rqmts_[NUM_NUTS];
};

class Nucleus : public Organelle {
  // what does the nucleus do in this simulation?
};

Nucleus::Nucleus(NucleusGene* genes){
  genes_ = genes;
  name_ = "nucleus";
  descrip_ = "The nucleus contains the cell's genetic material.";
  for (int i; i < NUM_NUTS; i++){
    nut_rqmts_[i] = genes->GetNutRqmts()[i];
  }
}

class Vacuole : public Organelle {
public:
  unsigned GetSize() const {return size_;}
  short GetSupportFactor() const {return support_;}
  short GetStorageFactor() const {return storage_;}
  VacuoleGene* GetGenes() const override {return genes_;}
protected:
  unsigned size_;
  short support_factor_;
  short storage_factor_;
};

Vacuole::Vacuole(VacuoleGene* genes){
  name_ = "vacuole";
  genes_ = genes;
  size_ = genes->GetSize();
  support_ = genes->IsSupport();
  storage_ = genes->IsStorage();
  for (int i; i < NUM_NUTS; i++){
    nut_rqmts_[i] = genes->GetNutRqmts()[i];
  }
}

class Producer : public Organelle {
public:
  double GetEfficiency() const {return efficiency_;}
protected:
  double efficiency_;
  unsigned short nuts_avail_[NUM_NUTS];
};

class Chloroplast : public Producer {
public:
  unsigned short* GetColors() const {return colors_;}
  ChloroplastGene* GetGenes() const override {return genes_;}
protected:
  unsigned short colors_[3];
};

Choloroplast::Chloroplast(ChloroplastGene* genes){
  genes_ = genes;
  efficiency_ = genes->GetEfficiency();
  for(int i = 0; i < 3; i++){
    colors_[i] = genes->GetColors()[i];
  }
  for (int i = 0; i < NUM_NUTS; i++){
    nut_rqmts[i] = genes->GetNutRqmts()[i];
  }
}

class Mitochondrion : public Producer {
public:
  MitochondrionGene* GetGenes() const override {return genes_;}
};

Mitochondrion::Mitochondrion(MitochondrionGene* genes){
  genes_ = genes;
  efficiency_ = genes->GetEfficiency();
  for (int i = 0; i < NUM_NUTS; i++){
    nut_rqmts[i] = genes->GetNutRqmts()[i];
  }
}

class EndoplasmicReticulum : public Producer {
public:
  ERGene* GetGenes() const override {return genes_;}
  vector<Phytochemical*> Produce();
protected:
  vector<Phytochemical*> chems_;
};

EndoplasmicReticulum::EndoplasmicReticulum(ERGene* genes){
  genes_ = genes;
  chem_ = &genes->chem_;
  efficiency_ = genes->GetEfficiency();
  for (int i = 0; i < NUM_NUTS; i++){
    nut_rqmts[i] = genes->GetNutRqmts()[i];
  }
};

class CellWall : public Organelle {
public:
  bool IsLignified() const {return lignified_;}
  CellWallGene* GetGenes() const override {return genes_;}
protected:
  bool lignified_;
};

CellWall::CellWall(CellWallGene* genes){
  genes_ = genes;
  lignified_ = genes->IsLignified();
  for (int i = 0; i < NUM_NUTS; i++){
    nut_rqmts[i] = genes->GetNutRqmts()[i];
  }
}

#endif // ORGANELLES_H_
