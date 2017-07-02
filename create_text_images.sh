#!/bin/bash

cat text_images.src | grep -v -E "^#" |
while read LINE
do
	FONT=${LINE%%:*}
	TEXT1=${LINE%:*}
	TEXT=${TEXT1#*:}
	OUTPUT=${LINE##*:}

	convert -background white -fill black  -font $FONT\
		-pointsize 400  -gravity center \
		label:"$TEXT" $OUTPUT
done
