//
// Created by shira on 10/6/19.
//

#ifndef CPP_UTH_ENCAPSULATION_SHIRAZALTSMAN_INHERITACE_DEF_H
#define CPP_UTH_ENCAPSULATION_SHIRAZALTSMAN_INHERITACE_DEF_H
#include <stdio.h>
#include "encaps_def.h"

//// Materials ////////////
typedef enum
{
    PLASTIC,
    METAL,
    WOOD,
    PAPER,
    OTHER
}Types;

typedef struct
{
}Materials;

static const char* getName(Types type)
{
    const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };
    return names[type];
}
const char* name(Types mat) {
    return getName(mat);
}

typedef struct{
        Types material;
        //Materials m_matirals;//empty struct
}Material_t;

void Material_t_cator_Ty(Material_t *this, Types mat){
    this->material=mat;
    printf("Material created, set to %s\n", name(mat));
}


void Material_t_cator(Material_t *this){
    this->material=OTHER;
    printf("Material created, set to %s\n", name(OTHER));
}
//
////// PhysicalBox ////////////
//
//typedef struct //PhysicalBox//: public Box
//{
//    Box box;
//    PhysicalBox(double l, double w, double h);
//    PhysicalBox(double l, double w, double h, Materials::Types t);
//    PhysicalBox(Materials::Types t);
//    ~PhysicalBox();
//
//    Materials::Types getMaterial() const;
//    void printp() const;
//
//    private:
//    Material_t material;
//}PhysicalBox;
//
//bool operator==(const PhysicalBox&, const PhysicalBox&);
//bool operator!=(const PhysicalBox&, const PhysicalBox&);

//// PhysicalBox Defs ////////////

//inline Materials::Types PhysicalBox::getMaterial() const
//{
//return material.material;
//}
//
//inline bool operator==(const PhysicalBox& lhs, const PhysicalBox& rhs)
//{
//return (const Box&)lhs == (const Box&)rhs && lhs.getMaterial() == rhs.getMaterial();
//}
//
//inline bool operator!=(const PhysicalBox& lhs, const PhysicalBox& rhs)
//{
//return !(lhs == rhs);
//}
#endif //CPP_UTH_ENCAPSULATION_SHIRAZALTSMAN_INHERITACE_DEF_H
