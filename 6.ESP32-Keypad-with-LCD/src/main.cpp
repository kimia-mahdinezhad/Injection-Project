#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <Wire.h>
#include <I2CKeyPad.h>

const unsigned char syringe_img[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x4a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x45, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x02, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x04, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x28, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x05, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x09, 0x56, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x2a, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x11, 0x05, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0xa5, 0xa8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x17, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0xcf, 0x78, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x05, 0xfe, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xfc, 0xff, 0x50, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x0a, 0xf5, 0xfe, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xab, 0xff, 0xd4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x02, 0x17, 0xff, 0x62, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xbd, 0xbf, 0xf4, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0e, 0xff, 0xd9, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0xa7, 0x7f, 0xfc, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x13, 0xab, 0xff, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0xdf, 0xfb, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0xef, 0xff, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x02, 0x35, 0xff, 0xc4, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x9b, 0xff, 0x72, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x4c, 0xdf, 0xe9, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x97, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xbf, 0xf6, 0xa0, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0xd7, 0xfd, 0x15, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xef, 0xfe, 0x8a, 0x10, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x57, 0x7b, 0xe7, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x39, 0xff, 0x2a, 0xa8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x96, 0xff, 0xd3, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2e, 0xdf, 0x69, 0xa8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x5f, 0xd5, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x29, 0xfd, 0xda, 0x90, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xd7, 0xe9, 0xa0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x77, 0xea, 0x88, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xbb, 0xf7, 0x20, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0xeb, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x47, 0xce, 0x50, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x31, 0x3d, 0x88, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xbc, 0xba, 0xd0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf3, 0xe5, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x1f, 0xcb, 0xe8, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4a, 0x90, 0xf5, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x22, 0xfc, 0xab, 0x50, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x80, 0x3e, 0x16, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x9f, 0xbf, 0xa8, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4f, 0x4d, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0xd6, 0xd0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x13, 0xe3, 0x48, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf5, 0xa0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2a, 0x66, 0x88, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x2b, 0x50, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x27, 0xbd, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0b, 0xfe, 0x40, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x17, 0xf9, 0x20, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xf8, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2b, 0xe4, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#define BLACK 0x0000
#define RED 0xF800
#define WHITE 0xFFFF

#define LCD_CS 33
#define LCD_RS 15
#define LCD_WR 4
#define LCD_RD 2
#define LCD_RESET 32

#define menu_page 0
#define setting_page 1
#define change_unit_page 11
#define change_unit_error_page 111
#define change_syringe_page 12
#define add_syringe_page 121
#define add_syringe_error_no_volume_page 1211
#define add_syringe_error_no_radius_page 1212
#define remove_syringe_page 122
#define new_injection_page 2
#define new_injection_error_no_time_or_volume_page 21
#define new_injection_error_both_time_and_volume_page 22
#define new_suction_page 3
#define new_suction_error_no_time_or_volume_page 31
#define new_suction_error_both_time_and_volume_page 32
#define progress_page_with_time 41
#define progress_page_with_volume 42
#define stop_page 51
#define end_page 52
#define button_start_page 61
#define button_finish_page 62
#define free_move_page 7

#define up_move 20
#define right_move 60
#define down_move 80
#define left_move 40
#define ok_move 50
#define erase_move 100

#define time_interrupt 10
#define volume_interrupt 11
#define button_interrupt 12

#define injection 0
#define suction 1

#define time_ 0
#define volume_ 1

void set_menu_page();
void update_menu_page(int);
void set_setting_page();
void update_setting_page(int);
void set_change_unit_page();
void update_change_unit_page(int);
void set_change_unit_error_page();
void update_change_unit_error_page(int);
void set_change_syringe_page();
void update_change_syringe_page(int);
void set_add_syringe_page();
void update_add_syringe_page(int);
void update_remove_syringe_page(int);
void set_add_syringe_error_no_volume_page();
void update_add_syringe_error_no_volume_page(int);
void set_add_syringe_error_no_radius_page();
void update_add_syringe_error_no_radius_page(int);
void set_remove_syringe_page();
void set_new_injection_page();
void update_new_injection_page(int);
void update_new_injection_error_no_time_page(int);
void set_new_injection_error_no_time_or_volume_page();
void update_new_injection_error_no_time_or_volume_page(int);
void set_new_injection_error_both_time_and_volume_page();
void update_new_injection_error_both_time_and_volume_page(int);
void set_new_suction_page();
void update_new_suction_page(int);
void set_new_suction_error_no_time_page();
void set_new_suction_error_no_time_or_volume_page();
void update_new_suction_error_no_time_or_volume_page(int);
void set_new_suction_error_both_time_and_volume_page();
void update_new_suction_error_both_time_and_volume_page(int);
void set_progress_page_with_time();
void update_progress_page_with_time(double, int);
void set_progress_page_with_volume();
void update_progress_page_with_volume(double, int);
void set_stop_page();
void update_stop_page(int);
void set_end_page();
void update_end_page(int);
void set_button_start_page();
void update_button_start_page(int);
void set_button_finish_page();
void update_button_finish_page(int);
void set_free_move_page();
void update_free_move_page(int);

void up();
void down();
void right();
void left();
void ok();
void enter(char);
void erase();

double calculate_height(double);
void stepper_move(int, int);

MCUFRIEND_kbv tft(LCD_CS, LCD_RS, LCD_WR, LCD_RD, LCD_RESET);

int program_state;
int injection_or_suction_flag, time_or_volume_flag;
bool new_injection_flag = false;
bool new_suction_flag = false;
bool add_syringe_flag = false;
bool change_unit_flag = false;

char available_volume_units[2][4] = {{"mL"}, {"muL"}};
int volume_unit = 0;
char available_time_units[3][4] = {{"sec"}, {"min"}, {"h"}};
int time_unit = 0;

double available_syringe_types[10][2];
int syringe = 4;
double temp_syringe_volume = 0, temp_syringe_radius = 0;
int syringe_volume_point_count = 0, syringe_radius_point_count = 0;

double input_time = 0, temp_time = 0;
int time_point_count = 0;
double input_volume = 0, temp_volume = 0;
int volume_point_count = 0;

double input_rate = 1, temp_rate = 0, useable_input_rate = 1;
int rate_point_count = 0;

double height = 0;

int temp_speed = 0;

const uint8_t KEYPAD_ADDRESS = 0x20;
I2CKeyPad keyPad(KEYPAD_ADDRESS);

char keys[] = "123A456B789C*0#DNF";

uint32_t lastKeyPressed = 0;

int current_button_row = 0;
int current_button_col[3] = {0};

hw_timer_t *timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

int r = 0, c = 0;

struct Button
{
    const uint8_t PIN;
    bool pressed;
    unsigned long last_button_time;
};

Button button_start = {34, false, 0};
Button button_finish = {35, false, 0};

double remaining_volume = 0, remaining_time = 0, current_rate = 0.1;
int volume_counter = 0, time_counter = 0;
int v_count = 0, t_count = 0;

char key = '\0';
bool char_flag = false;

void IRAM_ATTR button_start_press_interrupt()
{
    unsigned long button_time = millis();

    if (button_time - button_start.last_button_time > 250)
    {
        button_start.pressed = true;
        button_start.last_button_time = button_time;
        program_state = button_start_page;
        set_button_start_page();
    }
}

void IRAM_ATTR button_finish_press_interrupt()
{
    unsigned long button_time = millis();

    if (button_time - button_finish.last_button_time > 250)
    {
        button_finish.pressed = true;
        button_finish.last_button_time = button_time;
        program_state = button_finish_page;
        set_button_finish_page();
    }
}

void IRAM_ATTR onTimer()
{
    portENTER_CRITICAL_ISR(&timerMux);
    if (millis() - lastKeyPressed >= 200) // figure key
    {
        char_flag = true;
    }
    portEXIT_CRITICAL_ISR(&timerMux);
}

#define step 23
#define dir 18

void setup()
{
    uint16_t ID = tft.readID();

    pinMode(step, OUTPUT);
    pinMode(dir, OUTPUT);

    /* available syringe count */
    available_syringe_types[0][0] = 5;

    /* syringe 1 mL */
    int i = 1;
    available_syringe_types[i][0] = i;   // mL
    available_syringe_types[i][1] = 2.3; // r in mm

    /* syringe 2 mL */
    i++;
    available_syringe_types[i][0] = i;     // mL
    available_syringe_types[i][1] = 4.325; // r in mm

    /* syringe 3 mL */
    i++;
    available_syringe_types[i][0] = i;    // mL
    available_syringe_types[i][1] = 4.75; // r in mm

    /* syringe 4 mL */
    i++;
    available_syringe_types[i][0] = i; // mL
    available_syringe_types[i][1] = 3; // r in mm ??????????????????????????????????????????????????????//

    /* syringe 5 mL */
    i++;
    available_syringe_types[i][0] = i;    // mL
    available_syringe_types[i][1] = 6.65; // r in mm

    pinMode(button_start.PIN, INPUT);
    pinMode(button_finish.PIN, INPUT);
    attachInterrupt(button_start.PIN, button_start_press_interrupt, FALLING);
    attachInterrupt(button_finish.PIN, button_finish_press_interrupt, FALLING);

    tft.begin(ID);

    program_state = menu_page;
    set_menu_page();

    Serial.begin(9600);

    keyPad.begin();

    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 10000, true);
    timerAlarmEnable(timer);
}

void loop()
{
    if (char_flag)
    {
        int index = keyPad.getKey();
        if (index < 16)
        {
            key = keys[index];
        }
        lastKeyPressed = millis();

        char_flag = false;
    }

    if (key >= '0' && key <= '9') // enter
    {
        char key_copy = key;
        key = '\0';
        enter(key_copy);
    }
    else if (key == 'A') // up
    {
        key = '\0';
        up();
    }
    else if (key == 'B') // down
    {
        key = '\0';
        down();
    }
    else if (key == 'C') // right
    {
        key = '\0';
        right();
    }
    else if (key == 'D') // left
    {
        key = '\0';
        left();
    }
    else if (key == '#') // ok
    {
        key = '\0';
        ok();
    }
    else if (key == '*') // erase
    {
        key = '\0';
        erase();
    }
}

/* moves */
void up()
{
    if (program_state == menu_page)
    {
        update_menu_page(up_move);
    }
    else if (program_state == setting_page)
    {
        update_setting_page(up_move);
    }
    else if (program_state == change_unit_page)
    {
        update_change_unit_page(up_move);
    }
    else if (program_state == change_syringe_page)
    {
        update_change_syringe_page(up_move);
    }
    else if (program_state == remove_syringe_page)
    {
        update_remove_syringe_page(up_move);
    }
    else if (program_state == add_syringe_page)
    {
        update_add_syringe_page(up_move);
    }
    else if (program_state == new_injection_page)
    {
        update_new_injection_page(up_move);
    }
    else if (program_state == new_suction_page)
    {
        update_new_suction_page(up_move);
    }
    else if (program_state == stop_page)
    {
        update_stop_page(up_move);
    }
    else if (program_state == end_page)
    {
        update_end_page(up_move);
    }
    else if (program_state == free_move_page)
    {
        update_free_move_page(up_move);
    }
}

