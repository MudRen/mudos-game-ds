// edit.c

varargs int edit(function callback, string text)
{
	//is_input=1;
	write("  開始編輯              結束離開用 '.'﹐取消輸入用 '~q'。\n");
	write("─────────────────────────────\n");
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
		write("輸入取消。\n");
		
		return;
	}
//	 else if( line=="~e" )
//	{
		
//	}
	 else text += line + "\n";
	input_to("input_line", text, callback);
}
