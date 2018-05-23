#!/bin/bash
# ファイル名(chxx)を第一，ソースの番号を第二に引数にとると自動コンパイル(かつ実行)

if [ $# != 2 ]; then
	echo "set cpp file"
	exit
fi

chxxname=$1
num=$2

ls ../$chxxname/src | grep "${num}.cpp"  | while read filename
do
	trap break SIGINT
	echo $filename
	g++ -o ../$chxxname/exe/${filename%.cpp}.out ../$chxxname/src/$filename
	
	
	echo "$chxxname/exe  にコンパイル完了"
done



