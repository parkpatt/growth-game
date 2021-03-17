// Plantpart header file
// Copyright 2021, Parker Patterson. All rights reserved.

#include <string>

using namespace std;

class PlantPart {
public:
  string GetName() const {return name_;}
  string GetDescrip() const {return descrip_;}
  void SetName(string name) {name_ = name;}
  void SetDescrip(string descrip) {descrip_ = descrip;}
  virtual void Update() = 0;
  virtual void Draw() = 0;
protected:
  string name_;
  string descrip_;
};

PlantPart::PlantPart(string name, string descrip){
  name_ = name;
  descrip_ = descrip;
}



