.PHONY : all clean

all: writing.hd.png dice.png

clean:
	rm -rf *.hd.png *.svg .preview.png

dice.preview.png : dice/face1.hd.png \
                   dice/face2.hd.png \
                   dice/face3.hd.png \
                   dice/face4.hd.png \
                   dice/face5.hd.png \
                   dice/face6.hd.png
	convert +append $^ $@


%.hd.png : %.svg
	convert $< -resize 200x200\! $@ 

%.svg : %.png
	pngtopnm $< | potrace --svg > $@
