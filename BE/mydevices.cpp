
#include "mydevices.h"

using namespace std;

//classe AnalogSensorTemperature
AnalogSensorTemperature::AnalogSensorTemperature(int d,int  t):Device(),val(t),temps(d){
  alea=1;
}

void AnalogSensorTemperature::run(){
  while(1){
    alea=1-alea;
    if(ptrmem!=NULL)
      *ptrmem=val+alea;
    sleep(temps);
  }
}


//classe AnalogSensorLuminosity
AnalogSensorLuminosity::AnalogSensorLuminosity(int data, int tps) : Device(), val(data), temps(tps) {
	alea = 1;
}

int AnalogSensorLuminosity::GetLuminosity() {
	return luminosite_environment;
}

void AnalogSensorLuminosity::run() {
	while (1) {
		alea = 1 - alea;
		if (ptrmem != NULL)
			*ptrmem = val + alea;
		sleep(temps);
	}
}



//classe DigitalActuatorLED
DigitalActuatorLED::DigitalActuatorLED(int t):Device(),state(LOW),temps(t){
}

void DigitalActuatorLED::run(){
  while(1){
    if(ptrmem!=NULL)
      state=*ptrmem;
    if (state==LOW)
      cout << "((((eteint))))\n";
    else
    cout << "((((allume))))\n";
    sleep(temps);
    }
}

//classe IntelligenteDigitalActuatorLED
IntelligenteDigitalActuatorLED::IntelligenteDigitalActuatorLED(int t) :Device(), state(LOW), temps(t) {
}

void IntelligenteDigitalActuatorLED::run() {
	while (1) {
		if (ptrmem != NULL)
			state = *ptrmem;
		if (state == LOW)
			cout << "((((eteint))))\n";
		luminosite_environment -= 50;
		else
			cout << "((((allume))))\n";
		luminosite_environment += 50;
		sleep(temps);
	}
}

// classe I2CActuatorScreen
I2CActuatorScreen::I2CActuatorScreen ():Device(){
  }

void I2CActuatorScreen::run(){
  while(1){
    if ( (i2cbus!=NULL)&&!(i2cbus->isEmptyRegister(i2caddr))){
      Device::i2cbus->requestFrom(i2caddr, buf, I2C_BUFFER_SIZE);
      cout << "---screen :"<< buf << endl;
    }
    sleep(1);
    }
}


//classe ExternalDigitalSensorButton
ExternalDigitalSensorButton::ExternalDigitalSensorButton() : Device() {
	stateButton = OFF;
}


void ExternalDigitalSensorButton::run() {
	while (1) {
		if (ptrmem != NULL)
			stateButton = *ptrmem;
		if (stateButton == ON)
			cout << "ON\n";
		else
			cout << "OFF\n";
		sleep(1);
	}
}

/*
void ExternalDigitalSensorButton::run() {
	while (1) {
		if (ifstream("on.txt"))
			stateButton = ON;
			cout << "ON\n";
		else
			stateButton = OFF;
			cout << "OFF\n";
		sleep(1);
	}
}
*/


