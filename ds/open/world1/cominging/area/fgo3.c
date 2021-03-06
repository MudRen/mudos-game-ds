inherit ROOM;

void create()
{
	set("short", "森林中");
	set("long", @LONG
你現在在森林之中，在這裡的樹下有著茂盛的紫蘇玉蘭花和一些可
食的蕈類植物，你若是餓了也可以採集一些下來食用，你也看到了這附
近有一些採藥童在採摘花果，這的樹林茂盛，日不見天，涼爽怡人，似
身處於河水般涼爽。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"fgo2.c",
  "west" : __DIR__"fgo4.c",
]));
	set("no_clean_up", 0);
	set("outdoors","forest");
	set("objects",([
  __DIR__"npc/obj/wtree.c" :random(5),
]));
	set("item_desc",([
  "紫蘇玉蘭花" : "一種草科植物, 你可以摘(pick)下來看看。\n",
]));
	setup();
}

void init()
{
	add_action("do_pick","pick");
}

int do_pick(string arg)
{
	object me=this_player(),flower;
	flower = new(__DIR__"npc/obj/gsflower.c");
	if( arg !="gei-su flower" && arg !="紫蘇玉蘭花" )
		return notify_fail("你要摘什麼東西呀？\n");
	else if( !me->query_temp("rflower")) {
		message_vision("$N用手把樹下的紫蘇玉蘭花摘了一朵起來。\n",me);
		me->set_temp("rflower",1);
		flower->move(me);
	} else {
		message_vision("$N想用手摘起紫蘇玉蘭花，沒料卻給旁邊的花給刺了。\n",me);
		me->receive_damage("hp",1);
	}
	return 1;
}