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
	encode_file="encode_judge.txt"
	
	ls $dir_name | while read filename
do

	echo $filename
	file -i $dir_name/$filename > $encode_file


	cat $encode_file | while read line
do
	if [[ $line == *utf* ]]; then 
		echo 'UTF8';	
		
		g++ -o exe/${filename%.cpp}.out $dir_name/$filename

		FILE=exe/${filename%.cpp}.out

		if [ -e $FILE ];then
			echo "=============== $filename is executed ===============" 
			./exe/${filename%.cpp}.out < /dev/stdout
			point=$(( point + 1 ))
			rm -f FILE

		else 
			echo -e $'\t\t\e[31mcomple error\e[0m'
		fi
		
	echo "=============== Show Source File ([y] or other) ===============" 
	read key_board < /dev/stdout
	case "$key_board" in
		[y]) echo "Yes"
			# less $dir_name/$filename
			less $dir_name/$filename
	esac

	else
		echo 'Shift-jis';

		iconv -c -f sjis -t utf8 $dir_name/$filename > $filename.utf8

		sed -e 's/¥n/\\n/g' $filename.utf8 > $filename
		mv $filename  UTF8
		rm -f $filename.utf8


		g++ -o exe/${filename%.cpp}.out UTF8/$filename


		FILE=exe/${filename%.cpp}.out

		if [ -e $FILE ];then
			echo "=============== $filename is executed ===============" 
			./exe/${filename%.cpp}.out < /dev/stdout
			point=$(( point + 1 ))
			rm -f FILE

		else 
			echo -e $'\t\t\e[31mcomple error\e[0m'
		fi

	echo "=============== Show Source File ([y] or other) ===============" 
	read key_board < /dev/stdout
	case "$key_board" in
		[y]) echo "Yes"
			# less $dir_name/$filename
			less UTF8/$filename
	esac
	rm -f UTF8/$filename		
	
	fi

done

	echo -e "\n"
	echo "=============== $filename finish ===============" 
	echo -e "\n"
	kadai_all=$(( kadai_all + 1 ))

	echo "point=$point/$kadai_all"

	rm -f $encode_file
	
done



done

