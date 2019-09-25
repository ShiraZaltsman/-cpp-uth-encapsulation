//
// Created by shira on 9/25/19.
//

#ifndef CPP_UTH_ENCAPSULATION_SHIRAZALTSMAN_ENCAPS_DEF_H
#define CPP_UTH_ENCAPSULATION_SHIRAZALTSMAN_ENCAPS_DEF_H

typedef enum{false, true}bool;
//// Box ////////////

typedef struct Box
{
    double width;
    double height;
    double length;
}Box;

void Box_ctor(Box *box);
void Box_ctor_d(Box *box, double);
void Box_cpy_ctor(Box *box1,Box *box2);
void Box_ctor_ddd(Box *box, double l, double w, double h);
void Box_dtor(Box *box);


//Box operator*(const Box& box, double mult);
void box_mult_d(Box *box, double mult);
Box* boxp_Box_mult_d(const Box* box, double mult);
bool box_is_equal(const Box* lhs, const Box* rhs);
bool box_isnot_equal(const Box *lhs, const Box* rhs);
double box_getVolume(const Box *box);
void box_print(const Box *box);




//// Shelf ////////////
const char* const DEF_MSG;
const char* message;
typedef struct
{
    Box *boxes[3];
} Shelf;

//void shelf_ctor(Shelf *shelf);

double shelf_getVolume(Shelf *shelf);
static void setMessage(const char* msg);
void setBox(Shelf *shelf, int index, const Box* dims);
void shelf_print(Shelf *shelf);


#endif //CPP_UTH_ENCAPSULATION_SHIRAZALTSMAN_ENCAPS_DEF_H
