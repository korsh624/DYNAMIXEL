


#include <Ethernet.h>
#include <EthernetUdp.h>
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED
};
IPAddress ip(192, 168, 42, 17);
#define lamp_ip "192.168.42.15"
#define manip_ip "192.168.42.12"
unsigned int localPort = 8888;      // local port to listen on

char packetBuffer[UDP_TX_PACKET_MAX_SIZE];  // buffer to hold incoming packet,
char ReplyBuffer[] = "acknowledged";        // a string to send back
EthernetUDP Udp;
bool flag = false;
void setup() {
  Ethernet.init(10);  // Most Arduino shields
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    Serial.println("Ethernet shield was not found.  Sorry, can't run without hardware. :(");
    while (true) {
      delay(1); // do nothing, no point running without Ethernet hardware
    }
  }
  if (Ethernet.linkStatus() == LinkOFF) {
    Serial.println("Ethernet cable is not connected.");
  }

  // start UDP
  Udp.begin(localPort);
}
void manip_set(int x, int y, int z, int a, int g)
{
  char buffer[50];

  sprintf(buffer, "g:%d:%d:%d:%d:%d#", x, y, a, z, g);
  Udp.beginPacket(manip_ip, 8888);
  Udp.write(buffer);
  Udp.endPacket();
  memset(buffer,0, sizeof(buffer));
}
void loop() {
//  manip_set(150, 0, 120, 0, 0);
//  delay(2000);
//  manip_set(150, 0, 120, 0, 1);
//  delay(2000);
//  manip_set(150, 0, 150, 0, 1);
//  delay(2000);
//  manip_set(150, 0, 150, 0, 0);
//  delay(2000);

}
void setlamp(String message ) {
  Udp.beginPacket("192.168.42.16", 8888);
  char Buf[50];
  message.toCharArray(Buf, 50);
  Udp.write(Buf);
  Udp.endPacket();
  delay(100);
}