void down()
{
    if (program_state == menu_page)
    {
        update_menu_page(down_move);
    }
    else if (program_state == setting_page)
    {
        update_setting_page(down_move);
    }
    else if (program_state == change_unit_page)
    {
        update_change_unit_page(down_move);
    }
    else if (program_state == change_syringe_page)
    {
        update_change_syringe_page(down_move);
    }
    else if (program_state == add_syringe_page)
    {
        update_add_syringe_page(down_move);
    }
    else if (program_state == remove_syringe_page)
    {
        update_remove_syringe_page(down_move);
    }
    else if (program_state == new_injection_page)
    {
        update_new_injection_page(down_move);
    }
    else if (program_state == new_suction_page)
    {
        update_new_suction_page(down_move);
    }
    else if (program_state == stop_page)
    {
        update_stop_page(down_move);
    }
    else if (program_state == end_page)
    {
        update_end_page(down_move);
    }
    else if (program_state == free_move_page)
    {
        update_free_move_page(down_move);
    }
}

void right()
{
    if (program_state == change_unit_page)
    {
        update_change_unit_page(right_move);
    }
    else if (program_state == add_syringe_page)
    {
        update_add_syringe_page(right_move);
    }
    else if (program_state == new_injection_page)
    {
        update_new_injection_page(right_move);
    }
    else if (program_state == new_suction_page)
    {
        update_new_suction_page(right_move);
    }
}

void left()
{
    if (program_state == change_unit_page)
    {
        update_change_unit_page(left_move);
    }
}

void ok()
{
    if (program_state == menu_page)
    {
        update_menu_page(ok_move);
    }
    else if (program_state == setting_page)
    {
        update_setting_page(ok_move);
    }
    else if (program_state == change_unit_page)
    {
        update_change_unit_page(ok_move);
    }
    else if (program_state == change_unit_error_page)
    {
        update_change_unit_error_page(ok_move);
    }
    else if (program_state == change_syringe_page)
    {
        update_change_syringe_page(ok_move);
    }
    else if (program_state == add_syringe_page)
    {
        update_add_syringe_page(ok_move);
    }
    else if (program_state == add_syringe_error_no_volume_page)
    {
        update_add_syringe_error_no_volume_page(ok_move);
    }
    else if (program_state == add_syringe_error_no_radius_page)
    {
        update_add_syringe_error_no_radius_page(ok_move);
    }
    else if (program_state == remove_syringe_page)
    {
        update_remove_syringe_page(ok_move);
    }
    else if (program_state == new_injection_page)
    {
        update_new_injection_page(ok_move);
    }
    else if (program_state == new_injection_error_no_time_or_volume_page)
    {
        update_new_injection_error_no_time_or_volume_page(ok_move);
    }
    else if (program_state == new_injection_error_both_time_and_volume_page)
    {
        update_new_injection_error_both_time_and_volume_page(ok_move);
    }
    else if (program_state == new_suction_page)
    {
        update_new_suction_page(ok_move);
    }
    else if (program_state == new_suction_error_no_time_or_volume_page)
    {
        update_new_suction_error_no_time_or_volume_page(ok_move);
    }
    else if (program_state == new_suction_error_both_time_and_volume_page)
    {
        update_new_suction_error_both_time_and_volume_page(ok_move);
    }
    else if (program_state == progress_page_with_time)
    {
        update_progress_page_with_time(0, ok_move);
    }
    else if (program_state == progress_page_with_volume)
    {
        update_progress_page_with_volume(0, ok_move);
    }
    else if (program_state == stop_page)
    {
        update_stop_page(ok_move);
    }
    else if (program_state == end_page)
    {
        update_end_page(ok_move);
    }
    else if (program_state == button_start_page)
    {
        update_button_start_page(ok_move);
    }
    else if (program_state == button_finish_page)
    {
        update_button_finish_page(ok_move);
    }
    else if (program_state == free_move_page)
    {
        update_free_move_page(ok_move);
    }
}

void enter(char input_key)
{
    if (program_state == change_unit_page)
    {
        update_change_unit_page(input_key - '0');
    }
    else if (program_state == add_syringe_page)
    {
        update_add_syringe_page(input_key - '0');
    }
    else if (program_state == new_injection_page)
    {
        update_new_injection_page(input_key - '0');
    }
    else if (program_state == new_suction_page)
    {
        update_new_suction_page(input_key - '0');
    }
    else if (program_state == free_move_page)
    {
        update_free_move_page(input_key - '0');
    }
}

void erase()
{
    if (program_state == change_unit_page)
    {
        update_change_unit_page(erase_move);
    }
    else if (program_state == add_syringe_page)
    {
        update_add_syringe_page(erase_move);
    }
    else if (program_state == new_injection_page)
    {
        update_new_injection_page(erase_move);
    }
    else if (program_state == new_suction_page)
    {
        update_new_suction_page(erase_move);
    }
    else if (program_state == free_move_page)
    {
        update_free_move_page(erase_move);
    }
}

/* menu page */
void set_menu_page()
{
    tft.fillScreen(BLACK);

    tft.fillRoundRect(60, 250, 200, 40, 8, RED);

    int thick = 3;
    int radius = 8;
    for (int i = 0; i < thick; i++)
    {
        tft.drawRoundRect(60 + i, 250 + i, 200 - i * 2, 40 - i * 2, radius, WHITE);
    }

    tft.fillRoundRect(60, 300, 200, 40, 8, RED);

    tft.fillRoundRect(60, 350, 200, 40, 8, RED);

    tft.fillRoundRect(60, 400, 200, 40, 8, RED);

    tft.setTextColor(WHITE);

    tft.setCursor(50, 50);
    tft.setTextSize(3);
    tft.print("Project Name");

    tft.drawBitmap(100, 100, syringe_img, 100, 100, WHITE);

    tft.setTextSize(2);

    tft.setCursor(120, 265);
    tft.print("Setting");

    tft.setCursor(85, 315);
    tft.print("New Injection");

    tft.setCursor(95, 365);
    tft.print("New Suction");

    tft.setCursor(110, 415);
    tft.print("Free Move");
}

void update_menu_page(int move)
{
    if (move == up_move)
    {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 250;
            curr_row = 400;
            current_button_row = 3;
        }
        else if (current_button_row == 1)
        {
            last_row = 300;
            curr_row = 250;
            current_button_row = 0;
        }
        else if (current_button_row == 2)
        {
            last_row = 350;
            curr_row = 300;
            current_button_row = 1;
        }
        else
        {
            last_row = 400;
            curr_row = 350;
            current_button_row = 2;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    }
    else if (move == down_move)
    {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 250;
            curr_row = 300;
            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            last_row = 300;
            curr_row = 350;
            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {
            last_row = 350;
            curr_row = 400;
            current_button_row = 3;
        }
        else
        {
            last_row = 400;
            curr_row = 250;
            current_button_row = 0;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    }
    else if (move == ok_move)
    {
        if (current_button_row == 0)
        {
            program_state = setting_page;
            current_button_row = 0;
            set_setting_page();
        }
        else if (current_button_row == 1)
        {
            program_state = new_injection_page;
            current_button_row = 0;
            set_new_injection_page();
        }
        else if (current_button_row == 2)
        {
            program_state = new_suction_page;
            current_button_row = 0;
            set_new_suction_page();
        }
        else
        {
            program_state = free_move_page;
            current_button_row = 0;
            set_free_move_page();
        }
    }
}

/* setting page */
void set_setting_page()
{
    tft.fillScreen(BLACK);

    tft.fillRoundRect(60, 200, 200, 40, 8, RED);

    int thick = 3;
    int radius = 8;
    for (int i = 0; i < thick; i++)
    {
        tft.drawRoundRect(60 + i, 200 + i, 200 - i * 2, 40 - i * 2, radius, WHITE);
    }

    tft.fillRoundRect(60, 250, 200, 40, 8, RED);

    tft.fillRoundRect(60, 300, 200, 40, 8, RED);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    tft.setCursor(100, 215);
    tft.print("Change Unit");

    tft.setCursor(80, 265);
    tft.print("Change Syringe");

    tft.setCursor(135, 315);
    tft.print("Back");
}

void update_setting_page(int move)
{
    if (move == up_move)
    {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 200;
            curr_row = 300;
            current_button_row = 2;
        }
        else if (current_button_row == 1)
        {
            last_row = 250;
            curr_row = 200;
            current_button_row = 0;
        }
        else
        {
            last_row = 300;
            curr_row = 250;
            current_button_row = 1;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    }
    else if (move == down_move)
    {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 200;
            curr_row = 250;
            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            last_row = 250;
            curr_row = 300;
            current_button_row = 2;
        }
        else
        {
            last_row = 300;
            curr_row = 200;
            current_button_row = 0;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    }
    else if (move == ok_move)
    {
        if (current_button_row == 0)
        {
            program_state = change_unit_page;
            current_button_row = 0;
            current_button_col[0] = time_unit;
            current_button_col[1] = volume_unit;
            set_change_unit_page();
        }
        else if (current_button_row == 1)
        {
            program_state = change_syringe_page;
            current_button_row = syringe - 1;
            set_change_syringe_page();
        }
        else
        {
            program_state = menu_page;
            current_button_row = 0;
            set_menu_page();
        }
    }
}

/* change unit page */
void set_change_unit_page()
{
    tft.fillScreen(BLACK);
    int thikness = 3;

    /* volume */
    tft.fillRect(93, 42, 120, 35, RED);

    tft.setTextSize(3);
    tft.setTextColor(BLACK);
    int row = 50;
    tft.setCursor(100, row);
    tft.print("Volume");

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    tft.setCursor(90, row += 35);
    tft.print("mL");

    tft.setCursor(180, row);
    tft.print("muL");

    if (volume_unit == 0)
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(87, 105 + i, 115, 105 + i, WHITE);
        }
    }
    else
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(177, 105 + i, 215, 105 + i, WHITE);
        }
    }

    /* time */
    tft.setTextSize(3);
    tft.setTextColor(RED);
    row += 70;
    tft.setCursor(120, row);
    tft.print("Time");

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    tft.setCursor(40, row += 35);
    tft.print("sec");

    tft.setCursor(150, row);
    tft.print("min");

    tft.setCursor(260, row);
    tft.print("h");

    if (time_unit == 0)
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(37, 210 + i, 77, 210 + i, WHITE);
        }
    }
    else if (time_unit == 1)
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(147, 210 + i, 187, 210 + i, WHITE);
        }
    }
    else
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(257, 210 + i, 270, 210 + i, WHITE);
        }
    }

    tft.setCursor(20, 260);
    tft.print("Volume Flow Rate:");
    tft.drawRect(20, 280, 230, 30, WHITE);
    tft.setTextSize(1);
    tft.setCursor(255, 290);
    tft.printf("%s/%s", available_volume_units[volume_unit], available_time_units[time_unit]);
    tft.setTextSize(2);

    tft.fillRoundRect(60, 370, 200, 40, 8, RED);

    tft.setCursor(135, 385);
    tft.print("Apply");

    tft.fillRoundRect(60, 420, 200, 40, 8, RED);

    tft.setCursor(135, 435);
    tft.print("Back");
}

