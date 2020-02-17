/* Displays equal tempered frequencies for an octave with N distinct notes,
   starting from a given midi note.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char* argv[]) {
	int notes, midinote;
	double frequency, ratio, c0, c5;
	double frequencies[24];

	notes = atoi(argv[1]);
	if ((notes < 1) || (notes > 24)) {
		printf("Error: invalid number of notes. \n");
		printf("Please enter a number between 1 and 24\n");
	}

	if (argc != 3) {
		printf("usage: do something different");
		return 1;
	}
	
	midinote = atoi(argv[2]);
	if ((midinote <0) || (midinote > 127)) {
		printf("Error: invalid midinote. Please enter\n");
		printf("a number between 1 and 127.\n");
	}

	ratio = pow(2.0, 1.0/12.0);
        c5 = 220.0 * pow(ratio, 3);
        c0 = c5 * pow(0.5, 5);
        frequency = c0 * pow(ratio, midinote);

	for (int i=0; i<notes; i++) {
		frequencies[i] = frequency;
		frequency = frequency *=  
	return 0;
}
