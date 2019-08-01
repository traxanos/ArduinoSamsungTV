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
	 * Change source to a specific source (combined)
	 *
	 *  0 = TV
	 * 11 = AV 1
	 * 12 = AV 2
	 * 13 = AV 3
	 * 21 = S-Video 1
	 * 22 = S-Video 2
	 * 23 = S-Video 3
	 * 31 = Component 1
	 * 32 = Component 2
	 * 33 = Component 3
	 * 41 = PC 1
	 * 42 = PC 2
	 * 43 = PC 3
	 * 51 = HDMI 1
	 * 52 = HDMI 2
	 * 53 = HDMI 3
	 * 54 = HDMI 4
	 * 61 = DVI 1
	 * 62 = DVI 2
	 * 63 = DVI 3
	 * 70 = RVU
	 *
	 * @param  value
	 */
	void source(int value);
	/**
	 * Change source to TV
	 * @param  value  1-3 (depend on your model)
	 */
	void source_tv();
	/**
	 * Change source to AV
	 * @param  value  1-3 (depend on your model)
	 */
	void source_av(int value);
	/**
	 * Change source to S-Video
	 * @param  value  1-3 (depend on your model)
	 */
	void source_svideo(int value);
	/**
	 * Change source to Component
	 * @param  value  1-3 (depend on your model)
	 */
	void source_component(int value);
	/**
	 * Change source to PC (VGA)
	 * @param  value  1-3 (depend on your model)
	 */
	void source_pc(int value);
	/**
	 * Change source to HDMI
	 * @param  value  1-4 (depend on your model)
	 */
	void source_hdmi(int value);
	/**
	 * Change source to DVI
	 * @param  value  1-3 (depend on your model)
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
	void execute(int cmd1, int cmd2, int cmd3, int cmd4);
	
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
