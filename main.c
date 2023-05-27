#include <stdio.h>
#include <stdint.h>

typedef struct 74151_s  {

  int     addr;   // regular number (for now?)
  uint8_t in_port;
  uint8_t out_bit;// only using lowest bit

} 74151_t;

typedef struct 74574_s  {

  uint8_t d;
  uint8_t q;
} 74574_t;

typedef struct 74259_s  {

  int     addr;   // regular number (for now?)
  uint8_t in_bit; //(d) only using lowest bit
  uint8_t out_port; 
  
} 74259_t;


typedef struct rom_s  {

  uint8_t* p;
  int addr;
} rom_t;

void 74574to74259(74574_t* p 74259_t* q)  {

  
}

void RomOutputBus(rom_t* rom, 74574_t* upper, 74574_t* lower, 74151_t* q)  {

  upper->d = rom->p[rom->addr];
  q.addr   = (rom->p[rom->addr] & 7);
  lower->d = (rom->p[rom->addr] & 0b00011110); //right? endian too?
}

void 74151OutputBus(74151_t* p, 74574_t* q)  {

  if (p->out_bit & 1)
  
    q->d |= 0b10000000;
    
  else q->d &= !(0b10000000); //clear the bit. how? brain fart :P
}

void Upper74574OutputBus(74574_t* p, rom_t* rom)  {

  rom->addr = ((p->q) << 2);
}

void Lower74574OutputBus(74574_t* p, rom_t* rom, 74259_t q)  {

  

int AddressDecoder(int address)  {// basically returns 2^(address-1).

  int select = 1;
  
  if ((address == 0) || (address > 8)) return 0;
  
  return ( select << (address-1) );
}

void 74151InternalJazz(74151_t* p)  {

  if ( p->in_port & (AddressDecoder(p->addr)) ) 
  
    p->out_bit = 1;
    
  else p->out_bit = 0;
}

void 74574InternalJazz()  {
  
  //move inputs through to outputs
  p->q = p->d;
  //in the scope of the top chip put address through to rom.!!!(bus funtion)?
}

void 74259InternalJazz()  {
  
  if ( p->in_bit & 1 )
  
    p->out_port |= (AddressDecoder(p->addr));     //set the addressed bit.
    
  //maybe this is not what works. no I think it will.  
  else p->out_port &= !(AddressDecoder(p->addr)); //clr the addressed bit. 
}

int main()  {

  int x;
  rom_t Rom; Rom.address = 0;
  
  putchar(10);
  
  while(1)  {
  
    //Do a bucnh of good stuff.
    RomOutput();
    
    //lower 74574
    
    //74151
    
    //74259
    
    //then commit main data address feedback latch.
    74574InternalJazz(&DataAdressfeedbackguy, &Rom);
  }
  
  return 0;
}
