inherit ROOM;
void create()
{
	set("short", "石壁");
        set("long", @LONG

你所見的是一塊巨大的石壁, 石壁上刻有著許多人形, 似乎是在描述著
一件大事, 似乎在石壁旁有個長滿藤枝的小洞(hole)。

LONG
);
	set("exits",([
  "west" : __DIR__"map_1_1",
  "east" : __DIR__"map_1_3",
  "south" : __DIR__"map_2_2",
]));
	set("item_desc", ([
  "hole" : "大概容納的下一個人大小的洞, 你可以嘗試著(enter)進去。\n"
]));
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
	add_action("do_enter", "enter");
}

int do_enter(string arg)
{
	object me = this_player();

	if( !arg || arg != "hole" )
		return notify_fail("你想要進去那裡呀？\n");
	if( me->query_temp("invis") < 2 )
		message_vision("$N縮著身子, 往小洞裡面鑽進去了！\n", me);
	me->move("wh_1.c");
	if( me->query_temp("invis") < 2 )
		message_vision("只見$N從洞外鑽了進來∼\n", me);
	return 1;
}