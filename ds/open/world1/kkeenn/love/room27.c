#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"����������"NOR);
        set("long", @LONG
���B�O�����������U�A��B�\���F�_�Ყ��A�A�@��i�ӴN�D��@��
���W�������A�q�ⰼ�����X�h�O�����������A���󩳫h�\�ۤ@�i��
�ȤӮv�ȡA���G�O�@��j�H���ҧ�����m�C
LONG
        );
        set("exits", ([ 
  "south"  : __DIR__"room25",
  "west"  : __DIR__"room29",
  "east"  : __DIR__"room28",
  "up"    : __DIR__"room30",
]));
set("valid_startroom", 1);
set("no_recall", 1);
        set("objects", ([
 __DIR__"npc/obj/obj.c" : 1,
 __DIR__"npc/master_1" : 1,
]));
        set("light",1);
        setup();
}
void init()
{
	object me = this_player();
	if( !me ) return;

	if( me->query("gender") == "�k��") 
	{
		add_action("no_save","save");
	}
}
int no_save(string arg)
{
	object me = this_player();

	set("valid_startroom", 0);
	"/cmds/usr/save.c"->main(me, arg);
	set("valid_startroom", 1);
	return 1;
}

int valid_leave(object me,string arg)
{
        foreach(object ob in all_inventory(this_object()))
        {
                if( ob->do_guard(arg) ) return 0;
        }
        :: valid_leave(me, arg);

        return 1;
}
