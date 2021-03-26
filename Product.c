#include "Product.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct SProduct {
    int id;
    char name[30];
    double price;
};

Product Product_create(int id, char *name, double price) {
    Product created = (Product) calloc(sizeof(struct SProduct), 1);

    created->id = id;
    created->price = price;
    strcpy(created->name, name);

    return created;
}

void Product_print(Product _this) {
    printf("[%d] %s : %lf", _this->id, _this->name, _this->price);
}

void Product_delete(Product _this) {
    free(_this);
}

int Product_getId(Product _this) {
    return _this->id;
}

double Product_getPrice(Product _this) {
    return _this->price;
}

void Product_setPrice(Product _this, double newPrice) {
    _this->price = newPrice;
}

char *Product_getName(Product _this) {
    return _this->name;
}

void Product_setName(Product _this, char *newName) {
    strcpy(_this->name, newName);
}

void Product_write(Product _this, char *fileName) {
    FILE *fp = fopen(fileName, "ab");
    if (!fp) {
        printf("Cannot create or open file.\n");
        return;
    }

    fwrite(_this, sizeof (struct SProduct), 1, fp);
    fclose(fp);
}

void Product_read(Product _this, char *fileName, int position) {
    FILE *fp = fopen(fileName, "rb");
    if (!fp) {
        printf("Could not open file.\n");
        return;
    }

    int read = fseek(fp, (long) sizeof (struct SProduct) * position, SEEK_SET);
    if (read != 0) {
        printf("Could not seek to position.\n");
        fclose(fp);
        return;
    }

    fread(_this, sizeof(struct SProduct), 1, fp);
    fclose(fp);
}