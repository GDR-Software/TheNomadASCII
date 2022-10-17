#!bin/bash

if [ $1 == "update" ]; then
	if [ $2 == "check" ]; then
		changed = 0
		git remote update && git status -uno | grep -q 'Your branch is behind' && changed = 1
		if [ $changed == 1 ]; then
			echo "current local repository is behind master branch, update is recommended"
		else
			echo "current local repository is up-to-date with master branch"
		fi
	elif [ $2 == "run" ]; then
		changed = 0
		git remote update && git status -uno | grep -q 'Your branch is behind' && changed = 1
		if [ $changed == 1 ]; then
			echo "current local repository is behind master branch, updating game..."
			git pull origin master
			echo "update completed, you can now launch nomadascii"
		else
			echo "game is already up to date"
		fi
	fi
elif [ $1 == "run" ]; then
	if [ $2 == "debug" ]; then
		make debug
	#elif [ $2 == "release" ]; then
	#	make release
	elif [ $2 == "testbuild" ]; then
		make testbuild
	#elif [ $2 == "experimental" ]; then
	#	make experimental
	fi
elif [ $1 == "open_console" ]; then # this arg opens the cmd console directly upon launch
	if test -f "bin/launcher"; then
		chmod +x bin/launcher
		./bin/launcher console
	else
		cd bin
		g++ -g -Wall runner.cpp -o launcher
		chmod +x launcher
		./launcher console
	fi
else
	echo "ERROR: INVALID LAUNCH PARAMETERS"
	exit
fi


if test -f "bin/launcher"; then
	chmod +x bin/launcher
	./bin/launcher helper
else
	cd bin
	g++ -g -Wall runner.cpp -o launcher
	chmod +x launcher
	./launcher helper
fi