void update_change_unit_page(int move)
{
    if (move == up_move)
    {
        if (current_button_row == 0)
        {
            tft.fillRect(93, 42, 120, 35, BLACK);

            tft.setTextSize(3);
            tft.setTextColor(RED);
            tft.setCursor(100, 50);
            tft.print("Volume");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 420 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }
        else if (current_button_row == 1)
        {
            tft.fillRect(113, 147, 85, 35, BLACK);

            tft.setTextSize(3);
            tft.setTextColor(RED);
            tft.setCursor(120, 155);
            tft.print("Time");

            tft.fillRect(93, 42, 120, 35, RED);

            tft.setTextSize(3);
            tft.setTextColor(BLACK);
            tft.setCursor(100, 50);
            tft.print("Volume");

            current_button_row = 0;
        }
        else if (current_button_row == 2)
        {
            tft.setCursor(20, 260);
            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            tft.print("Volume Flow Rate:");

            tft.fillRect(113, 147, 85, 35, RED);

            tft.setTextSize(3);
            tft.setTextColor(BLACK);
            tft.setCursor(120, 155);
            tft.print("Time");

            current_button_row = 1;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 370 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            tft.setCursor(20, 260);
            tft.setTextSize(2);
            tft.setTextColor(RED);
            tft.print("Volume Flow Rate:");

            current_button_row = 2;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 420 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 370 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
    }
    else if (move == right_move)
    {
        if (current_button_row == 0)
        {
            if (current_button_col[1] == 0)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(87, 105 + i, 115, 105 + i, BLACK);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(177, 105 + i, 215, 105 + i, WHITE);
                }

                current_button_col[1] = 1;
            }
            else
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(87, 105 + i, 115, 105 + i, WHITE);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(177, 105 + i, 215, 105 + i, BLACK);
                }

                current_button_col[1] = 0;
            }
        }
        else if (current_button_row == 1)
        {
            if (current_button_col[0] == 0)
            {
                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(37, 210 + i, 77, 210 + i, BLACK);
                }

                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(147, 210 + i, 187, 210 + i, WHITE);
                }

                current_button_col[0] = 1;
            }
            else if (current_button_col[0] == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(147, 210 + i, 187, 210 + i, BLACK);
                }

                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(257, 210 + i, 270, 210 + i, WHITE);
                }

                current_button_col[0] = 2;
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(257, 210 + i, 270, 210 + i, BLACK);
                }

                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(37, 210 + i, 77, 210 + i, WHITE);
                }

                current_button_col[0] = 0;
            }
        }
        else if (current_button_row == 2)
        {
            if (rate_point_count == 0)
            {
                tft.fillRect(20, 280, 230, 30, BLACK);
                tft.drawRect(20, 280, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 288);
                tft.printf("%.1f", temp_rate);

                rate_point_count++;
            }
        }
    }
    else if (move == down_move)
    {
        if (current_button_row == 0)
        {
            tft.fillRect(93, 42, 120, 35, BLACK);

            tft.setTextSize(3);
            tft.setTextColor(RED);
            tft.setCursor(100, 50);
            tft.print("Volume");

            tft.fillRect(113, 147, 85, 35, RED);

            tft.setTextSize(3);
            tft.setTextColor(BLACK);
            tft.setCursor(120, 155);
            tft.print("Time");

            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            tft.fillRect(113, 147, 85, 35, BLACK);

            tft.setTextSize(3);
            tft.setTextColor(RED);
            tft.setCursor(120, 155);
            tft.print("Time");

            tft.setTextSize(2);
            tft.setTextColor(RED);
            tft.setCursor(20, 260);
            tft.print("Volume Flow Rate:");

            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {

            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            tft.setCursor(20, 260);
            tft.print("Volume Flow Rate:");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 370 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 370 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 420 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 420 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            tft.fillRect(93, 42, 120, 35, RED);

            tft.setTextSize(3);
            tft.setTextColor(BLACK);
            tft.setCursor(100, 50);
            tft.print("Volume");

            current_button_row = 0;
        }
    }
    else if (move == left_move)
    {
        if (current_button_row == 0)
        {
            if (current_button_col[1] == 0)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(87, 105 + i, 115, 105 + i, BLACK);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(177, 105 + i, 215, 105 + i, WHITE);
                }

                current_button_col[1] = 1;
            }
            else
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(87, 105 + i, 115, 105 + i, WHITE);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(177, 105 + i, 215, 105 + i, BLACK);
                }

                current_button_col[1] = 0;
            }
        }
        else if (current_button_row == 1)
        {
            if (current_button_col[0] == 0)
            {
                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(37, 210 + i, 77, 210 + i, BLACK);
                }

                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(257, 210 + i, 270, 210 + i, WHITE);
                }

                current_button_col[0] = 2;
            }
            else if (current_button_col[0] == 1)
            {
                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(147, 210 + i, 187, 210 + i, BLACK);
                }

                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(37, 210 + i, 77, 210 + i, WHITE);
                }

                current_button_col[0] = 0;
            }
            else
            {
                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(257, 210 + i, 270, 210 + i, BLACK);
                }

                for (int i = 0; i < 3; i++)
                {
                    tft.drawLine(147, 210 + i, 187, 210 + i, WHITE);
                }

                current_button_col[0] = 1;
            }
        }
    }
    else if (move == erase_move)
    {
        tft.fillRect(20, 280, 230, 30, BLACK);
        tft.drawRect(20, 280, 230, 30, WHITE);

        temp_rate = 0;
        rate_point_count = 0;
    }
    else if (move == ok_move)
    {
        if (current_button_row == 3)
        {
            time_unit = current_button_col[0];
            volume_unit = current_button_col[1];

            input_rate = temp_rate;
            useable_input_rate = input_rate;

            if (volume_unit == 1)
            {
                useable_input_rate /= 1000;
            }

            if (time_unit == 0)
            {
                useable_input_rate /= 60;
            }
            else if (time_unit == 2)
            {
                useable_input_rate *= 60;
            }

            current_button_row = 0;

            if (new_injection_flag)
            {
                program_state = new_injection_page;
                set_new_injection_page();
            }
            else if (new_suction_flag)
            {
                program_state = new_suction_page;
                set_new_suction_page();
            }
            else
            {
                program_state = setting_page;
                set_setting_page();
            }
        }
        else if (current_button_row == 4)
        {
            current_button_row = 0;
            if (new_injection_flag)
            {
                program_state = new_injection_page;
                set_new_injection_page();
            }
            else if (new_suction_flag)
            {
                program_state = new_suction_page;
                set_new_suction_page();
            }
            else
            {
                program_state = setting_page;
                set_setting_page();
            }
        }
    }
    else
    {
        if (current_button_row == 2)
        {
            if (rate_point_count == 0)
            {
                temp_rate *= 10;
                temp_rate += move;

                tft.fillRect(20, 280, 230, 30, BLACK);
                tft.drawRect(20, 280, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 288);
                tft.printf("%.0f", temp_rate);
            }
            else if (rate_point_count == 1)
            {
                temp_rate = temp_rate + (double(move) / 10.0);
                tft.fillRect(20, 280, 230, 30, BLACK);
                tft.drawRect(20, 280, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 288);
                tft.printf("%.1f", temp_rate);
                rate_point_count++;
            }
            else if (rate_point_count == 2)
            {
                temp_rate = temp_rate + (double(move) / 100.0);
                tft.fillRect(20, 280, 230, 30, BLACK);
                tft.drawRect(20, 280, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 288);
                tft.printf("%.2f", temp_rate);
                rate_point_count++;
            }
        }
    }
}

/* change unit error page */
void set_change_unit_error_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* volume */
    int row = 180, col = 80;
    tft.setCursor(col, row);
    tft.print("Please Enter ");

    row = 210, col = 120;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(RED);
    tft.print("Rate");

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}

void update_change_unit_error_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = change_unit_page;
        current_button_row = 0;
        rate_point_count = 0;
        set_change_unit_page();
    }
}

/* change syringe page */
void set_change_syringe_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);

    int syringe_count = available_syringe_types[0][0];
    int row_diff = int(370 / syringe_count);
    int col = 10, row = 30;

    for (int i = 1; i <= syringe_count; i++)
    {
        if (syringe == i)
        {
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[i][0], available_syringe_types[i][1]);
        }
        else
        {
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[i][0], available_syringe_types[i][1]);
        }

        row += row_diff;
    }

    tft.fillRoundRect(60, 350, 200, 40, 8, RED);

    tft.setCursor(145, 365);
    tft.print("Add");

    tft.fillRoundRect(60, 395, 200, 40, 8, RED);

    tft.setCursor(125, 410);
    tft.print("remove");

    tft.fillRoundRect(60, 440, 200, 40, 8, RED);

    tft.setCursor(135, 455);
    tft.print("Back");
}

void update_change_syringe_page(int move)
{
    if (move == up_move)
    {
        int syringe_count = available_syringe_types[0][0];
        int row_diff = int(370 / syringe_count);

        if (current_button_row == 0)
        {
            int col = 10, row = 30;
            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[1][0], available_syringe_types[1][1]);

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = syringe_count + 2;
        }
        else if (current_button_row == syringe_count)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 350 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            int col = 10, row = 30 + (syringe_count - 1) * row_diff;
            tft.setTextSize(2);
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[syringe_count][0], available_syringe_types[syringe_count][1]);

            current_button_row--;
        }
        else if (current_button_row == syringe_count + 1)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 395 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 350 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row--;
        }
        else if (current_button_row == syringe_count + 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 395 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row--;
        }
        else
        {
            tft.setTextSize(2);

            int col = 10, row = 30 + (current_button_row)*row_diff;
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[current_button_row + 1][0], available_syringe_types[current_button_row + 1][1]);

            row -= row_diff;
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[current_button_row][0], available_syringe_types[current_button_row][1]);

            current_button_row--;
        }
    }
    else if (move == down_move)
    {
        int syringe_count = available_syringe_types[0][0];
        int row_diff = int(370 / syringe_count);

        if (current_button_row == syringe_count - 1)
        {
            int col = 10, row = 30 + (syringe_count - 1) * row_diff;
            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[syringe_count][0], available_syringe_types[syringe_count][1]);

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 350 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row++;
        }
        else if (current_button_row == syringe_count)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 350 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 395 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row++;
        }
        else if (current_button_row == syringe_count + 1)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 395 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row++;
        }
        else if (current_button_row == syringe_count + 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            int col = 10, row = 30;
            tft.setTextSize(2);
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[1][0], available_syringe_types[1][1]);

            current_button_row = 0;
        }
        else
        {
            tft.setTextSize(2);

            int col = 10, row = 30 + (current_button_row)*row_diff;
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[current_button_row + 1][0], available_syringe_types[current_button_row + 1][1]);

            row += row_diff;
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[current_button_row + 2][0], available_syringe_types[current_button_row + 2][1]);

            current_button_row++;
        }
    }
    else if (move == ok_move)
    {
        int syringe_count = available_syringe_types[0][0];

        if (current_button_row == syringe_count)
        {
            current_button_row = 0;
            program_state = add_syringe_page;
            set_add_syringe_page();
        }
        else if (current_button_row == syringe_count + 1)
        {
            current_button_row = 0;
            program_state = remove_syringe_page;
            set_remove_syringe_page();
        }
        else if (current_button_row == syringe_count + 2)
        {
            current_button_row = 0;
            if (new_injection_flag)
            {
                program_state = new_injection_page;
                set_new_injection_page();
            }
            else if (new_suction_flag)
            {
                program_state = new_suction_page;
                set_new_suction_page();
            }
            else
            {
                program_state = setting_page;
                set_setting_page();
            }
        }
        else
        {
            syringe = current_button_row + 1;
            current_button_row = 0;

            if (new_injection_flag)
            {
                program_state = new_injection_page;
                set_new_injection_page();
            }
            else if (new_suction_flag)
            {
                program_state = new_suction_page;
                set_new_suction_page();
            }
            else
            {
                program_state = setting_page;
                set_setting_page();
            }
        }
    }
}

