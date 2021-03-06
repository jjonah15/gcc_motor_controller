void setup() {
  // Set up both ports at 9600 baud. This value is most important
  // for the XBee. Make sure the baud rate matches the config
  // setting of your XBee.
  XBee.begin(9600);
  Serial.begin(57600);

  //Open roboclaw serial ports
  roboclawL.begin(38400);
  roboclawR.begin(38400);

  jscmd.linkActive = true; // override this value until we check for it
  jscmd.up = false;
  jscmd.dn = false;
  jscmd.lt = false;
  jscmd.rt = false;
  jscmd.b1 = false;
  jscmd.b2 = false;
  jscmd.b3 = false;
  jscmd.b4 = false;
  jscmd.r1 = false;
  jscmd.r2 = false;
  jscmd.l1 = false;
  jscmd.l2 = false;
  jscmd.st = false;
  jscmd.se = false;

  // populate drive param 
  param[SLOW].vel       = VEL_SLOW;
  param[SLOW].ramp      = RAMP_RATE_SLOW;
  param[SLOW].thr       = THR_SLOW;
  param[SLOW].diag      = DIAG_OFFSET_SLOW;
  param[FAST].vel       = VEL_FAST;
  param[FAST].ramp      = RAMP_RATE_FAST;
  param[FAST].thr       = THR_FAST;
  param[FAST].diag      = DIAG_OFFSET_FAST;  
  param[LUDICROUS].vel  = VEL_LUDICROUS;
  param[LUDICROUS].ramp = RAMP_RATE_LUDICROUS;
  param[LUDICROUS].thr  = THR_LUDICROUS;
  param[LUDICROUS].diag = DIAG_OFFSET_LUDICROUS;  

  // connect to TM1638 module
  // display a hexadecimal number and set the left 4 dots
  //tm1638.setDisplayToHexNumber(0x6CC, 0xF0);
  char s[8];
  sprintf(s, " HELLO ");
  tm1638.setDisplayToString(s);
  tm1638.setLEDs(0x0);
  delay(500);

  pinMode(BIGLIGHT_PIN, OUTPUT);
  // flush XBee serial stream before we get into loop()
  XBee.flush();
      
} // setup()
