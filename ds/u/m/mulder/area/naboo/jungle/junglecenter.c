// Room: /u/m/mulder/area/naboo/jungle/junglecenter.c
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIM"�˪L����");
	set("long", 
HIG"�o�̪����ҩM��~���˪L�Q�����P�A�o�̭��Ҧp�e�M���B���������H\n"NOR
HIG"�@�زM�s���Pı�C�ӳo�঳�@�ʯ������j��(tree)�ݨӦ��@�ǥj�ǡC�|�P\n"NOR
HIG"���ͪ��ݨ�o�ʤj�𳣤�������o�̡C�q�a�W�����ءA�i�H�ݥX��観�H\n"NOR
HIG"���}�o�̡C\n"NOR

	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"jungle13",
  "west" : __DIR__"jungle15",
  "south" : __DIR__"jungle20",
  "east" : __DIR__"jungle1",
]));
	set("item_desc",([
	"tree":"�o�ʤj��ݨӥi�H��(climb)��\n",
	]));
	set("world", "undefine");
	set("outdoors","forest");
	set("no_map",1);
	set("no_clean_up", 0);
	


	setup();
}
void init()
{
	add_action("do_climb","climb");
}	
	int do_climb(string arg)
{
	object me;
	me=this_player();
	if (arg != "�j��" && arg !="tree" )
	return 0;

	else
	{
	message_vision(HIG"$N�����W�W�Ѧa�����W�𳻡C\n"NOR,me);
	me->add("ap",-10);
	me->move(__DIR__"tree");
	tell_room(environment(me),me->query("name")+"�}�l�Ѧa�����W�𳻡C\n",me);
	return 1;
	}
}

int valid_leave(object me, string dir)
{
        if( dir=="east" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
