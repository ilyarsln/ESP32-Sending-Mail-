#include <WiFi.h>
#include <ESP_Mail_Client.h>

#define WIFI_SSID "Your_WiFi_SSID"
#define WIFI_PASSWORD "Your_WiFi_Password"
#define SMTP_SERVER "smtp.gmail.com"
#define SMTP_PORT 465
#define SENDER_EMAIL "your_email@gmail.com"
#define SENDER_PASSWORD "your_email_password"
#define RECIPIENT_EMAIL "recipient_email@example.com"

#define BUTTON_PIN 5 // Define the button pin here

SMTPSession smtp;

void setup() {
  Serial.begin(115200);
  Serial.println();
  
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set the button pin as input
  
  // Initialize Wi-Fi connection
  Serial.print("Connecting to Wi-Fi...");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("Wi-Fi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Send email when the button is pressed
    sendEmail();
    
    delay(1000); // Short delay to prevent consecutive button presses
  }
}

void sendEmail() {
  // Configure SMTP session
  smtp.debug(1);
  ESP_Mail_Session session;
  session.server.host_name = SMTP_SERVER;
  session.server.port = SMTP_PORT;
  session.login.email = SENDER_EMAIL;
  session.login.password = SENDER_PASSWORD;
  session.login.user_domain = "";

  // Generate a random 4-digit code
  String randomCode = generateRandomCode();
  
  // Create email message
  SMTP_Message message;
  message.sender.name = "ESP32";
  message.sender.email = SENDER_EMAIL;
  message.subject = "Random Code";
  message.addRecipient("", RECIPIENT_EMAIL);
  message.text.content = "Your random 4-digit code: " + randomCode;

  // Connect to SMTP server and send email
  if (smtp.connect(&session)) {
    if (MailClient.sendMail(&smtp, &message)) {
      Serial.println("Email sent successfully.");
    } else {
      Serial.println("Error sending email: " + smtp.errorReason());
    }
  } else {
    Serial.println("Error connecting to SMTP server.");
  }
}

String generateRandomCode() {
  // Generate a random 4-digit code
  String code = "";
  for (int i = 0; i < 4; i++) {
    code += String(random(0, 10)); // Random digits between 0-9
  }
  return code;
}
