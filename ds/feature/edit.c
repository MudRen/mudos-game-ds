// edit.c

varargs int edit(function callback, string text)
{
	//is_input=1;
	write("  �}�l�s��              �������}�� '.'�M������J�� '~q'�C\n");
	write("�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n");
	if (!text) input_to("input_line", "", callback);
	else
	{
          write (text);
          input_to("input_line", text, callback);
        }
	return 1;
}

void input_line(string line, string text, function callback)
{
	if( line=="." )
	{
		if(this_player()->query_temp("gb_player")) text=LANGUAGE_D->GB2Big5(text);
		(*callback)(text);
		
		return;
	}
	 else if( line=="~q" )
	{
		write("��J�����C\n");
		
		return;
	}
//	 else if( line=="~e" )
//	{
		
//	}
	 else text += line + "\n";
	input_to("input_line", text, callback);
}
