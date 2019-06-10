volatile unsigned char* PA = (unsigned char*) 0xC800;
volatile unsigned char* PB = (unsigned char*) 0xC801;
volatile unsigned char* PC = (unsigned char*) 0xC802;
volatile unsigned char* ctrl = (unsigned char*) 0xC803;
volatile unsigned char* xmem = (unsigned char*) 0x74;
char dummy = 0;

void setup() {
  // put your setup code here, to run once:
  *ctrl = 0x82; //set control word, PA out, PB in, PC out
  *xmem |= 0x88; //turn on external memory and set wait states

}

void loop() {
  // put your main code here, to run repeatedly:
  //wait for busy to go low
  while( *PB & 0x01 ){
    dummy++;
    }

  //write data
  //*PA = 0x00;
  
  //delay
  for(int dlay = 0; dlay < 10; dlay++){}
  
  //set /STROBE low
  *PC &= 0xFE;

  //delay
  for(int dlay = 0; dlay < 10; dlay++){}
  
  //set /STROBE high
  *PC |= 0x01;

  while( !(*PB & 0x01)){
    dummy++;
  }
}
