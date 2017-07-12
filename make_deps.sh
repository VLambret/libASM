#!/bin/bash

PREVIEWS=
PREV_DEPS=

for DICE in jour*
do
	if [ -d $DICE ]
	then
		DICE_TARGET=$DICE.preview.png
		PREVIEWS+=" $DICE_TARGET"
		DEPS="$DICE.sum.png :"
		for IMG in $(ls $DICE/*.png | grep -Ev '.hd.png$')
		do
			IMG_DEP="${IMG/%.png/.hd.png}"
			DEPS+=" $IMG_DEP"	
		done
		echo "$DEPS"
		echo
	fi
done

echo progress.png : $PREVIEWS
echo '	convert -append $^ $@'
echo
