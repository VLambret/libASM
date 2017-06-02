.PHONY : all clean

REPS = $(wildcard */)
PREVIEWS = $(REPS:/=.preview.png)

all: writing.hd.png $(PREVIEWS)
	echo $*

clean:
	rm -rf *.hd.png *.svg *.preview.png */*.hd.png

%.preview.png : %/*.hd.png 
	convert +append $^ $@


%.hd.png : %.svg
	convert $< -resize 200x200\! $@ 

%.svg : %.png
	pngtopnm $< | potrace --svg > $@
