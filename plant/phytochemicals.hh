// Phytochemicals header file
// Copyright 2021, Parker Patterson. All rights reserved.

#ifndef PHYTOCHEMICALS_H_
#define PHYTOCHEMICALS_H_

#include <string>
#include "./plantpart.hh"
#include "./colors.hh"

using namespace std;

enum gastype {CO2, O2};
enum mineraltype {N, P, K};

class Phytochemical : public PlantPart {
  // all chemicals; must be either raw or synthetic
};

class Raw : public PhytoChemical {
  // raw chemicals from the environment such as water or co2
};

class TypedRaw : public Raw {
};

class Gas : public TypedRaw {
  // O2 or CO2, as defined by enum above
protected:
  gastype type_;
public:
  gastype GetType() const {return type_;}
};

Gas::Gas(gastype type){
  type_ = type;
  if (type == CO2){
    name_ = "carbon dioxide";
    descrip_ = "Carbon dioxide is used to synthesize sugars.";
  } else {
    name_ = "oxygen";
    descrip_ = "Oxygen is needed by Mitochondria to produce ATP.";
  }
};

class Water : public Raw {
};

Water::Water(){
  name_ = "water";
  descrip_ = "Plain old H2O";
};

class Mineral : public TypedRaw {
protected:
  mineraltype type_;
public:
  mineraltype GetType() const {return type_;}
};

Mineral::Mineral(mineraltype type){
  type_ = type;
  switch (type) {
  case N:
    name_ = "nitrogen";
    descrip_ = "nitrogen is needed to synthesize proteins."
    break;
  case P:
    name_ = "phosphorus";
    descrip_ = "phosophorus is used to synthesize a variety of phytochemicals.";
    break;
  case K:
    name_ = "potassium";
    descrip_ = "potassium is used by organelles to maintain homeostasis.";
    break;
  }
}

class SynthChem : public Phytochemical {
  // plant-synthesized chemicals
protected:
  ChemGene* genes_;
public:
  ChemGene* GetGenes() const {return genes_;}
};

// alkaloid? terpene? 

class Sugar : public SynthChem {
  // may be glucose, nectar, or polysaccharide
};

class Glucose : public Sugar {
};

Glucose::Glucose(){
  genes_ = nullptr;
  name_ = "glucose";
  descrip_ = "Cells use glucose as a source of energy.";
}

class Nectar : public Sugar {
protected:
  unsigned short fragrance_;
public:
  unsigned short GetFragrance() const {return fragrance_}
};

Nectar::Nectar(NectarGene* genes){
  genes_ = genes;
  aroma_ = genes->GetAroma();
  //name_ = genes->GetName();
  //descrip_ = genes->GetDescrip();
}

class Polysaccharide : public Sugar {
protected:
  unsigned int length_;
  unsigned short rigidity_;
  unsigned short elasticity_;
public:
  unsigned int GetLength() const {return length_;}
  unsigned short GetRigidity() const {return rigidity_;}
  unsigned double GetElasticity() const {elasticity_;}
};

Polysaccharide::Polysaccharide(){
  name_ = "polysaccharide";
  descrip_ = "Polysaccharides are used to strengthen cell walls.";
}

class Toxin : public SynthChem {
protected:
  unsigned short potency_;
public:
  unsigned short GetPotency();
};

class Tannin : public Toxin {
  // antimicrobial anti-enzyme
};

class Alkaloid : public Toxin {

};

class Glycoside : public Toxin {

};

class VolatileOil : public Toxin {
  // liquids that may be irritants, emetics, or nephrotoxins
};

class Furocoumarin : public Toxin {
  // phototoxic stress toxins. May induce gastrointensinal effects.
};

class Enzyme : public Toxin {
  // These toxins enter eukaryotic cells to inhibit protein synthesis or mimic
  // natural proteins. Expensive to produce but effective.
};

class Pigment : public SynthChem {
protected:
  unsigned double production_factor_;
  struct Color color;
public:
};


#endif  // PHYTOCHEMICALS_H_
