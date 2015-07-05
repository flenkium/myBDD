//
// Created by Tino Flenker on 6/10/15.
//

#pragma once

namespace myBDD {

enum class type_t{ NULL_t, AND, OR, XOR, NOT, NAND, NOR, XNOR, ITE, IMPLIES };

class Type {
 public:
  Type();
 private:
  type_t type_;
};

} // end namespace myBDD

