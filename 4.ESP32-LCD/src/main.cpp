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

#define ml "mL"
#define mul "muL"
#define min "min"
#define hour "h"

MCUFRIEND_kbv tft(LCD_CS, LCD_RS, LCD_WR, LCD_RD, LCD_RESET);
int program_state;
bool page_shown;

char volume_unit[4] = mul;
char time_unit[4] = min;

/* to-do */
/* tidy up (pretty - choose icon) - picture */
void set_menu_page()
{
    tft.fillScreen(BLACK);

    tft.fillRoundRect(60, 250, 200, 40, 8, RED);
    tft.drawRoundRect(60, 250, 200, 40, 8, WHITE);

    tft.fillRoundRect(60, 300, 200, 40, 8, RED);
    tft.drawRoundRect(60, 300, 200, 40, 8, WHITE);

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

/* to-do */
/* tidy up (pretty - choose icon) */
void set_setting_page()
{
    tft.fillScreen(BLACK);

    tft.fillRoundRect(60, 200, 200, 40, 8, RED);
    tft.drawRoundRect(60, 200, 200, 40, 8, WHITE);

    tft.fillRoundRect(60, 250, 200, 40, 8, RED);
    tft.drawRoundRect(60, 250, 200, 40, 8, WHITE);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    tft.setCursor(100, 215);
    tft.print("Change Unit");

    tft.setCursor(80, 265);
    tft.print("Change Syringe");
}

/* to-do */
/* tidy up (pretty - choose icon (up-down & right-left)) - micro symbol - division */
void set_change_unit_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(3);
    tft.setTextColor(RED);

    tft.setCursor(100, 60);
    tft.print("Volume");

    tft.setCursor(120, 200);
    tft.print("Time");

    tft.setCursor(20, 340);
    tft.print("Volume Flow Rate");

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* volume */
    tft.setCursor(90, 110);
    tft.print("mL");

    tft.setCursor(180, 110);
    tft.print("muL");

    /* time */
    tft.setCursor(90, 250);
    tft.print("min");

    tft.setCursor(200, 250);
    tft.print("h");

    /* volume flow rate */
    tft.setCursor(20, 390);
    tft.print("mL per min");

    tft.setCursor(200, 390);
    tft.print("mL per h");

    tft.setCursor(15, 415);
    tft.print("muL per min");

    tft.setCursor(195, 415);
    tft.print("muL per h");
}

/* to-do */
/* tidy up (pretty - choose icon) - syringe picture */
void set_change_syringe_page()
{
    tft.fillScreen(BLACK);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    int row_diff = 90;
    int col = 30;

    int row = 50;
    tft.setCursor(col, row);
    tft.print("syring 1");

    row += row_diff;
    tft.setCursor(col, row);
    tft.print("syring 2");

    row += row_diff;
    tft.setCursor(col, row);
    tft.print("syring 3");

    row += row_diff;
    tft.setCursor(col, row);
    tft.print("syring 4");

    row += row_diff;
    tft.setCursor(col, row);
    tft.print("syring 5");
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

void setup()
{
    uint16_t ID = tft.readID();
    tft.begin(ID);
    program_state = menu_page;
    page_shown = false;
}

void loop()
{
    if (!page_shown)
    {
        if (program_state == menu_page)
        {
            set_menu_page();
            page_shown = true;
        }
        else if (program_state == setting_page)
        {
            set_setting_page();
            page_shown = true;
        }
        else if (program_state == change_unit_page)
        {
            set_change_unit_page();
            page_shown = true;
        }
        else if (program_state == change_syringe_page)
        {
            set_change_syringe_page();
            page_shown = true;
        }
        else if (program_state == new_injection_page)
        {
            set_new_injection_page();
            page_shown = true;
        }
        else if (program_state == injection_progress_page)
        {
            set_injection_progress_page();
            page_shown = true;
        }
        else if (program_state == end_page)
        {
            set_end_page();
            page_shown = true;
        }
    }
}