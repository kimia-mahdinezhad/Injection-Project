#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>
#include <Wire.h>
#include <I2CKeyPad.h>

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
#define change_syringe_page 12
#define new_injection_page 2
#define new_injection_error_no_time_page 21
#define new_injection_error_no_volume_or_rate_page 22
#define new_injection_error_both_volume_and_rate_page 23
#define injection_progress_page 3
#define end_page 4

#define up_move 20
#define right_move 60
#define down_move 80
#define left_move 40
#define ok_move 50
#define erase_move 100

void set_menu_page();
void update_menu_page(int);
void set_setting_page();
void update_setting_page(int);
void set_change_unit_page();
void update_change_unit_page(int);
void set_change_syringe_page();
void update_change_syringe_page(int);
void set_new_injection_page();
void update_new_injection_page(int);
void set_new_injection_error_no_time_page();
void update_new_injection_error_no_time_page(int);
void set_new_injection_error_no_volume_or_rate_page();
void update_new_injection_error_no_volume_or_rate_page(int);
void set_new_injection_error_both_volume_and_rate_page();
void update_new_injection_error_both_volume_and_rate_page(int);
void set_injection_progress_page();
void update_injection_progress_page(int);
void set_end_page();
void update_end_page(int);

void up();
void down();
void right();
void left();
void ok();
void enter(char);
void erase();

void stepper_move();
double calculate_height();

MCUFRIEND_kbv tft(LCD_CS, LCD_RS, LCD_WR, LCD_RD, LCD_RESET);

int program_state;
bool new_injection_flag = false;

char available_volume_units[2][4] = {{"mL"}, {"muL"}};
int volume_unit = 0;
char available_time_units[2][4] = {{"min"}, {"h"}};
int time_unit = 0;
char available_rate_units[4][8] = {{"mL/min"}, {"mL/h"}, {"muL/min"}, {"muL/h"}};
int rate_unit = 0;

double input_time = 0, temp_time = 0;
int time_point_count = 0;
double input_volume = 0, temp_volume = 0;
int volume_point_count = 0;
double input_rate = 0, temp_rate = 0;
int rate_point_count = 0;
double height = 0;

int syringe = 1;

const uint8_t KEYPAD_ADDRESS = 0x20;
I2CKeyPad keyPad(KEYPAD_ADDRESS);

char keys[] = "123A456B789C*0#DNF";

uint32_t lastKeyPressed = 0;

int current_button_row = 0;
int current_button_col[3] = {0};

#define step 23
#define dir 19
// #define PI 3.14159265359

void setup()
{
    uint16_t ID = tft.readID();
    pinMode(step, OUTPUT);
    pinMode(dir, OUTPUT);
    tft.begin(ID);
    program_state = menu_page;
    set_menu_page();
    Serial.begin(9600);
    keyPad.begin();
}

