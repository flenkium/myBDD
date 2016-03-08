//
// Created by Tino Flenker on 6/10/15.
//

#pragma once

#include <boost/graph/directed_graph.hpp>

namespace myBDD {

enum class type_t{ NULL_t, AND, OR, XOR, NOT, NAND, NOR, XNOR, ITE, IMPLIES };

class Type {
 public:
  Type();

  void test(){
   boost::directed_graph graph;
  }



 private:
  type_t type_;
};

} // end namespace myBDD

