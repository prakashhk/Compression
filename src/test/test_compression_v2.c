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
#include <decoding/decoding.h>
#include <binary/binary.h>

#include <v2/file/file.h>
#include <v2/compression/compression.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "test.h"

int main() {

	/* The Compression Part */
	FILE *in_compression = fopen("./src/exemples/version2/texte_non_code_v2_ascii", "r");
	FILE *out_compression = fopen("./src/exemples/version2/texte_non_code_v2_ascii_code", "w");
	
	assert(newCompression(in_compression, out_compression) == 1);
	
	fclose(in_compression);
	fclose(out_compression);
	
	FILE *in_compression_advanced = fopen("./src/exemples/version2/jaccuse_v2_ascii", "r");
	FILE *out_compression_advanced = fopen("./src/exemples/version2/jaccuse_v2_ascii_code", "w");
	
	assert(newCompression(in_compression_advanced, out_compression_advanced) == 1);
	
	fclose(in_compression_advanced);
	fclose(out_compression_advanced);
	
	FILE *in_compression_bytes = fopen("./src/exemples/version2/texte_non_code_v2_ascii", "r");
	FILE *out_compression_bytes = fopen("./src/exemples/version2/texte_non_code_v2_ascii_code_bytes", "w");
	
	assert(newCompressionBytes(in_compression_bytes, out_compression_bytes) == 1);
	
	fclose(in_compression_bytes);
	fclose(out_compression_bytes);
	printf("\n");
	
	printf("To see the file result with compression, go in src/exemples/texte_non_code_v2_ascii_code & bytes !\n\n");
	
	/* The Decompression Part */
	FILE *in_decompression = fopen("./src/exemples/version2/texte_non_code_v2_ascii_code", "r");
	FILE *out_decompression = fopen("./src/exemples/version2/texte_non_code_v2_ascii_origin", "w");
	
	assert(newDecompression(in_decompression, out_decompression) == 1);
	
	fclose(in_decompression);
	fclose(out_decompression);
	
	FILE *in_decompression_advanced = fopen("./src/exemples/version2/jaccuse_v2_ascii_code", "r");
	FILE *out_decompression_advanced = fopen("./src/exemples/version2/jaccuse_v2_ascii_origin", "w");
	
	assert(newDecompression(in_decompression_advanced, out_decompression_advanced) == 1);
	
	printf("To see the file result, go in src/exemples/version2/texte_non_code_v2_ascii_origin !\n");
	printf("To see the file result, go in src/exemples/version2/jaccuse_v2_ascii_origin !\n\n");
	
	fclose(in_decompression_advanced);
	fclose(out_decompression_advanced);

	testSuccessful(__FILE__);

	return 0;
}