void loop()
{
    char key = '\0';
    if (millis() - lastKeyPressed >= 200) // figure key
    {
        int index = keyPad.getKey();
        if (index < 16)
        {
            key = keys[index];
        }
        lastKeyPressed = millis();
    }

    if (key >= '0' && key <= '9') // enter
    {
        enter(key);
    }
    else if (key == 'A') // up
    {
        up();
    }
    else if (key == 'B') // down
    {
        down();
    }
    else if (key == 'C') // right
    {
        right();
    }
    else if (key == 'D') // left
    {
        left();
    }
    else if (key == '#') // ok
    {
        ok();
    }
    else if (key == '*')
    {
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
    else if (program_state == new_injection_page)
    {
        update_new_injection_page(up_move);
    }
    else if (program_state == injection_progress_page)
    {
        update_injection_progress_page(up_move);
    }
    else if (program_state == end_page)
    {
        update_end_page(up_move);
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
    else if (program_state == new_injection_page)
    {
        update_new_injection_page(down_move);
    }
    else if (program_state == injection_progress_page)
    {
        update_injection_progress_page(down_move);
    }
    else if (program_state == end_page)
    {
        update_end_page(down_move);
    }
}

void right()
{
    if (program_state == change_unit_page)
    {
        update_change_unit_page(right_move);
    }
    else if (program_state == new_injection_page)
    {
        update_new_injection_page(right_move);
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
    else if (program_state == change_syringe_page)
    {
        update_change_syringe_page(ok_move);
    }
    else if (program_state == new_injection_page)
    {
        update_new_injection_page(ok_move);
    }
    else if (program_state == new_injection_error_no_time_page)
    {
        update_new_injection_error_no_time_page(ok_move);
    }
    else if (program_state == new_injection_error_no_volume_or_rate_page)
    {
        update_new_injection_error_no_volume_or_rate_page(ok_move);
    }
    else if (program_state == new_injection_error_both_volume_and_rate_page)
    {
        update_new_injection_error_both_volume_and_rate_page(ok_move);
    }
    else if (program_state == injection_progress_page)
    {
        update_injection_progress_page(ok_move);
    }
    else if (program_state == ok_move)
    {
        update_end_page(ok_move);
    }
}

void enter(char key)
{
    if (program_state == new_injection_page)
    {
        update_new_injection_page(key - '0');
    }
}

void erase()
{
    if (program_state == new_injection_page)
    {
        update_new_injection_page(erase_move);
    }
}

/* to-do */
/* tidy up (pretty - choose icon) - picture */
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

    tft.setTextColor(WHITE);

    tft.setCursor(50, 35);
    tft.setTextSize(3);
    tft.print("Project Name");

    tft.setTextSize(2);

    tft.setCursor(120, 80);
    tft.print("Picture");

    tft.setCursor(120, 265);
    tft.print("Setting");

    tft.setCursor(85, 315);
    tft.print("New Injection");
}

void update_menu_page(int move)
{
    if (move == up_move || move == down_move)
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
    }
}

/* to-do */
/* tidy up (pretty - choose icon) */
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
            current_button_col[2] = rate_unit;
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

/* to-do */
/* tidy up (pretty - choose icon (up-down & right-left)) - micro symbol - division */
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

    tft.setCursor(90, row += 35);
    tft.print("min");

    if (time_unit == 0)
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(87, 210 + i, 127, 210 + i, WHITE);
        }
    }
    else
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(198, 210 + i, 213, 210 + i, WHITE);
        }
    }

    tft.setCursor(200, row);
    tft.print("h");

    /* volume flow rate */
    tft.setTextSize(3);
    tft.setTextColor(RED);
    row += 70;
    tft.setCursor(20, row);
    tft.print("Volume Flow Rate");

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    tft.setCursor(20, row += 35);
    tft.print("mL per min");

    tft.setCursor(200, row);
    tft.print("mL per h");

    tft.setCursor(15, row += 25);
    tft.print("muL per min");

    tft.setCursor(195, row);
    tft.print("muL per h");

    if (rate_unit == 0)
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(16, 312 + i, 140, 312 + i, WHITE);
        }
    }
    else if (rate_unit == 1)
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(196, 312 + i, 298, 312 + i, WHITE);
        }
    }
    else if (rate_unit == 2)
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(11, 337 + i, 150, 337 + i, WHITE);
        }
    }
    else
    {
        for (int i = 0; i < thikness; i++)
        {
            tft.drawLine(191, 337 + i, 303, 337 + i, WHITE);
        }
    }

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
            tft.fillRect(13, 252, 300, 35, BLACK);

            tft.setTextSize(3);
            tft.setTextColor(RED);
            tft.setCursor(20, 260);
            tft.print("Volume Flow Rate");

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

            tft.fillRect(13, 252, 300, 35, RED);

            tft.setTextSize(3);
            tft.setTextColor(BLACK);
            tft.setCursor(20, 260);
            tft.print("Volume Flow Rate");

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
            if (current_button_col[0] == 0)
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

                current_button_col[0] = 1;
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

                current_button_col[0] = 0;
            }
        }
        else if (current_button_row == 1)
        {
            if (current_button_col[1] == 0)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(87, 210 + i, 127, 210 + i, BLACK);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(198, 210 + i, 213, 210 + i, WHITE);
                }

                current_button_col[1] = 1;
            }
            else
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(87, 210 + i, 127, 210 + i, WHITE);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(198, 210 + i, 213, 210 + i, BLACK);
                }

                current_button_col[1] = 0;
            }
        }
        else if (current_button_row == 2)
        {
            if (current_button_col[2] == 0)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(16, 312 + i, 140, 312 + i, BLACK);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(196, 312 + i, 298, 312 + i, WHITE);
                }

                current_button_col[2] = 1;
            }
            else if (current_button_col[2] == 1)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(196, 312 + i, 298, 312 + i, BLACK);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(11, 337 + i, 150, 337 + i, WHITE);
                }

                current_button_col[2] = 2;
            }
            else if (current_button_col[2] == 2)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(11, 337 + i, 150, 337 + i, BLACK);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(191, 337 + i, 303, 337 + i, WHITE);
                }

                current_button_col[2] = 3;
            }
            else if (current_button_col[2] == 3)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(16, 312 + i, 140, 312 + i, WHITE);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(191, 337 + i, 303, 337 + i, BLACK);
                }

                current_button_col[2] = 0;
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

            tft.fillRect(13, 252, 300, 35, RED);

            tft.setTextSize(3);
            tft.setTextColor(BLACK);
            tft.setCursor(20, 260);
            tft.print("Volume Flow Rate");

            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {
            tft.fillRect(13, 252, 300, 35, BLACK);

            tft.setTextSize(3);
            tft.setTextColor(RED);
            tft.setCursor(20, 260);
            tft.print("Volume Flow Rate");

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
            if (current_button_col[0] == 0)
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

                current_button_col[0] = 1;
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

                current_button_col[0] = 0;
            }
        }
        else if (current_button_row == 1)
        {
            if (current_button_col[1] == 0)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(87, 210 + i, 127, 210 + i, BLACK);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(198, 210 + i, 213, 210 + i, WHITE);
                }

                current_button_col[1] = 1;
            }
            else
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(87, 210 + i, 127, 210 + i, WHITE);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(198, 210 + i, 213, 210 + i, BLACK);
                }

                current_button_col[1] = 0;
            }
        }
        else if (current_button_row == 2)
        {
            if (current_button_col[2] == 0)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(16, 312 + i, 140, 312 + i, BLACK);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(191, 337 + i, 303, 337 + i, WHITE);
                }

                current_button_col[2] = 3;
            }
            else if (current_button_col[2] == 1)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(16, 312 + i, 140, 312 + i, WHITE);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(196, 312 + i, 298, 312 + i, BLACK);
                }

                current_button_col[2] = 0;
            }
            else if (current_button_col[2] == 2)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(196, 312 + i, 298, 312 + i, WHITE);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(11, 337 + i, 150, 337 + i, BLACK);
                }

                current_button_col[2] = 1;
            }
            else if (current_button_col[2] == 3)
            {
                int thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(11, 337 + i, 150, 337 + i, WHITE);
                }

                thikness = 3;
                for (int i = 0; i < thikness; i++)
                {
                    tft.drawLine(191, 337 + i, 303, 337 + i, BLACK);
                }

                current_button_col[2] = 2;
            }
        }
    }
    else if (move == ok_move)
    {
        if (current_button_row == 3)
        {
            time_unit = current_button_col[0];
            volume_unit = current_button_col[1];
            rate_unit = current_button_col[2];

            current_button_row = 0;

            if (new_injection_flag)
            {
                program_state = new_injection_page;
                set_new_injection_page();
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
            else
            {
                program_state = setting_page;
                set_setting_page();
            }
        }
    }
}

