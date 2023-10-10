void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void regulate(float Iout, float Vin, float Vout) {
  <br>  if((Vout>Vout_max) || (Iout>Iout_max) || ((Pin>Pin_previous && Vout_sense<Vout_last) || (Pin<Pin_previous && Vout_sense>Vout_last))) {
    if(duty_cycle>0) {
      duty_cycle -=1;
    }
    analogWrite(buck_pin,duty_cycle);
  } 

  else if ((Vout<Vout_max) && (Iout<Iout_max) && ( (Pin>Pin_previous && Vout_sense>Vout_last) || (Pin<Pin_previous && Vout_sense<Vout_last))){
    if(duty_cycle<240) {
      <br>    duty_cycle+=1;
    }
    analogWrite(buck_pin,duty_cycle);
  }

Pin_previous = Pin;
Vin_last = Vin;
Vout_last = Vout;

}