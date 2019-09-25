//
// Created by shira on 9/25/19.
//

#include "encaps_def.h"
#include <stdio.h>

//// Box ////////////

void Box_ctor_d(Box * box,double dim) {
    box->length=dim;
    box->width=dim;
    box->height=dim;
    box_print(box);
}
void Box_ctor(Box * box) {
    box->length=1;
    box->width=1;
    box->height=1;
    box_print(box);
}
void Box_cpy_ctor(Box *box1, Box *box2) {
    box1->length=box2->length;
    box1->height=box2->height;
    box1->width=box2->width;
}
void Box_ctor_ddd(Box *box, double l, double w, double h){
    box->length=l;
    box->width=w;
    box->height=h;
    box_print(box);
}

void Box_dtor(Box *box)
{
    printf("Box destructor, %f x %f x %f\n", box->width, box->height, box->length);
}

void Box_mult_d(Box* box, double mult)
{
    box->width *= mult;
    box->height *= mult;
    box->length *= mult;
}
Box* boxp_Box_mult_d(const Box* box, double mult)
{
    Box *ret;
    Box_cpy_ctor(ret,box);
    Box_mult_d(ret, mult);
    return ret;
}
bool box_is_equal(const Box *lhs, const Box *rhs)
{
    if(lhs->width == rhs->width && lhs->height == rhs->height && lhs->length == rhs->length){
        return true;
    }
    else{
        return false;
    }

}
void box_print(const Box *box)
{
    printf("Box: %f x %f x %f\n", box->length, box->width, box->height);
}

double box_getVolume(const Box *box)
{
    double res =  box->width * box->length * box->height;
    return res;
}


//// Shelf ////////////

const char* message = "The total volume held on the shelf is";
void setBox(Shelf *shelf, int index, const Box* dims)
{
    shelf->boxes[index] = dims;
}

double shelf_getVolume(Shelf *shelf)
{
    double vol = 0;
    for (int i = 0; i < 3; ++i)
    vol += box_getVolume(shelf->boxes[i]);

return vol;
}

void shelf_print(Shelf *shelf)
{
    printf("%s %d\n", message, shelf_getVolume(shelf));
}

void setMessage(const char* msg)
{
    message = msg;
}


