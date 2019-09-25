//
// Created by shira on 9/25/19.
//
#include <stdio.h>
#include "encaps_def.h"

static Box largeBox;
//
//void thisFunc()
//{
//    printf("\n--- thisFunc() ---\n\n");
//    Box box99;
//    Box_ctor_ddd(&box99,99, 99, 99);
//    box_mult_d(&box99,10);
//
//}
//
//void thatFunc()
//{
//    printf("\n--- thatFunc() ---\n\n");
//    Box box99;
//    Box_ctor_ddd(&box99,99, 99, 99);
//    box_mult_d(&box99,10);
//    static Box box88(88, 88, 88);
//    box88 *= 10;
//}
//
//void doBoxes()
//{
//    printf("\n--- Start doBoxes() ---\n\n");
//
//    Box b1(3);
//    Box b2(4, 5, 6);
//
//    printf("b1 volume: %f\n", b1.getVolume());
//    printf("b2 volume: %f\n", b2.getVolume());
//
//    b1 *= 1.5;
//    b2 *= 0.5;
//
//    printf("b1 volume: %f\n", b1.getVolume());
//    printf("b2 volume: %f\n", b2.getVolume());
//
//    Box b3 = b2;
//    Box b4 = 3 * b2;
//    printf("b3 %s b4\n", b3 == b4 ? "equals" : "does not equal");
//
//    b3 *= 1.5;
//    b4 *= 0.5;
//    printf("Now, b3 %s b4\n", b3 == b4 ? "equals" : "does not equal");
//
//    printf("\n--- End doBoxes() ---\n\n");
//}
//
//
//void doShelves()
//{
//   printf("\n--- start doShelves() ---\n\n");
//
//    Box aBox;
//    Box_d(&aBox, 5);
//
//    Shelf aShelf;
//
//    aShelf.print();
//    aShelf.setBox(1, largeBox);
//    aShelf.setBox(0, aBox);
//
//    aShelf.print();
//    aShelf.setMessage("This is the total volume on the shelf:");
//    aShelf.print();
//    Shelf::setMessage("Shelf's volume:");
//    aShelf.print();
//
//    aShelf.setBox(1, Box(2, 4, 6));
//
//    setBox(&aShelf,2, 2);
//    shelf_print(&aShelf);
//
//    printf("\n--- end doShelves() ---\n\n");
//}

int main()
{

    Box_ctor_ddd(&largeBox ,10, 20, 30);
    printf("\n--- Start main() ---\n\n");
    //doBoxes();
    //thisFunc();
    //thisFunc();
    //thisFunc();
    //doShelves();
    printf("\n--- End main() ---\n\n");

    return 0;
}