/* add syringe page */
void set_add_syringe_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);

    tft.setTextColor(WHITE);

    int unit_col = 255;
    int box_col = 20;

    /* time */
    int row, col;
    if (current_button_row == 0)
    {
        tft.setTextColor(RED);
        row = 50, col = 20;
        tft.setCursor(col, row);
        tft.print("Syringe Volume:");
    }
    else
    {
        row = 50, col = 20;
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        tft.print("Syringe Volume:");
    }

    row += 20;
    tft.drawRect(box_col, row, 230, 30, WHITE);

    /* volume */
    if (current_button_row == 1)
    {
        tft.setTextColor(RED);
        row = 120, col = 20;
        tft.setCursor(col, row);
        tft.print("Syringe Radius:");
    }
    else
    {
        tft.setTextColor(WHITE);
        row = 120, col = 20;
        tft.setCursor(col, row);
        tft.print("Syringe Radius:");
    }

    row += 20;
    tft.drawRect(box_col, row, 230, 30, WHITE);

    if (add_syringe_flag)
    {
        if (temp_syringe_volume != 0)
        {
            tft.setCursor(24, 78);
            tft.printf("%.2f", temp_syringe_volume);
        }

        if (temp_syringe_radius != 0)
        {
            tft.setCursor(24, 148);
            tft.printf("%.2f", temp_syringe_radius);
        }

        add_syringe_flag = false;
    }

    tft.fillRoundRect(60, 385, 200, 40, 8, RED);

    tft.setCursor(145, 400);
    tft.print("Add");

    tft.fillRoundRect(60, 430, 200, 40, 8, RED);

    tft.setCursor(135, 445);
    tft.print("Back");
}

void update_add_syringe_page(int move_or_number)
{
    if (move_or_number == up_move)
    {
        if (current_button_row == 0)
        {
            int row = 50, col = 20;
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.print("Syringe Volume:");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 1)
        {
            int row = 50, col = 20;
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.print("Syringe Volume:");

            row = 120, col = 20;
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.print("Syringe Radius:");

            current_button_row = 0;
        }
        else if (current_button_row == 2)
        {
            int row = 120, col = 20;
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.print("Syringe Radius:");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 385 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            current_button_row = 1;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 385 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
    }
    else if (move_or_number == down_move)
    {
        if (current_button_row == 0)
        {
            int row = 50, col = 20;
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.print("Syringe Volume:");

            row = 120, col = 20;
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.print("Syringe Radius:");

            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            int row = 120, col = 20;
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.print("Syringe Radius:");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 385 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 385 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            int row = 50, col = 20;
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.print("Syringe Volume:");

            current_button_row = 0;
        }
    }
    else if (move_or_number == right_move)
    {
        if (current_button_row == 0)
        {
            if (syringe_volume_point_count == 0)
            {
                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.1f", temp_syringe_volume);

                syringe_volume_point_count++;
            }
        }
        else if (current_button_row == 1)
        {
            if (syringe_radius_point_count == 0)
            {
                tft.fillRect(20, 140, 230, 30, BLACK);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.1f", temp_syringe_radius);

                syringe_radius_point_count++;
            }
        }
    }
    else if (move_or_number == ok_move)
    {
        if (current_button_row == 2)
        {
            if (temp_syringe_volume == double(0))
            {
                program_state = add_syringe_error_no_volume_page;
                current_button_row = 0;
                set_add_syringe_error_no_volume_page();
            }
            else if (temp_syringe_radius == double(0))
            {
                program_state = add_syringe_error_no_radius_page;
                current_button_row = 0;
                set_add_syringe_error_no_radius_page();
            }
            else
            {
                program_state = change_syringe_page;
                current_button_row = syringe - 1;
                available_syringe_types[0][0]++;
                available_syringe_types[int(available_syringe_types[0][0])][0] = temp_syringe_volume;
                available_syringe_types[int(available_syringe_types[0][0])][1] = temp_syringe_radius;
                set_change_syringe_page();
            }
        }
        else if (current_button_row == 3)
        {
            program_state = change_syringe_page;
            temp_syringe_volume = 0;
            temp_syringe_radius = 0;
            current_button_row = syringe - 1;
            set_change_syringe_page();
        }
    }
    else if (move_or_number == erase_move)
    {
        if (current_button_row == 0)
        {
            tft.fillRect(20, 70, 230, 30, BLACK);
            tft.drawRect(20, 70, 230, 30, WHITE);

            temp_syringe_volume = 0;
            syringe_volume_point_count = 0;
        }
        else if (current_button_row == 1)
        {
            tft.fillRect(20, 170, 230, 30, BLACK);
            tft.drawRect(20, 170, 230, 30, WHITE);

            temp_syringe_radius = 0;
            syringe_radius_point_count = 0;
        }
    }
    else
    {
        if (current_button_row == 0)
        {
            if (syringe_volume_point_count == 0)
            {
                temp_syringe_volume *= 10;
                temp_syringe_volume += move_or_number;

                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.0f", temp_syringe_volume);
            }
            else if (syringe_volume_point_count == 1)
            {
                temp_syringe_volume = temp_syringe_volume + (double(move_or_number) / 10.0);
                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.1f", temp_syringe_volume);
                syringe_volume_point_count++;
            }
            else if (syringe_volume_point_count == 2)
            {
                temp_syringe_volume = temp_syringe_volume + (double(move_or_number) / 100.0);
                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.2f", temp_syringe_volume);
                syringe_volume_point_count++;
            }
        }
        else if (current_button_row == 1)
        {
            if (syringe_radius_point_count == 0)
            {
                temp_syringe_radius *= 10;
                temp_syringe_radius += move_or_number;

                tft.fillRect(20, 140, 230, 30, BLACK);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.0f", temp_syringe_radius);
            }
            else if (syringe_radius_point_count == 1)
            {
                temp_syringe_radius = temp_syringe_radius + (double(move_or_number) / 10.0);
                tft.fillRect(20, 140, 230, 30, BLACK);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.1f", temp_syringe_radius);
                syringe_radius_point_count++;
            }
            else if (syringe_radius_point_count == 2)
            {
                temp_syringe_radius = temp_syringe_radius + (double(move_or_number) / 100.0);
                tft.fillRect(20, 140, 230, 30, BLACK);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.2f", temp_syringe_radius);
                syringe_radius_point_count++;
            }
        }
    }
}

/* add syringe error no volume page */
void set_add_syringe_error_no_volume_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* volume */
    int row = 180, col = 80;
    tft.setCursor(col, row);
    tft.print("Please Enter ");

    row = 210, col = 100;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(RED);
    tft.print("Volume");

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}

void update_add_syringe_error_no_volume_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = add_syringe_page;
        current_button_row = 0;
        syringe_volume_point_count = 0;
        add_syringe_flag = true;
        set_add_syringe_page();
    }
}

/* add syringe error no radius page */
void set_add_syringe_error_no_radius_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* error */
    int row = 180, col = 80;
    tft.setCursor(col, row);
    tft.print("Please Enter");

    row = 210, col = 100;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(RED);
    tft.print("Radius");

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}

void update_add_syringe_error_no_radius_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = add_syringe_page;
        current_button_row = 0;
        syringe_radius_point_count = 0;
        add_syringe_flag = true;
        set_add_syringe_page();
    }
}

/* add syringe page */
void set_remove_syringe_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);

    int syringe_count = available_syringe_types[0][0];
    int row_diff = int(370 / syringe_count);
    int col = 10, row = 30;

    tft.setTextColor(RED);
    tft.setCursor(col, row);
    tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[1][0], available_syringe_types[1][1]);

    row += row_diff;

    for (int i = 2; i <= syringe_count; i++)
    {
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[i][0], available_syringe_types[i][1]);

        row += row_diff;
    }

    tft.fillRoundRect(60, 430, 200, 40, 8, RED);

    tft.setCursor(135, 445);
    tft.print("Back");
}

void update_remove_syringe_page(int move)
{
    if (move == up_move)
    {
        int syringe_count = available_syringe_types[0][0];
        int row_diff = int(370 / syringe_count);

        if (current_button_row == 0)
        {
            int col = 10, row = 30;
            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[1][0], available_syringe_types[1][1]);

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = syringe_count;
        }
        else if (current_button_row == syringe_count)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            int col = 10, row = 30 + (syringe_count - 1) * row_diff;
            tft.setTextSize(2);
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[syringe_count][0], available_syringe_types[syringe_count][1]);

            current_button_row--;
        }
        else if (current_button_row == syringe_count + 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 395 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row--;
        }
        else
        {
            tft.setTextSize(2);

            int col = 10, row = 30 + (current_button_row)*row_diff;
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[current_button_row + 1][0], available_syringe_types[current_button_row + 1][1]);

            row -= row_diff;
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[current_button_row][0], available_syringe_types[current_button_row][1]);

            current_button_row--;
        }
    }
    else if (move == down_move)
    {
        int syringe_count = available_syringe_types[0][0];
        int row_diff = int(370 / syringe_count);

        if (current_button_row == syringe_count - 1)
        {
            int col = 10, row = 30 + (syringe_count - 1) * row_diff;
            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[syringe_count][0], available_syringe_types[syringe_count][1]);

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row++;
        }
        else if (current_button_row == syringe_count)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            int col = 10, row = 30;
            tft.setTextSize(2);
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[1][0], available_syringe_types[1][1]);

            current_button_row = 0;
        }
        else
        {
            tft.setTextSize(2);

            int col = 10, row = 30 + (current_button_row)*row_diff;
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[current_button_row + 1][0], available_syringe_types[current_button_row + 1][1]);

            row += row_diff;
            tft.setTextColor(RED);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[current_button_row + 2][0], available_syringe_types[current_button_row + 2][1]);

            current_button_row++;
        }
    }
    else if (move == ok_move)
    {
        int syringe_count = available_syringe_types[0][0];
        if (current_button_row == syringe_count)
        {
            program_state = change_syringe_page;
            current_button_row = syringe - 1;
            set_change_syringe_page();
        }
        else
        {
            available_syringe_types[0][0]--;

            for (int i = current_button_row + 2; i <= syringe_count; i++)
            {
                available_syringe_types[i - 1][0] = available_syringe_types[i][0];
                available_syringe_types[i - 1][1] = available_syringe_types[i][1];
            }

            available_syringe_types[syringe_count][0] = 0;
            available_syringe_types[syringe_count][1] = 0;

            if (syringe - 1 == current_button_row)
            {
                syringe = 1;
            }
            else if (syringe - 1 > current_button_row)
            {
                syringe--;
            }

            program_state = change_syringe_page;
            current_button_row = syringe - 1;
            set_change_syringe_page();
        }
    }
}

