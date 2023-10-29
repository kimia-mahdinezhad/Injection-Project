# Injection Project
### In this document, we will discuss the steps for controlling an injection device during the internship course I took as part of my university program.

## Overview
The following images were captured from the device's LCD, which I designed and used to control the injection device by programming the stepper motor.

![](https://i.ibb.co/JmtNqVg/4-1.jpg)

![](https://i.ibb.co/RPZXnfv/4-3.jpg)

![](https://i.ibb.co/zRx00BT/4-4.jpg)

![](https://i.ibb.co/rQbL1gT/4-5.jpg)

![](https://i.ibb.co/sygQcyV/4-6.jpg)

![](https://i.ibb.co/T10kwvP/4-7.jpg)

![](https://i.ibb.co/JFKPzpY/4-8.jpg)

![](https://i.ibb.co/6nNCDbk/4-9.jpg)

## Main Text

In each part of the main text of the report, I will first explain the main task and then explain the steps taken during reaching the defined goal. In general, the main text is divided into 4 parts, each part has smaller parts. The names of sections and sub-sections are listed in full in the list section.

### 1. Getting to know circuit and data protection
   - **1.1. Ways to protect circuits**
     - Task Description: Find ways to protect circuits.
     - **1.1.1. Threats**
       - The meaning of threat is predictable and logical threats and does not mean external threats such such as crushing the circuit under the wheel of a car.
       - **1.1.1.1. Types of threats**
         - Transient: Noise Spike and Surge
         - Steady State: Over Voltage / Over Current and Reverse Polarity
       - **1.1.1.2. Noise Spike**
         - Noise refers to the sudden increase in voltage that occurs in less than one millisecond.
         - *ESD (Electrical Discharge) is a type of Noise Spike threat:*
           - **Reasons:**
             - The contact of a charged human (electrical charge) with an integrated circuit.
             - Contact of a charged IC with a metal plate connected to ground.
             - Contact of a loaded device with an IC.
             - Induction of an electromagnetic field by very high voltage.
           - **Damages:**
             - Severe damage to ICs such as gate oxide (MOSTETs), metallization and PN junction.
           - **Standards:**
             - Device level: checking the effect of ESD on the chip itself.
             - *Qualifications:*
               - Human body model (HBM)
               - Car model (MM)
               - Pregnant device model (CDM)
               - Transmission Line Pulse (TLP)
             - System level: checking the impact of ESD on the system and in relation to different parts.
             - *Qualifications:*
               - Electronic Discharge Immunity Test or IEC 510000-4-2
               - ISO 10605
       - **1.1.1.3. Surge**
         - It means a sudden increase in voltage that lasts more than 1 millisecond. This threat can burn or cook different parts of the circuit.
         - *The safe voltage in this picture is between 230 and 275 (based on the power of European countries).*
         - *TVS (Transient Voltage Suppression) is a type of Surge threats:*
           - *Reasons:* Passive load on motors, solenoid valves and converters.
           - *Damages:* Very high temperature damage to PN junctions and metallization. Compared to ESD, it is lower in voltage, but has more current and affects for a longer period of time.

- **1.1.2. Circuit protection against threats**
  - **Protection** means that we want to always stay in the blue range. It means that we have passed the normal state, but we want to prevent serious damage to the circuit and reaching the limit of current or voltage damage.

  - Even without trying to use circuit protection methods, paying attention to different parts of the circuit and how these parts are related to each other and paying attention to the behavior of the circuit can protect the circuit against many threats.

  - **1.1.2.1. Types of protection**
    - Protection against transient threats:
      - Passive: filters (inductors and capacitors) and resistors.
      - Active: Zener and TVS diodes and Silicon Controlled Rectifier.

    - Protection against persistent threats:
      - Circuit: fuses, circuit breakers, GFCIs, AFCIs, high-low switches, OVP-OVCs, and overload relays.
      - **1.1.2.2. Supplementary Protector Circuit Breaker**
        - If there is a fault, it will break only one of the circuits and cannot be used as a single unit.
          - Only one part of the circuit to which this circuit breaker is connected is cut off.
      - **1.1.2.3. GFCI or Ground Fault Circuit Interrupt**
        - If there is an unwanted connection between the circuit and the ground, it immediately cuts off the power source to the circuit.
          - For example, if there is an unwanted connection between the metal box and the circuit, if a person touches or makes contact with the seemingly harmless metal box, it will cause electrocution or even death.
          - To avoid this dangerous situation, a very simple circuit is closed as below.
      - **1.1.2.4. AFCI or Arc Fault Circuit Interrupt**
        - This method detects improper wiring by using appropriate sensors and prevents the device from catching fire and other devices connected to it from being damaged. In diagnosing wrong wiring, we must pay attention to the difference between normal or wrong communication. For example, a light switch can form an open circuit while this circuit is a normal circuit.
      - **1.1.2.5. High-Low Switching**
        - There is an off button in all circuits and devices, but where this button is placed on the device can make a big difference.
          - As seen below, if the button is placed under the device, it is both difficult to access and can be dangerous if there is an unwanted connection to the ground.
      - **1.1.2.6. OVP (Over Voltage Protection) - OCP (Over Current Protection)**
        - In these protection methods, the input voltage or current value is checked automatically, and when these values exceed their limits, the damaged part of the circuit is cut off.
      - **1.1.2.7. Overload Relay**
        - This protection method is used when the effect of circuit failure remains for a long time. This device, which is just a normal sensor, cannot break the circuit by itself, and if the current continues to increase after a certain period of time, it will break the circuit by notifying the circuit breaker or contactor.
          - **Types of Overload Relay:**
            - An increase in the temperature of the circuit is used to increase the length of a metal strap, which causes the contactor to be alerted by expansion.
            - It uses an increase in temperature to create steam and boil a liquid, which causes an increase in the volume of this part, which compresses a spring whose one end is in the liquid part and the other end is in the solid part, and causes the contactor to be alerted.
            - It uses digital methods and a small computer to check the flow.
          - Overload relays can be reused, but like circuit breakers, they must be reset automatically or manually.
- **1.2. Ways to protect data**
  - Task description: Find ways to protect data.

  - **1.2.1. Data definition**
    - The data that is defined as privacy can be divided into two types of personal data related to health and personal data related to identification.
      - **Personal data related to health (Personal Health Information or (PHI)):** including health history, insurance used and its provider, legal guardian, etc.
      - **Personal identification information (PII):** including name, address, email, fingerprint, etc.

  - **1.2.2. The difference between data protection and data privacy**
    - With data protection, we implement the laws that are addressed by data privacy. Accordingly, data privacy emphasizes the fact that who has access to what kind of data, and data protection is about applying these laws. It is emphasized.

  - **1.2.3. Principles of data protection**
    - - Availability of data: ensuring that all users in the network have access to the provided data (although depending on their access level)
      - Data life cycle management: automatic transfer of data to offline or online storage.
      - Life cycle management of information: protection of information collected from various sources against machine damage, virus attacks, user errors, outage of facilities, etc.

  - **1.2.4. Data protection technology**
    - Various management options can help restrict access, monitor activity, or defend the system against threats. Therefore, we can choose the technologies that are most suitable for use.
      - - Data discovery: determining the types of data and identifying sensitive data that may be subject to regulations.
        - Prevent data loss: Appropriate strategies should be used to prevent theft, loss or accidental deletion.
        - Memory with internal protection.
        - Backup.
        - Firewall: helps monitor and filter network traffic and ensures that only authorized users can access and transfer data.
        - Authentication and authorization: ways for users and assigning their access levels correctly.
        - Encryption: data is changed by encryption key that prevents data from being stolen.
        - Endpoint Protection: Protect and monitor network gateways and filter traffic as needed.
        - Delete data.
        - Disaster recovery.

  - **1.2.5. Prevent network data loss**
    - - Manage session-level (not packet-level) inspection of network traffic on all network ports.
      - Provide the possibility to view protocols, channels, and applications in the network. Network data loss prevention solutions must understand a wide variety of network traffic to determine how people are communicating and extract information for analysis.
      - Ability to extract readable content and related cloud data in meetings, as well as any attachments and compressed files for analysis.
      - Explain several complex content analysis technologies to identify sensitive information for accurate content detection.
      - Providing an engine to enforce rules to identify network sessions that violate rules.
      - Prevent a single network that violates the rules on all ports to prevent data leakage in all network traffic.
      - Capturing on-premise or cloud data for up to 360 days for real-time analysis.

  - **1.2.6. Firewall**
    - The network layer or packet filterers inspect packets at a relatively low level of the TCP/IP protocol stack and do not allow packets to pass through the firewall unless they match a set of rules, where the source and destination of the rule set are the basis of the protocol (IP Address) and ports. Firewalls that perform network layer inspection are better than similar devices that perform application layer inspection. The disadvantage is that unwanted programs or software can pass through authorized ports. For example, outgoing Internet traffic through HTTP and HTTPS web protocols, port 80 and 443.

  - **1.2.7. Types of encryption**
    - - Symmetric encryption: it is best used for private and in-package systems because it uses a key for encryption-decryption and if the key is shared, data can be stolen.
      - Asymmetric encryption: best used for private and public use and throughout the system (such as a system that uses the Internet) because it uses pairs of keys that are mathematically connected to each other so that data cannot be stolen.

  - **1.2.8. Cryptographic algorithms**
    - - Triple DES: DES algorithm is executed 3 times (encrypt-decrypt-encrypt again) and can give one or two and sometimes three keys. Since DES algorithm uses block encryption method, this algorithm is vulnerable to block collision attack.
      - RSA: famous for long key length. It is widely used on the Internet. It is part of many protocols such as SSH, OpenPGB, etc. Browsers use this algorithm to establish a secure connection over the Internet.
      - Two fish: which is one of the fastest algorithms. It has a complicated key and is in some of the best free software.
      - Elliptic Curve Cryptography: Improved RSA better security with shorter keys. Asymmetric method.
- **1.2.9. Data encryption in transit vs. at rest**
  - Data encryption in transport: data in case of transmission are at high risk due to the need for decryption (if the selected algorithm is strengthened) and the transmission itself.
  - Encryption at rest: While data is stored, it is still at great risk because the data is more important. But system security can block unwanted access at a certain level.

- **1.2.10. Hack encrypted data**
  - Malware on Endpoint Devices: If the endpoint device uses a full disk encryption method, attackers may use malware to obtain the key.
  - Brute Force Attack: If the key is short (255 bits is recommended), the attacker can guess the key until he finds the encryption key.
  - Cryptanalysis: finding a weakness and using it against the system.
  - Side-Channel Attack: Finding an error or weakness in the code that prevents encryption by using it.
  - Social Engineering Attacks: the easiest way to trick a privileged user (by phishing) to get the key.
  - Inside Threats: If privileged users try to act against the system and abuse the situation.

- **1.2.11. Data encryption solution**
  - Use of standard strong encryption: use in industry AES with 256 bits.
  - Data encryption at rest.
  - Data encryption in transit.
  - Grain control: Encrypting not all data but sensitive data.
  - Key management: the most important step is to perform these steps: encrypt, send, backup, destroy if access is revoked.
  - Implementation of policies: set encryption policies and implement them automatically.
  - Always-on-encryption: Always keep sensitive data encrypted. Whether the data is copied, emailed or redefined.

- **1.2.12. Cryptographic trends**
  - BYOE (Bring Your Own Encryption): Allow customers to manage their encryption keys by virtualizing encryption software.
  - EaaS (Encryption as a Service: They allow users to use encryption on a pay-per-use basis. They usually offer full disk encryption, database encryption or file encryption.
  - Encryption based on cloud storage: It is a service that cloud storage providers use encryption algorithms to encrypt all the data stored in the cloud storage. But customers should read the provider's policies thoroughly to choose the right encryption for their data.
  - E2EE (End-to-End Encryption): it makes sure that the data is not seen by anyone when it is sent, but TSL (encryption channel construction) does not guarantee E2EE because the attacker can access the data before encryption or after decryption. get access
  - Encryption at the field level: data is encrypted in certain fields of the webpage, such as card number and...
  - Encrypting consecutive links: data is encrypted before leaving the network and decrypted as soon as it enters the next network and encrypted again before leaving this network. This operation is repeated until it reaches the destination.
  - Encryption at the network level: In this method, encryption algorithms are applied in the network forwarding layer, i.e. layer 3 in the OSI model. This layer is above the link layer and below the application layer. This encryption is provided by Internet Protocol Security or IPsec. When used with a set of IETF standards, a platform for private communication is created.

- **1.2.13. Protection endpoint**
  - Using machine learning classification to identify zero-day threats.
  - Using antimalware and advanced antiviruses.
  - Improve web security.
  - Using data classification and preventing data loss.
  - Use of firewall to identify attackers.
  - Using an email gateway to block phishing for employees who may have been threatened.
  - Using protection methods against threats to prevent unwanted events.
  - Focusing on endpoint management to improve visibility.
  - Using endpoint email and disk encryption.

- **2. The first project (reading the values of digital counters)**
  - **2.1. RS485 and Modbus**
    - **2.1.4. Code**
      - **2.1.4.2. Slave**
        - **Pins related to the board:**
          - **Arduino:**
            ```cpp
            #define LED 13
            #define SLAVE_EN 8
            ```
          - **ESP32:**
            ```cpp
            #define LED 2
            #define SLAVE_EN 5
            ```
        - The following codes are similar on each board:
        - **Setup:**
          ```cpp
          void setup()
          {
              pinMode(LED, OUTPUT);
              pinMode(SLAVE_EN, OUTPUT);
              Serial.begin(9600);
              digitalWrite(SLAVE_EN, LOW);
          }
          ```
          - We define the LED pin as Output.
          - Also, by defining Slave Enabler as Output, you can toggle between receiving and sending.
          - Finally, we define Serial with a baud rate of 9600.
        - **Loop:**
          ```cpp
          void loop()
          {
              digitalWrite(MASTER_EN, HIGH);
              delay(5);

              Serial.println('A');
              Serial.flush();

              digitalWrite(MASTER_EN, LOW);
              delay(500);
          }
          ```
          - In the loop, we check if Serial is active or not. Then we read the Serial value. If its character is equal to A, we toggle the LED.

  - **2.2. Getting to know digital counters and reading their values**
    - **Description of tasks:** Read the values of digital counters using the Modbus protocol.
    - **2.2.1. What is a digital counter?**
      - A digital meter is a device for displaying various electrical parameters such as voltage, current, power, and energy, etc. These counters can support the Modbus protocol, and therefore we can communicate with the counter using RS485.
    - **2.2.2. What is 3-phase power?**
      - Usually, the power used in a data center is 3-phase AC. In these circuits, the copper wires are 120 degrees apart, and as a result, by rotating a magnet in the middle of these 3 wires, electrons are attracted to the north pole of the magnet and repelled from its south pole.
      - Therefore, with the rotation of the magnet, current is maintained in at least 2 of the wires at any moment.
      - Therefore, according to the above images, we have:
      - Therefore, the corresponding values are different at each moment, and the peaks and valleys occur at different times. In fact, they occur with a 120-degree difference. So to display all the values together we have:
      - So to calculate the voltage we have:
      - If it is said that the current voltage in a 3-phase circuit is 208 volts, then there is a voltage of 120 volts in each wire.
      - Also, if it is said that the current voltage in a 3-phase circuit is 400 volts, then there is a voltage of 230 volts in each wire.
      - By connecting both wires, the said voltage can be achieved. If each wire can pass a current of 30 amps, then it will be power, while if we did not use a 3-phase circuit and the voltage is 208 volts and the current in each wire is 30 amps, the power can only have a value of 6.2, which shows that The use of a 3-phase circuit increases power.
    - **2.2.3. Connections**
      - To communicate with Arduino or ESP, we can use one of the following circuits:
      - **Connectivity Diagram**
      - **Real Connections**
      - **Real Parallel Connections**
    - **2.2.4. Code**
      - For the code part, we generally need to start the serial monitor and use the appropriate baud rate and delay values. But the data may be given in the form of a packet, for which the following ready libraries can be used: (Simple Modbus Master - EmonLib - Daromer)
- **3. The second project (control of the vaccine injection device)**
  - **3.1. Device Description**
    - In this project, we will control the motor of a vaccine injection machine. The vaccine injection device is a device designed by the project mechanics group, which is driven by a stepper motor with the ability to inject 2 syringes at the same time.
    - This device includes a fixed platform where the motor and syringes are placed in this chamber, and injection and suction activities are performed by a mobile platform that moves horizontally. The moving platform is connected to the motor, and the purpose of controlling the motor is to move the moving platform at a suitable rate and speed, which is determined by the set speed (flow rate) based on the time or amount of volume required for injection.
    - To control the syringe for injection or suction as well as to change the units and volume of the syringes, a graphic LCD along with a keypad is used so that the process of choosing different modes and the progress of the injection is clearer for the user. The microcontroller used in this project is ESP32 due to its real-time importance.
    - Also, two buttons are placed at the beginning and the end of the fixed platform to detect the collision of the moving platform with the beginning and the end of the path and prevent the movement in the prohibited environment.
    - In the continuation of the description of this project, the different parts of display by LCD, control by Keypad and movement by Stepper are explained, and finally the demo version of the user manual of the device that is published for the user of the device is also included in the report.
  - **3.2. Project Git Description**
    - In this project, the GitHub platform is used to view the progress of the project and control the codes more easily. Due to a lack of familiarity with Git and GitHub, the following information describes the tasks involved in managing the project using Git and GitHub.
    - **3.2.1. What is Git?**
      - Git is a version control system that makes it easier to control large or multi-person projects. Instead of the project being stored in one place and developed in the same place, each developer can develop the project alone in their own system and finally turn the project into an integrated project using Git.
    - **3.2.2. What is GitHub or GitLab?**
      - GitHub or GitLab are Git hosting platforms that can be accessed via the web, while Git is a local platform.
    - **3.2.3. How to Use Git and GitHub?**
      - To use Git, you must first create an empty repository in the desired project folder, which we do using the git init command.
      - Next, to save the progress of the project, after we have made our changes on the files, we save the desired files in the staging area with the git add command or remove them from the staging area with git remove. Staging area is an environment provided by Git and not seen in most version control systems, which allows the user to view files before committing.
      - When we are sure of the files placed in the staging area, we take a snapshot of the changes made using the git commit command and place them in the repository. In addition, we can use the command git commit -m "message" in addition to the changes to put a meaningful message in the repository, which expresses the difference between the new files and the previous files, and can be of great help in observing the progress of the project.
      - Finally, using the git push origin main command, save all the changes made in the repository and in the main branch called main or master in GitHub. The meaning of origin is the repository link created in GitHub, which is set as origin using the git remote add origin link command, and instead, the link can be placed directly in the push command.
    - **3.2.4. Managing the Progress of the Project by the Platform**
      - In this project, the progress of the project is stored in GitHub and in the repository called injection project. It can be viewed [here](https://github.com/yourprojectlink).
  - **3.3. LCD**
    - **3.3.1. Familiarity with LCD and Connecting It to ESP32**
      - **3.3.1-1. What is TFT 3.5" Arduino Shield?**
        - TFT series LCDs are produced in various sizes, for this project a 3.5-inch LCD was used. The LCD series used is the Arduino shield, and for this reason, it was a little difficult to connect it to the ESP32, which is explained in the following.
        - These types of LCDs are produced in touch and non-touch types, the LCD used in the project is non-touch. Also, these LCDs have a micro SD port, which was not used in this project.
      - **3.3.1-2. Libraries Used**
        - In this project, we use two libraries, Adafruit_GFX.h and MCUFRIEND_kbv.h, to display and write on the LCD, and we make a tft object to initialize the LCD and include the connected pins in it.
      - **3.3.1-3. Connect to ESP32**
        - Because the LCD is an Arduino Shield type, we use the following connections to connect to the ESP32 board:
          - LCD_RD → 2 (bus read signal)
          - LCD_WR → 4 (bus write signal)
          - LCD_RS → 15 (bus command / data selection signal)
          - LCD_CS → 33 (bus chip select signal)
          - LCD_RST → 32 (bus reset signal)
          - LCD_D0 → 12 (8-bit data Bit0)
          - LCD_D1 → 13 (8-bit data Bit1)
          - LCD_D2 → 26 (8-bit data Bit2)
          - LCD_D3 → 25 (8-bit data Bit3)
          - LCD_D4 → 17 (8-bit data Bit4)
          - LCD_D5 → 16 (8-bit data Bit5)
          - LCD_D6 → 27 (8-bit data Bit6)
          - LCD_D7 → 14 (8-bit data Bit7)
        - Other pins are not connected except GND and 5V.
        - In the construction of the TFT object, we first define 5 pins related to the signal bus in the code and we have:
          ```cpp
          MCUFRIEND_kbv tft(LCD_CS, LCD_RS, LCD_WR, LCD_RD, LCD_RESET)
          ```
      - **3.3.1-4. Simple Project**
        - As a simple project, we will only display the text Hello World on the LCD. As a result, the background color will be black and the text will be white.
        - ```cpp
          #include <Arduino.h>
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

          MCUFRIEND_kbv tft(LCD_CS, LCD_RS, LCD_WR, LCD_RD, LCD_RESET);

          void setup()
          {
              uint16_t ID = tft.readID();
              tft.begin(ID);

              tft.fillScreen(BLACK);
              tft.setTextSize(2);
              tft.setTextColor(WHITE);
              tft.print("Hello World!");
          }
          void loop()
          {
          }
          ```

### 3-3-2. Description of the Codes in the Main Project

In this part, the codes related to the display in the main project are given. Codes are separated by pages.

#### 3-3-2-1. Menu Page
``` cpp
void set_menu_page() {
    tft.fillScreen(DARK_BLUE);

    tft.fillRoundRect(60, 250, 200, 40, 8, LIGHT_BLUE);

    int thickness = 3;
    int radius = 8;
    for (int i = 0; i < thickness; i++)
    {
        tft.drawRoundRect(60 + i, 250 + i, 200 - i * 2, 40 - i * 2, radius, WHITE);
    }

    tft.fillRoundRect(60, 300, 200, 40, 8, LIGHT_BLUE);

    tft.fillRoundRect(60, 350, 200, 40, 8, LIGHT_BLUE);

    tft.fillRoundRect(60, 400, 200, 40, 8, LIGHT_BLUE);

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
```

#### 3-3-2-2. Settings Page
``` cpp
void set_setting_page() {
    tft.fillScreen(DARK_BLUE);

    tft.fillRoundRect(60, 200, 200, 40, 8, LIGHT_BLUE);

    int thickness = 3;
    int radius = 8;
    for (int i = 0; i < thickness; i++)
    {
        tft.drawRoundRect(60 + i, 200 + i, 200 - i * 2, 40 - i * 2, radius, WHITE);
    }

    tft.fillRoundRect(60, 250, 200, 40, 8, LIGHT_BLUE);

    tft.fillRoundRect(60, 300, 200, 40, 8, LIGHT_BLUE);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    tft.setCursor(100, 215);
    tft.print("Change Unit");

    tft.setCursor(80, 265);
    tft.print("Change Syringe");

    tft.setCursor(135, 315);
    tft.print("Back");
}
```

#### 3-3-2-2-1. Change Unit Page

``` cpp
void set_change_unit_page() {
    tft.fillScreen(DARK_BLUE);
    int thickness = 3;

    /* Volume */
    tft.fillRect(93, 42, 120, 35, LIGHT_BLUE);

    tft.setTextSize(3);
    tft.setTextColor(DARK_BLUE);
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
        for (int i = 0; i < thickness; i++)
        {
            tft.drawLine(87, 105 + i, 115, 105 + i, WHITE);
        }
    }
    else
    {
        for (int i = 0; i < thickness; i++)
        {
            tft.drawLine(177, 105 + i, 215, 105 + i, WHITE);
        }
    }

    /* Time */
    tft.setTextSize(3);
    tft.setTextColor(LIGHT_BLUE);
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
        for (int i = 0; i < thickness; i++)
        {
            tft.drawLine(37, 210 + i, 77, 210 + i, WHITE);
        }
    }
    else if (time_unit == 1)
    {
        for (int i = 0; i < thickness; i++)
        {
            tft.drawLine(147, 210 + i, 187, 210 + i, WHITE);
        }
    }
    else
    {
        for (int i = 0; i < thickness; i++)
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

    tft.fillRoundRect(60, 370, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(135, 385);
    tft.print("Apply");

    tft.fillRoundRect(60, 420, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(135, 435);
    tft.print("Back");
}
```
#### 3-3-2-2-1-1. Change Unit Error Page

``` cpp
void set_change_unit_error_page() {
    tft.fillScreen(DARK_BLUE);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    // Volume
    int row = 180, col = 80;
    tft.setCursor(col, row);
    tft.print("Please Enter ");

    row = 210, col = 120;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(LIGHT_BLUE);
    tft.print("Rate");

    // Buttons
    int width = 180, height = 34, rounding_factor = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_factor, LIGHT_BLUE);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_factor, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}
```

#### 3-3-2-2-2. Change syringe page
``` cpp
void set_change_syringe_page()
{
    tft.fillScreen(DARK_BLUE);
    tft.setTextSize(2);

    int syringe_count = available_syringe_types[0][0];
    int row_diff = int(370 / syringe_count);
    int col = 10, row = 30;

    for (int i = 1; i <= syringe_count; i++)
    {
        if (syringe == i)
        {
            tft.setTextColor(LIGHT_BLUE);
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

    tft.setTextColor(WHITE);

    tft.fillRoundRect(60, 350, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(145, 365);
    tft.print("Add");

    tft.fillRoundRect(60, 395, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(125, 410);
    tft.print("Remove");

    tft.fillRoundRect(60, 440, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(135, 455);
    tft.print("Back");
}
```

#### 3-3-2-2-2-1. Add syringe page
``` cpp
void set_add_syringe_page()
{
    tft.fillScreen(DARK_BLUE);
    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    int unit_col = 255;
    int box_col = 20;

    /* time */
    int row, col;
    if (current_button_row == 0)
    {
        tft.setTextColor(LIGHT_BLUE);
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
        tft.setTextColor(LIGHT_BLUE);
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

    tft.fillRoundRect(60, 385, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(145, 400);
    tft.print("Add");

    tft.fillRoundRect(60, 430, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(135, 445);
    tft.print("Back");
}
```

#### 3-3-2-2-2-1-1. Add syringe error no volume page
``` cpp
void set_add_syringe_error_no_volume_page()
{
    tft.fillScreen(DARK_BLUE);
    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* volume */
    int row = 180, col = 80;
    tft.setCursor(col, row);
    tft.print("Please Enter ");

    row = 210, col = 100;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(LIGHT_BLUE);
    tft.print("Volume");

    /* buttons */
    int width = 180, height = 34, rounding_factor = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_factor, LIGHT_BLUE);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_factor, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}
```

#### 3-3-2-2-2-1-2. Add syringe error no radius page
``` cpp
void set_add_syringe_error_no_radius_page()
{
    tft.fillScreen(DARK_BLUE);
    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* error */
    int row = 180, col = 80;
    tft.setCursor(col, row);
    tft.print("Please Enter");

    row = 210, col = 100;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(LIGHT_BLUE);
    tft.print("Radius");

    /* buttons */
    int width = 180, height = 34, rounding_factor = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_factor, LIGHT_BLUE);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_factor, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}
```

#### 3-3-2-2-2-2. Remove syringe page
``` cpp
void set_remove_syringe_page()
{
    tft.fillScreen(DARK_BLUE);
    tft.setTextSize(2);

    int syringe_count = available_syringe_types[0][0];
    int row_diff = int(370 / syringe_count);
    int col = 10, row = 30;

    tft.setTextColor(LIGHT_BLUE);
    tft.setCursor(col, row);
    tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[1][0],
         available_syringe_types[1][1]);

    row += row_diff;

    for (int i = 2; i <= syringe_count; i++)
    {
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[i][0],
              available_syringe_types[i][1]);

        row += row_diff;
    }

    tft.fillRoundRect(60, 430, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(135, 445);
    tft.print("Back");
}
```

#### 3-3-2-2-3. Load page

``` cpp
void set_load_page()
{
    tft.fillScreen(DARK_BLUE);
    tft.setTextSize(2);

    int count = stored[0][0];
    int row_diff = int(380 / count);
    int col = 10, row = 30;

    if (count > 0)
    {
        tft.setTextColor(LIGHT_BLUE);
        tft.setCursor(col, row);
        int i = 1;
        if (stored[i][0] == time_)
        {
            tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2],
                 stored[i][1], available_syringe_types[int(stored[i][5])][1]);
        }
        else
        {
            tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2],
                 stored[i][1], available_syringe_types[int(stored[i][5])][1]);
        }
        tft.setTextColor(WHITE);
        row += row_diff;
    }

    for (int i = 2; i <= count; i++)
    {
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        if (stored[i][0] == time_)
        {
            tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2],
                 stored[i][1], available_syringe_types[int(stored[i][5])][1]);
        }
        else
        {
            tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2],
                 stored[i][1], available_syringe_types[int(stored[i][5])][1]);
        }
        row += row_diff;
    }

    tft.setTextColor(WHITE);

    tft.fillRoundRect(60, 395, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(125, 405);
    tft.print("Remove");

    tft.fillRoundRect(60, 440, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(135, 450);
    tft.print("Back");
}
```

#### 3-3-2-2-4. Store page
``` cpp
void set_store_page()
{
    tft.fillScreen(DARK_BLUE);
    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* volume */
    int row = 180, col = 20;
    tft.setCursor(col, row);
    tft.print("Stored Successfully");

    /* buttons */
    int width = 180, height = 34, rounding_factor = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_factor, LIGHT_BLUE);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_factor,
    WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);
    tft.print("OK");
}
```

#### 3-3-2-2-5. Remove page
``` cpp
void set_remove_page()
{
    tft.fillScreen(DARK_BLUE);
    tft.setTextSize(2);

    int count = stored[0][0];
    int row_diff = int(380 / count);
    int col = 10, row = 30;

    if (count > 0)
    {
        tft.setTextColor(LIGHT_BLUE);
        tft.setCursor(col, row);
        int i = 1;
        if (stored[i][0] == time_)
        {
            tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2],
    stored[i][1], available_syringe_types[int(stored[i][5])][1]);
        }
        else
        {
            tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2],
    stored[i][1], available_syringe_types[int(stored[i][5])][1]);
        }
        tft.setTextColor(WHITE);
        row += row_diff;
    }

    for (int i = 2; i <= count; i++)
    {
        tft.setTextColor(WHITE);
        tft.setCursor(col, row);
        if (stored[i][0] == time_)
        {
            tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2],
    stored[i][1], available_syringe_types[int(stored[i][5])][1]);
        }
        else
        {
            tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2],
    stored[i][1], available_syringe_types[int(stored[i][5])][1]);
        }

        row += row_diff;
    }

    tft.setTextColor(WHITE);

    tft.fillRoundRect(60, 430, 200, 40, 8, LIGHT_BLUE);

    tft.setCursor(135, 445);
    tft.print("Back");
}
```

#### 3-3-2-3. New injection page
``` cpp
void set_new_injection_page()
{
    tft.fillScreen(DARK_BLUE);

    tft.setTextSize(3);
    tft.setTextColor(LIGHT_BLUE);
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
        tft.setTextColor(LIGHT_BLUE);
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
        tft.setTextColor(LIGHT_BLUE);
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
    row += 35, col = 20;
    tft.setCursor(col, row);
    tft.printf("Syringe %.2f mL (%.2f mm)", available_syringe_types[syringe][0],
         available_syringe_types[syringe][1]);

    row += 20, col = 20;
    tft.setCursor(col, row);
    tft.printf("Rate %.2f %s/%s", input_rate, available_volume_units[volume_unit],
         available_time_units[time_unit]);

    if (new_injection_flag)
    {
        if (temp_time != 0)
        {
            tft.setCursor(24, 78);
            tft.printf("%.2f", temp_time);
        }

        if (temp_volume != 0)
        {
            tft.setCursor(24, 178);
            tft.printf("%.2f", temp_volume);
        }

        new_injection_flag = false;
    }

    /* buttons */
    int width = 180, height = 34, rounding_factor = 8, diff = 38;

    col = 70, row = 250;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    row += diff;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    col = 95, row = 260;
    tft.setCursor(col, row);
    tft.print("Change Unit");

    col = 78, row += diff;
    tft.setCursor(col, row);
    tft.print("Change Syringe");

    col = 135, row += diff;
    tft.setCursor(col, row);
    tft.print("Load");

    col = 125, row += diff;
    tft.setCursor(col, row);
    tft.print("Store");

    col = 125, row += diff;
    tft.setCursor(col, row);
    tft.print("Created");

    col = 135, row += diff;
    tft.setCursor(col, row);
    tft.print("Back");
}
```

#### 3-3-2-3-1. New injection error no time or volume page
``` cpp
void set_new_injection_error_no_time_or_volume_page()
{
    tft.fillScreen(DARK_BLUE);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* error */
    int row = 180, col = 80;
    tft.setCursor(col, row);
    tft.print("Please Enter");

    row = 210, col = 25;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(LIGHT_BLUE);
    tft.print("Time or Volume");

    /* buttons */
    int width = 180, height = 34, rounding_factor = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

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
```

#### 3-3-2-3-2. New injection error both time and volume page
``` cpp
void set_new_injection_error_both_time_and_volume_page()
{
    tft.fillScreen(DARK_BLUE);

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
    tft.setTextColor(LIGHT_BLUE);
    tft.print("Not Both");

    /* buttons */
    int width = 180, height = 34, rounding_factor = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

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
```

#### 3-3-2-5. Progress page
It includes two types of progress with time or volume.

#### 3-3-2-5-1. Progress with time page
``` cpp
void set_progress_page_with_time()
{
    tft.fillScreen(DARK_BLUE);

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
    tft.fillRect(12, 177, 297, 21, LIGHT_BLUE);

    int update = ((input_time - remaining_time) / input_time) * 300;
    tft.fillRect(12, 177, update, 21, DARK_BLUE);

    /* rate */
    row = 255, col = 10;
    tft.setCursor(col, row);
    tft.print("Rate:");

    row = 280, col = 10;
    tft.setCursor(col, row);
    tft.printf("%.2f %s/%s", input_rate, available_volume_units[volume_unit],
        available_time_units[time_unit]);

    int width = 180, height = 40, rounding_factor = 8, diff = 41;
    col = 70, row = 400;

    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    tft.setCursor(135, row += 15);
    tft.print("STOP");
}
```

#### 3-3-2-5-2. Progress page with volume
``` cpp
void set_progress_page_with_volume()
{
    tft.fillScreen(DARK_BLUE);

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
    tft.fillRect(12, 177, 297, 21, LIGHT_BLUE);

    if (volume_counter >= 297)
    {
        tft.fillRect(12, 177, 297, 21, DARK_BLUE);
    }
    otherwise
    {
        tft.fillRect(12, 177, volume_counter, 21, DARK_BLUE);
    }

    /* rate */
    row = 255, col = 10;
    tft.setCursor(col, row);
    tft.print("Rate:");

    row = 280, col = 10;
    tft.setCursor(col, row);

    tft.printf("%.2f %s/%s", input_rate, available_volume_units[volume_unit],
        available_time_units[time_unit]);

    int width = 180, height = 40, rounding_factor = 8, diff = 41;
    col = 70, row = 400;

    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_facotr, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    tft.setCursor(135, row += 15);
    tft.print("STOP");
}
```

#### 3-3-2-6. Abort page
It includes two types of stop or end.

#### 3-3-2-6-1. Stop page
``` cpp
void set_stop_page()
{
    tft.fillScreen(DARK_BLUE);

    /* injection end */
    tft.setTextSize(3);
    tft.setCursor(120, 50);
    tft.setTextColor(LIGHT_BLUE);
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
        otherwise
        {
            tft.setCursor(10, 150);
            tft.print("Seced Volume:");

            tft.setCursor(10, 170);
            tft.printf("%.2f mL of %.2f mL", input_volume - remaining_volume, input_volume);
        }
    }
    otherwise
    {
        if (injection_or_suction_flag == injection)
        {
            tft.setCursor(10, 150);
            tft.print("Injection Time:");

            tft.setCursor(10, 170);
            tft.printf("%.2f sec of %.2f sec", input_time - remaining_time, input_time);
        }
        otherwise
        {
            tft.setCursor(10, 150);
            tft.print("Suction Time:");

            tft.setCursor(10, 170);
            tft.printf("%.2f sec of %.2f sec", input_time - remaining_time, input_time);
        }
    }

    /* buttons */
    int width = 200, height = 40, rounding_factor = 8;

    int col = 70, row = 320;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    row += 50;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    row += 50;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

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
```

#### 3-3-2-6-2. End page
``` cpp
void set_end_page()
{
    tft.fillScreen(DARK_BLUE);

    /* injection end */
    tft.setTextSize(3);
    tft.setCursor(150, 50);
    tft.setTextColor(LIGHT_BLUE);
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
        otherwise
        {
            tft.setCursor(10, 150);
            tft.print("Seced Volume:");

            tft.setCursor(10, 170);
            tft.printf("%.2f mL of %.2f mL", input_volume - remaining_volume, input_volume);
        }
    }
    otherwise
    {
        if (injection_or_suction_flag == injection)
        {
            tft.setCursor(10, 150);
            tft.print("Passed Time:");

            tft.setCursor(10, 170);
            tft.printf("%.2f sec of %.2f sec", input_time, input_time);
        }
        otherwise
        {
            tft.setCursor(10, 150);
            tft.print("Passed Time:");

            tft.setCursor(10, 170);
            tft.printf("%.2f sec of %.2f sec", input_time, input_time);
        }
    }

    /* buttons */
    int width = 200, height = 40, rounding_factor = 8;

    int col = 70, row = 320;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

    row += 50;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

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
```

#### 3-3-2-7. Button page
It includes two types of start and finish.

#### 3-3-2-7-1. Button start page
``` cpp
void set_button_start_page()
{
    tft.fillScreen(DARK_BLUE);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* error */
    int row = 210, col = 100;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(LIGHT_BLUE);
    tft.print("Start");

    // stop_stepper

    /* buttons */
    int width = 180, height = 34, rounding_factor = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_facotr, LIGHT_BLUE);

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
```
#### 3-3-2-7-2. Button finish page

```cpp
void set_button_finish_page()
{
    tft.fillScreen(DARK_BLUE);

    tft.setTextSize(2);
    tft.setTextColor(WHITE);

    /* error */
    int row = 210, col = 100;
    tft.setCursor(col, row);
    tft.setTextSize(3);
    tft.setTextColor(LIGHT_BLUE);
    tft.print("Finish");

    // stop_stepper

    /* buttons */
    int width = 180, height = 34, rounding_factor = 8, diff = 41;

    col = 70, row = 310;
    tft.fillRoundRect(col, row, width, height, rounding_factor, LIGHT_BLUE);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_factor, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 145, row = 320;
    tft.setCursor(col, row);

    tft.print("OK");
}
```

#### 3-3-2-8. Free move page
``` cpp
void set_free_move_page() {
    tft.fillScreen(DARK_BLUE);

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
    int width = 180, height = 34, rounding_factor = 8, diff = 41;

    col = 70, row = 400;
    tft.fillRoundRect(col, row, width, height, rounding_factor, LIGHT_BLUE);

    for (int i = 0; i < 3; i++)
    {
        tft.drawRoundRect(col + i, row + i, width - i * 2, height - i * 2, rounding_factor, WHITE);
    }

    tft.setTextSize(2);
    tft.setTextColor(WHITE);
    col = 135, row = 410;
    tft.setCursor(col, row);
    tft.print("Back");
}
```
#### 3-3-2-8. Creating an Image on the Menu Page
On the main page, there is an image, and below are the instructions on how to create it.
To display an image on TFT series LCDs, you can use two methods. Most TFT series LCDs come with an SD Card port, allowing you to save and display images from the SD Card. However, in this project, due to pin limitations and the need to display only one image, the SD Card is not used. Instead, the second method is employed to display the image.
In this method, rather than using an image stored on the SD Card, the image is converted into hexadecimal numbers and loaded from flash memory. Here's how to do it:
1. Select the Image:
   Start by choosing the image you want to display.
2. **Resize the Image:
   Use an image resizing tool or any other software to adjust the image's dimensions to fit the LCD screen.
3. Convert to Hexadecimal Numbers:
   Utilize a suitable tool or script to convert the resized image into hexadecimal numbers. This process involves converting the color values of each pixel into their hexadecimal representation. If you prefer a monochrome image, ensure that you convert it accordingly, as monochrome images are much smaller than full-color ones.

4. Add Hexadecimal Numbers to the Code:
   Integrate the hexadecimal numbers into your code. These numbers will represent the image data and can be stored as an array or in an appropriate data structure.

5. Display the Image:
   To display the image on your TFT series LCD, you can use the following code:
   For monochrome images:
   ```cpp
   tft.drawBitmap(col, row, name, width, height, color);` 
   ```

For multi-color images (each pixel represented separately):
``` cpp
for (row = 0; row < height; row++) {
    for (col = 0; col < width; col++) {
        tft.drawPixel(col, row, pgm_read_word(name + buffidx));
        buffidx++;
    }
}
```

-   `col` and `row` specify the starting position of the image on the LCD.
-   `name` refers to the array or memory location where the hexadecimal data is stored.
-   `width` and `height` are the dimensions of the image.
-   `color` represents the color mode of the image (e.g., monochrome or full-color).

Ensure that you replace the placeholders (`col`, `row`, `name`, `width`, `height`, `color`) with the actual values or variables specific to your image and LCD configuration.
By following these steps and incorporating the code into your project, you can display images on your TFT series LCD without the need for an SD card.

### 3-4. Keypad

All movements are controlled in the Keypad section. First, I will get acquainted with the keypad itself, and then I will check how to connect it to the microcontroller, and finally, I will bring the codes related to the project.

#### 3-4-1. Getting to know Keypad and connecting it to the board

#### 3-4-1-1. Introduction to Keypad and initial connection to ESP32

Task description: Connect the keypad to ESP32 and write a short project with your knowledge.

#### 3-4-1-1-1. What is a keypad?

A keypad is one of the types of input devices that come in various configurations. Keypads consist of a set of buttons that can represent different numbers, letters, or symbols. This project uses a 4x4 matrix keypad.

To read the input values from the matrix keypad, it's essential to understand that direct access to each button's pin is not available. Instead, the reading is based on rows and columns.

In the internal structure of matrix keypads, the rows are connected together, and the columns are also connected. Therefore, these keypads (such as our 4x4 keypad) have 4 pins as rows and 4 pins as columns. To read their values, first, set all pins as input, then set the values of each row to High and read the values of the columns. Any column set to High indicates that a button is pressed in the corresponding row and column.

#### 3-4-1-1-2. Libraries used

To simplify the process of reading keypad values, ready-made libraries can be employed. The Keypad.h library is suitable for this project.

To use this library, create an object from it and provide information about the keypad map, row and column pins, and the number of rows and columns for the library. Then, you can read the pressed key using the `getKey()` command.

`Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);` 

The values in parentheses are defined as follows:
``` cpp
#define ROW_NUM 4
#define COLUMN_NUM 4

char keys[ROW_NUM][COLUMN_NUM] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM] = {19, 18, 5, 17};
byte pin_column[COLUMN_NUM] = {16, 4, 0, 2};` 
```

If a different-sized keypad is used or the values on the keypad do not match the keys defined above, the code can be easily adjusted. To read the keypad values, use the following command:
``` cpp
char key = keypad.getKey();` 
```
By recognizing the key, you can utilize the desired input.

#### 3-4-1-1-3. Connect to ESP32
To connect the keypad to ESP32 or any microcontroller, first define the row and column pins and connect them to the microcontroller pins as per the pinout specified for the keypad. For example, for the 4x4 matrix keypad used in the project, observe the following image:
Hence, the 4 pins on the left are for the row, and the 4 on the right are for the column. Connect these pins to the microcontroller based on the pins defined in the code, i.e., 19, 18, 5, and 17 for the row, and 16, 4, 0, and 2 for the column, or any available pins. Another crucial step is to connect the keypad pins to the microcontroller.

#### 3-4-1-1-4. Simple project
Now, we will use the above information to read and display the keypad values using the library:
``` cpp
#include <Keypad.h>

#define ROW_NUM 4
#define COLUMN_NUM 4

char keys[ROW_NUM][COLUMN_NUM] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}
};

byte pin_rows[ROW_NUM] = {19, 18, 5, 17};
byte pin_column[COLUMN_NUM] = {16, 4, 0, 2};

Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();

  if (key)
  {
    Serial.println(key);
  }
}
```
#### 3-4-1-2. Introduction to GPIO Extender and connection to ESP32
Task description: Connect GPIO extender to ESP32.
#### 3-4-1-2-1. What is a GPIO extender?
In a project where more pins are needed than the microcontroller provides, GPIO extenders can be utilized. These modules come in various types, and the one used in this project is the PCF8574 module, which communicates via the I2C protocol and provides an additional 8 pins for each module.
Additionally, if more pins are required, multiple modules can be daisy-chained together, allowing for up to 8 modules to be used in tandem.
To connect each module, it is necessary to assign an address value to the module, which can be a number between 20 and 27. This address can be set using jumpers on the module, following a specific table.
To ensure the correct I2C connection, you can use an I2C Scanner.

#### 3-4-1-2-2. Libraries used
To work with I2C pins, you can use the wire.h library or a library specific to the module, such as PCF8574.h.
#### 3-4-1-2-3. Connect to ESP32

To use the I2C bus in any microcontroller, you need to identify the pins associated with it. In ESP32, these pins are as follows:
- SDA -> GPIO 21
- SCL -> GPIO 22

In addition to these pins, connect the VCC and GND pins to the microcontroller. This allows you to use the 8 additional pins provided by the GPIO extender.

To use these pins, first create an object and provide the module's address as input:

```cpp
PCF8574 pcf8574(0x20);
```

Then, define the used pins in the setup section, and you can utilize these pins as needed:

```cpp
pcf8574.pinMode(P0, OUTPUT);
```

To read the state of a pin:

```cpp
pcf8574.digitalRead(P0);
```

To write to a pin:

```cpp
pcf8574.digitalWrite(P0, HIGH);
```

#### 3-4-1-3. Connecting Keypad to GPIO Extender

Task description: Connect a Keypad to ESP32 using a GPIO Extender and write a short project with your knowledge.

#### 3-4-1-3-1. Challenges of connecting Keypad to ESP32 by GPIO Extender

Connecting a device to PCF8574 is straightforward, but challenges arise when you need a library for easier use and a smoother experience of the connected device. Due to the different way of defining and using pins with I2C, using old libraries is not suitable. You have the option to use the device without the library or replace the old library with a new one that supports the I2C protocol.

In this project, due to the limited microcontroller pins, we used PCF8574 to connect the Keypad, which requires exactly 8 pins. For this solution, we used the I2CKeyPad.h library, as explained below.

First, create an object and provide the address of the PCF8574 module as an input:

```cpp
const uint8_t KEYPAD_ADDRESS = 0x38;
I2CKeyPad keyPad(KEYPAD_ADDRESS);
```

Then, map the Keypad buttons as desired:

```cpp
char keys[] = "123A456B789C*0#DNF";
```

Here, "N" means NoKey, and "F" means False, which can be used to detect errors. You can detect the pressed key's value using the `keyPad.begin()` command:

```cpp
if (millis() - lastKeyPressed >= 200) // figure key
{
    int index = keyPad.getKey();
    if (index < 16)
    {
        key = keys[index];
    }
    lastKeyPressed = millis();
}
```

Once you recognize the key character, you can perform the desired tasks.

#### 3-4-1-3-2. Simple project

Using the above knowledge, we can read and display the pressed value:

```cpp
#include <I2CKeyPad.h>

const uint8_t KEYPAD_ADDRESS = 0x20;
I2CKeyPad keyPad(KEYPAD_ADDRESS);

char keys[] = "123A456B789C*0#DNF";

uint32_t lastKeyPressed = 0;
char key = '\0';

void setup()
{
    Serial.begin(9600);
    keyPad.begin();
}

void loop()
{
    if (millis() - lastKeyPressed >= 200) // figure key
    {
        int index = keyPad.getKey();
        if (index < 16)
        {
            key = keys[index];
            Serial.println(key);
        }
        lastKeyPressed = millis();
    }
}
```

#### 3-4-1-4. How to use Keypad in the original project

In the original project, there were three methods to use the Keypad. One of the methods is to read the key value in the main loop of the program. However, this method lacks an interruption mode, which means that if the program is in another loop when a key is pressed, the detection capability for that key is lost. To address this issue, two methods can be used: freeRTOS or a timer, both of which are explained below.

#### 3-4-1-4-1. Explain what freeRTOS is and how to use it in ESP32.

Task Description: How to use freeRTOS in ESP32? Write a short project with your knowledge.

#### 3-4-1-4-1-1. What is freeRTOS?

freeRTOS, short for Real-time Operating System, is a simple and open-source operating system that is included by default on ESP32. This operating system is designed for multitasking and helps control the use of shared resources, enhancing system efficiency.

### 3-4-1-4-1-2. How to use freeRTOS in ESP32?

ESP32 is a microcontroller with 2 cores, and by default, when running code, it executes on Core 1 while Core 0 is reserved for RF communication. However, based on your needs, you can run code on any desired core.

In general, for multitasking, you need to define the tasks that you want to be executed. Therefore, you create a function for each of the tasks:

```cpp
void task1(void *parameters) {
    Serial.print("Task1");
}

void task2(void *parameters) {
    Serial.print("Task2");
}
```

Then you define each of these tasks for the microcontroller in the setup:

```cpp
xTaskCreate(task1, "Task 1", 1000, NULL, 1, NULL);
xTaskCreate(task2, "Task 2", 1000, NULL, 1, NULL);
```

In this case, both tasks are performed by freeRTOS and on Core 1. However, if you use `xTaskCreatePinnedToCore` instead of `xTaskCreate`, you can run each task on separate cores:

```cpp
xTaskCreatePinnedToCore(task1, "Task 1", 1000, NULL, 1, NULL, 1);
xTaskCreatePinnedToCore(task2, "Task 2", 1000, NULL, 1, NULL, 1);
```

### 3-4-1-4-1-3. Simple project

In this project, freeRTOS is used to read two buttons that are set up as interrupts:

```cpp
struct Button
{
    const uint8_t PIN;
    unsigned long last_button_time;
};

Button button_right = {18, 0};
Button button_left = {17, 0};

void task1(void *parameters)
{
    for (;;)
    {
        if (!digitalRead(button_right.PIN))
        {
            unsigned long button_time = millis();
            if (button_time - button_right.last_button_time > 250)
            {
                Serial.println("Right");
                button_right.last_button_time = button_time;
            }
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void task2(void *parameters)
{
    for (;;)
    {
        if (!digitalRead(button_left.PIN))
        {
            unsigned long button_time = millis();
            if (button_time - button_left.last_button_time > 250)
            {
                Serial.println("Left");
                button_left.last_button_time = button_time;
            }
        }
        vTaskDelay(10 / portTICK_PERIOD_MS);
    }
}

void setup()
{
    Serial.begin(9600);

    pinMode(button_right.PIN, INPUT_PULLUP);
    pinMode(button_left.PIN, INPUT_PULLUP);

    xTaskCreatePinnedToCore(task1, "Task 1", 1000, NULL, 1, NULL, 0);
    xTaskCreatePinnedToCore(task2, "Task 2", 1000, NULL, 1, NULL, 1);
}

void loop()
{
}
```

### 3-4-1-4-2. Explain what Timer is and how to use it in ESP32.

**Task Description:** How to use Timer in ESP32? Write a short project with your knowledge.

#### 3-4-1-4-2-1. What is Timer?

A Timer is a type of interrupt and can be considered as the internal timer of a microcontroller. It triggers an event when a specified period of time, determined by the developer, has passed, and it can be used to control various activities within the microcontroller.

#### 3-4-1-4-2-2. How to use Timer in ESP32?

In ESP32, there are two hardware timers, each with 64-bit precision. To use each of these timers, follow these steps:

1. Create a pointer of type `hw_timer_t`:

```cpp
hw_timer_t *timer = NULL;
```

2. Initialize the timer in the setup:

```cpp
timer = timerBegin(0, 80, true);
timerAttachInterrupt(timer, &onTimer, true);
timerAlarmWrite(timer, 1000000, true);
timerAlarmEnable(timer);
```

- The number `80` represents the prescaler, and the number `1000000` sets the timer to trigger an event every 1 second (or every 1000000 microseconds). You can adjust this number to change the time interval.

3. Define a function to be executed when the timer event occurs:

```cpp
void IRAM_ATTR onTimer()
{
    // Your code to be executed on the timer event
}
```

By following these steps, you can be notified of the passage of time at regular intervals.

#### 3-4-1-4-2-3. Simple Project
In this project, we will create a program that prints a suitable phrase every 1 second. We use a hardware timer and an interrupt to achieve this.

```cpp
hw_timer_t * timer = NULL;
bool timer_flag = false;

void IRAM_ATTR onTimer() {
    timer_flag = true;
}

void setup() {
    Serial.begin(115200);

    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &onTimer, true);
    timerAlarmWrite(timer, 1000000, true);
    timerAlarmEnable(timer);
}

void loop() {
    if (timer_flag) {
        Serial.println("An interrupt has occurred.");
        timer_flag = false;
    }
}
```

Due to limitations described in the FreeRTOS and Timer sections, we check for keypad button presses every 100 microseconds and if there's a change, we use a flag to track it. The actual key value is checked elsewhere in the program, as using some codes in `IRAM_ATTR` functions isn't straightforward.

#### 3-4-1-5. Description of the Codes in the Main Project
In the primary part of the project, as previously described, we detect button presses by using a timer. In sections where code execution may take a long time, such as certain loops, we also check the keypad key value.

To control and perform the required activities using the keypad, we must define an action for each button.

- We use number keys to enter numerical values.
- The A, B, C, and D keys are used for navigation within different parts of the LCD screen.
- The # button serves as a confirmation or selection button.
- In sections where numerical input is needed, the C button is used to enter numbers.
- The * button is used to clear entered values.

In the keypad section of the code, actions are determined based on the pressed buttons for each page, considering the program's state and page context. Each page performs different activities, and to update the displayed image for the page, an update function is implemented in addition to the set functions used for displaying images. Below are some of the code snippets that handle keypad input and corresponding actions:

```cpp
void up();
void down();
void right();
void left();
void ok();
void enter(char input_key);
void erase();
```
#### 3-4-1-5-1. The main part of reading Keypad and calling pages
 ``` cpp
 void IRAM_ATTR onTimer() {
    portENTER_CRITICAL_ISR(&timerMux);
    if (millis() - lastKeyPressed >= 200) {
        char_flag = true;
    }
    portEXIT_CRITICAL_ISR(&timerMux);

    if (program_state == progress_page_with_time) {
        if (time_counter == 100) {
            remaining_time--;

            int update = ((input_time - remaining_time) / input_time) * 300;

            if (update > 297) {
                update = 297;
            }

            tft.fillRect(12, 177, update, 21, DARK_BLUE);

            int row = 150, col = 10;
            tft.fillRect(col, row, 300, 25, DARK_BLUE);

            tft.setCursor(col, row);
            tft.setTextColor(WHITE);
            tft.printf("%.2f sec", remaining_time);

            time_counter = 0;
        }

        time_counter++;
    } else if (program_state == progress_page_with_volume) {
        if (time_counter == 100) {
            remaining_volume -= useable_input_rate;

            int update = ((input_volume - remaining_volume) / input_volume) * 300;

            if (update > 297) {
                update = 297;
            }

            tft.fillRect(12, 177, update, 21, DARK_BLUE);

            int row = 150, col = 10;
            tft.fillRect(col, row, 300, 25, DARK_BLUE);

            tft.setCursor(col, row);
            tft.setTextColor(WHITE);
            tft.printf("%.2f mL", remaining_volume);

            time_counter = 0;
        }

        time_counter++;
    }
}

void loop() {
    if (char_flag) {
        int index = keyPad.getKey();
        if (index < 16) {
            key = keys[index];
        }
        lastKeyPressed = millis();

        char_flag = false;
    }

    if (key >= '0' && key <= '9') { // enter
        char key_copy = key;
        key = '\0';
        enter(key_copy);
    } else if (key == 'A') { // up
        key = '\0';
        up();
    } else if (key == 'B') { // down
        key = '\0';
        down();
    } else if (key == 'C') { // right
        key = '\0';
        right();
    } else if (key == 'D') { // left
        key = '\0';
        left();
    } else if (key == '#') { // ok
        key = '\0';
        ok();
    } else if (key == '*') { // erase
        key = '\0';
        erase();
    }
}
/* moves */
void up() {
    if (program_state == menu_page) {
        update_menu_page(up_move);
    }
    else if (program_state == setting_page) {
        update_setting_page(up_move);
    }
    else if (program_state == change_unit_page) {
        update_change_unit_page(up_move);
    }
    else if (program_state == change_syringe_page) {
        update_change_syringe_page(up_move);
    }
    else if (program_state == remove_syringe_page) {
        update_remove_syringe_page(up_move);
    }
    else if (program_state == add_syringe_page) {
        update_add_syringe_page(up_move);
    }
    else if (program_state == remove_page) {
        update_remove_page(up_move);
    }
    else if (program_state == load_page) {
        update_load_page(up_move);
    }
    else if (program_state == new_injection_page) {
        update_new_injection_page(up_move);
    }
    else if (program_state == new_suction_page) {
        update_new_suction_page(up_move);
    }
    else if (program_state == stop_page) {
        update_stop_page(up_move);
    }
    else if (program_state == end_page) {
        update_end_page(up_move);
    }
    else if (program_state == free_move_page) {
        update_free_move_page(up_move);
    }
}

void down() {
    if (program_state == menu_page) {
        update_menu_page(down_move);
    }
    else if (program_state == setting_page) {
        update_setting_page(down_move);
    }
    else if (program_state == change_unit_page) {
        update_change_unit_page(down_move);
    }
    else if (program_state == change_syringe_page) {
        update_change_syringe_page(down_move);
    }
    else if (program_state == add_syringe_page) {
        update_add_syringe_page(down_move);
    }
    else if (program_state == remove_syringe_page) {
        update_remove_syringe_page(down_move);
    }
    else if (program_state == remove_page) {
        update_remove_page(down_move);
    }
    else if (program_state == load_page) {
        update_load_page(down_move);
    }
    else if (program_state == new_injection_page) {
        update_new_injection_page(down_move);
    }
    else if (program_state == new_suction_page) {
        update_new_suction_page(down_move);
    }
    else if (program_state == stop_page) {
        update_stop_page(down_move);
    }
    else if (program_state == end_page) {
        update_end_page(down_move);
    }
    else if (program_state == free_move_page) {
        update_free_move_page(down_move);
    }
}

void right() {
    if (program_state == change_unit_page) {
        update_change_unit_page(right_move);
    }
    else if (program_state == add_syringe_page) {
        update_add_syringe_page(right_move);
    }
    else if (program_state == new_injection_page) {
        update_new_injection_page(right_move);
    }
    else if (program_state == new_suction_page) {
        update_new_suction_page(right_move);
    }
}

void left() {
    if (program_state == change_unit_page) {
        update_change_unit_page(left_move);
    }
}
void ok() {
    if (program_state == menu_page) {
        update_menu_page(ok_move);
    }
    else if (program_state == setting_page) {
        update_setting_page(ok_move);
    }
    else if (program_state == change_unit_page) {
        update_change_unit_page(ok_move);
    }
    else if (program_state == change_unit_error_page) {
        update_change_unit_error_page(ok_move);
    }
    else if (program_state == change_syringe_page) {
        update_change_syringe_page(ok_move);
    }
    else if (program_state == add_syringe_page) {
        update_add_syringe_page(ok_move);
    }
    else if (program_state == add_syringe_error_no_volume_page) {
        update_add_syringe_error_no_volume_page(ok_move);
    }
    else if (program_state == add_syringe_error_no_radius_page) {
        update_add_syringe_error_no_radius_page(ok_move);
    }
    else if (program_state == remove_syringe_page) {
        update_remove_syringe_page(ok_move);
    }
    else if (program_state == load_page) {
        update_load_page(ok_move);
    }
    else if (program_state == remove_page) {
        update_remove_page(ok_move);
    }
    else if (program_state == store_page) {
        update_store_page(ok_move);
    }
    else if (program_state == new_injection_page) {
        update_new_injection_page(ok_move);
    }
    else if (program_state == new_injection_error_no_time_or_volume_page) {
        update_new_injection_error_no_time_or_volume_page(ok_move);
    }
    else if (program_state == new_injection_error_both_time_and_volume_page) {
        update_new_injection_error_both_time_and_volume_page(ok_move);
    }
    else if (program_state == new_suction_page) {
        update_new_suction_page(ok_move);
    }
    else if (program_state == new_suction_error_no_time_or_volume_page) {
        update_new_suction_error_no_time_or_volume_page(ok_move);
    }
    else if (program_state == new_suction_error_both_time_and_volume_page) {
        update_new_suction_error_both_time_and_volume_page(ok_move);
    }
    else if (program_state == progress_page_with_time) {
        update_progress_page_with_time(ok_move);
    }
    else if (program_state == progress_page_with_volume) {
        update_progress_page_with_volume(0, ok_move);
    }
    else if (program_state == stop_page) {
        update_stop_page(ok_move);
    }
    else if (program_state == end_page) {
        update_end_page(ok_move);
    }
    else if (program_state == button_start_page) {
        update_button_start_page(ok_move);
    }
    else if (program_state == button_finish_page) {
        update_button_finish_page(ok_move);
    }
    else if (program_state == free_move_page) {
        update_free_move_page(ok_move);
    }
}
void enter(char input_key) {
    if (program_state == change_unit_page) {
        update_change_unit_page(input_key - '0');
    }
    else if (program_state == add_syringe_page) {
        update_add_syringe_page(input_key - '0');
    }
    else if (program_state == new_injection_page) {
        update_new_injection_page(input_key - '0');
    }
    else if (program_state == new_suction_page) {
        update_new_suction_page(input_key - '0');
    }
    else if (program_state == free_move_page) {
        update_free_move_page(input_key - '0');
    }
}

void erase() {
    if (program_state == change_unit_page) {
        update_change_unit_page(erase_move);
    }
    else if (program_state == add_syringe_page) {
        update_add_syringe_page(erase_move);
    }
    else if (program_state == new_injection_page) {
        update_new_injection_page(erase_move);
    }
    else if (program_state == new_suction_page) {
        update_new_suction_page(erase_move);
    }
    else if (program_state == free_move_page) {
        update_free_move_page(erase_move);
    }
}
 ```

#### 3-4-1-5-2. Menu page
``` cpp
void update_menu_page(int move) {
    if (move == up_move) {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0) {
            last_row = 250;
            curr_row = 400;
            current_button_row = 3;
        } else if (current_button_row == 1) {
            last_row = 300;
            curr_row = 250;
            current_button_row = 0;
        } else if (current_button_row == 2) {
            last_row = 350;
            curr_row = 300;
            current_button_row = 1;
        } else {
            last_row = 400;
            curr_row = 350;
            current_button_row = 2;
        }

        for (int i = 0; i < thick; i++) {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, LIGHT_BLUE);
        }

        for (int i = 0; i < thick; i++) {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    } else if (move == down_move) {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0) {
            last_row = 250;
            curr_row = 300;
            current_button_row = 1;
        } else if (current_button_row == 1) {
            last_row = 300;
            curr_row = 350;
            current_button_row = 2;
        } else if (current_button_row == 2) {
            last_row = 350;
            curr_row = 400;
            current_button_row = 3;
        } else {
            last_row = 400;
            curr_row = 250;
            current_button_row = 0;
        }

        for (int i = 0; i < thick; i++) {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, LIGHT_BLUE);
        }

        for (int i = 0; i < thick; i++) {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    } else if (move == ok_move) {
        if (current_button_row == 0) {
            program_state = setting_page;
            current_button_row = 0;
            set_setting_page();
        } else if (current_button_row == 1) {
            program_state = new_injection_page;
            current_button_row = 0;
            set_new_injection_page();
        } else if (current_button_row == 2) {
            program_state = new_suction_page;
            current_button_row = 0;
            set_new_suction_page();
        } else {
            program_state = free_move_page;
            current_button_row = 0;
            set_free_move_page();
        }
    }
}
```

#### 3-4-1-5-3. Settings page
``` cpp
void update_setting_page(int move) {
    if (move == up_move) {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0) {
            last_row = 200;
            curr_row = 300;
            current_button_row = 2;
        } else if (current_button_row == 1) {
            last_row = 250;
            curr_row = 200;
            current_button_row = 0;
        } else {
            last_row = 300;
            curr_row = 250;
            current_button_row = 1;
        }

        for (int i = 0; i < thick; i++) {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, LIGHT_BLUE);
        }

        for (int i = 0; i < thick; i++) {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    } else if (move == down_move) {
        int last_col = 60, last_row, curr_col = 60, curr_row;
        int width = 200, height = 40, thick = 3, radius = 8;

        if (current_button_row == 0) {
            last_row = 200;
            curr_row = 250;
            current_button_row = 1;
        } else if (current_button_row == 1) {
            last_row = 250;
            curr_row = 300;
            current_button_row = 2;
        } else {
            last_row = 300;
            curr_row = 200;
            current_button_row = 0;
        }

        for (int i = 0; i < thick; i++) {
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, LIGHT_BLUE);
        }

        for (int i = 0; i < thick; i()) {
            tft.drawRoundRect(curr_col + i, curr_row + i, width - i * 2, height - i * 2, radius, WHITE);
        }
    } else if (move == ok_move) {
        if (current_button_row == 0) {
            program_state = change_unit_page;
            current_button_row = 0;
            current_button_col[0] = time_unit;
            current_button_col[1] = volume_unit;
            set_change_unit_page();
        } else if (current_button_row == 1) {
            program_state = change_syringe_page;
            current_button_row = syringe - 1;
            set_change_syringe_page();
        } else {
            program_state = menu_page;
            current_button_row = 0;
            set_menu_page();
        }
    }
}
```

#### 3-4-1-5-3-1. Change Unit page
``` cpp
void update_change_unit_page(int move)
{
    if (move == up_move)
    {
        if (current_button_row == 0)
        {
            tft.fillRect(93, 42, 120, 35, DARK_BLUE);
            tft.setTextSize(3);
            tft.setTextColor(LIGHT_BLUE);
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
            tft.fillRect(113, 147, 85, 35, DARK_BLUE);
            tft.setTextSize(3);
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(120, 155);
            tft.print("Time");
            tft.fillRect(93, 42, 120, 35, LIGHT_BLUE);
            tft.setTextSize(3);
            tft.setTextColor(DARK_BLUE);
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
            tft.fillRect(113, 147, 85, 35, LIGHT_BLUE);
            tft.setTextSize(3);
            tft.setTextColor(DARK_BLUE);
            tft.setCursor(120, 155);
            tft.print("Time");
            current_button_row = 1;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 370 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
            }
            tft.setCursor(20, 260);
            tft.setTextSize(2);
            tft.setTextColor(LIGHT_BLUE);
            tft.print("Volume Flow Rate:");
            current_button_row = 2;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 420 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
            }
        }
    }
        else if (move == right_move)
    {
        if (current_button_row == 0)
        {
            if (current_button_col[1] == 0)
            {
                int thickness = 3;
                for (int i = 0; i < thickness; i++)
                {
                    tft.drawLine(87, 105 + i, 115, 105 + i, DARK_BLUE);
                }
                thickness = 3;
                for (int i = 0; i < thickness; i++)
                {
                    tft.drawLine(177, 105 + i, 215, 105 + i, WHITE);
                }
                current_button_col[1] = 1;
            }
            else
            {
                int thickness = 3;
                for (int i = 0; i < thickness; i++)
                {
                    tft.drawLine(87, 105 + i, 115, 105 + i, WHITE);
                }
                thickness = 3;
                for (int i = 0; i < thickness; i++)
                {
                    tft.drawLine(177, 105 + i, 215, 105 + i, DARK_BLUE);
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
                    tft.drawLine(37, 210 + i, 77, 210 + i, DARK_BLUE);
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
                    tft.drawLine(147, 210 + i, 187, 210 + i, DARK_BLUE);
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
                    tft.drawLine(257, 210 + i, 270, 210 + i, DARK_BLUE);
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
                tft.fillRect(20, 280, 230, 30, DARK_BLUE);
                tft.drawRect(20, 280, 230, 30, WHITE);
                tft.setTextColor(WHITE);
                tft.setCursor(24, 288);
                tft.printf("%.1f", temp_rate);
                rate_point_count++;
            }
        }
            else if (move == down_move)
    {
        if (current_button_row == 0)
        {
            tft.fillRect(93, 42, 120, 35, DARK_BLUE);

            tft.setTextSize(3);
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(100, 50);
            tft.print("Volume");

            tft.fillRect(113, 147, 85, 35, LIGHT_BLUE);

            tft.setTextSize(3);
            tft.setTextColor(DARK_BLUE);
            tft.setCursor(120, 155);
            tft.print("Time");

            current_button_row = 1;
        }
        else if (current_button_row == 1)
        {
            tft.fillRect(113, 147, 85, 35, DARK_BLUE);

            tft.setTextSize(3);
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(120, 155);
            tft.print("Time");

            tft.setTextSize(2);
            tft.setTextColor(LIGHT_BLUE);
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
                tft.drawRoundRect(60 + i, 370 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
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
                tft.drawRoundRect(60 + i, 420 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
            }

            tft.fillRect(93, 42, 120, 35, LIGHT_BLUE);

            tft.setTextSize(3);
            tft.setTextColor(DARK_BLUE);
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
                int thickness = 3;
                for (int i = 0; i < thickness; i++)
                {
                    tft.drawLine(87, 105 + i, 115, 105 + i, DARK_BLUE);
                }

                thickness = 3;
                for (int i = 0; i < thickness; i++)
                {
                    tft.drawLine(177, 105 + i, 215, 105 + i, WHITE);
                }

                current_button_col[1] = 1;
            }
            else
            {
                int thickness = 3;
                for (int i = 0; i < thickness; i++)
                {
                    tft.drawLine(87, 105 + i, 115, 105 + i, WHITE);
                }

                thickness = 3;
                for (int i = 0; i < thickness; i++)
                {
                    tft.drawLine(177, 105 + i, 215, 105 + i, DARK_BLUE);
                }

                current_button_col[1] = 0;
            }
        }
            else if (move == erase_move)
    {
        tft.fillRect(20, 280, 230, 30, DARK_BLUE);
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

            if (time_unit == 1)
            {
                useable_input_rate /= 60;
            }
            else if (time_unit == 2)
            {
                useable_input_rate /= 3600;
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
            else
    {
        if (current_button_row == 2)
        {
            if (rate_point_count == 0)
            {
                temp_rate *= 10;
                temp_rate += move;

                tft.fillRect(20, 280, 230, 30, DARK_BLUE);
                tft.drawRect(20, 280, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 288);
                tft.printf("%.0f", temp_rate);
            }
            else if (rate_point_count == 1)
            {
                temp_rate = temp_rate + (double(move) / 10.0);
                tft.fillRect(20, 280, 230, 30, DARK_BLUE);
                tft.drawRect(20, 280, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 288);
                tft.printf("%.1f", temp_rate);
                rate_point_count++;
            }
            else if (rate_point_count == 2)
            {
                temp_rate = temp_rate + (double(move) / 100.0);
                tft.fillRect(20, 280, 230, 30, DARK_BLUE);
                tft.drawRect(20, 280, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 288);
                tft.printf("%.2f", temp_rate);
                rate_point_count++;
            }
        }
    }
}
```

#### 3-4-1-5-3-1-1. **Change Unit Error Page**
```cpp
void update_change_unit_error_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        program_state = change_unit_page;
        current_button_row = 0;
        rate_point_count = 0;
        set_change_unit_page();
    }
}` 
```
#### 3-4-1-5-3-2. **Change Syringe Page**

``` cpp
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
            tft.printf("Syringe %.2f mL (%%.2f mm)", available_syringe_types[1][0], available_syringe_types[1][1]);

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
                tft.drawRoundRect(60 + i, 350 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
            }

            int col = 10, row = 30 + (syringe_count - 1) * row_diff;
            tft.setTextSize(2);
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%%.2f mm)", available_syringe_types[syringe_count][0], available_syringe_types[syringe_count][1]);

            current_button_row--;
        }
        else if (current_button_row == syringe_count + 1)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 395 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
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
                tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
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
            tft.printf("Syringe %.2f mL (%%.2f mm)", available_syringe_types[current_button_row + 1][0], available_syringe_types[current_button_row + 1][1]);

            row -= row_diff;
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%%.2f mm)", available_syringe_types[current_button_row][0], available_syringe_types[current_button_row][1]);

            current_button_row--;
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
		           tft.drawRoundRect(60 + i, 350 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
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
		           tft.drawRoundRect(60 + i, 395 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
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
		           tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
		       }

		       int col = 10, row = 30;
		       tft.setTextSize(2);
		       tft.setTextColor(LIGHT_BLUE);
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
		       tft.setTextColor(LIGHT_BLUE);
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
```

#### 3-4-1-5-3-2-1. **Add syringe page**

```cpp
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
            tft.setTextColor(LIGHT_BLUE);
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
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            tft.print("Syringe Radius:");

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 385 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
            }

            current_button_row = 1;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
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
            tft.setTextColor(LIGHT_BLUE);
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
                tft.drawRoundRect(60 + i, 385 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
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
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
            }

            int row = 50, col = 20;
            tft.setTextColor(LIGHT_BLUE);
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
                tft.fillRect(20, 70, 230, 30, DARK_BLUE);
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
                tft.fillRect(20, 140, 230, 30, DARK_BLUE);
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
            tft.fillRect(20, 70, 230, 30, DARK_BLUE);
            tft.drawRect(20, 70, 230, 30, WHITE);

            temp_syringe_volume = 0;
            syringe_volume_point_count = 0;
        }
        else if (current_button_row == 1)
        {
            tft.fillRect(20, 170, 230, 30, DARK_BLUE);
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

                tft.fillRect(20, 70, 230, 30, DARK_BLUE);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.0f", temp_syringe_volume);
            }
            else if (syringe_volume_point_count == 1)
            {
                temp_syringe_volume = temp_syringe_volume + (double(move_or_number) / 10.0);
                tft.fillRect(20, 70, 230, 30, DARK_BLUE);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.1f", temp_syringe_volume);
                syringe_volume_point_count++;
            }
            else if (syringe_volume_point_count == 2)
            {
                temp_syringe_volume = temp_syringe_volume + (double(move_or_number) / 100.0);
                tft.fillRect(20, 70, 230, 30, DARK_BLUE);
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

                tft.fillRect(20, 140, 230, 30, DARK_BLUE);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.0f", temp_syringe_radius);
            }
            else if (syringe_radius_point_count == 1)
            {
                temp_syringe_radius = temp_syringe_radius + (double(move_or_number) / 10.0);
                tft.fillRect(20, 140, 230, 30, DARK_BLUE);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.1f", temp_syringe_radius);
                syringe_radius_point_count++;
            }
            else if (syringe_radius_point_count == 2)
            {
                temp_syringe_radius = temp_syringe_radius + (double(move_or_number) / 100.0);
                tft.fillRect(20, 140, 230, 30, DARK_BLUE);
                tft.drawRect(20, 140, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 148);
                tft.printf("%.2f", temp_syringe_radius);
                syringe_radius_point_count++;
            }
        }
    }
}
```
#### 3-4-1-5-3-2-1-1. **Add Syringe Error No Volume Page**

```cpp
void update_add_syringe_error_no_volume_page(int move) {
    if (move == ok_move && current_button_row == 0)
    {
        program_state = add_syringe_page;
        current_button_row = 0;
        syringe_volume_point_count = 0;
        add_syringe_flag = true;
        set_add_syringe_page();
    }
}
```

#### 3-4-1-5-3-2-1-2.  **Add Syringe Error No Radius Page**
``` cpp
void update_add_syringe_error_no_radius_page(int move) {
    if (move == ok_move && current_button_row == 0)
    {
        program_state = add_syringe_page;
        current_button_row = 0;
        syringe_radius_point_count = 0;
        add_syringe_flag = true;
        set_add_syringe_page();
    }
}
```
#### 3-4-1-5-3-2-2. Remove syringe page
```cpp
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
            tft.printf("Syringe %.2f mL (%%.2f mm)", available_syringe_types[1][0], available_syringe_types[1][1]);

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
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
            }

            int col = 10, row = 30 + (syringe_count - 1) * row_diff;
            tft.setTextSize(2);
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%%.2f mm)", available_syringe_types[syringe_count][0], available_syringe_types[syringe_count][1]);

            current_button_row--;
        }
        else if (current_button_row == syringe_count + 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
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
            tft.printf("Syringe %.2f mL (%%.2f mm)", available_syringe_types[current_button_row + 1][0], available_syringe_types[current_button_row + 1][1]);

            row -= row_diff;
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            tft.printf("Syringe %.2f mL (%%.2f mm)",
                available_syringe_types[current_button_row][0], 
                available_syringe_types[current_button_row][1]);

            current_button_row--;
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
		            tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
		        }

		        int col = 10, row = 30;
		        tft.setTextSize(2);
		        tft.setTextColor(LIGHT_BLUE);
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
		        tft.setTextColor(LIGHT_BLUE);
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
}
```

#### 3-4-1-5-3-3. Load page
``` cpp
void update_load_page(int move)
{
    if (move == up_move)
    {
        int count = stored[0][0];
        int row_diff = int(380 / count);

        if (current_button_row == 0)
        {
            int col = 10, row = 30;
            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            int i = 1;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = count + 1;
        }
        else if (current_button_row == count)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 395 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
            }

            int col = 10, row = 30 + (count - 1) * row_diff;
            tft.setTextSize(2);
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            int i = count;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            current_button_row--;
        }
        else if (current_button_row == count + 1)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
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
            int i = current_button_row + 1;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            row -= row_diff;
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            i = current_button_row;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            current_button_row--;
        }
	}
	else if (move == down_move)
	{
	    int count = stored[0][0];
	    int row_diff = int(380 / count);

	    if (current_button_row == count - 1)
	    {
	        int col = 10, row = 30 + (count - 1) * row_diff;
	        tft.setTextSize(2);
	        tft.setTextColor(WHITE);
	        tft.setCursor(col, row);
	        int i = count;
	        if (stored[i][0] == time_)
	        {
	            tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
	        }
	        else
	        {
	            tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
	        }

	        for (int i = 0; i < 3; i++)
	        {
	            tft.drawRoundRect(60 + i, 395 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
	        }

	        current_button_row++;
	    }
	    else if (current_button_row == count)
	    {
	        for (int i = 0; i < 3; i++)
	        {
	            tft.drawRoundRect(60 + i, 395 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
	        }

	        for (int i = 0; i < 3; i++)
	        {
	            tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
	        }

	        current_button_row++;
	    }
	    else if (current_button_row == count + 1)
	    {
	        for (int i = 0; i < 3; i++)
	        {
	            tft.drawRoundRect(60 + i, 440 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
	        }

	        int col = 10, row = 30;
	        tft.setTextSize(2);
	        tft.setTextColor(LIGHT_BLUE);
	        tft.setCursor(col, row);
	        int i = 1;
	        if (stored[i][0] == time_)
	        {
	            tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
	        }
	        else
	        {
	            tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
	        }
	        current_button_row = 0;
	    }
	    else
	    {
	        tft.setTextSize(2);

	        int col = 10, row = 30 + (current_button_row)*row_diff;
	        tft.setTextColor(WHITE);
	        tft.setCursor(col, row);
	        int i = current_button_row + 1;
	        if (stored[i][0] == time_)
	        {
	            tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
	        }
	        else
	        {
	            tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
	        }

	        row += row_diff;
	        tft.setTextColor(LIGHT_BLUE);
	        tft.setCursor(col, row);
	        i = current_button_row + 2;
	        if (stored[i][0] == time_)
	        {
	            tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
	        }
	        else
	        {
	            tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
	        }

	        current_button_row++;
	    }
	}
	else if (move == ok_move)
	{
	    int count = stored[0][0];
	    int row_diff = int(380 / count);

	    if (current_button_row == count) // remove
	    {
	        current_button_row = 0;
	        program_state = remove_page;
	        set_remove_page();
	    }
	    else if (current_button_row == count + 1) // back
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
	    }
	    else // choose
	    {
	        time_or_volume_flag = stored[current_button_row + 1][0];

	        if (time_or_volume_flag == time_)
	        {
	            temp_time = stored[current_button_row + 1][1];
	            temp_volume = 0;
	        }
	        else
	        {
	            temp_time = 0;
	            temp_volume = stored[current_button_row + 1][1];
	        }

	        input_rate = stored[current_button_row + 1][2];

	        time_unit = stored[current_button_row + 1][3];

	        volume_unit = stored[current_button_row + 1][4];

	        syringe = stored[current_button_row + 1][5];

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
	    }
	}
}
```

#### 3-4-1-5-3-4. Store page
``` cpp
void update_store_page(int move)
{
    if (move == ok_move && current_button_row == 0)
    {
        if (new_injection_flag)
        {
            program_state = new_injection_page;
            current_button_row = 0;
            set_new_injection_page();
        }
        else if (new_suction_flag)
        {
            program_state = new_suction_page;
            current_button_row = 0;
            set_new_suction_page();
        }
    }
}
```

#### 3-4-1-5-3-5. Remove page

```cpp
void update_remove_page(int move)
{
    if (move == up_move)
    {
        int count = stored[0][0];
        int row_diff = int(380 / count);

        if (current_button_row == 0)
        {
            int col = 10, row = 30;
            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            int i = 1;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row = count;
        }
        else if (current_button_row == count)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
            }

            int col = 10, row = 30 + (count - 1) * row_diff;
            tft.setTextSize(2);
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            int i = count;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            current_button_row--;
        }
        else
        {
            tft.setTextSize(2);

            int col = 10, row = 30 + (current_button_row)*row_diff;
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            int i = current_button_row + 1;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            row -= row_diff;
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            i = current_button_row;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            current_button_row--;
        }
    }
    else if (move == down_move)
    {
        int count = stored[0][0];
        int row_diff = int(380 / count);

        if (current_button_row == count - 1)
        {
            int col = 10, row = 30 + (count - 1) * row_diff;
            tft.setTextSize(2);
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            int i = count;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, WHITE);
            }

            current_button_row++;
        }
        else if (current_button_row == count)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(60 + i, 430 + i, 200 - i * 2, 40 - i * 2, 8, LIGHT_BLUE);
            }

            int col = 10, row = 30;
            tft.setTextSize(2);
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            int i = 1;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            current_button_row = 0;
        }
        else
        {
            tft.setTextSize(2);

            int col = 10, row = 30 + (current_button_row)*row_diff;
            tft.setTextColor(WHITE);
            tft.setCursor(col, row);
            int i = current_button_row + 1;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            row += row_diff;
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(col, row);
            i = current_button_row + 2;
            if (stored[i][0] == time_)
            {
                tft.printf("r = %.2f mL/sec\n t = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }
            else
            {
                tft.printf("r = %.2f mL/sec\n v = %.2f sec\n s = %.2f mL", stored[i][2], stored[i][1], available_syringe_types[int(stored[i][5])][1]);
            }

            current_button_row++;
        }
    }
    else if (move == ok_move)
    {
        int count = stored[0][0];
        int row_diff = int(380 / count);

        if (current_button_row == count)
        {
            program_state = load_page;
            current_button_row = 0;
            set_load_page();
        }
        else
        {
            stored[0][0]--;

            for (int i = current_button_row + 2; i <= count; i++)
            {
                stored[i - 1][0] = stored[i][0];
                stored[i - 1][1] = stored[i][1];
                stored[i - 1][2] = stored[i][2];
                stored[i - 1][3] = stored[i][3];
                stored[i - 1][4] = stored[i][4];
                stored[i - 1][5] = stored[i][5];
            }

            stored[count][0] = 0;
            stored[count][1] = 0;
            stored[count][2] = 0;
            stored[count][3] = 0;
            stored[count][4] = 0;
            stored[count][5] = 0;

            program_state = load_page;
            current_button_row = 0;
            set_load_page();
        }
    }
}
```

#### 3-4-1-5-4. New injection page

```cpp
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
                tft.drawRoundRect(70 + i, 440 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 7;
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
                tft.drawRoundRect(70 + i, 250 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            curr_row = 150;
            sprintf(curr_message, "Volume:");

            current_button_row = 1;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 288 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 250 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 326 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 288 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 5)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 364 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 326 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }
        else if (current_button_row == 6)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 402 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 364 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 440 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 402 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 6;
        }

        if (current_button_row == 1)
        {
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
        else if (current_button_row == 7)
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

            tft.setTextColor(LIGHT_BLUE);
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
                tft.drawRoundRect(70 + i, 250 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 250 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 288 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 288 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 326 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 326 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 364 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else if (current_button_row == 5)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 364 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 402 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 6;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 402 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 440 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 7;
        }

        if (current_button_row == 0)
        {
            tft.setTextColor(LIGHT_BLUE);
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

            tft.setTextColor(LIGHT_BLUE);
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
                tft.drawRoundRect(70 + i, 250 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 250 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 288 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 288 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 326 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 326 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 364 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else if (current_button_row == 5)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 364 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 402 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 6;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 402 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 440 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            curr_row = 50;
            sprintf(curr_message, "Time:");

            current_button_row = 0;
        }

        if (current_button_row == 0)
        {
            tft.setTextColor(LIGHT_BLUE);
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

            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
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
        else if (current_button_row == 4) // Load
        {
            program_state = load_page;
            current_button_row = 0;
            new_injection_flag = true;
            set_load_page();
        }
        else if (current_button_row == 5) // Store
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
                double t = temp_time;

                if (time_unit == 1)
                {
                    t *= 60;
                }
                else if (time_unit == 2)
                {
                    t *= 3600;
                }

                stored[0][0]++;

                int index = stored[0][0];
                stored[index][0] = time_;
                stored[index][1] = t;
                stored[index][2] = useable_input_rate;
                stored[index][3] = 0;
                stored[index][4] = 0;
                stored[index][5] = syringe;

                program_state = store_page;
                current_button_row = 0;
                new_injection_flag = true;
                set_store_page();
            }
            else if (temp_volume != double(0)) // volume
            {
                double v = temp_volume;

                if (volume_unit == 1)
                {
                    v /= 1000;
                }

                stored[0][0]++;

                int index = stored[0][0];
                stored[index][0] = volume_;
                stored[index][1] = v;
                stored[index][2] = useable_input_rate;
                stored[index][3] = 0;
                stored[index][4] = 0;
                stored[index][5] = syringe;

                program_state = store_page;
                current_button_row = 0;
                new_injection_flag = true;
                set_store_page();
            }
        }
        else if (current_button_row == 6) // Create
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
        else if (current_button_row == 7) // Back
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
            tft.fillRect(20, 70, 230, 30, DARK_BLUE);
            tft.drawRect(20, 70, 230, 30, WHITE);

            temp_time = 0;
            time_point_count = 0;
        }
        else if (current_button_row == 1)
        {
            tft.fillRect(20, 170, 230, 30, DARK_BLUE);
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

                tft.fillRect(20, 70, 230, 30, DARK_BLUE);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.0f", temp_time);
            }
            else if (time_point_count == 1)
            {
                temp_time = temp_time + (double(move_or_number) / 10.0);
                tft.fillRect(20, 70, 230, 30, DARK_BLUE);
                tft.drawRect(20, 70, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 78);
                tft.printf("%.1f", temp_time);
                time_point_count++;
            }
            else if (time_point_count == 2)
            {
                temp_time = temp_time + (double(move_or_number) / 100.0);
                tft.fillRect(20, 70, 230, 30, DARK_BLUE);
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

                tft.fillRect(20, 170, 230, 30, DARK_BLUE);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.0f", temp_volume);
            }
            else if (volume_point_count == 1)
            {
                temp_volume = temp_volume + (double(move_or_number) / 10.0);
                tft.fillRect(20, 170, 230, 30, DARK_BLUE);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.1f", temp_volume);
                volume_point_count++;
            }
            else if (volume_point_count == 2)
            {
                temp_volume = temp_volume + (double(move_or_number) / 100.0);
                tft.fillRect(20, 170, 230, 30, DARK_BLUE);
                tft.drawRect(20, 170, 230, 30, WHITE);

                tft.setTextColor(WHITE);
                tft.setCursor(24, 178);
                tft.printf("%.2f", temp_volume);
                volume_point_count++;
            }
        }
    }
}
```
#### 3-4-1-5-4-1. New injection error no time or volume page
```cpp
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
```

#### 3-4-1-5-4-2. New injection error both time and volume page
```cpp
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
```

#### 3-4-1-5-5. New suction page
```cpp
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
                tft.drawRoundRect(70 + i, 440 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 7;
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
                tft.drawRoundRect(70 + i, 250 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            curr_row = 150;
            sprintf(curr_message, "Volume:");

            current_button_row = 1;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 288 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 250 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 326 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 288 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 5)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 364 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 326 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }
        else if (current_button_row == 6)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 402 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 364 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 440 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 402 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 6;
        }

        if (current_button_row == 1)
        {
            tft.setTextColor(LIGHT_BLUE);
            tft.setCursor(Curr_col, curr_row);
            tft.print(curr_message);
        }
        else if (current_button_row == 7)
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

            tft.setTextColor(LIGHT_BLUE);
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
                tft.drawRoundRect(70 + i, 250 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 2;
        }
        else if (current_button_row == 2)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 250 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 288 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 3;
        }
        else if (current_button_row == 3)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 288 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 326 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 4;
        }
        else if (current_button_row == 4)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 326 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 364 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 5;
        }
        else if (current_button_row == 5)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 364 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 402 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 6;
        }
        else if (current_button_row == 6)
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 402 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 440 + i, 180 - i * 2, 34 - i * 2, 8, WHITE);
            }

            current_button_row = 7;
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                tft.drawRoundRect(70 + i, 440 + i, 180 - i * 2, 34 - i * 2, 8, LIGHT_BLUE);
            }

            curr_row = 50;
            sprintf(curr_message, "Time:");

            current_button_row = 0;
        }

        if (current_button_row == 0)
        {
            tft.setTextColor(LIGHT_BLUE);
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

            tft.setTextColor(LIGHT_BLUE);
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
                tft.fillRect(20, 70, 230, 30, DARK_BLUE);
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
                tft.fillRect(20, 170, 230, 30, DARK_BLUE);
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
	    else if (current_button_row == 4) // Load
	    {
	        program_state = load_page;
	        current_button_row = 0;
	        new_suction_flag = true;
	        set_load_page();
	    }
	    else if (current_button_row == 5) // Store
	    {
	        if (input_rate == 0)
	        {
	            program_state = change_unit_error_page;
	            current_button_row = 0;
	            new_suction_flag = true;
	            set_change_unit_error_page();
	        }
	        else if (temp_volume == double(0) && temp_time == double(0)) // Error none
	        {
	            program_state = new_suction_error_no_time_or_volume_page;
	            current_button_row = 0;
	            set_new_suction_error_no_time_or_volume_page();
	        }
	        else if (temp_volume != double(0) && temp_time != double(0)) // Error both
	        {
	            program_state = new_suction_error_both_time_and_volume_page;
	            current_button_row = 0;
	            set_new_suction_error_both_time_and_volume_page();
	        }
	        else if (temp_time != double(0)) // Time
	        {
	            double t = temp_time;

	            if (time_unit == 1)
	            {
	                t *= 60;
	            }
	            else if (time_unit == 2)
	            {
	                t *= 3600;
	            }

	            stored[0][0]++;

	            int index = stored[0][0];
	            stored[index][0] = time_;
	            stored[index][1] = t;
	            stored[index][2] = useable_input_rate;
	            stored[index][3] = 0;
	            stored[index][4] = 0;
	            stored[index][5] = syringe;

	            program_state = store_page;
	            current_button_row = 0;
	            new_suction_flag = true;
	            set_store_page();
	        }
	        else if (temp_volume != double(0)) // Volume
	        {
	            double v = temp_volume;

	            if (volume_unit == 1)
	            {
	                v /= 1000;
	            }

	            stored[0][0]++;

	            int index = stored[0][0];
	            stored[index][0] = volume_;
	            stored[index][1] = v;
	            stored[index][2] = useable_input_rate;
	            stored[index][3] = 0;
	            stored[index][4] = 0;
	            stored[index][5] = syringe;

	            program_state = store_page;
	            current_button_row = 0;
	            new_suction_flag = true;
	            set_store_page();
	        }
	    }
	    else if (current_button_row == 6) // Create
	    {
	        if (input_rate == 0)
	        {
	            program_state = change_unit_error_page;
	            current_button_row = 0;
	            new_suction_flag = true;
	            set_change_unit_error_page();
	        }
	        else if (temp_volume == double(0) && temp_time == double(0)) // Error none
	        {
	            program_state = new_suction_error_no_time_or_volume_page;
	            current_button_row = 0;
	            set_new_suction_error_no_time_or_volume_page();
	        }
	        else if (temp_volume != double(0) && temp_time != double(0)) // Error both
	        {
	            program_state = new_suction_error_both_time_and_volume_page;
	            current_button_row = 0;
	            set_new_suction_error_both_time_and_volume_page();
	        }
	        else if (temp_time != double(0)) // Time
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
	        else if (temp_volume != double(0)) // Volume
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
	            injection_or_suction_flag = suction;
	            set_progress_page_with_volume();

	            stepper_move(suction, volume_);
	        }
	    }
	    else if (current_button_row == 7) // Back
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
	        tft.fillRect(20, 70, 230, 30, DARK_BLUE);
	        tft.drawRect(20, 70, 230, 30, WHITE);

	        temp_time = 0;
	        time_point_count = 0;
	    }
	    else if (current_button_row == 1)
	    {
	        tft.fillRect(20, 170, 230, 30, DARK_BLUE);
	        tft.drawRect(20, 170, 230, 30, WHITE);

	        temp_volume = 0;
	        volume_point_count = 0;
	    }
	}
	else
	{
	    if (current_button_row == 0) // Time
	    {
	        if (time_point_count == 0)
	        {
	            temp_time *= 10;
	            temp_time += move_or_number;

	            tft.fillRect(20, 70, 230, 30, DARK_BLUE);
	            tft.drawRect(20, 70, 230, 30, WHITE);

	            tft.setTextColor(WHITE);
	            tft.setCursor(24, 78);
	            tft.printf("%.0f", temp_time);
	        }
	        else if (time_point_count == 1)
	        {
	            temp_time = temp_time + (double(move_or_number) / 10.0);
	            tft.fillRect(20, 70, 230, 30, DARK_BLUE);
	            tft.drawRect(20, 70, 230, 30, WHITE);

	            tft.setTextColor(WHITE);
	            tft.setCursor(24, 78);
	            tft.printf("%.1f", temp_time);
	            time_point_count++;
	        }
	        else if (time_point_count == 2)
	        {
	            temp_time = temp_time + (double(move_or_number) / 100.0);
	            tft.fillRect(20, 70, 230, 30, DARK_BLUE);
	            tft.drawRect(20, 70, 230, 30, WHITE);

	            tft.setTextColor(WHITE);
	            tft.setCursor(24, 78);
	            tft.printf("%.2f", temp_time);
	            time_point_count++;
	        }
	    }
	    else if (current_button_row == 1) // Volume
	    {
	        if (volume_point_count == 0)
	        {
	            temp_volume *= 10;
	            temp_volume += move_or_number;

	            tft.fillRect(20, 170, 230, 30, DARK_BLUE);
	            tft.drawRect(20, 170, 230, 30, WHITE);

	            tft.setTextColor(WHITE);
	            tft.setCursor(24, 178);
	            tft.printf("%.0f", temp_volume);
	        }
	        else if (volume_point_count == 1)
	        {
	            temp_volume = temp_volume + (double(move_or_number) / 10.0);
	            tft.fillRect(20, 170, 230, 30, DARK_BLUE);
	            tft.drawRect(20, 170, 230, 30, WHITE);

	            tft.setTextColor(WHITE);
	            tft.setCursor(24, 178);
	            tft.printf("%.1f", temp_volume);
	            volume_point_count++;
	        }
	        else if (volume_point_count == 2)
	        {
	            temp_volume = temp_volume + (double(move_or_number) / 100.0);
	            tft.fillRect(20, 170, 230, 30, DARK_BLUE);
	            tft.drawRect(20, 170, 230, 30, WHITE);

	            tft.setTextColor(WHITE);
	            tft.setCursor(24, 178);
	            tft.printf("%.2f", temp_volume);
	            volume_point_count++;
	        }
	    }
	}
}
```

#### 3-4-1-5-1. New Suction Error No Time or Volume Page

```cpp
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
```

#### 3-4-1-5-2. New Suction Error Both Time and Volume Page

```cpp
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
```

#### 3-4-1-5-6. Progress Page

It includes two types of progress with time or volume.

#### 3-4-1-5-6-1. Progress with Time Page

```cpp
void update_progress_page_with_time(int move)
{
    if (move == ok_move)
    {
        if (current_button_row == 0)
        {
            program_state = stop_page;
            current_button_row = 0;
            set_stop_page();
        }
    }
}
```

#### 3-4-1-5-6-2. Progress Page with Volume

```cpp
void update_progress_page_with_volume(int move)
{
    if (move == ok_move)
    {
        if (current_button_row == 0)
        {
            program_state = stop_page;
            current_button_row = 0;
            set_stop_page();
        }
    }
}
```

#### 3-4-1-5-7. Abort Page
It includes two types of stop or end.

#### 3-4-1-5-7-1. Stop Page

```cpp
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
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, LIGHT_BLUE);
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
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, LIGHT_BLUE);
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
```

#### **3-4-1-5-7-2. End Page**
```cpp
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
            tft.drawRoundRect(last_col + i, last_row + i, width - i * 2, height - i * 2, radius, LIGHT_BLUE);
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
```

#### **3-4-1-5-8. Button Page**

#### **3-4-1-5-8-1. Button Start Page**
```cpp
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
```

#### **3-4-1-5-8-2. Button Finish Page**
```cpp
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
```

#### **3-4-1-5-9. Free Move Page**
```cpp
void update_free_move_page(int move_or_number)
{
    if (move_or_number == up_move)
    {
        double r = available_syringe_types[syringe][1];
        double steps = 10000;
        double length = 3.47;

        double speed;
        double move = 100;

        if (temp_speed != 0)
        {
            speed = (1000000 * PI * r * r * length) / (temp_speed * steps * 1000);
        }
        else
        {
            speed = (1000000 * PI * r * r * length) / (1 * steps * 1000);
        }

        double t = 0.1;

        stepper->setSpeedInUs(speed);
        stepper->setAcceleration(speed / t);
        stepper->move(-1 * move);
    }
    else if (move_or_number == down_move)
    {
        double r = available_syringe_types[syringe][1];
        double steps = 10000;
        double length = 3.47;

        double speed;
        double move = 100;

        if (temp_speed != 0)
        {
            speed = (1000000 * PI * r * r * length) / (temp_speed * steps * 1000);
        }
        else
        {
            speed = (1000000 * PI * r * r * length) / (1 * steps * 1000);
        }

        stepper->setSpeedInUs(speed);
        stepper->setAcceleration(10 * speed);
        stepper->move(move);
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
        tft.fillRect(20, 300, 300, 30, DARK_BLUE);
        tft.drawRect(20, 300, 300, 30, WHITE);
        temp_speed = 0;
    }
    else
    {
        temp_speed *= 10;
        temp_speed += move_or_number;

        tft.fillRect(20, 300, 300, 30, DARK_BLUE);
        tft.drawRect(20, 300, 300, 30, WHITE);

        tft.setTextColor(WHITE);
        tft.setCursor(24, 308);
        tft.printf("%d", temp_speed);
    }
}
```

### 3-5. Stepper
In this section, we will first become familiar with different types of movements, explore the desired movement for this project, introduce the Stepper motor, and check its connections. Then, we will delve into the project code and verify it.

#### 3-5-1. Familiarity with Types of Movement
**Task Description:** Explain and compare the types of constant acceleration, S Curve, and Parabolic movements.

#### 3-5-1-1. Types of Movement
When we refer to types of movement, we are talking about constant acceleration, S Curve, and Parabolic movements, which are specific modes of motion. We are interested in these three types of movement due to their ability to provide smooth motion. For a comparison, you can watch this video that illustrates the differences between constant acceleration and S Curve.

#### 3-5-1-2. Constant or Trapezoidal Acceleration
In this type of movement, instead of starting at a predefined speed, the motion starts from zero and gradually accelerates to the desired speed with constant acceleration. When coming to a halt, it doesn't abruptly drop to zero from the desired speed but does so with a constant acceleration.

To calculate the acceleration or its duration, you can use the following formulas:

#### 3-5-1-3. S Curve
In S Curve motion, the smoothness of motion can be observed even from the graph. This type of motion, similar to Trapezoidal motion but smoother, eliminates the sharp corners in the graph, and the variation in speed is not always characterized by a constant acceleration.

The following formulas can be employed for calculations:

S Curve motion takes some time to accelerate, so Trapezoidal movement is usually accomplished in a shorter time. If the application demands a shorter time, but S Curve motion is desired, you can initiate speed from a higher value instead of starting from zero. When done correctly, this results in smoother motion compared to Trapezoidal motion.

#### 3-5-1-4. Parabolic
Constant acceleration and S Curve movements work well with linear torque, but for stepper motors at high speeds, the torque deviates from linearity. In these types of motors, an alternative movement known as parabolic motion can be employed. Parabolic motion is as follows:

The following formulas can be used for calculations:

### 3-5-2. Introduction to Stepper and Connection to ESP32
**Job Description:** Understand what a Stepper and Stepper Driver are, move the Stepper motor without a library and with a library, and create a simple project for each using your knowledge.

#### 3-5-2-1. What is a Stepper?
A Stepper is a type of DC motor that moves in discrete steps. These motors typically have four coils or phases, and the mechanism involves energizing each coil in a specific sequence to move the motor one step at a time.

- Clockwise Movement
- Counterclockwise Movement

The sequence in which the coils receive pulses determines the motor's direction, while the pulse frequency influences its speed, and the number of pulses determines the extent of movement.

#### 3-5-2-2. What is Stepper Driver?
Stepper drivers, available in various types, incorporate built-in translators that reduce the pin count to only 2 pins for step and direction control. In some cases, more than one motor can be connected to these drivers for convenient control, providing a smoother experience. Additionally, these drivers can offer microstepping, allowing movement in full, half, quarter, eighth, and sixteenth steps. In this project, the DRV8825 and A4988 drivers are used.

#### 3-5-2-3. Connecting Driver and Motor to ESP32
To connect and use the motor, first connect the motor to the driver. Then, connect the 4 pins of the driver. Connect two pins for VCC and GND and select two pins for step and dir, connecting them together. You can use them by simply defining these two pins in the setup section:

```cpp
pinMode(5, OUTPUT); // Step
pinMode(4, OUTPUT); // Direction
```

In the drivers, there is a pin called "enable" that, when activated, energizes the coils. This pin can be directly connected to GND for constant activation, but to prevent motor overheating, it's better to activate this pin in the code (most libraries handle this more efficiently).

```cpp
pinMode(6, OUTPUT); // Enable
digitalWrite(6, LOW);
```

#### 3-5-2-4. Moving Without a Library
To move without using a library, you can control the number of steps and regulate the motor's speed by specifying the time you want the motor to move. The duration of each step is determined by the equation: `t/n`, where `t` is the time in seconds, and `n` is the number of steps.

Here's an example code snippet for moving without a library:

```cpp
#include <Arduino.h>

#define step 21
#define dir 22
#define enable 23

void setup()
{
  pinMode(step, OUTPUT);
  pinMode(dir, OUTPUT);
  pinMode(enable, OUTPUT);
}

void loop()
{
  digitalWrite(dir, HIGH);

  int steps = 1000;
  int time = 5000000;
  time /= 1000;
  time /= 2;

  for (int Index = 0; Index < steps; Index++)
  {
    digitalWrite(step, HIGH);
    delayMicroseconds(time);
    digitalWrite(step, LOW);
    delayMicroseconds(time);
  }

  digitalWrite(dir, LOW);

  for (int Index = 0; Index < steps; Index++)
  {
    digitalWrite(step, HIGH);
    delayMicroseconds(time);
    digitalWrite(step, LOW);
    delayMicroseconds(time);
  }
}
```

#### 3-5-2-5. Moving With the Library
Using a library allows you to achieve smoother motion and more control over movement compared to moving without a library. Libraries can control the motor's pulses with PWM and manage the duty cycle to provide a smoother experience without stopping the motor's motion.

When working with Arduino, you can use the `stepper.h` library. However, this library cannot be used with ESP32. Instead, you can use libraries like `smoothstepper.h`, `sinusoidal.h`, or `fastaccelstepper.h` with this microcontroller.

Here's an example for using the `fastaccelstepper.h` library:

To use the library, specify the speed directly to the corresponding function (the speed unit should be in microseconds per step). Additionally, you can use the `setAcceleration` function to define the acceleration needed to reach the speed. The `fastaccelstepper` library supports constant acceleration movement.

```cpp
#include "FastAccelStepper.h"

#define step 21
#define dir 22
#define enable 23

FastAccelStepperEngine engine = FastAccelStepperEngine();
FastAccelStepper *stepper = NULL;

void setup()
{
  Serial.begin(9600);
  engine.init();
  stepper = engine.stepperConnectToPin(step);
  if (stepper)
  {
    stepper->setDirectionPin(dir);
    stepper->setEnablePin(enable);
    stepper->setAutoEnable(true);

    int steps = 1000;
    int speed = 50;

    stepper->setSpeedInUs(speed);
    stepper->setAcceleration(1000000 / (1 * speed));
    stepper->move(steps);
  }
}

void loop()
{
}
```

#### 3-5-3. Relevant Codes in the Project
```cpp
void stepper_move(int injection_or_suction, int time_or_volume) {
  /* Used for calibration */
  double steps = 10000;
  double length = 3.47;

  double r = available_syringe_types[syringe][1];
  double move;

  if (time_or_volume == volume_) {
    move = 1000 * (remaining_volume * steps) / (PI * r * r * length);
  }
  else {
    move = 1000 * (usable_input_rate * remaining_time * steps) / (PI * r * r * length);
  }

  if (injection_or_suction == injection) {
    move *= -1;
  }

  double speed = (1000000 * PI * r * r * length) / (usable_input_rate * steps / 1000);
  double T = 0.1;
  double acceleration = 1000000 / (speed * T);

  stepper->setSpeedInUs(speed);
  stepper->setAcceleration(acceleration);
  stepper->move(move);

  while (stepper->isRunning()) {
    if (char_flag) {
      int index = keyPad.getKey();
      if (index < 16) {
        key = keys[index];
      }
      lastKeyPressed = millis();
      char_flag = false;

      if (key == '#') {
        key = '\0';
        program_state = stop_page;
        current_button_row = 0;
        set_stop_page();
        stepper->forceStop();
        return;
      }
    }

    if (button_start.pressed || button_finish.pressed) {
      button_start.pressed = false;
      button_finish.pressed = false;
      stepper->forceStop();
      return;
    }
  }

  program_state = end_page;
  current_button_row = 0;
  set_end_page();
}
```

#### 3-6. MicroSwitch
In this part, we connect the MicroSwitches to the microcontroller and bring the main codes. Because the codes in this part use Interrupt, first we will explain the Interrupt, then we will get acquainted with MicroSwitch and bring the project codes.

#### 3-6-1. Getting to Know Interrupt and How to Use it in ESP32
##### 3-6-1-1. What is Interrupt?
When an event occurs, such as hitting a key or reaching a certain time, the microcontroller must handle this event without interrupting the main flow of the program. Interrupts can be defined in two ways: software interrupts and hardware interrupts. Software interrupts are internal and occur due to the program, while hardware interrupts are external, occurring due to an external factor, such as a sensor or button.

#### 3-6-1-2. How to Use Interrupt in ESP32?
ESP32 is a microcontroller with two cores and allows defining 32 interrupts in each core. You can use external interrupts in ESP32 as follows:

For example, to define pressing a button as an interrupt, first, assign a pin from the board's GPIO pins to the button:
```cpp
struct Button {
  const uint8_t PIN;
  bool pressed;
  unsigned long last_button_time;
};

Button button = {18, false, 0};
```

In the setup section, define this button as an input:
```cpp
pinMode(button.PIN, INPUT_PULLUP);
```

Use the `IRAM_ATTR` attribute to run the required code in RAM because it is faster than Flash Memory and doesn't disrupt the main program:
```cpp
void IRAM_ATTR button_press_interrupt() {
  unsigned long button_time = millis();

  if (button_time - button.last_button_time > 250) {
    Serial.println("Pressed");
    button.pressed = true;
    button.last_button_time = button_time;
  }
}
```

Define the intended pin for the button as an interrupt in the setup:
```cpp
attachInterrupt(button.PIN, button_press_interrupt, FALLING);
```

`FALLING` occurs when the pin goes from 1 to 0 and can be replaced by `RISING`, which triggers when the pin goes from 0 to 1, and `CHANGE`, which is triggered on any change in the pin.

#### 3-6-1-3. Simple Project
In this simple project, pressing two buttons is recognized as an interrupt, and appropriate expressions are printed in the terminal.

```cpp
struct Button {
  const uint8_t PIN;
  bool pressed;
  unsigned long last_button_time;
};

Button button_right = {18, false, 0};
Button button_left = {17, false, 0};

void IRAM_ATTR button_right_press_interrupt() {
  unsigned long button_time = millis();

  if (button_time - button_right.last_button_time > 250) {
    Serial.println("right");
    button_right.pressed = true;
    button_right.last_button_time = button_time;
  }
}

void IRAM_ATTR button_left_press_interrupt() {
  unsigned long button_time = millis();

  if (button_time - button_left.last_button_time > 250) {
    Serial.println("left");
    button_left.pressed = true;
    button_left.last_button_time = button_time;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(button_right.PIN, INPUT_PULLUP);
  pinMode(button_left.PIN, INPUT_PULLUP);
  attachInterrupt(button_left.PIN, button_left_press_interrupt, FALLING);
  attachInterrupt(button_right.PIN, button_right_press_interrupt, FALLING);
}

void loop() {
}
```

#### 3-6-2. Getting to Know What MicroSwitch Is and How to Connect It to ESP32
#### 3-6-2-1. What is Micro Switch?
Micro switches are very sensitive types of switches that are widely used due to their affordability, reliability, and long lifespan (usually up to 10 million cycles). They are used in sensitive applications such as automatic door safety and in this project to prevent the engine from hitting the beginning and end of the designated path for platform movement.

#### 3-6-2-2. How to Use Micro Switch in ESP32?
To use these switches, select a pin on the microcontroller and connect the green pin in the micro switch module (or the corresponding pin in different micro switches) to that pin. By checking the value of this pin, you can be informed about the collision of the platform with the beginning or the end of the path and perform the desired task.

#### 3-6-2-3. Simple Project
In this simple project, the use of micro switches as interrupts is demonstrated:

```cpp
struct Button {
  const uint8_t PIN;
  bool pressed;
  unsigned long last_button_time;
};

Button button_start = {34, false, 0};
Button button_finish = {35, false, 0};

void IRAM_ATTR button_start_press_interrupt() {
  unsigned long button_time = millis();

  if (button_time - button_start.last_button_time > 250) {
    button_start.pressed = true;
    button_start.last_button_time = button_time;
    program_state = button_start_page;
    set_button_start_page();
  }
}

void IRAM_ATTR button_finish_press_interrupt() {
  unsigned long button_time = millis();

  if (button_time - button_finish.last_button_time > 250) {
    button_finish.pressed = true;
    button_finish.last_button_time = button_time;
    program_state = button_finish_page;
    set_button_finish_page();
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(button_start.PIN, INPUT);
  pinMode(button_finish.PIN, INPUT);
  attachInterrupt(button_start.PIN, button_start_press_interrupt, FALLING);
  attachInterrupt(button_finish.PIN, button_finish_press_interrupt, FALLING);
}

void loop() {
  if (button_start.pressed) {
    Serial.println("Start button pressed");
    button_start.pressed = false;
  }

  if (button_finish.pressed) {
    Serial.println("Finish button pressed");
    button_finish.pressed = false;
  }
}
```

#### 3-6-3. Related Codes in the Main Project
These functions for micro switch presses have been defined and are used in the main project.

I've formatted your text into a clear guide for using the injection device:

## Instructions for Using the Injection Device

To use the injection device, follow this guide. The device allows you to perform manual or automatically adjusted syringe injection and suction operations with the ability to specify injection time or volume along with the flow rate. You can navigate through the device using up, down, right, left, and OK buttons, and use numeric buttons for data input. The Erase button is used to delete entered numbers, and the button with a dot is used for decimal input.

#### General Navigation
- Use up, down, right, and left buttons to move around the device.
- Use the OK button to select an option.
- Use numeric buttons for data entry.
- Use the Erase button to delete entered numbers.
- Use the button with a dot for decimal input.

#### Main Pages
1. **Menu Page:** Use this page to access other sections of the device.
   - **Settings Page:** Change units and syringes.
   - **New Injection:** Access the automatic injection page.
   - **New Suction:** Access the automatic suction page.
   - **Free Move:** Access manual injection or suction page.

2. **Settings Page:**
   - **Change Unit:** Change units.
   - **Change Syringe:** Change the syringe.
   - **Back:** Return to the menu page.

3. **Unit Change Page:**
   - Select Volume or Time modes.
   - Choose units.
   - Save settings with "Apply" or delete with "Back."

4. **Syringe Change Page:**
   - Select a syringe.
   - Add a syringe or remove it from the list.
   - Return to the previous page.

5. **Add Syringe Page:**
   - Enter syringe volume and radius.
   - Save settings with "Add."
   - Note: All fields must be filled.
   
6. **Syringe Removal Page:**
   - Remove a selected syringe from the list.
   - Return to the syringe change page.

7. **Automatic Injection or Suction Pages:**
   - Set injection time or volume.
   - Start injection with "Create."
   - Access unit and syringe settings.
   - Load previous settings or store new ones.
   - Delete settings and return to the menu page.

8. **Injection Progress Page:**
   - View remaining time or volume.
   - Stop the operation at any time with "Confirmation."

9. **Stop Page:**
   - Display the amount injected.
   - Resume, edit settings, or exit to the menu page.

10. **End Page:**
    - Display the amount of time or volume.
    - Start a new operation or return to the menu page.

11. **Suction or Manual Injection Page:**
    - Perform manual injection or suction.
    - Set the flow rate.
    - Return to the menu page.

12. **Stopping the Operation:**
    - The moving platform may reach its path's beginning or end.
    - Stop the operation, and configure device settings.

Use this guide to navigate and operate your injection device effectively.

## 4. The third project (pass box device control) Task description: Research Raspberry pi 3.
### 4-1. **What is Raspberry Pi?**
   - Raspberry Pi is a popular and affordable single-board computer designed to make computing accessible to the public, especially for educational purposes. It has played a crucial role in promoting computer science and programming skills among students.
   - Raspberry Pi boards are small, low-cost computers equipped with features like Bluetooth, WiFi, USB ports, and input/output pins.
   - They can be connected to a monitor and used with a keyboard and mouse, making them versatile and user-friendly.
   - The name "Raspberry Pi" is a combination of "Raspberry" from the Raspberry operating system and "Pi" from the Python programming language.

4-2. **Capabilities**
   - Raspberry Pi offers a wide range of capabilities, including:
     - Internet connectivity and HD video playback.
     - Office applications for spreadsheets and word processing.
     - Support for gaming.
     - Compatibility with infra-red cameras and security systems.
     - Application in music and weather detection systems.

4-3. **Board Hardware**
   - Raspberry Pi boards are equipped with the following hardware components:
     - Processor: Quad-Core ARM Cortex-A53.
     - 40 general input/output pins.
     - WiFi antenna.
     - DSI port (Display interface).
     - Micro USB connector.
     - HDMI support.
     - CSI port (Camera interface).
     - Audio jack.
     - Ethernet connector.
     - USB Ports.
     - SD card slot.

Raspberry Pi's affordability and versatility make it a popular choice for various projects, including pass box device control.
