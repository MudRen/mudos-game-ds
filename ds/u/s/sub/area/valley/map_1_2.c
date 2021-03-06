// Room: /u/s/sub/area/valley/map_1_2.c

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "神木");
	set("long", @LONG

LONG
	);
    set("outdoors", "land");
	set("map_long", 1);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_1_3",
  "west" : __DIR__"map_1_1",
  "south" : __DIR__"map_2_2",
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "神木" : "這是一棵巨大的神木，在壯觀的表面下，可以看到被歲月侵蝕的痕跡。
此外也可以看出樹幹內部因為白蟻啃食幾乎變成中空的。
似乎可以把樹幹撞出一個洞(crash)。
",
]));
	set("current_light", 1);

	setup();
}
void init()
{ 
         add_action("do_crash","crash");
         add_action("do_enter","enter");
}
int do_crash(string arg)
{
          object me;
          me=this_player();
        if(!arg) return notify_fail("你要撞什麼?\n");
          if(arg != "神木")
            return notify_fail("這裡沒有這樣東西。\n");
          else {
            message_vision("$N深深吸了一口氣，朝著神木用力撞了過去，結果樹幹因此破了一個大洞。\n\n",me);
            message_vision(HIR"不少的木屑插入$N的身體，使得$N血流不此，全身淤青。\n"NOR,me);
            set("exits", ([
               "enter" : "/u/s/sub/area/village/tree1",
               "south" : __DIR__"map_2_2",
               "west" : __DIR__"map_1_1",
               "east" : __DIR__"map_1_3",
            ]));
            me->receive_wound("body",10);
            tell_room("/u/s/sub/area/village/tree1",HIG"樹幹被"+me->query("name")+"撞出一個大洞。\n"NOR,me);
            return 1;
          }
}
int do_enter()
{
            object me;
            me=this_player();
            set("exits", ([
               "south" : __DIR__"map_2_2",
               "west" : __DIR__"map_1_1",
               "east" : __DIR__"map_1_3",
            ]));
           message_vision(HIG"$N通過樹皮的破洞後，神木的傷口又漸漸復原了。\n"NOR,me);
            me->move("/u/s/sub/area/village/tree1");
            tell_room(environment(me),HIG+me->query("name")+"進來後，樹皮又恢復原貌。\n"NOR,me);
            return 1;
}