/* new injection page */
void set_new_injection_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(3);
    tft.setTextColor(RED);
    int row = 10, col = 70;
    tft.setCursor(col, row);
    tft.print("Injection");
    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    int unit_col = 255;
    int box_col = 20;

    /* time */
    if (current_button_row == 0)
    {
        tft.setTextColor(RED);
        row = 50, col = 20;
        tft.setCursor(col, row);
        tft.print("Time:");
        tft.setTextColor(WHITE);
    }
    else
    {
        row = 50, col = 20;
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        tft.print("Time:");
    }

    row += 20;
    tft.drawRect(box_col, row, 230, 30, WHITE);

    tft.setTextSize(1);
    tft.setCursor(unit_col, row + 10);
    tft.print(available_time_units[time_unit]);
    tft.setTextSize(2);

    /* or */
    tft.setTextSize(1);
    tft.setCursor(20, 125);
    tft.print("OR");
    tft.setTextSize(2);

    /* volume */
    if (current_button_row == 1)
    {
        tft.setTextColor(RED);
        row = 150, col = 20;
        tft.setCursor(col, row);
        tft.print("Volume:");
        tft.setTextColor(WHITE);
    }
    else
    {
        tft.setTextColor(WHITE);
        row = 150, col = 20;
        tft.setCursor(col, row);
        tft.print("Volume:");
    }

    row += 20;
    tft.drawRect(box_col, row, 230, 30, WHITE);

    tft.setTextSize(1);
    tft.setCursor(unit_col, row + 10);
    tft.print(available_volume_units[volume_unit]);
    tft.setTextSize(2);

    /* Syringe */
    row += 70, col = 20;
    tft.setCursor(col, row);
    tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[syringe][0], available_syringe_types[syringe][1]);

    row += 20, col = 20;
    tft.setCursor(col, row);
    tft.printf("Rate %.2f %s/%s", input_rate, available_volume_units[volume_unit], available_time_units[time_unit]);

    if (new_injection_flag)
    {
        if (temp_time != 0)
        {
            tft.setCursor(24, 78);
            tft.printf("%.2f", temp_time);
        }

        if (temp_volume != 0)
        {
            tft.setCursor(24, 1478);
            tft.printf("%.2f", temp_volume);
        }

        new_injection_flag = false;
    }

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    col = 95, row = 320;
    tft.setCursor(col, row);
    tft.print("Change Unit");

    col = 78, row += diff;
    tft.setCursor(col, row);
    tft.print("Change Syringe");

    col = 125, row += diff;
    tft.setCursor(col, row);
    tft.print("Create");

    col = 135, row += diff;
    tft.setCursor(col, row);
    tft.print("Back");
}

void update_new_injection_page(int move_or_number)
{
    if (move_or_number == up_move)
    {
        int last_row, last_col = 20, curr_row, Curr_col = 20;

        char last_message[100];
        char curr_message[100];

        if (current_button_row == 0)
        {
            last_row = 50;
            sprintf(last_message, "Time:");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 433 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else if (current_button_row == 1)
        {
            last_row = 150;
            sprintf(last_message, "Volume:");
            curr_row = 50;
            sprintf(curr_message, "Time:");
            current_button_row = 0;
        }
        else if (current_button_row == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            curr_row = 150;
            sprintf(curr_message, "Volume:");

            current_button_row = 1;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 433 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }

        if (current_button_row == 1)
        {
            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
        else if (current_button_row == 5)
        {
            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);
        }
        else if (current_button_row == 0)
        {
            tft.setTextSize(2);

            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);

            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
    }
    else if (move_or_number == down_move)
    {
        int last_row, last_col = 20, curr_row, Curr_col = 20;

        char last_message[100];
        char curr_message[100];

        if (current_button_row == 0)
        {
            last_row = 50;
            sprintf(last_message, "Time:");
            curr_row = 150;
            sprintf(curr_message, "Volume:");

            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            last_row = 150;
            sprintf(last_message, "Volume:");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 433 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 433 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            curr_row = 50;
            sprintf(curr_message, "Time:");

            current_button_row = 0;
        }

        if (current_button_row == 0)
        {
            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
        else if (current_button_row == 2)
        {
            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);
        }
        else if (current_button_row == 1)
        {
            tft.setTextSize(2);

            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);

            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
    }
    else if (move_or_number == right_move)
    {
        if (current_button_row == 0)
        {
            if (time_point_count == 0)
            {
                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.1f", temp_time);

                time_point_count++;
            }
        }
        else if (current_button_row == 1)
        {
            if (volume_point_count == 0)
            {
                tft.fillRect(20, 170, 230, 30, BLACK);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.1f", temp_volume);

                volume_point_count++;
            }
        }
    }
    else if (move_or_number == ok_move)
    {
        if (current_button_row == 2) // Change Unit
        {
            program_state = change_unit_page;
            current_button_row = 0;
            new_injection_flag = true;
            current_button_col[0] = time_unit;
            current_button_col[1] = volume_unit;
            set_change_unit_page();
        }
        else if (current_button_row == 3) // Change Syringe
        {
            program_state = change_syringe_page;
            current_button_row = syringe - 1;
            new_injection_flag = true;
            set_change_syringe_page();
        }
        else if (current_button_row == 4) // Create
        {
            if (input_rate == 0)
            {
                program_state = change_unit_error_page;
                current_button_row = 0;
                new_injection_flag = true;
                set_change_unit_error_page();
            }
            else if (temp_volume == double(0) && temp_time == double(0)) // error none
            {
                program_state = new_injection_error_no_time_or_volume_page;
                current_button_row = 0;
                set_new_injection_error_no_time_or_volume_page();
            }
            else if (temp_volume != double(0) && temp_time != double(0)) // error both
            {
                program_state = new_injection_error_both_time_and_volume_page;
                current_button_row = 0;
                set_new_injection_error_both_time_and_volume_page();
            }
            else if (temp_time != double(0)) // time
            {
                input_time = temp_time;
                temp_time = 0;
                input_volume = 0;

                if (time_unit == 1)
                {
                    input_time *= 60;
                }
                else if (time_unit == 2)
                {
                    input_time *= 3600;
                }

                remaining_time = input_time;

                program_state = progress_page_with_time;
                current_button_row = 0;
                time_or_volume_flag = time_;
                injection_or_suction_flag = injection;
                set_progress_page_with_time();

                stepper_move(injection, time_);
            }
            else if (temp_volume != double(0)) // volume
            {
                input_volume = temp_volume;
                remaining_volume = input_volume;
                if (volume_unit == 1)
                {
                    input_volume /= 1000;
                }
                temp_volume = 0;
                input_time = 0;

                program_state = progress_page_with_volume;
                current_button_row = 0;
                time_or_volume_flag = volume_;
                injection_or_suction_flag = injection;
                set_progress_page_with_volume();

                stepper_move(injection, volume_);
            }
        }
        else if (current_button_row == 5) // Back
        {
            program_state = menu_page;
            temp_volume = 0;
            temp_time = 0;
            current_button_row = 0;
            set_menu_page();
        }
    }
    else if (move_or_number == erase_move)
    {
        if (current_button_row == 0)
        {
            tft.fillRect(20, 70, 230, 30, BLACK);
            tft.drawRect(20, 70, 230, 30, WHITE);

            temp_time = 0;
            time_point_count = 0;
        }
        else if (current_button_row == 1)
        {
            tft.fillRect(20, 170, 230, 30, BLACK);
            tft.drawRect(20, 170, 230, 30, WHITE);

            temp_volume = 0;
            volume_point_count = 0;
        }
    }
    else
    {
        if (current_button_row == 0) // time
        {
            if (time_point_count == 0)
            {
                temp_time *= 10;
                temp_time += move_or_number;

                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.0f", temp_time);
            }
            else if (time_point_count == 1)
            {
                temp_time = temp_time + (double(move_or_number) / 10.0);
                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.1f", temp_time);
                time_point_count++;
            }
            else if (time_point_count == 2)
            {
                temp_time = temp_time + (double(move_or_number) / 100.0);
                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.2f", temp_time);
                time_point_count++;
            }
        }
        else if (current_button_row == 1) // volume
        {
            if (volume_point_count == 0)
            {
                temp_volume *= 10;
                temp_volume += move_or_number;

                tft.fillRect(20, 170, 230, 30, BLACK);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.0f", temp_volume);
            }
            else if (volume_point_count == 1)
            {
                temp_volume = temp_volume + (double(move_or_number) / 10.0);
                tft.fillRect(20, 170, 230, 30, BLACK);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.1f", temp_volume);
                volume_point_count++;
            }
            else if (volume_point_count == 2)
            {
                temp_volume = temp_volume + (double(move_or_number) / 100.0);
                tft.fillRect(20, 170, 230, 30, BLACK);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.2f", temp_volume);
                volume_point_count++;
            }
        }
    }
}

/* no volume or time error page */
void set_new_injection_error_no_time_or_volume_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* error */
    int row = 180, col = 80;
    tft.setCursor(col, row);
    tft.print("Please Enter");

    row = 210, col = 25;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(RED);
    tft.print("Time or Volume");

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}

void update_new_injection_error_no_time_or_volume_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = new_injection_page;
        current_button_row = 1;
        volume_point_count = 0;
        new_injection_flag = true;
        set_new_injection_page();
    }
}

/* both volume and time error page*/
void set_new_injection_error_both_time_and_volume_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* volume */
    int row = 150, col = 90;
    tft.setCursor(col, row);
    tft.print("Please Enter");

    row = 180, col = 40;
    tft.setCursor(col, row);
    tft.print("only Time or Volume");

    row = 210, col = 90;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(RED);
    tft.print("Not Both");

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}

void update_new_injection_error_both_time_and_volume_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = new_injection_page;
        temp_volume = 0;
        volume_point_count = 0;
        temp_time = 0;
        time_point_count = 0;
        current_button_row = 0;
        new_injection_flag = true;
        set_new_injection_page();
    }
}

/* new suction page */
void set_new_suction_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(3);
    tft.setTextColor(RED);
    int row = 10, col = 90;
    tft.setCursor(col, row);
    tft.print("Suction");
    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    int unit_col = 255;
    int box_col = 20;

    /* time */
    if (current_button_row == 0)
    {
        tft.setTextColor(RED);
        row = 50, col = 20;
        tft.setCursor(col, row);
        tft.print("Time:");
        tft.setTextColor(WHITE);
    }
    else
    {
        row = 50, col = 20;
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        tft.print("Time:");
    }

    row += 20;
    tft.drawRect(box_col, row, 230, 30, WHITE);

    tft.setTextSize(1);
    tft.setCursor(unit_col, row + 10);
    tft.print(available_time_units[time_unit]);
    tft.setTextSize(2);

    /* or */
    tft.setTextSize(1);
    tft.setCursor(20, 125);
    tft.print("OR");
    tft.setTextSize(2);

    /* volume */
    if (current_button_row == 1)
    {
        tft.setTextColor(RED);
        row = 150, col = 20;
        tft.setCursor(col, row);
        tft.print("Volume:");
        tft.setTextColor(WHITE);
    }
    else
    {
        tft.setTextColor(WHITE);
        row = 150, col = 20;
        tft.setCursor(col, row);
        tft.print("Volume:");
    }

    row += 20;
    tft.drawRect(box_col, row, 230, 30, WHITE);

    tft.setTextSize(1);
    tft.setCursor(unit_col, row + 10);
    tft.print(available_volume_units[volume_unit]);
    tft.setTextSize(2);

    /* Syringe */
    row += 70, col = 20;
    tft.setCursor(col, row);
    tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[syringe][0], available_syringe_types[syringe][1]);

    row += 20, col = 20;
    tft.setCursor(col, row);
    tft.printf("Rate %.2f %s/%s", input_rate, available_volume_units[volume_unit], available_time_units[time_unit]);

    if (new_suction_flag)
    {
        if (temp_time != 0)
        {
            tft.setCursor(24, 78);
            tft.printf("%.2f", temp_time);
        }

        if (temp_volume != 0)
        {
            tft.setCursor(24, 1478);
            tft.printf("%.2f", temp_volume);
        }

        new_suction_flag = false;
    }

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    col = 95, row = 320;
    tft.setCursor(col, row);
    tft.print("Change Unit");

    col = 78, row += diff;
    tft.setCursor(col, row);
    tft.print("Change Syringe");

    col = 125, row += diff;
    tft.setCursor(col, row);
    tft.print("Create");

    col = 135, row += diff;
    tft.setCursor(col, row);
    tft.print("Back");
}

