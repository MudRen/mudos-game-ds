// Room: /u/a/aiwa/workroom.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIG+"世外桃園"+NOR);
	set("long", @LONG
你來到了一個看似天堂的地方。有小橋、有流水，有一片草地，
更有一座小湖，在湖中有一間小屋。是不是仙人住在裡面呢？你
可以進去(enter)看看！
LONG
	);
	set("objects", ([
            ]));

	set("light", 1);

	set("exits", ([ /* sizeof() == 7 */
		"enter"	: __DIR__"home",
		"wiz"	: "/d/wiz/hall1",
		"shengsan" : "/u/s/shengsan/workroom",
		"luky"	: "/u/l/luky/workroom",
            ]));

	set("valid_startroom",1);
	set("no_clean_up", 0);
       	setup();
        call_other("/obj/board/aiwa_b", "???");
}

void init()
{
	add_action("do_enter","enter");
}

void do_enter()
{
	object me;
	me = this_player();
	tell_object(me,"\n\n[1;37m你走過湖邊的小橋，到達小屋的門口，正打算敲門\n");
	tell_object(me,"的時候，忽然響起了一陣銀鈴般清徹的聲音∼[m\n\n");
	tell_object(me,"[1;35m歡迎光臨艾華工作室[m\n\n\n");
}
