#!/bin/bash
# ディレクトリ名(chxx)を引数にとると自動コンパイル
# 同じディレクトリ下で実行する

if [ $# != 1 ]; then
	echo "set task number"
	exit
fi

num=$1

ls ./ | grep "${num}"  | while read dir_name
do
	trap break SIGINT #ctrl+c,Del で Interrupt processing

	echo -e $"\t\t\e[30m\e[47m $dir_name の採点 \e[0m"
	
	point=0
	kadai_all=0
	
	ls $dir_name | while read filename
do

	echo $filename

	g++ -o ../exe/${filename%.cpp}.out $dir_name/$filename


	FILE=../exe/${filename%.cpp}.out

	if [ -e $FILE ];then
		echo "=============== $filename is executed ===============" 
		./../exe/${filename%.cpp}.out < /dev/stdout
		point=$(( point + 1 ))

	else 
		echo -e $'\t\t\e[31mcomple error\e[0m'
	fi

	echo "=============== Show Source File ([y] or other) ===============" 
	read key_board < /dev/stdout
	case "$key_board" in
		[y]) echo "Yes"
			less $dir_name/$filename
	esac
	echo -e "\n"
	echo "=============== $filename finish ===============" 
	echo -e "\n"
	kadai_all=$(( kadai_all + 1 ))

	echo "point=$point/$kadai_all"

done



done

