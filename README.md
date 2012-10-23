#Standalone Designs

##Hardware
This project includes hardware schematics and board layouts for the standalone batterbox (izuba.box) for e.quinox (www.e.quinox.org).

Cadsoft EAGLE is the tool of choice when designing PCBs

###Contents

The following designs are included in this repository

* [Stand_Alone] : The main PCB board controlling payment and outputs
* [Stand_Alone_Inv_Adapter] : The adapter board used in the commercial unit, allows high power loads such as the inverter to be switched. Also provided 2 extra USB outputs and fan contol. Connects the the main boards inverter adapter connector.


##Software

This project includes PIC microcontroller software for the standalone batterbox (izuba.box) for e.quinox (www.e.quinox.org).

The project is MPLAB v1.20. The compiler is the Hi-Tech PIC18 v9.80 Lite C compiler

###Contents

The following designs are included in this repository

* [Stand_Alone] : The main firmware for the standalone units

###Notes
The unlock_code.c file has been deliberatly exluded as it would allow misuse of the payment system. If this is a problem please contact e.quinox.org