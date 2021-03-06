#include <ansi.h>
inherit MOBROOM;
void create()
{
	set("short", "步靈城南大街北");
	set("long",
"你站在步靈城的南大街，在這裡有許\多坐臥在地上的乞丐，他們正\n"
"在向人乞討東西吃，在北邊是步靈城的中央部份，在那有許\多東西可以\n"
"購買，而在這裡的附近有一家新開的武器店，聽說裡面賣的東西滿貴的\n"
"但是卻擁有相當的名聲，連步靈城衛兵隊隊長都會到那購買物品，在這\n"
"的南方是步靈城的南大街，那裡有更大的廣場，也有很多的人，在這裡\n"
"的側邊有一條小路，似乎罕有人煙。\n"
	);
	set("exits", ([
  "north" : __DIR__"boo-lin2.c",
  "south" : __DIR__"bsouth.c",
  "east" : __DIR__"weapon.c",
]));
	set("item_desc",([
  "小路" : "一條罕有人經過的小路，在那似乎有一些雜物堆。\n",
  "road" : "一條罕有人經過的小路，在那似乎有一些雜物堆。\n",
]));
	set("no_clean_up", 0);
	set("outdoors","land");
	set("chance",40);
        set("mob_amount",3);
        set("mob_object",({
  __DIR__"npc/cat",
  __DIR__"npc/dog",
  __DIR__"npc/sparrow",
}) );
	setup();
}

void init()
{
	add_action("do_enter","enter");
}

int do_enter(string arg)
{
	object me,sidestreet;
	me = this_player();
	sidestreet = load_object(__DIR__"sidestreet4.c");
	if( !arg )return notify_fail("你要進入那呀？\n");
	if( arg!="road" && arg!="小路" )
		return notify_fail("你要進入那呀？\n");
	else
	{
		tell_room(environment(me),me->name()+"往小路裡走去。\n",({ me }));
		me->move(sidestreet);
		tell_room(environment(me),me->name()+"走了進來。\n",({ me }));
		return 1;
	}
}