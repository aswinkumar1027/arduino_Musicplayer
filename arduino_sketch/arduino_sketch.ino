/*
 *  First we need to convert mp3 file to wav file with below setting
 *  bit resolution : 8 Bit
 *  sampling rate  : 32000 Hz
 *  audio channel  : stereo
 *  
 *  to convert mp3 visit link: https://audio.online-convert.com/convert-to-wav
 */
#include <SimpleSDAudio.h>

void setup() {
  
  SdPlay.setSDCSPin(4); // sd card cs pin
  if (!SdPlay.init(SSDA_MODE_HALFRATE | SSDA_MODE_MONO | SSDA_MODE_AUTOWORKER)) // setting mode 
  { 
    while(1); 
  }

}

int count = 1;
void loop(void)
{
  
  switch (count) {
      case 1:
        if(!SdPlay.setFile("music.wav")) // music name file
          { 
            while(1);          
          }
          count = 2;
        break;
      case 2:
        if(!SdPlay.setFile("music.wav")) // music name file
          { 
            while(1);
          }
          count = 3;
        break;
      case 3:
        if(!SdPlay.setFile("music3.wav")) // music name file
          { 
            while(1);
          }
          count = 1;
        break;
    }
    
  SdPlay.play(); // play music
  
  while(!SdPlay.isStopped())
    { 
      ;
    }

}
