#ifndef __SAMSUNGTV_H__
#define __SAMSUNGTV_H__

#include <Arduino.h>
#include <Stream.h>

class SamsungTV {
	
public:
	/**
	 * Constructor
	 * @param  serial  Stream reference for transmit data
	 */
	SamsungTV(Stream &serial);
	/**
	 * Toogle TV on/off
	 */
	void power_toogle();
	/**
	 * Power on
	 */
	void power_on();
	/**
	 * Power off
	 */
	void power_off();
	/**
	 * Set power
	 * @param  on  power state
	 */
	void power(bool on);
	/**
	 * Toogle Mute
	 */
	void mute_toogle();
	/**
	 * Volume up
	 */
	void volume_up();
	/**
	 * Volume down
	 */
	void volume_down();
	/**
	 * Set volume in percent
	 * @param  volume  range 0-100%
	 */
	void volume(int volume);
	/**
	 * Channel up in TV mode
	 */
	void channel_up();
	/**
	 * Channel down in TV mode
	 */
	void channel_down();
	/**
	 * Set channel number in TV mode
	 * @param  channel  range 1-255
	 */
	void channel(int channel);
	/**
	 * Change source to TV
	 */
	void source_tv();
	/**
	 * Change source to AV
	 * @param  value  range > 1 (depend on your model)
	 */
	void source_av(int value);
	/**
	 * Change source to S-Video
	 * @param  value  range > 1 (depend on your model)
	 */
	void source_svideo(int value);
	/**
	 * Change source to Component
	 * @param  value  range > 1 (depend on your model)
	 */
	void source_component(int value);
	/**
	 * Change source to PC (VGA)
	 */
	void source_pc();
	/**
	 * Change source to HDMI
	 * @param  value  range > 1 (depend on your model)
	 */
	void source_hdmi(int value);
	/**
	 * Change source to DVI
	 * @param  value  range > 1 (depend on your model)
	 */
	void source_dvi(int value);
	/**
	 * Change source to RVU
	 */
	void source_rvu();
	/**
	 * Send virtual remote key
	 *
	 * Allow you to send key events like using a remote.
	 * Every model can have different keys. I have in remotecodes.txt some ids from my TV.
	 * Not avaibale are marked with "-". "?" Keys are avaibale but i don't know the real function.
	 * 
	 * @param  value  Id of key (depend on you model)
	 */
	void key(int value);
	void send(int cmd1, int cmd2, int cmd3, int cmd4);
	
private:
	/**
	 * Reference to a Stream class (like HardwareSerial, Softwareserial...)
	 */
	Stream *_serial;
	/**
	 * Calculate the checksum
	 * @param  cmds[]  all 6 cmds for calculation
	 */
	int _checksum(byte cmds[]);
};

#endif
