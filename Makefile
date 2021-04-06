#Name of the application
APPLICATION = RIOT-BLOCKCHAIN

#Which default board to use. The "?" allows to override this value
BOARD ?= native

#This is important! It tells the application where the RIOT-OS is
RIOTBASE ?= $(CURDIR)/RIOT


#Appends target specific values to variables
include $(RIOTBASE)/Makefile.include
