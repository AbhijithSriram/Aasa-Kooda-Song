/* Play "Aasa Kooda" Theme Song
 * By Abhijith Sriram 26.07.2024
 * Youtube in Action: https://www.youtube.com/shorts/vEsOTIJJDDk
 * 
 * 
 * INSTRUCTION: Hook up Pin 10 to the positive side of a buzzer or a microphone, hook up 
 * any resistor to the negative side of a buzzer (to limit current & volume & to protect the pin), 
 * and then connect the other end of the resistor to ground pin. Upload the sketch and enjoy! 
 * 

 * 
 * Last updated: 26.07.2024
 * ---------------------
 * Credits:

 * 
 * Code inspired by Xitang Zhao
 * Link: https://github.com/xitanggg/-Pirates-of-the-Caribbean-Theme-Song/blob/master/Pirates_of_the_Caribbean_-_Theme_Song.ino
 * 

 */

// Define pin 10 for buzzer, you can use any other digital pins (Pin 0-13)
const int buzzer = 10;

// Change to 0.5 for a slower version of the song, 1.25 for a faster version
const float songSpeed = 1;

// Defining frequency of each music note
#define NOTE_C4 262
#define NOTE_D4 294
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_G4 392
#define NOTE_A4 440
#define NOTE_A45 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_D5 587
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_G5 784
#define NOTE_A5 880
#define NOTE_B5 988

// Music notes of the song, 0 is a rest/pulse
int notes[] = {
    NOTE_D5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5,
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5,
    0, NOTE_G4, 0, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A45, NOTE_A4,

    NOTE_D5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5,
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5,
    0, NOTE_G4, 0, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A45, NOTE_A4,

    NOTE_D5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_C5, NOTE_C5, NOTE_D5,
    NOTE_A4, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5,
    0, NOTE_G4, 0, NOTE_A4, NOTE_A4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A45, NOTE_A4,

    0, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_D5, NOTE_C5, NOTE_C5, NOTE_D5, NOTE_E5,
    NOTE_F5, 0, NOTE_F5, NOTE_E5, NOTE_G5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5, NOTE_A45, NOTE_C5, NOTE_A45,
    NOTE_A4, 0, NOTE_A45, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A45, NOTE_A4, 
    0, NOTE_A45, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A45, NOTE_A4, NOTE_A4,

    NOTE_A45, NOTE_D5, NOTE_A45, NOTE_D5, NOTE_A45, NOTE_D5, NOTE_A45, NOTE_D5,
    NOTE_E5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_F5,NOTE_D5, NOTE_C5,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A45, NOTE_A4,
    NOTE_A45, NOTE_D5, NOTE_A45, NOTE_D5, NOTE_A45, NOTE_D5, NOTE_A45, NOTE_D5,
    NOTE_E5, NOTE_F5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_F5,NOTE_D5, NOTE_C5,
    NOTE_D5, NOTE_E5, NOTE_F5, NOTE_E5, NOTE_D5, NOTE_C5,
    NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, NOTE_A45, NOTE_A4,
    };

// Durations (in ms) of each music note of the song
// Quarter Note is 250 ms when songSpeed = 1.0
int durations[] = {
    300, 100, 300, 300, 450, 150, 300, 300,
    450, 150, 300, 300, 450, 150, 300, 300,
    200, 100, 150, 150, 300, 300, 450, 150, 300, 300,
    450, 150, 450, 150, 450, 150, 300, 300, 
    
    300, 100, 300, 300, 450, 150, 300, 300,
    450, 150, 300, 300, 450, 150, 300, 300,
    200, 100, 150, 150, 300, 300, 450, 150, 300, 300,
    450, 150, 450, 150, 450, 150, 300, 300, 

    300, 100, 300, 300, 450, 150, 300, 300,
    450, 150, 300, 300, 450, 150, 300, 300,
    200, 100, 150, 150, 300, 300, 450, 150, 300, 300,
    450, 150, 450, 150, 450, 150, 300, 300, 

    150, 300, 150, 300, 300, 300, 300, 300, 300, 
    600, 300, 150, 150, 150, 150, 150, 150, 150, 150, 150, 150, 
    300, 300, 300, 300, 300, 300, 300, 300, 
    300, 300, 300, 300, 300, 300, 300, 300, 

    
    300, 300, 300, 300, 300, 300, 300, 300, 
    300, 300, 300, 300, 300, 300, 300, 300, 
    600, 300, 600, 300, 300, 300, 
    600, 300, 600, 300, 300, 300,
    300, 300, 300, 300, 300, 300, 300, 300, 
    300, 300, 300, 300, 300, 300, 300, 300, 
    600, 300, 600, 300, 300, 300, 
    600, 300, 600, 300, 300, 300,


    
    };

void setup()
{
  const int totalNotes = sizeof(notes) / sizeof(int);
  // Loop through each note
  for (int i = 0; i < totalNotes; i++)
  {
    const int currentNote = notes[i];
    float wait = durations[i] / songSpeed;
    // Play tone if currentNote is not 0 frequency, otherwise pause (noTone)
    if (currentNote != 0)
    {
      tone(buzzer, notes[i], wait); // tone(pin, frequency, duration)
    }
    else
    {
      noTone(buzzer);
    }
    // delay is used to wait for tone to finish playing before moving to next loop
    delay(wait);
  }
}

void loop()
{
  // Nothing in loop. Music only plays once.
  // You can click reset on Arduino to replay the song.
}