/* to-do */
/* tidy up (pretty - choose icon) - syringe picture */
void set_change_syringe_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);

    int row_diff = 75;
    int col = 30;

    int row = 30;
    if (syringe == 1)
    {
        tft.setTextColor(RED);
        tft.setCursor(col, row);
        tft.print("syringe 1");
    }
    else
    {
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        tft.print("syringe 1");
    }

    row += row_diff;
    if (syringe == 2)
    {
        tft.setTextColor(RED);
        tft.setCursor(col, row);
        tft.print("syringe 2");
    }
    else
    {
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        tft.print("syringe 2");
    }

    row += row_diff;
    if (syringe == 3)
    {
        tft.setTextColor(RED);
        tft.setCursor(col, row);
        tft.print("syringe 3");
    }
    else
    {
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        tft.print("syringe 3");
    }

    row += row_diff;
    if (syringe == 4)
    {
        tft.setTextColor(RED);
        tft.setCursor(col, row);
        tft.print("syringe 4");
    }
    else
    {
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        tft.print("syringe 4");
    }

    row += row_diff;
    if (syringe == 5)
    {
        tft.setTextColor(RED);
        tft.setCursor(col, row);
        tft.print("syringe 5");
    }
    else
    {
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        tft.print("syringe 5");
    }

    tft.fillRoundRect(60, 400, 200, 40, 8, RED);

    tft.setCursor(135, 415);
    tft.print("Back");
}

