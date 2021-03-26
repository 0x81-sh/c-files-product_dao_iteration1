#include <stdio.h>
#include "Product.h"

void testWrite(Product inst);
void testRead(Product inst);

int main() {
    Product inst = Product_create(1, "test5", 1.50);

    testWrite(inst);
    testRead(inst);

    Product_delete(inst);
    return 0;
}

void testWrite(Product inst) {
    printf("Writing product: ");
    Product_print(inst);
    printf("\n");

    Product_write(inst, "test.dat");
}

void testRead(Product inst) {
    Product_read(inst, "test.dat", 0);

    printf("Product after read: ");
    Product_print(inst);
    printf("\n");
}