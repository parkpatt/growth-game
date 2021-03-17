// Tissues header file
// Copyright 2021, Parker Patterson. All rights reserved.

#ifndef TISSUES_H_
#define TISSUES_H_

#include "./phytochemicals.h"
#include "./cells.h"
#include "./plantpart.h"

class Tissue : public PlantPart {
protected:
  vector<Polysaccharide*> polys_; 
  vector<Cell> cells_;
  vector<int> cell_qtys_;
public:
  vector<Polysaccharide*> GetPolys() const {return polys_;}
};

class Vascular : public Tissue {
public:
  virtual void Transport() = 0;
protected:
  Tissue* above_;
  Tissue* below_;
  vector<Tissue*> adjacent_;
};

class GroundTissue : public Tissue {
  virtual vector<int> Produce() = 0;
};

class Dermal : public Tissue {
public:
  virtual vector<int> Absorb() = 0;
};

class Epidermis : public Dermal {

};

class Bark : public Epidermis {

};

class Stoma : public Dermal {
protected:
  Shape shape_;
};

class Trichome : public Dermal {
protected:
  unsigned short width_;
  unsigned short length_;
  
  Shape shape_;
  vector<Phytochemical*> chems_;
public:
  vector<Phytochemical*> GetChems() const {return chems_};
};

class RootHair : public Dermal {
  
};

class Cuticle : public Dermal {
protected:
  unsigned double efficiency_;
  unsigned short thickness_;
public:
  unsigned double GetEfficiency const {return efficiency_;}
  unsigned short GetThickness const {return thickness_;}
};

class Xylem : public Vascular {
  
};

class Phloem : public Vascular {

};

#endif // TISSUES_H_
