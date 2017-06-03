#!/bin/bash

PREVIEWS=
PREV_DEPS=

for DICE in dice*
do
	if [ -d $DICE ]
	then
		DICE_TARGET=$DICE.preview.png
		PREVIEWS+=" $DICE_TARGET"
		DEPS="$DICE_TARGET :"
		for IMG in $(ls dice/*.png | grep -Ev '.hd.png$')
		do
			IMG_DEP="${IMG/%.png/.hd.png}"
			DEPS+=" $IMG_DEP"	
		done
		echo "$DEPS"
		echo
	fi
done

echo previews : $PREVIEWS
echo
