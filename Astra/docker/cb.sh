#! /bin/bash
PRESENTDIR=$(pwd)
if [ ! -d /shared/Astra ] ; then
	git clone -b "$GITBRANCH" --depth 1 "$GITURI" /shared
	if [ -d /shared/Astra ] ; then
  		cd /shared/Astra/
  		./autogen.sh
  		./configure --disable-zerocoin --without-gui --enable-debug
  		make
  		sudo make install
  		mkdir /home/ubuntu/.Astra
  		cp /home/ubuntu/Astra.conf /home/ubuntu/.Astra/Astra.conf
  		cd $PRESENTDIR
	else
  		echo "There was a problem with the clone"
	fi
else
	echo "/shared is not empty, should you be running pbr.sh?"	
fi
