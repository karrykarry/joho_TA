# Compiler

## Usage 
+ 初めに
	このディレクトリにzipで解凍してきたものを置く(zip自体は置かない)

	joho_ta      
	└── compiler       
		│   
		├── auto_compile.sh        
		├── exe     
		│   ├── (実行ファイルを一時保存しておく場所)    
		│     
		├── UTF8       
		│   ├── (UTF8のコードを一時保存しておく場所)       
		│     
		├── 15_理工_1年0x組001番_氏名_01_1    
		│   ├── 153Rxxxxxxx-01-1.cpp    
		│    
		├── 15_理工_1年0x組002番_氏名_01_1    
		│   ├── 153Rxxxxxxx-01-1.cpp     

+ exeとUTF8のフォルダ作成   
```
	~$./preprocessing.sh
```

+ 15＿理工＿1年0x組0xx番＿氏名＿何回目＿1 の何回目を引数にとる   
	-> このディレクトリ下の 01 のフォルダーをコンパイル始める    
	例）15_理工_1年0x組0xx番_氏名_01_1     
```
	~$./auto_compile.sh 01 
```

+ 15＿理工＿1年0x組0xx番＿氏名＿何回目＿1 の何回目と、何番目のcppをコンパイルするかを引数に取る   
	-> このディレクトリ下の 01 のフォルダー内の引数で取ったcppをコンパイル始める    
	例）15_理工_1年0x組0xx番_氏名_01 の 1.cppをコンパイルしたい    
```
	~$./auto_compile_v2.sh 01 1 
```