void update_change_syringe_page(int move)
{
    if (move == up_move)
    {
        int last_row, last_col = 30, curr_row, Curr_col = 30;

        char last_message[10];
        sprintf(last_message, "syringe %d", current_button_row + 1);

        if (current_button_row == 0)
        {
            last_row = 30;

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 400 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else if (current_button_row == 1)
        {
            last_row = 105;
            curr_row = 30;
            current_button_row = 0;
        }
        else if (current_button_row == 2)
        {
            last_row = 180;
            curr_row = 105;
            current_button_row = 1;
        }
        else if (current_button_row == 3)
        {
            last_row = 255;
            curr_row = 180;
            current_button_row = 2;
        }
        else if (current_button_row == 4)
        {
            last_row = 330;
            curr_row = 255;
            current_button_row = 3;
        }
        else
        {
            curr_row = 330;

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 400 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }

            current_button_row = 4;
        }

        if (current_button_row == 4)
        {
            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.printf("syringe %d", current_button_row + 1);
        }
        else if (current_button_row == 5)
        {
            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);
        }
        else
        {
            tft.setTextSize(2);

            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);

            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.printf("syringe %d", current_button_row + 1);
        }
    }
    else if (move == down_move)
    {
        int last_row, last_col = 30, curr_row, Curr_col = 30;

        char last_message[10];
        sprintf(last_message, "syringe %d", current_button_row + 1);

        if (current_button_row == 0)
        {
            last_row = 30;
            curr_row = 105;
            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            last_row = 105;
            curr_row = 180;
            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {
            last_row = 180;
            curr_row = 255;
            current_button_row = 3;
        }
        else if (current_button_row == 3)
        {
            last_row = 255;
            curr_row = 330;
            current_button_row = 4;
        }
        else if (current_button_row == 4)
        {
            last_row = 330;

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 400 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 400 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }
            curr_row = 30;
            current_button_row = 0;
        }

        if (current_button_row == 0)
        {
            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.printf("syringe %d", current_button_row + 1);
        }
        else if (current_button_row == 5)
        {
            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);
        }
        else
        {
            tft.setTextSize(2);

            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);

            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.printf("syringe %d", current_button_row + 1);
        }
    }
    else if (move == ok_move)
    {
        if (current_button_row == 5)
        {
            current_button_row = 0;
            if (new_injection_flag)
            {
                program_state = new_injection_page;
                set_new_injection_page();
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
            else
            {
                program_state = setting_page;
                set_setting_page();
            }
        }
    }
}

