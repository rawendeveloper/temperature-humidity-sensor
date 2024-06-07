#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

#define led 6
int valeurCapteur;
int limite = 500; 						// valeur sous laquelle la LED s’allumera
const int sensorPin = 1; 				//Capteur de température sur la broche analogique A0

  
void setup() 
{
lcd.begin(16, 2);
pinMode(led, OUTPUT); 					// la connexion 6 doit pouvoir envoyer du courant
}

void loop() 
{
  lcd.setCursor(0,0); 					//Positioner le curseur ligne 0 colonne 0
  lcd.print ("T: "); 					//Afficher le T de température
  lcd.print (GetTemp()); 				//Aller chercher la température
  lcd.print (" C");
  
  valeurCapteur = analogRead(A0);		// Lire la valeur analogique sur la pin A0 et l'attribuer à la variable "valeur capteur"
  lcd.setCursor(0, 1);					// Placer le curseur sur le premier caractere de la deuxieme ligne
  lcd.print("Humidite : ");
  lcd.print(valeurCapteur);				// Afficher la valeur d'humidité

delay(100);
lcd.clear();

if (valeurCapteur > limite) 					// Si l'humidité est superieure à la limite
{
  digitalWrite(led, LOW); 						// Eteindre la LED 
}
  
  else											// Sinon
  {
    digitalWrite(led, HIGH); 					// Allumer la LED 
  }
} 

// Créer une fonction de type float qui renverra la valeur de la temperature

float GetTemp() 								//Creer une fonction qui renvoie un nombre de type float (à virgule)
{
  int reading = analogRead (sensorPin); 		//Definir reading qui va chercher le sensorPin
 
  //Calcul pour avoir la température
  float voltage = reading * 5.0; 
  voltage /= 1024.0; 							//Diviser le voltage par 1024 qui est la valeur analogique
  
  return (voltage-0.5)*100; 					//Renvoyer la température
}   