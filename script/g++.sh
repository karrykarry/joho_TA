#!/bin/bash
# ディレクトリ名(chxx)を引数にとると自動コンパイル

if [ $# != 1 ]; then
	echo "set cpp file"
	exit
fi

chxxname=$1

ls ../$chxxname/src | grep ".cpp"  | while read filename
do
	trap break SIGINT
	echo $filename
	g++ -o ../$chxxname/exe/${filename%.cpp}.out ../$chxxname/src/$filename
	
done

echo "$chxxname/exe  にコンパイル完了"
