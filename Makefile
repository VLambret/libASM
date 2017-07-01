SHELL=/bin/bash

.SECONDARY :
.PHONY : all clean deps.mk

SIZE=200

all : progress.png

include deps.mk

clean:
	rm -rf *.hd.png *.svg *.preview.png */*.hd.png *.title.png *.sum.png

deps : deps.mk

deps.mk :
	./make_deps.sh > $@

%.title.png : %
	convert -background white -fill black -size $$(( $(SIZE) * 6 ))x$(SIZE) -pointsize 28 -gravity center label:"$$(echo $< | sed -e 's/^dice.*_//')" $@

%.preview.png : %.title.png %.sum.png
	convert -append $^ $@

%.sum.png :
	convert +append $^ $@
	convert $@ -fill white -opaque none $@

%.hd.png : %.svg
	convert $<  -resize $(SIZE)x$(SIZE) $@ 
	convert $@ -fuzz 50% -trim -resize $(SIZE)x$(SIZE) $@
	convert $@ -background white -gravity center -extent $(SIZE)x$(SIZE) $@

%.svg : %.png
	pngtopnm $< | potrace --svg > $@
