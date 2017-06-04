.PHONY : all clean deps.mk

SIZE=80

all : progress.png

include deps.mk

clean:
	rm -rf *.hd.png *.svg *.preview.png */*.hd.png

deps : deps.mk

deps.mk :
	./make_deps.sh > $@

%.preview.png :
	convert +append $^ $@
	convert $@ -fill white -opaque none $@

%.hd.png : %.svg
	convert -flatten $< -resize $(SIZE)x$(SIZE)\! $@ 

%.svg : %.png
	pngtopnm $< | potrace --svg > $@
