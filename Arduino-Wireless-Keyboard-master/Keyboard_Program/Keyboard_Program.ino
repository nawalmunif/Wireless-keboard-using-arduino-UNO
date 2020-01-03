#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


#include <IRremote.h>
//Digit remote      keyboard
//      hexa
// volume up 4FB708F-----------82-----arrow up
//volume down 4FB7887----------81-----arrow down
//mute 4FB58A7-----------------16-----M
//pause 4FBE21D----------------44------spacebar
//step forward 4FBE01F---------79-----arrow right
//stop 4FB40BF-----------------77------end
//play 4FBA05F-----------------44-----spacebar
//repeat 4FB22DD----------------74-----home
//step backward 4FB609F------------80------left arrow
//forward 4FBC03F---------79----arrow right
//power 4FB28D7----------12--------i(expand)
//zoom 4FB827D-----------9----------f(full screen)
//subtitle 4FB18E7-------6----------c(subtitles)


int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

uint8_t buf[8] = {
  0
}; 	/* Keyboard report buffer */

//#define PIN_VOLUME_UP 5

int state = 0;

void setup()
{
  Serial.begin(9600);
  //  pinMode(PIN_VOLUME_UP, INPUT);
  // enable internal pull-ups
  // digitalWrite(PIN_VOLUME_UP, 1);
  irrecv.enableIRIn(); // Start the receiver
  delay(200);
}
void loop()
{
  if (irrecv.decode(&results))

  {
    if (results.value == 0x4FB708F) {
      // volume up 4FB708F-----------82-----arrow up
      buf[2] = 82;    //1
      Serial.write(buf, 8); // Send keypress
      releaseKey();

    }
    if (results.value == 0x4FB7887) {
      //volume down 4FB7887----------81-----arrow down
      buf[2] = 81;    //2
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    if (results.value == 0x4FB58A7) {
      //mute 4FB58A7-----------------16-----M
      buf[2] = 16;    //3
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    if (results.value == 0x4FBE21D) {
      //pause 4FBE21D----------------44------spacebar
      buf[2] = 44;    //4
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    
    if (results.value == 0x4FBE01F) {
      //step forward 4FBE01F---------79-----arrow right
      buf[2] = 79;    //5
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    if (results.value == 0x4FB40BF) {
      //stop 4FB40BF-----------------77------end
      buf[2] = 77;    //6
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    if (results.value == 0x4FBA05F) {
      //play 4FBA05F-----------------44-----spacebar
      buf[2] = 44;    //7
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    if (results.value == 0x4FB22DD) {
      //repeat 4FB22DD----------------74-----home
      buf[2] = 74;    //8
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    if (results.value == 0x4FB609F) {
      //step backward 4FB609F------------80------left arrow
      buf[2] = 80;    //9
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    if (results.value == 0x4FBC03F) {
      //forward 4FBC03F---------79----arrow right
      buf[2] = 79;    //10
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    if (results.value == 0x4FB28D7) {
      //power 4FB28D7----------12--------i(expand)
      buf[2] = 12;    //10
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    if (results.value == 0x4FB827D) {
      //zoom 4FB827D-----------9----------f(full screen)
      buf[2] = 9;    //11
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }
    if (results.value == 0x4FB18E7) {
      //subtitle 4FB18E7-------6----------c(subtitles)
      buf[2] = 6;    //12
      Serial.write(buf, 8); // Send keypress
      releaseKey();
    }


    //   Serial.println(results.value, HEX);    DON'T UNCOMMENT THIS DUE TO ALOT OF DISTORTION
    irrecv.resume(); // Receive the next value
  }

}

void releaseKey()
{
  buf[0] = 0;
  buf[2] = 0;
  Serial.write(buf, 8);	// Release key
  // delay(50);
}
