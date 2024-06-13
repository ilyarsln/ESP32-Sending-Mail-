# ESP32.Sending.Mail
 Sending Mail via ESP32

ESP32 Email Sender
This project demonstrates how to send emails using an ESP32 microcontroller. 
The ESP32 is configured to connect to a Wi-Fi network and send an email containing a randomly generated 4-digit code when a button is pressed.

Features

Email Sending: Sends an email with a randomly generated 4-digit code.
Button Triggered: Email sending is triggered by pressing a button connected to the ESP32.
SMTP Protocol: Uses the SMTP protocol to send emails via a specified SMTP server.

Setup

Hardware Connections:
Connect a button to GPIO pin 5 of the ESP32.
Software Configuration:
Set up your Wi-Fi credentials, SMTP server details, sender and recipient email addresses, and sender's email password in the code.
Upload the code to your ESP32 board.

Usage:

Power on the ESP32 and wait for it to connect to the Wi-Fi network.
Press the button to trigger the sending of an email with a randomly generated code.
Requirements
Arduino IDE
ESP_Mail_Client library
Code Explanation
WiFi Connection: The ESP32 connects to a specified Wi-Fi network.
Button Handling: The code continuously monitors the state of a button. When the button is pressed, an email is sent.
SMTP Configuration: The SMTP server details and email credentials are configured to send emails.
Email Sending: When the button is pressed, a random 4-digit code is generated and sent via email.