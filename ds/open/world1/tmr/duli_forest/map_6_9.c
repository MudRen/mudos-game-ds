inherit ROOM;
void create()
{
        set("short", "小路");
        set("long", @LONG
四週黃沙漫漫，堆起了數個快比人高的沙堆。
LONG
);
        set("exits",([
                "north" : __DIR__"map_5_9",
                "south" : __DIR__"map_7_9",
        ]));
        set("objects",([
                __DIR__"npc/bandit":2,
        ]));
        set("detail",([
                "沙堆" : "這兒四周堆滿數個沙堆，其中還有個頗大的沙穴，不知能不能進的去...\n",
        ]));
        set("outdoors","land");
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
        ::init();
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me = this_player();
        if(!arg || arg!="沙穴" ) return 0;
        if( me->is_busy() )
                return notify_fail("你正忙著，沒有空做其它的事。\n");
        message_vision("$N一彎腰進去了一處沙穴....\n",me);
        me->move(__DIR__"cave_enter.c");
        tell_room( environment(me) , me->name() + "從外面擠了進來", ({ me }) );
    return 1;
}

