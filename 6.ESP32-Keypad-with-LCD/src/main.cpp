#include <Keypad.h>
#include <Adafruit_GFX.h>
#include <MCUFRIEND_kbv.h>

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
#define injection_progress_page 3
#define end_page 4

#define up_move 20
#define right_move 60
#define down_move 80
#define left_move 40
#define ok_move 50

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
void set_injection_progress_page();
void update_injection_progress_page(int);
void set_end_page();
void update_end_page(int);

void up();
void right();
void down();
void left();
void ok();

MCUFRIEND_kbv tft(LCD_CS, LCD_RS, LCD_WR, LCD_RD, LCD_RESET);

int program_state;

char volume_unit[4] = "mL";
char time_unit[4] = "min";
char rate_unit[12] = "mL per min";

int syringe = 0;

const byte ROWS = 4;
const byte COLS = 3;

byte rowPins[ROWS] = {23, 22, 21, 19};
byte colPins[COLS] = {18, 5, 0};

char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {' ', '0', ' '}};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

int current_button_row = 0;
int current_button_col[3] = {0};

void setup()
{
    uint16_t ID = tft.readID();
    tft.begin(ID);
    program_state = menu_page;
    set_menu_page();
    Serial.begin(9600);
}

void loop()
{
    char key = keypad.getKey();

    if (key == '2')
    {
        up();
    }
    else if (key == '6')
    {
        right();
    }
    else if (key == '8')
    {
        down();
    }
    else if (key == '4')
    {
        left();
    }
    else if (key == '5')
    {
        ok();
    }
}

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

void right()
{
    if (program_state == change_unit_page)
    {
        update_change_unit_page(right_move);
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
    else if (program_state == injection_progress_page)
    {
        update_injection_progress_page(ok_move);
    }
    else if (program_state == ok_move)
    {
        update_end_page(ok_move);
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
            set_change_unit_page();
        }
        else if (current_button_row == 1)
        {
            program_state = change_syringe_page;
            current_button_row = 0;
            set_change_syringe_page();
        }
        else
        {
            program_state = menu_page;
            current_button_row = 0;
            set_menu_page();
        }

        current_button_row = 0;
    }
}

/* to-do */
/* tidy up (pretty - choose icon (up-down & right-left)) - micro symbol - division */
void set_change_unit_page()
{
    tft.fillScreen(BLACK);

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

    int thikness = 3;
    for (int i = 0; i < thikness; i++)
    {
        tft.drawLine(87, 105 + i, 115, 105 + i, WHITE);
    }

    tft.setCursor(180, row);
    tft.print("muL");

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

    thikness = 3;
    for (int i = 0; i < thikness; i++)
    {
        tft.drawLine(87, 210 + i, 127, 210 + i, WHITE);
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

    thikness = 3;
    for (int i = 0; i < thikness; i++)
    {
        tft.drawLine(16, 312 + i, 140, 312 + i, WHITE);
    }

    tft.setCursor(200, row);
    tft.print("mL per h");

    tft.setCursor(15, row += 25);
    tft.print("muL per min");

    tft.setCursor(195, row);
    tft.print("muL per h");

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
            if (current_button_col[0] == 0)
            {
                sprintf(volume_unit, "mL");
            }
            else
            {
                sprintf(volume_unit, "muL");
            }

            if (current_button_col[1] == 0)
            {
                sprintf(time_unit, "min");
            }
            else
            {
                sprintf(time_unit, "h");
            }

            if (current_button_col[2] == 0)
            {
                sprintf(rate_unit, "mL per min");
            }
            else if (current_button_col[2] == 1)
            {
                sprintf(rate_unit, "mL per h");
            }
            else if (current_button_col[2] == 2)
            {
                sprintf(rate_unit, "muL per min");
            }
            else
            {
                sprintf(rate_unit, "muL er h");
            }

            program_state = setting_page;
            current_button_row = 0;
            for (int i = 0; i < 3; i++)
            {
                current_button_col[i] = 0;
            }
            set_setting_page();
        }
        else if (current_button_row == 4)
        {
            program_state = setting_page;
            current_button_row = 0;
            for (int i = 0; i < 3; i++)
            {
                current_button_col[i] = 0;
            }
            set_setting_page();
        }
    }
}

