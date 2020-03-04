// Room: /d/gumu/chucangshi.c
// Last Modifyed by Winder on Jan. 14 2002

#include <room.h>
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIC"儲藏室"NOR);
	set("long", @LONG
    古墓生活甚是清苦，儲藏室堆著些日常用品，都整整齊齊堆放在牆
腳(search 牆腳)，看來經常有古墓弟子前來打掃，其餘別無他物。
LONG	);

	set("exits", ([
		"east" : __DIR__"mudao22",
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	::init();
	add_action("do_search","search");
}

int do_search(string arg)
{
	object ob, me = this_player();


	if ( arg == "牆腳")
	{
		if ( me->query_temp("fire") < 3 )
		{
			if(objectp(ob = present("fire", me)))
                  { write("你已經拿過火折了。\n"); return 1; }


			me->add_temp("fire", 1);
            message_vision(YEL "$N在牆腳的物品堆里翻來翻去什麼也沒找著。\n"NOR, me);
			return 1;
		}
		message_vision("$N在牆腳的物品堆里，翻來翻去找出一把火折。\n",me);
		me->delete_temp("fire");
     new(__DIR__"obj/fire")->move(me);
		return 1;
	}
	return notify_fail("你要找什麼？\n");
}
