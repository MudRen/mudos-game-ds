#include <room.h>
#include <ansi.h>
inherit ROOM;

void do_change(string str);

void create()
{
	set("short",HIC"����R����"NOR);
	set("long",@LONG
�o�̬O�]�k���@�ɤ������Ŧ�v��
���O���q�H���_����
�R���ΰ��:
�@����		50�U coin
buyhome  <�ʶR�R����>
myhome   <�^��R����>
setlong  <�ק�along>�>
setshort <�ק�ashort>�>
LONG
);
	set("exits",([
	"down":"/open/clc/start/enter",
	]));
	set("objects",([
	]));
	set("light",1);
	setup();
}

void init()
{
	add_action("do_home","myhome");
	add_action("do_buy","buyhome");
	add_action("do_setlong","setlong");
	add_action("do_setshort","setshort");
}

int do_buy()
{
	object env,me;
	string file,str;
	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(me->query("coin")<500000)
                return notify_fail("�A���W�S������h���C\n");
	if(file_size(file)!=-1)
                return notify_fail("�A�w�g���@���Τl�F�C\n");
	str = @ROOM_CODE
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit "/std/saveeq";

void create()
{
ROOM_CODE
	;

	str +=sprintf("set(\"short\",HIG\""+me->query("name")+"���R����\"NOR);");
	str +=@ROOM_CODE2
        set("long",@LONG
�o���ж����x�s���W���D��άO�˳�
�ثe��save 10��D��......�w��j�a��bug
��k:
putin  �W��
getout �s��
list
LONG);
        set("exits",([
	"back":"/open/eeman/room",
        ]));
	set("light",1);
	setup();
}

ROOM_CODE2
	;
	write("�سy "HIR + me->query("name") + NOR" ���R����....");
	if( write_file(file, str) )
	{
		write("���\\\n");
		me->add("coin",-500000);
	}	
	me->set("item/item1","");
	me->set("item/item2","");
	me->set("item/item3","");
	me->set("item/item4","");
	me->set("item/item5","");
	me->set("item/item6","");
	me->set("item/item7","");
	me->set("item/item8","");
	me->set("item/item9","");
	me->set("item/item10","");

return 1;
}

int do_home()
{
	object env,me;
	string file,str;
	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(file_size(file)==-1)
                return notify_fail("�A�S���R�Фl���^�a�ڡC\n");
	me->move(file);
	write("\n�g�L�@�Ѫ��b�i, �ש�^��ŷx���p�ۤF\n");
	
return 1;
}


int do_setlong()
{
	object env,me;
	string file,str;

	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(file_size(file)==-1)
                return notify_fail("�A�S���Фl�C\n");

        me->edit( (: call_other, __FILE__, "do_change" :) );

	return 1;
}

void do_change(string str)
{
	object me,room,env;
	string file,nf;
	me=this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	nf = @ROOM_CODE

#include <room.h>
#include <ansi.h>
inherit "/std/saveeq";
inherit ROOM;

void create()
{
ROOM_CODE
	;
	nf += sprintf("\tset(\"short\", %O);\n", new(file)->query("short") );
	nf += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", str );
	nf += @ROOM_CODE2
        set("exits",([
	"back":"/open/eeman/room",
        ]));
	set("light",1);
	setup();
}
ROOM_CODE2
	;
	rm(file);
	write("�ק� �R����....");
	if( write_file(file, nf) ) {
		write("Ok......\n");
		if(!find_object(file))
			return ;
		destruct(find_object(file));
		return ;
	} else
		return notify_fail("�A�S���ק�Фl���v�Q, �q��eeman�B�z�C\n");

	return ;
}

int do_setshort(string str)
{
	object room,env,me;
	string file,nf;

	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(file_size(file)==-1)
                return notify_fail("�A�S���Фl�C\n");

	if(!str || str=="")
                return notify_fail("setshort <�ԭz>�C\n");

	nf = @ROOM_CODE

#include <room.h>
#include <ansi.h>
inherit "/std/saveeq";
inherit ROOM;

void create()
{
ROOM_CODE
	;
	nf += sprintf("\tset(\"short\", %O);\n", str );
	nf += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", new(file)->query("long") );
	nf += @ROOM_CODE2
        set("exits",([
	"back":"/open/eeman/room",
        ]));
	set("light",1);
	setup();
}
ROOM_CODE2
	;
	rm(file);
	write("�ק� �R����....");
	if( write_file(file, nf) ) {
		write("Ok......\n");
		if(!find_object(file))
			return 1;
		destruct(find_object(file));
		return 1;
	} else
		return notify_fail("�A�S���ק�Фl���v�Q, �q��eeman�B�z�C\n");

	return 1;
}
