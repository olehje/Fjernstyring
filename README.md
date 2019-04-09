Stasjon 4: Styr roboten med fjernbetjening
På denne stasjon vil du lære å fjernstyre roboten med en fjernbetjening. Roboten har en liten modtaker, som kan modtake infrarøde signaler. De fleste TV fjernbetjeninger sender et slikt signal og du vil derfor kunne bruke disse til å styre roboten.
Det forventes ikke at du kan lage alle øvelserne selv, men det vil være mentorer tilstede som kan hjelpe med disse.
Al kode er markeret med grøn tekst som du kan kopiere ind i dit program, dersom du ikke vil skrive det selv 😊
På dette link finder du et eksempel på hvordan en færdig versjon af koden kan se ut, og du kan hente hjelp her dersom du trenger det. Det vil i hver oppgave også være henvisninger til bestemte linjer kode i denne fil.
Dersom du allerede har gjennemført noen af øvelserne på en tidligere stasjon trenger du ikke å lage disse igjen, men du kan bruke koden fra tidligere. Husk derfor å lagre dit program når du er ferdig.
Bliver du ferdig med øvelserne før tid, kan du enten velge å fortsette med de foreslåtte øvelser eller å lage dit eget program.
Opgaver:
1.	Start med å åpne et tomt Arduino program.
2.	Først skal du få roboten til å kjøre frem. For å bruke de fire motorer på roboten må vi tilføje disse fem linjer i starten af programmet:

#include <UCMotor.h>
UC_DCMotor leftMotor1(3, MOTOR34_64KHZ);
UC_DCMotor rightMotor1(4, MOTOR34_64KHZ);
UC_DCMotor leftMotor2(1, MOTOR34_64KHZ);
UC_DCMotor rightMotor2(2, MOTOR34_64KHZ);

Nå kan du styre hver enkelt motor ved å give den en retning og en hastighed. Hvis du for eksempel vil få venstre motor foran til å kjøre frem må du skrive dette i din loop funksjon:
leftMotor1.run(0x01); 	(“0x02” vil få motoren til å kjøre baglæns, “0x03” vil få den til å snu til venstre, og “0x04” vil snu til højre)

leftMotor1.setSpeed(200);		(farten sættes her til 200)

3.	For å skabe mere overblik i programmet, kan du lave funksjoner, som indeholder kode. Nu skal du lave en funksjon der får roboten til å kjøre frem (som du gjorde i forrige opgave). Et eksempel på en funksjon er dette:

void minFunksjon() {
    // mellem disse to “{ }” skal du skrive alt det kode, som din funksjon skal udføre.
}

Du kjører din funktion ved å skrive funksjonens navn:
	
void loop() {
minFunksjon();
}

4.	Lav nu funksjoner der får roboten til å:		(SE LINJE 165-208 I FERDIG VERSJON)
a.	Snu til venstre
b.	Snu til højre
c.	Kjøre tilbake
d.	Stoppe
Husk at du må bruke «delay()» mellem hver funksjon du kjører. Dette får programmet til å vente med å kjøre videre i programmet. Hvis du for eksempel vil kjøre frem i to sekunder, må du skrive:
funksjon_frem();
delay(2000);
funksjon_stop();

5.	Nå er du klar til å modtake signaler fra din fjernbetjening. Find den fjernbetjening du ønsker å bruke. For å bruke din modtaker må du skrive disse tre linjer i toppen af dit program (SE LINJE 7-9 I FERDIG VERSJON):

#include "IRLibAll.h"
IRrecvPCI myReceiver(2);
IRdecode myDecoder;
Og disse linjer må du sette ind i din setup funksjon (LINJE 16-20 I FERDIG VERSJON):
Serial.begin(9600);
  
myReceiver.enableIRIn();
Du kan hente data fra din modtaker ved å skrive «myReceiver.getResults()». Prøv å indsætte koden herunder i din loop funksjon og tryk på forskjellige knapper med din fjernbetjening (det er viktigt å peke på roboten med fjernbetjeningen).
void loop() {
  	if (myReceiver.getResults()) {
    myDecoder.decode();         
    unsigned long value = myDecoder.value;
    myReceiver.enableIRIn();      //Restart receiver

    Serial.print("0x"); Serial.println(value ,HEX);
}
}

6.	Du kan nu lage en «switch» funksjon, hvor du tjekker verdien af det som roboten modtaker og enten får roboten til å kjøre frem, tilbake, højre, venstre eller stoppe (LINJE 38-161 I FERDIG VERSJON).

7.	Du er nå klar til å teste dit ferdige program. Tænd for roboten og styr den med din fjernbetjening.

8.	Har du mere tid kan du få roboten til å stoppe hvis der kommer en forhindring. For å bruke afstandssensoren må du tilføje disse linjer før din setup funksjon:

#include <Ultrasonic.h>
Ultrasonic ultrasonic(A2, A3);
	Afstanden kan nu gemmes som variablen ”dist” ved at bruge denne linje kode i dit program:
		  int  dist = ultrasonic.distanceRead();
Du kan nu tilføje en if-statement der får roboten til å stoppe hvis afstanden eksempelvis er mindre end 40 (enheden er i centimeter) (LINJE 25-29 I FERDIG VERSJON).
9.	Find selv på annet du vil gjøre med roboten. Forslag:
-	Få den til å stoppe for en hindring bare hvis den kjører frem
-	Få den til å reagjere på flere forskjellige fjernbetjeninger
-	Lav funksjoner der får roboten til å snu akkurat 45 og 90 grader

