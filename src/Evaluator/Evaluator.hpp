#ifndef EVAL
#define EVAL

/*
 *  Evaluator.hpp
 *  
 *
 *  Created by Justin Montoya on 11/29/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

// Function Declarations

#include "Evaluator.h"

extern "C" {

int findit();
void init_deck(int *deck);
int find_card(int rank, int suit, int *deck);
void shuffle(int *deck);
int hand_val(short value);
short eval_5cards( int c1, int c2, int c3, int c4, int c5 );
short eval_5hand( int *hand );
short eval_7hand( int *hand );

}

#endif