#Name of the application
APPLICATION = CRYPTBENCH

#Which default board to use. The "?" allows to override this value
BOARD ?= native

#This is important! It tells the application where the RIOT-OS is
RIOTBASE ?= $(CURDIR)/RIOT

BIN_DIRS += generator
BIN_USEMODULE += generator
BIN_USEMODULE += $(APPLICATION_MODULE)

DIST_FILES += Makefile

AES_KEY_SIZE ?= 128

USEMODULE += shell_commands # RIOT SHELL COMMANDS
USEMODULE += shell 			# RIOT SHELL MODULE
USEMODULE += od				# Object Dump
USEMODULE += od_string		# OD as String
USEMODULE += random
USEMODULE += xtimer

ifneq ($(AES_KEY_SIZE),128)
  USEMODULE += crypto_aes_128	# AES Library
endif
ifneq ($(AES_KEY_SIZE),192)
  USEMODULE += crypto_aes_192	# AES Library
endif
ifneq ($(AES_KEY_SIZE),256)
  USEMODULE += crypto_aes_192	# AES Library
endif


CFLAGS += -DDEVELHELP=1

#Appends target specific values to variables
include $(RIOTBASE)/Makefile.include