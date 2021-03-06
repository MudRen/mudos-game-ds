// Room: /open/world1/tmr/advbonze/hill17.c

inherit ROOM;

int do_jump(string arg);
void create()
{
        set("short", "凌雲峰頂-缺口處");
        set("long", @LONG
你正站在上天梯的一處缺口處，往南十數丈遠的地方，是另一處通往山下
的缺口處，你現在可以清楚看到往北不遠處，就是凌雲峰頂上的平台，你赫然
發現峰頂平台上竟然有座達十人高的巨大金佛，陽光照射在金佛反射出來時，
就是在山腰處所看到的奇光，你看著看著，不禁感嘆此景之美。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "缺口" : "一個十幾丈見寬的大缺口，你或許\會想要跳(jump)過去。\n",
]));
        set("no_clean_up", 0);
        set("current_light", 6);
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"summit1",
]));
        set("outdoors", "forest");

        setup();
}
void init()
{
    ::init();
    add_action("do_jump","jump");
}

int do_jump(string arg)
{
       object me=this_player();        

       if(arg!="缺口") 
                return notify_fail("你想要跳(jump)過什麼？");
        if(me->is_busy() )
                return notify_fail("你正忙著，無法專心應付此動作。\n");
         if(me->query_skill("dodge") <10)
                return notify_fail("你的輕功\造詣不足，你無法安全地跳過去。\n");
        if(!me->move(__DIR__"hill16.c") )
                return notify_fail("你無法跳過缺口。\n");
        tell_room(environment(me), me->name() + "一提氣跳過了缺口，輕巧巧地落地上。\n");
        return 1;
}


