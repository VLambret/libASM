.PHONY : all clean deps.mk

all : previews

include deps.mk

clean:
	rm -rf *.hd.png *.svg *.preview.png */*.hd.png

deps : deps.mk

deps.mk :
	./make_deps.sh > $@

%.preview.png :
	convert +append $^ $@

%.hd.png : %.svg
	convert $< -resize 200x200\! $@ 

%.svg : %.png
	pngtopnm $< | potrace --svg > $@