void update_new_suction_page(int move_or_number)
{
    if (move_or_number == up_move)
    {
        int last_row, last_col = 20, curr_row, Curr_col = 20;

        char last_message[100];
        char curr_message[100];

        if (current_button_row == 0)
        {
            last_row = 50;
            sprintf(last_message, "Time:");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 433 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else if (current_button_row == 1)
        {
            last_row = 150;
            sprintf(last_message, "Volume:");
            curr_row = 50;
            sprintf(curr_message, "Time:");
            current_button_row = 0;
        }
        else if (current_button_row == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            curr_row = 150;
            sprintf(curr_message, "Volume:");

            current_button_row = 1;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 433 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }

        if (current_button_row == 1)
        {
            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
        else if (current_button_row == 5)
        {
            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);
        }
        else if (current_button_row == 0)
        {
            tft.setTextSize(2);

            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);

            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
    }
    else if (move_or_number == down_move)
    {
        int last_row, last_col = 20, curr_row, Curr_col = 20;

        char last_message[100];
        char curr_message[100];

        if (current_button_row == 0)
        {
            last_row = 50;
            sprintf(last_message, "Time:");
            curr_row = 150;
            sprintf(curr_message, "Volume:");

            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            last_row = 150;
            sprintf(last_message, "Volume:");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 433 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 433 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            curr_row = 50;
            sprintf(curr_message, "Time:");

            current_button_row = 0;
        }

        if (current_button_row == 0)
        {
            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
        else if (current_button_row == 2)
        {
            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);
        }
        else if (current_button_row == 1)
        {
            tft.setTextSize(2);

            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);

            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
    }
    else if (move_or_number == right_move)
    {
        if (current_button_row == 0)
        {
            if (time_point_count == 0)
            {
                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.1f", temp_time);

                time_point_count++;
            }
        }
        else if (current_button_row == 1)
        {
            if (volume_point_count == 0)
            {
                tft.fillRect(20, 170, 230, 30, BLACK);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.1f", temp_volume);

                volume_point_count++;
            }
        }
    }
    else if (move_or_number == ok_move)
    {
        if (current_button_row == 2) // Change Unit
        {
            program_state = change_unit_page;
            current_button_row = 0;
            new_suction_flag = true;
            current_button_col[0] = time_unit;
            current_button_col[1] = volume_unit;
            set_change_unit_page();
        }
        else if (current_button_row == 3) // Change Syringe
        {
            program_state = change_syringe_page;
            current_button_row = syringe - 1;
            new_suction_flag = true;
            set_change_syringe_page();
        }
        else if (current_button_row == 4) // Create
        {
            if (input_rate == 0)
            {
                program_state = change_unit_error_page;
                current_button_row = 0;
                new_suction_flag = true;
                set_change_unit_error_page();
            }
            else if (temp_volume == double(0) && temp_time == double(0)) // error none
            {
                program_state = new_suction_error_no_time_or_volume_page;
                current_button_row = 0;
                set_new_suction_error_no_time_or_volume_page();
            }
            else if (temp_volume != double(0) && temp_time != double(0)) // error both
            {
                program_state = new_suction_error_both_time_and_volume_page;
                current_button_row = 0;
                set_new_suction_error_both_time_and_volume_page();
            }
            else if (temp_time != double(0)) // time
            {
                input_time = temp_time;
                temp_time = 0;
                input_volume = 0;

                if (time_unit == 1)
                {
                    input_time *= 60;
                }
                else if (time_unit == 2)
                {
                    input_time *= 3600;
                }

                remaining_time = input_time;

                program_state = progress_page_with_time;
                current_button_row = 0;
                time_or_volume_flag = time_;
                injection_or_suction_flag = suction;
                set_progress_page_with_time();

                stepper_move(suction, time_);
            }
            else if (temp_volume != double(0)) // volume
            {
                input_volume = temp_volume;

                if (volume_unit == 1)
                {
                    input_volume /= 1000;
                }

                remaining_volume = input_volume;
                temp_volume = 0;
                input_time = 0;

                program_state = progress_page_with_volume;
                current_button_row = 0;
                time_or_volume_flag = volume_;
                injection_or_suction_flag = suction;
                set_progress_page_with_volume();

                stepper_move(suction, volume_);
            }
        }
        else if (current_button_row == 5) // Back
        {
            program_state = menu_page;
            temp_volume = 0;
            temp_time = 0;
            current_button_row = 0;
            set_menu_page();
        }
    }
    else if (move_or_number == erase_move)
    {
        if (current_button_row == 0)
        {
            tft.fillRect(20, 70, 230, 30, BLACK);
            tft.drawRect(20, 70, 230, 30, WHITE);

            temp_time = 0;
            time_point_count = 0;
        }
        else if (current_button_row == 1)
        {
            tft.fillRect(20, 170, 230, 30, BLACK);
            tft.drawRect(20, 170, 230, 30, WHITE);

            temp_volume = 0;
            volume_point_count = 0;
        }
    }
    else
    {
        if (current_button_row == 0) // time
        {
            if (time_point_count == 0)
            {
                temp_time *= 10;
                temp_time += move_or_number;

                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.0f", temp_time);
            }
            else if (time_point_count == 1)
            {
                temp_time = temp_time + (double(move_or_number) / 10.0);
                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.1f", temp_time);
                time_point_count++;
            }
            else if (time_point_count == 2)
            {
                temp_time = temp_time + (double(move_or_number) / 100.0);
                tft.fillRect(20, 70, 230, 30, BLACK);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.2f", temp_time);
                time_point_count++;
            }
        }
        else if (current_button_row == 1) // volume
        {
            if (volume_point_count == 0)
            {
                temp_volume *= 10;
                temp_volume += move_or_number;

                tft.fillRect(20, 170, 230, 30, BLACK);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.0f", temp_volume);
            }
            else if (volume_point_count == 1)
            {
                temp_volume = temp_volume + (double(move_or_number) / 10.0);
                tft.fillRect(20, 170, 230, 30, BLACK);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.1f", temp_volume);
                volume_point_count++;
            }
            else if (volume_point_count == 2)
            {
                temp_volume = temp_volume + (double(move_or_number) / 100.0);
                tft.fillRect(20, 170, 230, 30, BLACK);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.2f", temp_volume);
                volume_point_count++;
            }
        }
    }
}

/* no volume or time error page */
void set_new_suction_error_no_time_or_volume_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* error */
    int row = 180, col = 80;
    tft.setCursor(col, row);
    tft.print("Please Enter");

    row = 210, col = 25;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(RED);
    tft.print("Time or Volume");

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}

void update_new_suction_error_no_time_or_volume_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = new_suction_page;
        current_button_row = 1;
        volume_point_count = 0;
        new_suction_flag = true;
        set_new_suction_page();
    }
}

/* both volume and time error page*/
void set_new_suction_error_both_time_and_volume_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* volume */
    int row = 150, col = 90;
    tft.setCursor(col, row);
    tft.print("Please Enter");

    row = 180, col = 40;
    tft.setCursor(col, row);
    tft.print("only Time or Volume");

    row = 210, col = 90;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(RED);
    tft.print("Not Both");

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}

void update_new_suction_error_both_time_and_volume_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = new_suction_page;
        temp_volume = 0;
        volume_point_count = 0;
        temp_time = 0;
        time_point_count = 0;
        current_button_row = 0;
        new_suction_flag = true;
        set_new_suction_page();
    }
}

/* progress page with time */
void set_progress_page_with_time()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* time */
    int row = 125, col = 10;
    tft.setCursor(col, row);

    tft.print("Remaining Time:");

    row = 150, col = 10;
    tft.setCursor(col, row);
    tft.printf("%.2lf sec", remaining_time);

    row += 30, col = 10;
    tft.drawRect(col, row - 5, 300, 25, WHITE);
    tft.fillRect(12, 177, 297, 21, RED);
    if (time_counter >= 297)
    {
        tft.fillRect(12, 177, 297, 21, BLACK);
    }
    else
    {
        tft.fillRect(12, 177, time_counter, 21, BLACK);
    }

    /* rate */
    row = 255, col = 10;
    tft.setCursor(col, row);
    tft.print("Current Rate:");

    row = 280, col = 10;
    tft.setCursor(col, row);
    tft.printf("%.4f mL/min", current_rate);

    int width = 180, height = 40, rounding_facotr = 8, diff = 41;
    col = 70, row = 400;

    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    tft.setCursor(135, row += 15);
    tft.print("STOP");
}

void update_progress_page_with_time(double t, int move)
{
    if (move == time_interrupt)
    {
        if (current_rate != input_rate)
        {
            t_count++;

            if (v_count == 2)
            {
                time_counter++;
                t_count = 0;
            }
        }
        else
        {
            time_counter += 2;
        }

        if (time_counter >= 297)
        {
            tft.fillRect(12, 177, 297, 21, BLACK);
        }
        else
        {
            tft.fillRect(12, 177, time_counter, 21, BLACK);
        }

        int row = 150, col = 10;
        tft.fillRect(col, row, 300, 25, BLACK);

        tft.setCursor(col, row);

        remaining_time -= t;

        tft.printf("%.2f sec", remaining_time);

        row = 280, col = 10;
        tft.fillRect(col, row, 300, 25, BLACK);
        tft.setCursor(col, row);
        tft.printf("%.4lf mL/min", current_rate);
    }
    else if (move == ok_move)
    {
        if (current_button_row == 0)
        {
            program_state = stop_page;
            current_button_row = 0;
            set_stop_page();
        }
    }
}

/* progress page */
void set_progress_page_with_volume()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* volume */
    int row = 125, col = 10;
    tft.setCursor(col, row);
    tft.print("Remaining volume:");

    row = 150, col = 10;
    tft.setCursor(col, row);
    tft.printf("%.2lf mL", remaining_volume);

    row += 30, col = 10;
    tft.drawRect(col, row - 5, 300, 25, WHITE);
    tft.fillRect(12, 177, 297, 21, RED);
    if (volume_counter >= 297)
    {
        tft.fillRect(12, 177, 297, 21, BLACK);
    }
    else
    {
        tft.fillRect(12, 177, volume_counter, 21, BLACK);
    }

    /* rate */
    row = 255, col = 10;
    tft.setCursor(col, row);
    tft.print("Current Rate:");

    row = 280, col = 10;
    tft.setCursor(col, row);
    tft.printf("%.4lf mL/min", current_rate);

    int width = 180, height = 40, rounding_facotr = 8, diff = 41;
    col = 70, row = 400;

    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    tft.setCursor(135, row += 15);
    tft.print("STOP");
}

void update_progress_page_with_volume(double vol, int move)
{
    if (move == volume_interrupt)
    {
        if (current_rate != input_rate)
        {
            v_count++;

            if (v_count == 2)
            {
                volume_counter++;
                v_count = 0;
            }
        }
        else
        {
            volume_counter += 2;
        }

        if (volume_counter >= 297)
        {
            tft.fillRect(12, 177, 297, 21, BLACK);
        }
        else
        {
            tft.fillRect(12, 177, volume_counter, 21, BLACK);
        }

        int row = 150, col = 10;
        tft.fillRect(col, row, 300, 25, BLACK);

        tft.setCursor(col, row);

        remaining_volume -= vol;

        tft.printf("%.4lf mL", remaining_volume);

        row = 280, col = 10;
        tft.fillRect(col, row, 300, 25, BLACK);
        tft.setCursor(col, row);
        tft.printf("%.4lf mL/min", current_rate);
    }
    else if (move == ok_move)
    {
        if (current_button_row == 0)
        {
            program_state = stop_page;
            current_button_row = 0;
            set_stop_page();
        }
    }
}

