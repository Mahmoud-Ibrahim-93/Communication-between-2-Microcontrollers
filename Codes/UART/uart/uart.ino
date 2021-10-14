// Arduino UART Tutorial

void setup() {
  pinMode(8, INPUT_PULLUP); // set push button pin as input
  pinMode(13, OUTPUT);      // set LED pin as output
  digitalWrite(13, LOW);    // switch off LED pin

  Serial1.begin(9600);       // initialize UART with baud rate of 9600 bps
}

void loop() {
  if (Serial1.available()) {
    char data_rcvd = Serial1.read();   // read one byte from serial buffer and save to data_rcvd

    if (data_rcvd == '1') digitalWrite(13, HIGH); // switch LED On
    if (data_rcvd == '0') digitalWrite(13, LOW);  // switch LED Off
  }

  if (digitalRead(8) == HIGH) Serial1.write('0');    // send the char '0' to serial if button is not pressed.
  else Serial1.write('1');                           // send the char '1' to serial if button is pressed.
}
