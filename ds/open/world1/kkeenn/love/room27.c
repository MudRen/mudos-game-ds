#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"情城池正堂"NOR);
        set("long", @LONG
此處是情城池的正廳，到處擺滿了奇花異草，你一踏進來就聞到一種
莫名的香味，從兩側窗戶望出去是渺渺茫茫的霧氣，中堂底則擺著一張黑
檀太師椅，似乎是一位大人物所坐的位置。
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

	if( me->query("gender") == "男性") 
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
