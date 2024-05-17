void setup() {
	Serial.begin(9600);
	digitalWrite(13, HIGH);
}

void loop() {
Serial.write(send_buffer[0xFE]);
Serial.write(send_buffer[0x01]);
Serial.write(send_buffer[0x02]);
Serial.write(send_buffer[0x03]);
Serial.write(send_buffer[0x04]);
Serial.write(send_buffer[0x05]);
Serial.write(send_buffer[0x06]);
Serial.write(send_buffer[0x07]);
Serial.write(send_buffer[0x08]);
Serial.write(send_buffer[0x09]);
Serial.write(send_buffer[0x0A]);
Serial.write(send_buffer[0x0B]);
Serial.write(send_buffer[0x8F]);
}