/* stop page */
void set_stop_page()
{
    tft.fillScreen(BLACK);

    /* injection end */
    tft.setTextSize(3);
    tft.setCursor(120, 50);
    tft.setTextColor(RED);
    tft.print("Stop");
    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    if (time_or_volume_flag == volume_)
    {
        if (injection_or_suction_flag == injection)
        {
            tft.setCursor(10, 150);
            tft.print("Injected Volume:");

            tft.setCursor(10, 170);
            tft.printf("%.2f mL of %.2f mL", input_volume - remaining_volume, input_volume);
        }
        else
        {
            tft.setCursor(10, 150);
            tft.print("Secked Volume:");

            tft.setCursor(10, 170);
            tft.printf("%.2f mL of %.2f mL", input_volume - remaining_volume, input_volume);
        }
    }
    else
    {
        if (injection_or_suction_flag == injection)
        {
            tft.setCursor(10, 150);
            tft.print("Injection Time:");

            tft.setCursor(10, 170);
            tft.printf("%.2f sec of %.2f sec", input_time - remaining_time, input_time);
        }
        else
        {
            tft.setCursor(10, 150);
            tft.print("Suction Time:");

            tft.setCursor(10, 170);
            tft.printf("%.2f sec of %.2f sec", input_time - remaining_time, input_time);
        }
    }

    /* buttons */
    int width = 200, height = 40, rounding_facotr = 8;

    int col = 70, row = 320;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    row += 50;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    row += 50;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(70 + i, 320 + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    col = 130, row = 335;
    tft.setCursor(col, row);
    tft.print("Resume");

    col = 145, row += 50;
    tft.setCursor(col, row);
    tft.print("Edit");

    col = 145, row += 50;
    tft.setCursor(col, row);
    tft.print("EXIT");
}

void update_stop_page(int move)
{
    if (move == up_move)
    {
        int last_col = 70, last_row, curr_col = 70, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 320;
            curr_row = 420;
            current_button_row = 2;
        }
        else if (current_button_row == 1)
        {
            last_row = 370;
            curr_row = 320;
            current_button_row = 0;
        }
        else
        {
            last_row = 420;
            curr_row = 370;
            current_button_row = 1;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    }
    else if (move == down_move)
    {
        int last_col = 70, last_row, curr_col = 70, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 320;
            curr_row = 370;
            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            last_row = 370;
            curr_row = 420;
            current_button_row = 2;
        }
        else
        {
            last_row = 420;
            curr_row = 320;
            current_button_row = 0;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    }
    else if (move == ok_move)
    {
        if (current_button_row == 0)
        {
            if (time_or_volume_flag == time_)
            {
                program_state = progress_page_with_time;
                current_button_row = 0;
                set_progress_page_with_time();
                stepper_move(injection_or_suction_flag, time_);
            }
            else
            {
                program_state = progress_page_with_volume;
                current_button_row = 0;
                set_progress_page_with_volume();
                stepper_move(injection_or_suction_flag, volume_);
            }
        }
        else if (current_button_row == 1)
        {
            current_rate = 0.1;
            time_counter = 0, volume_counter = 0;
            volume_point_count = 0, time_point_count = 0;
            if (injection_or_suction_flag == injection)
            {
                program_state = new_injection_page;
                current_button_row = 0;
                set_new_injection_page();
            }
            else
            {
                program_state = new_suction_page;
                current_button_row = 0;
                set_new_suction_page();
            }
        }
        else
        {
            program_state = menu_page;
            current_button_row = 0;
            current_rate = 0.1;
            time_counter = 0, volume_counter = 0;
            volume_point_count = 0, time_point_count = 0;
            set_menu_page();
        }
    }
}

/* end page */
void set_end_page()
{
    tft.fillScreen(BLACK);

    /* injection end */
    tft.setTextSize(3);
    tft.setCursor(150, 50);
    tft.setTextColor(RED);
    tft.print("END");
    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    if (time_or_volume_flag == volume_)
    {
        if (injection_or_suction_flag == injection)
        {
            tft.setCursor(10, 150);
            tft.print("Injected Volume:");

            tft.setCursor(10, 170);
            tft.printf("%.2f mL of %.2f mL", input_volume - remaining_volume, input_volume);
        }
        else
        {
            tft.setCursor(10, 150);
            tft.print("Secked Volume:");

            tft.setCursor(10, 170);
            tft.printf("%.2f mL of %.2f mL", input_volume - remaining_volume, input_volume);
        }
    }
    else
    {
        if (injection_or_suction_flag == injection)
        {
            tft.setCursor(10, 150);
            tft.print("Passed Time:");

            tft.setCursor(10, 170);
            tft.printf("%.2f sec of %.2f sec", input_time, input_time);
        }
        else
        {
            tft.setCursor(10, 150);
            tft.print("Passed Time:");

            tft.setCursor(10, 170);
            tft.printf("%.2f sec of %.2f sec", input_time, input_time);
        }
    }

    /* buttons */
    int width = 200, height = 40, rounding_facotr = 8;

    int col = 70, row = 320;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    row += 50;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(70 + i, 320 + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    col = 140, row = 335;
    tft.setCursor(col, row);
    tft.print("New");

    col = 145, row += 50;
    tft.setCursor(col, row);
    tft.print("EXIT");
}

void update_end_page(int move)
{
    if (move == up_move || move == down_move)
    {
        int last_col = 70, last_row, curr_col = 70, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 320;
            curr_row = 370;
            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            last_row = 370;
            curr_row = 320;
            current_button_row = 0;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    }
    else if (move == ok_move)
    {
        current_rate = 0.1;
        time_counter = 0, volume_counter = 0;
        volume_point_count = 0, time_point_count = 0;

        if (current_button_row == 0)
        {
            if (injection_or_suction_flag == injection)
            {
                program_state = new_injection_page;
                current_button_row = 0;
                set_new_injection_page();
            }
            else
            {
                program_state = new_suction_page;
                current_button_row = 0;
                set_new_suction_page();
            }
        }
        else if (current_button_row == 1)
        {
            program_state = menu_page;
            current_button_row = 0;
            set_menu_page();
        }
    }
}

/* start button page */
void set_button_start_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* error */
    int row = 210, col = 100;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(RED);
    tft.print("Start");

    // stop_stepper

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}

void update_button_start_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        current_rate = 0.1;
        time_counter = 0, volume_counter = 0;
        volume_point_count = 0, time_point_count = 0;
        program_state = menu_page;
        current_button_row = 0;
        set_menu_page();
    }
}

/* finish button page */
void set_button_finish_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* error */
    int row = 210, col = 100;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(RED);
    tft.print("Finish");

    // stop_stepper

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}

void update_button_finish_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        current_rate = 0.1;
        time_counter = 0, volume_counter = 0;
        volume_point_count = 0, time_point_count = 0;
        program_state = menu_page;
        current_button_row = 0;
        set_menu_page();
    }
}

/* free move */
void set_free_move_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* error */
    int row = 180, col = 20;
    tft.setCursor(col, row);
    tft.print("Press Up to do injection");

    row += 50;
    tft.setCursor(col, row);
    tft.print("Press Down to do suction");

    row += 50;
    tft.setCursor(col, row);
    tft.print("Moving Rate:");

    tft.drawRect(20, 300, 300, 30, WHITE);

    /* buttons */
    int width = 180, height = 34, rounding_facotr = 8, diff = 41;

    col = 70, row = 400;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 135, row = 410;
    tft.setCursor(col, row);
    tft.print("Back");
}

void update_free_move_page(int move_or_number)
{
    if (move_or_number == up_move)
    {
        digitalWrite(dir, LOW);

        if (temp_speed != 0 && temp_speed < 21)
        {
            for (int i = 0; i < 800; i++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(500 - temp_speed * 20);

                digitalWrite(step, LOW);

                delayMicroseconds(500 - temp_speed * 20);
            }
        }
        else if (temp_speed != 0 && temp_speed >= 20)
        {
            for (int i = 0; i < 800; i++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(100);

                digitalWrite(step, LOW);

                delayMicroseconds(100);
            }
        }
        else if (temp_speed == 0)
        {
            for (int i = 0; i < 800; i++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(150);

                digitalWrite(step, LOW);

                delayMicroseconds(150);
            }
        }
    }
    else if (move_or_number == down_move)
    {
        digitalWrite(dir, HIGH);

        if (temp_speed != 0)
        {
            for (int i = 0; i < temp_speed * 100; i++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(150);

                digitalWrite(step, LOW);

                delayMicroseconds(150);
            }
        }
        else
        {
            for (int i = 0; i < 1000; i++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(150);

                digitalWrite(step, LOW);

                delayMicroseconds(150);
            }
        }
    }
    else if (move_or_number == ok_move && current_button_row == 0)
    {
        program_state = menu_page;
        current_button_row = 1;
        temp_speed = 0;
        set_menu_page();
    }
    else if (move_or_number == erase_move)
    {
        tft.fillRect(20, 300, 300, 30, BLACK);
        tft.drawRect(20, 300, 300, 30, WHITE);

        temp_speed = 0;
    }
    else
    {
        temp_speed *= 10;
        temp_speed += move_or_number;

        tft.fillRect(20, 300, 300, 30, BLACK);
        tft.drawRect(20, 300, 300, 30, WHITE);

        tft.setTextColor(WHITE);
        tft.setCursor(24, 308);
        tft.printf("%d", temp_speed);
    }
}

/* stepper */
double calculate_height(double volume)
{
    return volume / (PI * available_syringe_types[syringe][1] * available_syringe_types[syringe][1]) * 1000;
}