/* to-do */
/* tidy up (pretty - choose icon) - enter number - not accepting all values */
void set_new_injection_page()
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

    /* volume */
    if (current_button_row == 1)
    {
        tft.setTextColor(RED);
        row = 120, col = 20;
        tft.setCursor(col, row);
        tft.print("Volume:");
        tft.setTextColor(WHITE);
    }
    else
    {
        tft.setTextColor(WHITE);
        row = 120, col = 20;
        tft.setCursor(col, row);
        tft.print("Volume:");
    }

    row += 20;
    tft.drawRect(box_col, row, 230, 30, WHITE);

    tft.setTextSize(1);
    tft.setCursor(unit_col, row + 10);
    tft.print(available_volume_units[volume_unit]);
    tft.setTextSize(2);

    /* or */
    tft.setTextSize(1);
    tft.setCursor(20, 190);
    tft.print("OR");
    tft.setTextSize(2);

    /* time */
    row = 210, col = 20;
    tft.setCursor(col, row);
    tft.print("Volume Flow Rate:");

    row += 20;
    tft.drawRect(box_col, row, 230, 30, WHITE);

    tft.setTextSize(1);
    tft.setCursor(unit_col, row + 10);
    tft.print(available_rate_units[rate_unit]);
    tft.setTextSize(2);

    /* Syringe */
    row += 50, col = 20;
    tft.setCursor(col, row);
    tft.printf("Syringe type %d", syringe);

    if (new_injection_flag)
    {
        if (temp_time != 0)
        {
            tft.setCursor(24, 78);
            tft.printf("%.2f", temp_time);
        }

        if (temp_volume != 0)
        {
            tft.setCursor(24, 148);
            tft.printf("%.2f", temp_volume);
        }

        if (temp_rate != 0)
        {
            tft.setCursor(24, 238);
            tft.printf("%.2f", temp_rate);
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

            current_button_row = 6;
        }
        else if (current_button_row == 1)
        {
            last_row = 120;
            sprintf(last_message, "Volume:");
            curr_row = 50;
            sprintf(curr_message, "Time:");
            current_button_row = 0;
        }
        else if (current_button_row == 2)
        {
            last_row = 210;
            sprintf(last_message, "Volume Flow Rate:");
            curr_row = 120;
            sprintf(curr_message, "Volume:");
            current_button_row = 1;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            curr_row = 210;
            sprintf(curr_message, "Volume Flow Rate:");

            current_button_row = 2;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 5)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
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

            current_button_row = 5;
        }

        if (current_button_row == 2)
        {
            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
        else if (current_button_row == 6)
        {
            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);
        }
        else if (current_button_row == 0 || current_button_row == 1)
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
            curr_row = 120;
            sprintf(curr_message, "Volume:");

            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            last_row = 120;
            sprintf(last_message, "Volume:");
            curr_row = 210;
            sprintf(curr_message, "Volume Flow Rate:");

            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {
            last_row = 210;
            sprintf(last_message, "Volume Flow Rate:");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 310 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 351 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else if (current_button_row == 5)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 392 + i, 180 - i * 2, 34 - i * 2, 8, RED);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 433 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 6;
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
        else if (current_button_row == 3)
        {
            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);
        }
        else if (current_button_row == 1 || current_button_row == 2)
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
                tft.fillRect(20, 140, 230, 30, BLACK);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.1f", temp_volume);

                volume_point_count++;
            }
        }
        else if (current_button_row == 2)
        {
            if (rate_point_count == 0)
            {
                tft.fillRect(20, 230, 230, 30, BLACK);
                tft.drawRect(20, 230, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 238);
                tft.printf("%.1f", temp_rate);

                rate_point_count++;
            }
        }
    }
    else if (move_or_number == ok_move)
    {
        if (current_button_row == 3) // Change Unit
        {
            program_state = change_unit_page;
            current_button_row = 0;
            new_injection_flag = true;
            current_button_col[0] = time_unit;
            current_button_col[1] = volume_unit;
            current_button_col[2] = rate_unit;
            set_change_unit_page();
        }
        else if (current_button_row == 4) // Change Syringe
        {
            program_state = change_syringe_page;
            current_button_row = syringe - 1;
            new_injection_flag = true;
            set_change_syringe_page();
        }
        else if (current_button_row == 5) // Create
        {
            if (temp_time == double(0))
            {
                program_state = new_injection_error_no_time_page;
                current_button_row = 0;
                set_new_injection_error_no_time_page();
            }
            else if (temp_volume == double(0) && temp_rate == double(0))
            {
                program_state = new_injection_error_no_volume_or_rate_page;
                current_button_row = 0;
                set_new_injection_error_no_volume_or_rate_page();
            }
            else if (temp_volume == double(0))
            {
                input_time = temp_time;
                input_rate = temp_rate;
                temp_time = 0;
                temp_rate = 0;
                program_state = injection_progress_page;
                current_button_row = 0;
                set_injection_progress_page();
            }
            else if (temp_rate == double(0))
            {
                input_time = temp_time;
                input_volume = temp_volume;
                temp_time = 0;
                temp_volume = 0;
                program_state = injection_progress_page;
                current_button_row = 0;
                set_injection_progress_page();
                // stepper_move();
            }
            else if (temp_volume != double(0) && temp_rate != double(0))
            {
                program_state = new_injection_error_both_volume_and_rate_page;
                current_button_row = 0;
                set_new_injection_error_both_volume_and_rate_page();
            }
        }
        else if (current_button_row == 6) // Back
        {
            program_state = menu_page;
            temp_volume = 0;
            temp_time = 0;
            temp_rate = 0;
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
            tft.fillRect(20, 140, 230, 30, BLACK);
            tft.drawRect(20, 140, 230, 30, WHITE);

            temp_volume = 0;
            volume_point_count = 0;
        }
        else if (current_button_row == 2)
        {
            tft.fillRect(20, 230, 230, 30, BLACK);
            tft.drawRect(20, 230, 230, 30, WHITE);

            temp_rate = 0;
            rate_point_count = 0;
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

                tft.fillRect(20, 140, 230, 30, BLACK);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.0f", temp_volume);
            }
            else if (volume_point_count == 1)
            {
                temp_volume = temp_volume + (double(move_or_number) / 10.0);
                tft.fillRect(20, 140, 230, 30, BLACK);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.1f", temp_volume);
                volume_point_count++;
            }
            else if (volume_point_count == 2)
            {
                temp_volume = temp_volume + (double(move_or_number) / 100.0);
                tft.fillRect(20, 140, 230, 30, BLACK);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.2f", temp_volume);
                volume_point_count++;
            }
        }
        else if (current_button_row == 2) // rate
        {
            if (rate_point_count == 0)
            {
                temp_rate *= 10;
                temp_rate += move_or_number;

                tft.fillRect(20, 230, 230, 30, BLACK);
                tft.drawRect(20, 230, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 238);
                tft.printf("%.0f", temp_rate);
            }
            else if (rate_point_count == 1)
            {
                temp_rate = temp_rate + (double(move_or_number) / 10.0);
                tft.fillRect(20, 230, 230, 30, BLACK);
                tft.drawRect(20, 230, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 238);
                tft.printf("%.1f", temp_rate);
                rate_point_count++;
            }
            else if (rate_point_count == 2)
            {
                temp_rate = temp_rate + (double(move_or_number) / 100.0);
                tft.fillRect(20, 230, 230, 30, BLACK);
                tft.drawRect(20, 230, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 238);
                tft.printf("%.2f", temp_rate);
                rate_point_count++;
            }
        }
    }
}

