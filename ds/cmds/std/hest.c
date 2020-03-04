// hest.c

#include <ansi.h>

inherit F_CLEAN_UP;

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
          string dest,cmd;
	object ob;

	if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
		return notify_fail("���O�榡�Rhest <��U> to <���O>\n");
	 
	if( !(ob = present(dest, environment(me))) )
		return notify_fail("�o�̨S�� " + dest + "�C\n");
	
	if( userp(ob) || ob->query("creater") != me) return notify_fail(ob->query("name")+"�ä������A���R�O�C\n");
	
	if(ob->is_busy() ) return notify_fail(ob->query("name")+"�����ۡA�S����ť�A���X�ϡC\n");

	return ob->force_me(cmd);
}
