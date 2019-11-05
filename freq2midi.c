/* given a particular frequency, determine midi note */
#include <stdio.h>
#include <math.h>

int main()
{
	double semitone_ratio = pow(2, 1/12.0);
	double c5 = 220.0 * pow(semitone_ratio, 3.0);
	double c0 = c5 * pow(0.5, 5);
	double frequency = 620.0;
	int pitchbend_up, pitchbend_down;	
	int midinote, midi_pitch_up, midi_pitch_down;
	
	double fraction_of_midi = log(frequency / c0) / log(semitone_ratio);
	midinote = (int) (fraction_of_midi + 0.5);

	printf("The nearest MIDI note to the frequency %f is %d\n", frequency, midinote);

	pitchbend_up = (int) ((frequency / (frequency * pow(semitone_ratio, 0.5))) * 100); 
	pitchbend_down = (int) ((frequency / (frequency - (pitchbend_up - frequency))) * 100); 
	printf("pitch bend frequency up is %d and down is %d\n", pitchbend_up, pitchbend_down);

	return 0;
}
