// Room: /u/s/sub/area/village/tree1.c

inherit ROOM;

void create()
{
    set("short", "神木內部");
	set("long", @LONG
這裡是神木樹幹的木質部，由於長期地被白蟻啃食，現在已經變成中
空的。四周相當的寬敞，大約可容納十多個人，也不會覺得擁擠。因為樹
幹上有些破損，所以有一束束的光線照射進來，使得這裡充滿了安祥寧靜
的氣氛。
LONG
	);
       set("item_desc",([
  "樹皮" : "樹幹上似乎有著力點可以向上攀爬(climb up)。\n",
]));
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "out" : "/u/s/sub/area/valley/map_1_2.c",
]));
	set("world", "undefine");
	set("current_light", 1);
    set("objects",([
        __DIR__"npc/village_ant_5" : 3,
    ]));

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
        if(!arg) return notify_fail("你要往哪裡爬？\n");
        if (arg != "up") return 0;
        
        message_vision("$N手附著樹幹，慢慢地往上攀爬。\n" ,me);
        me->move(__DIR__"tree2");
          tell_room(environment(me),me->query("name")+"很狼狽地爬了上來。\n",me);
        return 1;
}
