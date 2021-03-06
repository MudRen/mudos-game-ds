// hest.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
          string dest,cmd;
	object ob;

	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("指令格式﹕hest <手下> to <指令>\n");
	 
	if( !(ob = present(dest, environment(me))) )
		return notify_fail("這裡沒有 " + dest + "。\n");
	
	if( userp(ob) || ob->query("creater") != me) return notify_fail(ob->query("name")+"並不接受你的命令。\n");
	
	if(ob->is_busy() ) return notify_fail(ob->query("name")+"正忙著，沒有空聽你的驅使。\n");

	return ob->force_me(cmd);
}
