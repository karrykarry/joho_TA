#!/bin/bash
# 何回目と何番目の課題かを引数にとると自動コンパイル($ ./auto_compile.sh 01 3)
# 同じディレクトリ下で実行する
# 同じディレクトリ下に"exe"と"UTF8"のフォルダを準備
# Shift-jisとUTF8に対応しているはず


if [ $# != 2 ]; then
	echo "set task number"
	exit
fi

num=$1
num_2=$2

ls ./ | grep "${num}"  | while read dir_name
do
	trap break SIGQUIT #ctrl+\ で 強制終了

	echo -e $"\t\t\e[30m\e[47m $dir_name の採点 \e[0m"
	
	encode_file="encode_judge.txt"
	
	ls $dir_name | grep "${num_2}"'.cpp' | while read filename
do
	trap continue SIGINT #ctrl+c,Del で Interrupt processing

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
			rm -f FILE

		else 
			echo -e $'\t\t\e[31mcomple error\e[0m'
		fi
		
	echo "=============== Show Source File ([y] or other) ===============" 
	read key_board < /dev/stdout
	case "$key_board" in
		[y]) 
			less $dir_name/$filename
			# ファイルを開いたら"q"で閉じる
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
			rm -f FILE

		else 
			echo -e $'\t\t\e[31mcomple error\e[0m'
		fi

	echo "=============== Show Source File ([y] or other) ===============" 
	read key_board < /dev/stdout
	case "$key_board" in
		[y]) 
			less UTF8/$filename
	esac
	rm -f UTF8/$filename		
	
	fi

done

	echo -e "\n"
	echo "=============== $filename finish ===============" 
	echo -e "\n"


	rm -f $encode_file
	
done



done

