Sources et fichiers pour le magazine Hackable #21
=================================================

Ce dépôt contient les croquis, sources et fichiers présents dans le 21ème numéro de [Hackable](http://www.hackable.fr/) :

* `Z80ctl_mem` : croquis Arduino du "moniteur" Z80 émulant la mémoire et fournissant le signal d'horloge.
* `Z80ctl_mem_sansISR` : Idem, mais sans utiliser d'interruption.
* `Z80ctl_mem_74165` : Idem mais en utilisant deux 74HCT165 pour lire les 16 bits d'adresse du bus (avec interruption/ISR).
* `Z80assembleur` : les source en assembleur pour le code de démonstration (crasm, GNU as, pasmo et z80asm).
* `googleANAhttp` : croquis Arduino/esp8266 pour le détecteur infrarouge Google Analytics.
* `ESPBasicOTA` : croquis Arduino/esp8266 pour la mise à jour OTA (via Wifi/réseau).
* `minitel_1` : croquis Arduino affichant du texte sur un Minitel.
* `minitelImages` : croquis Arduino affichant une image sur un Minitel.
* `alphamosaique` : script Python de conversion d'un fichier graphique (PNG, JPG, etc) en tableau de `char` pour le croquis Arduino.

