#ifndef __SAMSUNGTV_H__
#define __SAMSUNGTV_H__

#include <Arduino.h>
#include <Stream.h>

class SamsungTV {
	
public:
	SamsungTV(Stream &serial);
	void power_toogle();
	void power_on();
	void power_off();
	void power(bool on);
	void mute_toogle();
	void volume_up();
	void volume_down();
	void volume(int volume);
	void channel_up();
	void channel_down();
	void channel(int channel);
	void source_tv();
	void source_av(int value);
	void source_svideo(int value);
	void source_component(int value);
	void source_pc();
	void source_hdmi(int value);
	void source_dvi(int value);
	void source_rvu();
	void key(int value);
	void send(int cmd1, int cmd2, int cmd3, int cmd4);
	
private:
	Stream *_serial;
	bool _debug;
	int _checksum(byte cmds[]);
};

#endif
