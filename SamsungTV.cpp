#include "SamsungTV.h"

SamsungTV::SamsungTV(Stream &serial) {
	this->_serial = &serial;
}

void SamsungTV::power_toogle() {
	this->execute(0x0, 0x0, 0x0, 0x0);
}

void SamsungTV::power_on() {
	this->execute(0x0, 0x0, 0x0, 0x2);
}

void SamsungTV::power_off() {
	this->execute(0x0, 0x0, 0x0, 0x1);
}

void SamsungTV::power(bool on) {
	if(on) {
		this->power_on();
	} else {
		this->power_off();
	}
}

void SamsungTV::mute_toogle() {
	this->execute(0x02, 0x0, 0x0, 0x0);
}

void SamsungTV::volume_up() {
	this->execute(0x01, 0x0, 0x1, 0x0);
}

void SamsungTV::volume_down() {
	this->execute(0x01, 0x0, 0x2, 0x0);
}

void SamsungTV::volume(int volume) {
	this->execute(0x01, 0x0, 0x0, volume);
}

void SamsungTV::channel_up() {
	this->execute(0x03, 0x0, 0x1, 0x0);
}

void SamsungTV::channel_down() {
	this->execute(0x03, 0x0, 0x2, 0x0);
}

void SamsungTV::channel(int channel) {
	this->execute(0x04, 0x0, 0x0, channel);
}

void SamsungTV::source(int value) {
	if (value == 0) {
		this->source_tv();
	} else if(value >= 10 && value <= 19) {
		this->source_av(value - 10);
	} else if(value >= 20 && value <= 29) {
		this->source_svideo(value - 20);
	} else if(value >= 30 && value <= 39) {
		this->source_component(value - 30);
	} else if(value >= 40 && value <= 49) {
		this->source_pc(value - 40);
	} else if(value >= 50 && value <= 59) {
		this->source_hdmi(value - 50);
	} else if(value >= 60 && value <= 69) {
		this->source_dvi(value - 60);
	} else if(value == 70) {
		this->source_rvu();
	}
}

void SamsungTV::source_tv() {
	this->execute(0x0a, 0x0, 0x0, 0x0);
}

void SamsungTV::source_av(int value) {
	if (value > 0 && value <= 3) return;

	value--;
	this->execute(0x0a, 0x0, 0x1, value);
}

void SamsungTV::source_svideo(int value) {
	if (value > 0 && value <= 3) return;

	value--;
	this->execute(0x0a, 0x0, 0x2, value);
}

void SamsungTV::source_component(int value) {
	if (value > 0 && value <= 3) return;

	value--;
	this->execute(0x0a, 0x0, 0x3, value);
}

void SamsungTV::source_pc(int value) {
	if (value > 0 && value <= 3) return;

	value--;
	this->execute(0x0a, 0x0, 0x4, value);
}

void SamsungTV::source_hdmi(int value) {
	if (value > 0 && value <= 4) return;

	value--;
	this->execute(0x0a, 0x0, 0x5, value);
}

void SamsungTV::source_dvi(int value) {
	if (value > 0 && value <= 3) return;

	value--;
	this->execute(0x0a, 0x0, 0x6, value);
}

void SamsungTV::source_rvu() {
	this->execute(0x0a, 0x0, 0x7, 0x0);
}

void SamsungTV::key(int value) {
	if (value > 0 && value <= 255) return;

	this->execute(0x0d, 0x0, 0x0, value);
}

void SamsungTV::execute(int cmd1, int cmd2, int cmd3, int cmd4) {
	byte cmds[7] = { 0x08, 0x22, cmd1, cmd2, cmd3, cmd4, 0x0 };

	// build checksum
	int chksum = this->_checksum(cmds);
	cmds[6] = chksum;
	
	this->_serial->write(cmds[0]);
	this->_serial->write(cmds[1]);
	this->_serial->write(cmds[2]);
	this->_serial->write(cmds[3]);
	this->_serial->write(cmds[4]);
	this->_serial->write(cmds[5]);
	this->_serial->write(cmds[6]);
}
	
int SamsungTV::_checksum(byte cmds[]) {
	int chksum = 256;
	for (int i = 0; i < 6; i = i + 1) {
		chksum -= cmds[i];
	}
	return chksum;
}