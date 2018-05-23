#!/bin/bash
# ファイル名(chxx)を引数にとると自動コンパイル

if [ $# != 1 ]; then
	echo "set Joho_master dir name"
	exit
fi

chxxname=$1

ls ~/Joho_master/$chxxname/src | grep ".cpp" | while read filename
do
	trap break SIGINT
	echo $filename
	# g++ -o $chxxname/exe/${filename%.cpp}.out $chxxname/src/$filename	
	iconv -f SJIS -t UTF8 ~/Joho_master/$chxxname/src/$filename > $filename.utf8
	# sed -e 's/¥n/\\n/g' utf8s/$filename.utf8
	sed -e 's/¥n/\\n/g' $filename.utf8 > $filename
	mv $filename ../utf/src
	rm -f $filename.utf8

done


