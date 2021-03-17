// Organs header file
// Copyright 2021, Parker Patterson. All rights reserved.

#ifndef ORGANS_H_
#define ORGANS_H_

#include "./tissues.h"
#include "./plantpart.h"
#include "./shape.h"
#include <vector>

class Organ : public PlantPart {
protected:
  vector<Tissue> tissues_;
  Shape shape_;
};

class Leaf : public Organ {
protected:
  LeafShape shape_;
};

class Thallus : public Leaf {
  
};

class Cotyledon : public Leaf {

};

class TrueLeaf : public Leaf {

};

class Stem : public Organ {
protected:
  StemShape shape_;
};

class Root : public Organ {
protected:
  RootShape shape_;
};

class Rhizoid : public Root {

};

class Reproductive : public Organ {

};

class Sporangium : public Reproductive {

};

class Flower : public Reproductive {

};

class Bud : public Flower {

};

class Blossom : public Flower {

};

class Fruit : public Flower {

};

#endif // ORGANS_H_
