#include <IRremote.h>
IRsend irsend;
//setup 
void setup()
{
  Serial.begin(9600);
  
}
//sends command from the transmitter
void sendCommand(String code){
      Serial.println(code);
     for(int i = 0; i < 3; i++){ 
    if(code.equals("AD2"))
    irsend.sendSony(0xAD2, 12);
    if(code.equals("AD9"))
    irsend.sendSony(0xAD9, 12);
    if(code.equals("AE2"))
    irsend.sendSony(0xAE2, 12);
    if(code.equals("AE9"))
    irsend.sendSony(0xAE9, 12);
    if(code.equals("AF2"))
    irsend.sendSony(0xAF2, 12);
    if(code.equals("AF9"))
    irsend.sendSony(0xAF9, 12);
    if(code.equals("BD2"))
    irsend.sendSony(0xBD2, 12);
    if(code.equals("BD9"))
    irsend.sendSony(0xBD9, 12);
    if(code.equals("BE2"))
    irsend.sendSony(0xBE2, 12);
    if(code.equals("BE9"))
    irsend.sendSony(0xBE9, 12);
    if(code.equals("BF2"))
    irsend.sendSony(0xBF2, 12);
    if(code.equals("BF9"))
    irsend.sendSony(0xBF9, 12);
    if(code.equals("CD2"))
    irsend.sendSony(0xCD2, 12);
    if(code.equals("CD9"))
    irsend.sendSony(0xCD9, 12);
    if(code.equals("CE2"))
    irsend.sendSony(0xCE2, 12);
    if(code.equals("CE9"))
    irsend.sendSony(0xCE9, 12);
    if(code.equals("CF2"))
    irsend.sendSony(0xCF2, 12);
    if(code.equals("CF9"))
    irsend.sendSony(0xCF9, 12);
    delay(100);
     }
}
// using the bot #, pin # and onoroff # and returns a string with all those parts
String makeCommand(String bot, String pin, String onoroff){
  return bot+pin+onoroff;
}

  void loop() {
  if(Serial.available()>0){
    String sendarray[6];
    String dataarray[6];
    
    String data = Serial.readString();
    //puts the data received into an array
    for(int i = 0; i < data.length(); i++){
     dataarray[i] = String(data.charAt(i));
    }    
   
//makes individual commands
      int j = 0;
      String pin = " ";
      String toggle = " ";
     //takes from the command data and evaluates the pin and the on or off command
      for(int k = 0; k<6; k++){
            if(dataarray[k].equals("D"))
            pin = "D";
            if(dataarray[k].equals("E"))
            pin = "E";
            if(dataarray[k].equals("F"))
            pin = "F";
            if(dataarray[k].equals("9"))
              toggle = "9";
            if(dataarray[k].equals("2"))
            toggle = "2";
      }
  for(int m = 0; m < 6;m++){
    if(dataarray[m].equals("A")){
    sendarray[j] = makeCommand(dataarray[m], pin, toggle);
    j++;
    }
    if(dataarray[m].equals("B")){
    sendarray[j] = makeCommand(dataarray[m], pin,toggle);
    j++;
    }
    if(dataarray[m].equals("C")){
    sendarray[j] = makeCommand(dataarray[m], pin, toggle);
    j++;
    }
  }
//actually sends the commands written in the array
  for(int n = 0; n<6; n++){
    sendCommand(sendarray[n]);
  }

  
  } 
  }