/* */
void set_new_injection_error_no_time_page()
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
    tft.print("Time");

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

void update_new_injection_error_no_time_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = new_injection_page;
        current_button_row = 0;
        time_point_count = 0;
        new_injection_flag = true;
        set_new_injection_page();
    }
}

/* */
void set_new_injection_error_no_volume_or_rate_page()
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
    tft.print("Volume or Rate");

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

void update_new_injection_error_no_volume_or_rate_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = new_injection_page;
        current_button_row = 1;
        volume_point_count = 0;
        rate_point_count = 0;
        new_injection_flag = true;
        set_new_injection_page();
    }
}

/* */
void set_new_injection_error_both_volume_and_rate_page()
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
    tft.print("only Volume or Rate");

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

void update_new_injection_error_both_volume_and_rate_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = new_injection_page;
        temp_volume = 0;
        volume_point_count = 0;
        temp_rate = 0;
        rate_point_count = 0;
        current_button_row = 1;
        new_injection_flag = true;
        set_new_injection_page();
    }
}

/* to-do */
/* tidy up (pretty - show remaining - replace real time and vol and rate - update page in another core) - animation */
void set_injection_progress_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* volume */
    int row = 50, col = 10;
    tft.setCursor(col, row);
    tft.printf("Remaining Volume %d %s", 1000, available_volume_units[volume_unit]);

    row += 30, col = 10;
    tft.drawRect(col, row - 5, 300, 25, WHITE);

    /* time */
    row = 150, col = 10;
    tft.setCursor(col, row);
    tft.printf("Remaining Time %d:%d", 1, 20);

    row += 30, col = 10;
    tft.drawRect(col, row - 5, 300, 25, WHITE);

    /* rate */
    row = 280, col = 10;
    tft.setCursor(col, row);
    tft.printf("Current Rate %d %s/%s", 1111, available_volume_units[volume_unit], available_time_units[time_unit]);

    /* animation */
    row = 350, col = 10;
    tft.setCursor(col, row);
    tft.print("Animation");
}

