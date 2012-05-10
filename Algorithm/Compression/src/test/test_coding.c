/*****************************************************************************
 * 
 * Copyright 2012 
 * LE ROUX Thomas <thomas@november-eleven.fr>
 * LOR Jérémy <jeremyk.lor@gmail.com>
 * 
 * This file is part of the Algorithm Project : Compression.
 * 
 * Compression is free software: you can redistribute it and/or modify
 * it under the terms of the zlib license. See the COPYING file.
 * 
 *****************************************************************************/
 
#include <list/list.h>
#include <coding/coding.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "test.h"

int main() {

	Liste l = NULL;
	
	/* Exemple : 0 deux 0 et 1 0 quatre 3 3 2 0 huit */
	
	assert(codingWordList(&l, "deux") == 0);
	assert(codingWordList(&l, "et") == 0);
	assert(codingWordList(&l, "deux") == 1);
	assert(codingWordList(&l, "quatre") == 0);
	assert(codingWordList(&l, "quatre") == 3);
	assert(codingWordList(&l, "et") == 3);
	assert(codingWordList(&l, "quatre") == 2);
	assert(codingWordList(&l, "huit") == 0);
	
	printList(l);
	
	testSuccessful(__FILE__);
	
    return 0;
}