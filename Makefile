#Name of the application
APPLICATION = CRYPTBENCH

#Which default board to use. The "?" allows to override this value
BOARD ?= native

USEMODULE += shell_commands # RIOT SHELL COMMANDS
USEMODULE += shell 			# RIOT SHELL MODULE
USEMODULE += crypto_aes		# AES Library
USEMODULE += od				# Object Dump
USEMODULE += od_string		# OD as String

#This is important! It tells the application where the RIOT-OS is
RIOTBASE ?= $(CURDIR)/RIOT

#Appends target specific values to variables
include $(RIOTBASE)/Makefile.include