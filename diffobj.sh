#! /bin/bash


# Dump of objects files

TMP=./

od -w4 -x -v $1  | cut -f2- -d' ' |
	grep '.... ....' |
	sed -e 's/\(....\) \(....\)/\2\1/' |
	cat > ${TMP}/$1.code.txt

od -w4 -x -v $2  | cut -f2- -d' ' |
	grep '.... ....' |
	sed -e 's/\(....\) \(....\)/\2\1/' |
	cat > ${TMP}/$2.code.txt

mipsel-linux-gnu-objdump --show-raw-insn -s -D $1 > ${TMP}/$1.objdump.txt
mipsel-linux-gnu-objdump --show-raw-insn -s -D $2 > ${TMP}/$2.objdump.txt

cat ${TMP}/$1.objdump.txt ${TMP}/$2.objdump.txt |
	grep ":	" |
	grep -v "is out of bounds." |
	cut -f2 -d: |
	#ed -e 's/	//g' |
	sed -e 's/ / /' |
	sort -u |
	cat > ${TMP}/$1.translate.txt

#join $1.code.txt  $1.dump.txt >  $1.translate.txt
#join $2.code.txt  $2.dump.txt >> $1.translate.txt

diff ${TMP}/$1.code.txt ${TMP}/$2.code.txt |
while read l;
do
	l=${l/---/====}
	trad=`grep "${l:2}" ${TMP}/$1.translate.txt | head -n 1 | cut -d' ' -f2`
	trad="${trad}"
	l="${l}                                                                "
	echo "${l:0:12}: $trad"
done
