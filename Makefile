upload: stt.ino Makefile
	sudo arduino --board arduino:samd:mkr1000 --upload $<