/* to-do */
/* tidy up (pretty - choose icon) - syringe picture */
void set_change_syringe_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(RED);

    int row_diff = 75;
    int col = 30;

    int row = 30;
    tft.setCursor(col, row);
    tft.print("syringe 1");

    tft.setTextColor(WHITE);

    row += row_diff;
    tft.setCursor(col, row);
    tft.print("syringe 2");

    row += row_diff;
    tft.setCursor(col, row);
    tft.print("syringe 3");

    row += row_diff;
    tft.setCursor(col, row);
    tft.print("syringe 4");

    row += row_diff;
    tft.setCursor(col, row);
    tft.print("syringe 5");

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
            char curr_message[10];
            sprintf(curr_message, "syringe %d", current_button_row + 1);

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
        else
        {
            tft.setTextSize(2);
            
            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);

            char curr_message[10];
            sprintf(curr_message, "syringe %d", current_button_row + 1);

            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
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
        } else {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 400 + i, 200 - i * 2, 40 - i * 2, 8, RED);
            }
            curr_row = 30;
            current_button_row = 0;
        }

        if (current_button_row == 0)
        {
            char curr_message[10];
            sprintf(curr_message, "syringe %d", current_button_row + 1);

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
        else
        {
            tft.setTextSize(2);
            
            tft.setTextColor(WHITE);
            tft.setCursor(last_col, last_row);
            tft.print(last_message);

            char curr_message[10];
            sprintf(curr_message, "syringe %d", current_button_row + 1);

            tft.setTextColor(RED);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
    }
    else if (move == ok_move)
    {
        if (current_button_row == 5)
        {
            program_state = setting_page;
            current_button_row = 0;
            set_setting_page();
        } else {
            syringe = current_button_row + 1;
            program_state = setting_page;
            current_button_row = 0;
            set_setting_page();
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

    /* volume */
    int row = 50, col = 20;
    tft.setCursor(col, row);
    tft.print("Volume:");

    col += 90;
    tft.drawRect(col, row - 5, unit_col - 30 - 90, 25, WHITE);

    tft.setTextSize(1);
    tft.setCursor(unit_col, row);
    tft.print(volume_unit);
    tft.setTextSize(2);

    /* time */
    row = 150, col = 20;
    tft.setCursor(col, row);
    tft.print("Time:");

    col += 65;
    tft.drawRect(col, row - 5, unit_col - 30 - 65, 25, WHITE);

    tft.setTextSize(1);
    tft.setCursor(unit_col, row);
    tft.print(time_unit);
    tft.setTextSize(2);

    /* or */
    tft.setTextSize(1);
    tft.setCursor(20, 190);
    tft.print("OR");
    tft.setTextSize(2);

    /* time */
    row = 230, col = 20;
    tft.setCursor(col, row);
    tft.print("Flow Rate:");

    col += 125;
    tft.drawRect(col, row - 5, unit_col - 30 - 125, 25, WHITE);

    tft.setTextSize(1);
    tft.setCursor(unit_col, row);
    char message[12];
    sprintf(message, "%s/%s", volume_unit, time_unit);
    tft.print(message);
    tft.setTextSize(2);

    /* buttons */
    int width = 180, height = 32, rounding_facotr = 8;

    col = 70, row = 320;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);
    tft.drawRoundRect(col, row, width, height, rounding_facotr, WHITE);

    row += 50;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);
    tft.drawRoundRect(col, row, width, height, rounding_facotr, WHITE);

    row += 50;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, RED);
    tft.drawRoundRect(col, row, width, height, rounding_facotr, WHITE);

    col = 95, row = 328;
    tft.setCursor(col, row);
    tft.print("Change Unit");

    col = 78, row += 50;
    tft.setCursor(col, row);
    tft.print("Change Syringe");

    col = 125, row += 50;
    tft.setCursor(col, row);
    tft.print("Create");
}

void update_new_injection_page(int move)
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
/* tidy up (pretty - show remaining - replace real time and vol and rate - update page in another core) - animation */
void set_injection_progress_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* volume */
    int row = 50, col = 10;
    tft.setCursor(col, row);
    char message[100];
    sprintf(message, "Remaining Volume %d %s", 1000, volume_unit);
    tft.print(message);

    row += 30, col = 10;
    tft.drawRect(col, row - 5, 300, 25, WHITE);

    /* time */
    row = 150, col = 10;
    tft.setCursor(col, row);
    message[0] = '\0';
    sprintf(message, "Remaining Time %d:%d", 1, 20);
    tft.print(message);

    row += 30, col = 10;
    tft.drawRect(col, row - 5, 300, 25, WHITE);

    /* rate */
    row = 280, col = 10;
    tft.setCursor(col, row);
    message[0] = '\0';
    sprintf(message, "Current Rate %d %s/%s", 1111, volume_unit, time_unit);
    tft.print(message);

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
    char message[100];
    sprintf(message, "%d %s of %d %s", 1, volume_unit, 1, volume_unit);
    tft.print(message);

    /* time */
    tft.setCursor(10, 230);
    message[0] = '\0';
    sprintf(message, "Total passed Time: %d:%d", 1, 20);
    tft.print(message);

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