void update_injection_progress_page(int move)
{
    if (move == up_move)
    {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 250;
            curr_row = 200;
        }
        else if (current_button_row == 1)
        {
            last_row = 200;
            curr_row = 250;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        current_button_row++;
        current_button_row %= 2;
    }
    else if (move == down_move)
    {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 250;
            curr_row = 200;
        }
        else if (current_button_row == 1)
        {
            last_row = 200;
            curr_row = 250;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        current_button_row++;
        current_button_row %= 2;
    }
    else if (move == ok_move)
    {
        if (current_button_row == 0)
        {
            program_state = change_unit_page;
            current_button_row = 0;
        }
        else if (current_button_row == 1)
        {
            program_state = change_syringe_page;
            current_button_row = 0;
        }
    }
}

/* to-do */
/* tidy up */
void set_end_page()
{
    tft.fillScreen(BLACK);

    tft.setTextColor(WHITE);

    /* injection end */
    tft.setTextSize(3);
    tft.setCursor(40, 50);
    tft.print("Injection End");
    tft.setTextSize(2);

    /* volume */
    tft.setCursor(10, 150);
    tft.print("Total injected Volume");

    tft.setCursor(10, 170);
    tft.printf("%d %s of %d %s", 1, available_volume_units[volume_unit], 1, available_volume_units[volume_unit]);

    /* time */
    tft.setCursor(10, 230);
    tft.printf("Total passed Time: %d:%d", 1, 20);

    /* buttons */
    int width = 180, height = 32, rounding_facotr = 8;

    int col = 70, row = 320;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);
    tft.drawRoundRect(col, row, width, height, rounding_facotr, WHITE);

    row += 50;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);
    tft.drawRoundRect(col, row, width, height, rounding_facotr, WHITE);

    col = 85, row = 328;
    tft.setCursor(col, row);
    tft.print("New Injection");

    col = 135, row += 50;
    tft.setCursor(col, row);
    tft.print("EXIT");
}

void update_end_page(int move)
{
    if (move == up_move)
    {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 250;
            curr_row = 200;
        }
        else if (current_button_row == 1)
        {
            last_row = 200;
            curr_row = 250;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        current_button_row++;
        current_button_row %= 2;
    }
    else if (move == down_move)
    {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0)
        {
            last_row = 250;
            curr_row = 200;
        }
        else if (current_button_row == 1)
        {
            last_row = 200;
            curr_row = 250;
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }

        for (int i = 0; i < thick; i++)
        {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, RED);
        }

        current_button_row++;
        current_button_row %= 2;
    }
    else if (move == ok_move)
    {
        if (current_button_row == 0)
        {
            program_state = change_unit_page;
            current_button_row = 0;
        }
        else if (current_button_row == 1)
        {
            program_state = change_syringe_page;
            current_button_row = 0;
        }
    }
}

double calculate_height()
{
    return input_volume / (PI * syringe * syringe) * 1000;
}

void stepper_move()
{
    double height = calculate_height();
    digitalWrite(dir, LOW);

    int rounds = 10000 * height / 3.5;                    // 101,057.14285714285714285714285714
    int calculate_delay = input_time * 30000000 / rounds; // 296.86216689591022888073067674679

    Serial.println(rounds);
    Serial.println(calculate_delay);

    for (int Index = 0; Index < 101057; Index++)
    {
        digitalWrite(step, HIGH);

        delayMicroseconds(297);

        digitalWrite(step, LOW);

        delayMicroseconds(297);
    }
}