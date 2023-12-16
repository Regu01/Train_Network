import processing.serial.*;

Serial port;
int[] relayStatus = {0, 0, 0, 0}; // État initial des relais

void setup() {
  size(400, 200);
  // Initialiser la connexion série avec Arduino (ajuster le port et le baud rate)
  port = new Serial(this, "COM5", 9600); // Remplacez "COM5" par le port correct
}

void draw() {
  background(255);

  // Afficher l'état des relais
  for (int i = 0; i < 4; i++) {
    fill(relayStatus[i] == 1 ? color(255, 0, 0) : color(0, 255, 0));
    ellipse(50 + i * 80, 100, 30, 30);
    textAlign(CENTER, CENTER);
    fill(0);
    text("Relais " + i, 50 + i * 80, 150);
  }

  // Vérifier la présence d'un train
  for (int i = 0; i < 4; i++) {
    // Envoyer une commande à Arduino pour changer l'état du relais
    port.write("CHECK_TRAIN " + i);
    delay(100); // Délai pour laisser le temps à Arduino de répondre
    while (port.available() > 0) {
      String response = port.readStringUntil('\n').trim();
      if (response.startsWith("Canton " + i + ":")) {
        fill(response.endsWith("Occupé") ? color(255, 0, 0) : color(0, 255, 0));
        ellipse(50 + i * 80, 50, 30, 30);
      }
    }
  }
}

// Fonction appelée lorsque la souris est cliquée
void mousePressed() {
  // Changer l'état d'un relais lorsque la souris est cliquée sur le cercle du relais
  for (int i = 0; i < 4; i++) {
    float relayX = 50 + i * 80;
    float relayY = 100;
    float relaySize = 30;
    if (dist(mouseX, mouseY, relayX, relayY) < relaySize / 2) {
      relayStatus[i] = (relayStatus[i] + 1) % 2;
      // Envoyer une commande à Arduino pour changer l'état du relais
      port.write("RELAY " + i + " " + relayStatus[i]);
    }
  }
}
