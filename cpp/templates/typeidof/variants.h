#ifndef VARIANTS_H
#define VARIANTS_H

#include <QtCore>
#include "create_arrays.h"
#include "show_functions.h"

void variant_1();
void variant_2();
void variant_3();
void variant_4();

static void (*variants[4])() = { variant_1, variant_2, variant_3, variant_4 };
#endif // VARIANTS_H
