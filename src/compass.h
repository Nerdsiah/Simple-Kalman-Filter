/* Author = helscream (Omer Ikram ul Haq)
Last edit date = 2014-06-22
Website: http://hobbylogs.me.pn/?p=17
Location: Pakistan
Ver: 0.1 beta --- Start
Ver: 0.2 beta --- Debug feature included
*/
  
extern float heading;
extern float compass_x_scalled;
extern float compass_y_scalled;
extern float compass_z_scalled;
  
extern float compass_x_offset, compass_y_offset, compass_z_offset;
extern float compass_x_gainError,compass_y_gainError,compass_z_gainError;
  
extern uint8_t compass_debug;
  
void compass_read_XYZdata();
void compass_offset_calibration(uint8_t select);
void compass_init(uint8_t gain);
void compass_scalled_reading();
void compass_heading();
