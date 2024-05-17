long digit;
unsigned long score;
void setup() {
	Serial.begin(9600);
	digitalWrite(13, HIGH);
}

void loop() {
score = score + 100;
unsigned long previous_score = score;

int send_buffer[] = {0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x8F};

for (int u = 9; u > -1; u--) {
		digit = (int)(score / pow(10,u));
		send_buffer[11 - u] = (int) digit;
		score = score - (digit * (int)pow(10,u));
	}

Serial.write(send_buffer[0]);
Serial.write(send_buffer[1]);
Serial.write(send_buffer[2]);
Serial.write(send_buffer[3]);
Serial.write(send_buffer[4]);
Serial.write(send_buffer[5]);
Serial.write(send_buffer[6]);
Serial.write(send_buffer[7]);
Serial.write(send_buffer[8]);
Serial.write(send_buffer[9]);
Serial.write(send_buffer[10]);
Serial.write(send_buffer[11]);
Serial.write(send_buffer[12]);
Serial.write(send_buffer[13]);
delay(200);
score = previous_score;
}
