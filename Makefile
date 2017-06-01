.PHONY : all clean

all: writing.hd.png

clean:
	rm -rf *.hd.png *.svg

%.hd.png : %.svg
	convert $< $@ 

%.svg : %.png
	pngtopnm $< | potrace --svg > $@
