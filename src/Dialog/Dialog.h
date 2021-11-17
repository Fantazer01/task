//
// Created by oleg on 17.11.2021.
//

#ifndef TASK1_DIALOG_H
#define TASK1_DIALOG_H

#include "Graph.h"
#include "MapOfLocation.h"

Graph initGraph(char *filename);
MapOfLocation initMap(char *filename);

int dialog();

#endif //TASK1_DIALOG_H
