#include "SamsungTV.h"

SamsungTV::SamsungTV(Stream &serial) {
	this->_serial = &serial;
}

void SamsungTV::power_toogle() {
	this->send(0x0, 0x0, 0x0, 0x0);
}

void SamsungTV::power_on() {
	this->send(0x0, 0x0, 0x0, 0x2);
}

void SamsungTV::power_off() {
	this->send(0x0, 0x0, 0x0, 0x1);
}

void SamsungTV::power(bool on) {
	if(on) {
		this->power_on();
	} else {
		this->power_off();
	}
}

void SamsungTV::mute_toogle() {
	this->send(0x02, 0x0, 0x0, 0x0);
}

void SamsungTV::volume_up() {
	this->send(0x01, 0x0, 0x1, 0x0);
}

void SamsungTV::volume_down() {
	this->send(0x01, 0x0, 0x2, 0x0);
}

void SamsungTV::volume(int volume) {
	this->send(0x01, 0x0, 0x0, volume);
}

void SamsungTV::channel_up() {
	this->send(0x03, 0x0, 0x1, 0x0);
}

void SamsungTV::channel_down() {
	this->send(0x03, 0x0, 0x2, 0x0);
}

void SamsungTV::channel(int channel) {
	this->send(0x04, 0x0, 0x0, channel);
}

void SamsungTV::source_tv() {
	this->send(0x0a, 0x0, 0x0, 0x0);
}

void SamsungTV::source_av(int value) {
	value--;
	this->send(0x0a, 0x0, 0x1, value);
}

void SamsungTV::source_svideo(int value) {
	value--;
	this->send(0x0a, 0x0, 0x2, value);
}

void SamsungTV::source_component(int value) {
	value--;
	this->send(0x0a, 0x0, 0x3, value);
}

void SamsungTV::source_pc() {
	this->send(0x0a, 0x0, 0x4, 0x0);
}

void SamsungTV::source_hdmi(int value) {
	value--;
	this->send(0x0a, 0x0, 0x5, value);
}

void SamsungTV::source_dvi(int value) {
	value--;
	this->send(0x0a, 0x0, 0x6, value);
}

void SamsungTV::source_rvu() {
	this->send(0x0a, 0x0, 0x7, 0x0);
}

void SamsungTV::key(int value) {
	this->send(0x0d, 0x0, 0x0, value);
}

void SamsungTV::send(int cmd1, int cmd2, int cmd3, int cmd4) {
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