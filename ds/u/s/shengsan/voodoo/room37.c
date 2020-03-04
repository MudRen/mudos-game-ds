
inherit ROOM;

void create()
{
	set("short", "煉丹房");
	set("long", @LONG
這裡是巫毒教煉丹的地方，有一位煉丹師傅專門在這煉各種特殊的藥
丹。你可以看到有一個煉丹用的煉丹爐(furnace)在這房間的正中央，還有
一些工具及煉丹的藥品材料都在桌上。
LONG
	);

	set("item_desc", (["furnace":@NOTE
[1;36m
這個煉丹爐是專門煉出各種神奇藥丹的絕佳工具，也許你會想去摸摸它
(touch furnace)。
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room35",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/alchemist" : 1,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
}

void init()
{
  add_action("do_touch","touch");
}

int do_touch(string arg)
{
object me;
me=this_player();
  if (!arg || arg!="furnace") return notify_fail("你要摸什麼?\n");
    message_vision("$N[1;36m摸了煉丹爐一下......[1;31m哇!!!好燙阿[1;36m...[m\n",this_player());
    me->add("hp",-(10+random(10)));
//	message_vision("$N被燙傷了。\n",this_player());
	message_vision("$N被燙傷了。\n",me);
	return 1;
}
