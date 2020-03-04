// ls.c
//
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	int mark_loaded;
	int i, j, w, col,k;
	string dir,out,code,name,patt,replac;
	mixed *file;
	seteuid(geteuid(me));
	patt=@PPPPP
        setup();
}

string query_long(int raw)
{
	string out;
	out=ROOM_D->showmap(this_object());
	out+=query("long");
	return out;
}
PPPPP;
	replac=@RRRRR
        setup();
	set("map_long",1);     //show map as long
        replace_program(ROOM); //�[��L�禡xxx()�ɽЮ�������
}
RRRRR;
	dir = resolve_path(me->query("cwd"), arg);
	if( file_size(dir)==-2 && dir[strlen(dir)-1] != '/' ) dir += "/";
	file = get_dir(dir, -1);
	if( !sizeof(file) )
	{if (file_size(dir) == -2) return notify_fail("�ؿ��O�Ū��C\n");
		else
		return notify_fail("�S���o�ӥؿ��C\n");
	}
	i = sizeof(file);
	w = 0;
	while(i--) {
		if (file[i][1]==-2) file[i][0] += "/";
		if (strlen(file[i][0])>w) w = strlen(file[i][0]) + 1;
	}
	out="�ؿ��R" + dir + "\n";
	col = 70 / (w+6);
	k=0;
	if (sizeof(file))
		for(i=0, j = sizeof(file); i<j; i++) {
			if (strsrch(file[i][0], "/") >= 0) continue; // dir
			if(file[i][0][strlen(file[i][0])-2..strlen(file[i][0])-1]!=".c") continue;
			write(file[i][0]+" ...");
 			if(!code=read_file(dir+file[i][0]))
 			{
 				write("error. can't read_file \n");
 				continue;
 			}
 			if(strsrch(code,patt)==-1) continue;
 			if(strsrch(code,"MOBROOM")!=-1) continue;
 			if(strsrch(code,"add_action")!=-1) continue;
 			if(strsrch(code,"valid_leave")!=-1) continue;
			code=replace_string(code,patt,replac);
			rm(dir+file[i][0]);
			write_file(dir+file[i][0],code);
			write("ok\n");
                }
	else out+="    �S�������ɮסC\n";
	out+="\n";
	write(out);
	write_file(dir+"file_list.txt", out);
	return 1;
}
 