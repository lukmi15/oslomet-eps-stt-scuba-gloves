upload: stt.ino Makefile
	#sudo arduino --board arduino:samd:mkr1000 --upload $<
	arduino-cli compile --fqbn arduino:samd:mkr1000 src.ino
	sudo arduino-cli upload --port /dev/ttyACM0 --fqbn arduino:samd:mkr1000 stt.ino
