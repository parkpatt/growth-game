// shape header file
// Copyright 2021, Parker Patterson. All rights reserved.

#include <vector>

class Shape {
public:
  virtual void draw() = 0;
protected:
  unsigned char height_, width_, curve_;
};

class RootShape : public Shape {
  
};

class StemShape : public Shape {

};

class LeafShape : public Shape {

};