void stepper_move(int injection_or_suction, int time_or_volume)
{
    /* use for calibration */
    int steps = 10000;
    double length = 3.47;

    if (injection_or_suction == injection)
    {
        digitalWrite(dir, LOW);
    }
    else
    {
        digitalWrite(dir, HIGH);
    }

    if (time_or_volume == time_)
    {
        int step_count = 100;
        double t = 0.5;
        double rate_diff = useable_input_rate / step_count;
        double rate = 0;
        double total_vol = 0;

        current_rate = 0;

        for (int i = 0; i < step_count; i++)
        {
            double volume_take = ((t * rate) / (step_count * 60.0));
            total_vol += volume_take;
            double height = calculate_height(volume_take);
            double rounds = steps * height / length;
            double delay_inupt = (t * 1000000) / (step_count * rounds * 2);

            for (int j = 0; j < int(rounds); j++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(delay_inupt);

                digitalWrite(step, LOW);

                delayMicroseconds(delay_inupt);

                if (char_flag)
                {
                    int index = keyPad.getKey();
                    if (index < 16)
                    {
                        key = keys[index];
                    }
                    lastKeyPressed = millis();

                    char_flag = false;
                }

                if (key == '#')
                {
                    key = '\0';
                    program_state = stop_page;
                    current_button_row = 0;
                    set_stop_page();
                }

                if (program_state == stop_page || button_start.pressed || button_finish.pressed)
                {
                    button_start.pressed = false;
                    button_finish.pressed = false;
                    return;
                }
            }

            rate += rate_diff;

            current_rate = rate;

            update_progress_page_with_time(t / 100, time_interrupt);
        }

        double inj_t = input_time - (2 * t);

        rate = input_rate;

        double volume_take = ((inj_t * rate) / (100.0 * 60.0));
        double height = calculate_height(volume_take);
        double rounds = steps * height / length;
        double delay_inut = (input_time * 10000) / (rounds * 2);

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < int(rounds); j++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(delay_inut);

                digitalWrite(step, LOW);

                delayMicroseconds(delay_inut);

                if (char_flag)
                {
                    int index = keyPad.getKey();
                    if (index < 16)
                    {
                        key = keys[index];
                    }
                    lastKeyPressed = millis();

                    char_flag = false;
                }

                if (key == '#')
                {
                    key = '\0';
                    program_state = stop_page;
                    current_button_row = 0;
                    set_stop_page();
                }

                if (program_state == stop_page || button_start.pressed || button_finish.pressed)
                {
                    button_start.pressed = false;
                    button_finish.pressed = false;
                    return;
                }
            }

            update_progress_page_with_time(inj_t / 100, time_interrupt);
        }

        for (int i = 0; i < step_count; i++)
        {
            double volume_take = ((t * rate) / (step_count * 60.0));
            double height = calculate_height(volume_take);
            double rounds = steps * height / length;
            double delay_inupt = (t * 1000000) / (step_count * rounds * 2);

            for (int j = 0; j < int(rounds); j++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(delay_inupt);

                digitalWrite(step, LOW);

                delayMicroseconds(delay_inupt);

                if (char_flag)
                {
                    int index = keyPad.getKey();
                    if (index < 16)
                    {
                        key = keys[index];
                    }
                    lastKeyPressed = millis();

                    char_flag = false;
                }

                if (key == '#')
                {
                    key = '\0';
                    program_state = stop_page;
                    current_button_row = 0;
                    set_stop_page();
                }

                if (program_state == stop_page || button_start.pressed || button_finish.pressed)
                {
                    button_start.pressed = false;
                    button_finish.pressed = false;
                    return;
                }
            }

            rate -= rate_diff;

            current_rate = rate;

            update_progress_page_with_time(t / 100, time_interrupt);
        }
    }
    else
    {
        int step_count = 100;
        double t = 0.5;
        double rate_diff = useable_input_rate / step_count;
        double rate = 0;
        double total_vol = 0;

        current_rate = 0;

        for (int i = 0; i < step_count; i++)
        {
            double volume_take = ((t * rate) / (step_count * 60.0));
            total_vol += volume_take;
            double height = calculate_height(volume_take);
            double rounds = steps * height / length;
            double delay_inupt = (t * 1000000) / (step_count * rounds * 2);

            for (int j = 0; j < int(rounds); j++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(delay_inupt);

                digitalWrite(step, LOW);

                delayMicroseconds(delay_inupt);

                if (char_flag)
                {
                    int index = keyPad.getKey();
                    if (index < 16)
                    {
                        key = keys[index];
                    }
                    lastKeyPressed = millis();

                    char_flag = false;
                }

                if (key == '#')
                {
                    key = '\0';
                    program_state = stop_page;
                    current_button_row = 0;
                    set_stop_page();
                }

                if (program_state == stop_page || button_start.pressed || button_finish.pressed)
                {
                    button_start.pressed = false;
                    button_finish.pressed = false;
                    return;
                }
            }

            rate += rate_diff;

            current_rate = rate;

            update_progress_page_with_volume(volume_take, volume_interrupt);
        }

        double inj_vol = input_volume - (2 * total_vol);

        double height = calculate_height(inj_vol);
        double rounds = steps * height / length;
        rounds /= 100;

        rate = input_rate;
        current_rate = input_rate;

        double time_take = ((inj_vol / 100) / rate) * 60000000;
        double delay_inut = (time_take / rounds) / 2;

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < int(rounds); j++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(delay_inut);

                digitalWrite(step, LOW);

                delayMicroseconds(delay_inut);

                if (char_flag)
                {
                    int index = keyPad.getKey();
                    if (index < 16)
                    {
                        key = keys[index];
                    }
                    lastKeyPressed = millis();

                    char_flag = false;
                }

                if (key == '#')
                {
                    key = '\0';
                    program_state = stop_page;
                    current_button_row = 0;
                    set_stop_page();
                }

                if (program_state == stop_page || button_start.pressed || button_finish.pressed)
                {
                    button_start.pressed = false;
                    button_finish.pressed = false;
                    return;
                }
            }

            update_progress_page_with_volume(inj_vol / 100, volume_interrupt);
        }

        for (int i = 0; i < step_count; i++)
        {
            double volume_take = ((t * rate) / (step_count * 60.0));
            double height = calculate_height(volume_take);
            double rounds = steps * height / length;
            double delay_inupt = (t * 1000000) / (step_count * rounds * 2);

            for (int j = 0; j < int(rounds); j++)
            {
                digitalWrite(step, HIGH);

                delayMicroseconds(delay_inupt);

                digitalWrite(step, LOW);

                delayMicroseconds(delay_inupt);

                if (char_flag)
                {
                    int index = keyPad.getKey();
                    if (index < 16)
                    {
                        key = keys[index];
                    }
                    lastKeyPressed = millis();

                    char_flag = false;
                }

                if (key == '#')
                {
                    key = '\0';
                    program_state = stop_page;
                    current_button_row = 0;
                    set_stop_page();
                }

                if (program_state == stop_page || button_start.pressed || button_finish.pressed)
                {
                    button_start.pressed = false;
                    button_finish.pressed = false;
                    return;
                }
            }

            rate -= rate_diff;

            current_rate = rate;

            update_progress_page_with_volume(volume_take, volume_interrupt);
        }
    }

    program_state = end_page;
    current_button_row = 0;
    set_end_page();
}

// void stepper_move(int injection_or_suction, int time_or_volume)
// {
//     /* use for calibration */
//     int steps = 10000;
//     double length = 3.47;

//     if (injection_or_suction == injection)
//     {
//         digitalWrite(dir, LOW);
//     }
//     else
//     {
//         digitalWrite(dir, HIGH);
//     }

//     if (time_or_volume == time_)
//     {
//         double minimum_rate = 0.1, maximum_rate = 5;
//         double rate_add_each = (maximum_rate - minimum_rate) / 50.0;
//         double rate = current_rate;

//         if (remaining_time >= (input_time / 2))
//         {
//             double reach = (maximum_rate - current_rate) / rate_add_each;

//             for (int i = 0; i < int(reach); i++)
//             {
//                 double volume_take = ((input_time * rate) / (100.0 * 60.0));

//                 double height = calculate_height(volume_take);

//                 double rounds = steps * height / length;

//                 double delay_inut = (input_time * 10000) / (rounds * 2);

//                 for (int j = 0; j < int(rounds); j++)
//                 {
//                     digitalWrite(step, HIGH);

//                     delayMicroseconds(delay_inut);

//                     digitalWrite(step, LOW);

//                     delayMicroseconds(delay_inut);

//                     if (char_flag)
//                     {
//                         int index = keyPad.getKey();
//                         if (index < 16)
//                         {
//                             key = keys[index];
//                         }
//                         lastKeyPressed = millis();

//                         char_flag = false;
//                     }

//                     if (key == '#')
//                     {
//                         key = '\0';
//                         program_state = stop_page;
//                         current_button_row = 0;
//                         set_stop_page();
//                     }

//                     if (program_state == stop_page || button_start.pressed || button_finish.pressed)
//                     {
//                         button_start.pressed = false;
//                         button_finish.pressed = false;
//                         return;
//                     }
//                 }

//                 rate += rate_add_each;

//                 current_rate = rate;

//                 update_progress_page_with_time(time_interrupt);
//             }
//         }

//         double reach = (current_rate - minimum_rate) / rate_add_each;

//         for (int i = 0; i < int(reach); i++)
//         {
//             double volume_take = ((input_time * rate) / (100.0 * 60.0));

//             double height = calculate_height(volume_take);

//             double rounds = steps * height / length;

//             double delay_inut = (input_time * 10000) / (rounds * 2);

//             for (int j = 0; j < int(rounds); j++)
//             {
//                 digitalWrite(step, HIGH);

//                 delayMicroseconds(delay_inut);

//                 digitalWrite(step, LOW);

//                 delayMicroseconds(delay_inut);

//                 if (char_flag)
//                 {
//                     int index = keyPad.getKey();
//                     if (index < 16)
//                     {
//                         key = keys[index];
//                     }
//                     lastKeyPressed = millis();

//                     char_flag = false;
//                 }

//                 if (key == '#')
//                 {
//                     key = '\0';
//                     program_state = stop_page;
//                     current_button_row = 0;
//                     set_stop_page();
//                 }

//                 if (program_state == stop_page || button_start.pressed || button_finish.pressed)
//                 {
//                     button_start.pressed = false;
//                     button_finish.pressed = false;
//                     return;
//                 }
//             }

//             rate -= rate_add_each;

//             current_rate = rate;

//             update_progress_page_with_time(time_interrupt);
//         }
//     }
//     else
//     {
//         double height = calculate_height(input_volume);

//         double rounds = steps * height / length;
//         rounds /= 100;

//         double minimum_rate = 0.1, maximum_rate = 5;
//         double rate_add_each = (maximum_rate - minimum_rate) / 50.0;
//         double rate = current_rate;

//         if (remaining_volume >= (input_volume / 2))
//         {
//             double reach = (maximum_rate - current_rate) / rate_add_each;

//             for (int i = 0; i < int(reach); i++)
//             {
//                 double time_take = ((input_volume / 100) / rate) * 60000000;

//                 double delay_inut = (time_take / rounds) / 2;

//                 for (int j = 0; j < int(rounds); j++)
//                 {
//                     digitalWrite(step, HIGH);

//                     delayMicroseconds(delay_inut);

//                     digitalWrite(step, LOW);

//                     delayMicroseconds(delay_inut);

//                     if (char_flag)
//                     {
//                         int index = keyPad.getKey();
//                         if (index < 16)
//                         {
//                             key = keys[index];
//                         }
//                         lastKeyPressed = millis();

//                         char_flag = false;
//                     }

//                     if (key == '#')
//                     {
//                         key = '\0';
//                         program_state = stop_page;
//                         current_button_row = 0;
//                         set_stop_page();
//                     }

//                     if (program_state == stop_page || button_start.pressed || button_finish.pressed)
//                     {
//                         button_start.pressed = false;
//                         button_finish.pressed = false;
//                         return;
//                     }
//                 }

//                 rate += rate_add_each;

//                 current_rate = rate;

//                 update_progress_page_with_volume(volume_interrupt);
//             }
//         }

//         double reach = (current_rate - minimum_rate) / rate_add_each;

//         for (int i = 0; i < int(reach); i++)
//         {
//             double time_take = ((input_volume / 100) / rate) * 60000000;

//             double delay_inut = (time_take / rounds) / 2;

//             for (int j = 0; j < int(rounds); j++)
//             {
//                 digitalWrite(step, HIGH);

//                 delayMicroseconds(delay_inut);

//                 digitalWrite(step, LOW);

//                 delayMicroseconds(delay_inut);

//                 if (char_flag)
//                 {
//                     int index = keyPad.getKey();
//                     if (index < 16)
//                     {
//                         key = keys[index];
//                     }
//                     lastKeyPressed = millis();

//                     char_flag = false;
//                 }

//                 if (key == '#')
//                 {
//                     key = '\0';
//                     program_state = stop_page;
//                     current_button_row = 0;
//                     set_stop_page();
//                 }

//                 if (program_state == stop_page || button_start.pressed || button_finish.pressed)
//                 {
//                     button_start.pressed = false;
//                     button_finish.pressed = false;
//                     return;
//                 }
//             }

//             rate -= rate_add_each;

//             current_rate = rate;

//             update_progress_page_with_volume(volume_interrupt);
//         }
//     }

//     program_state = end_page;
//     current_button_row = 0;
//     set_end_page();
// }
