inherit ROOM;
void create()
{
        set("short", "荒島上的小路");
        set("long", @LONG
你注意到北邊林區的雜草堆成不規則的翻折現像，似乎是有人匆匆走
過而踏壞的樣子。
LONG
);
        set("exits",([
        "west" : __DIR__"map_8_8",
        "east" : __DIR__"map_8_10",
        "south" : __DIR__"map_9_9",
        ]));
        set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
        add_action("do_pass","pass");
}
int do_pass(string arg)
{
        object me=this_player();
        if(!arg || arg!="雜草堆")
                return notify_fail("你要通過那裡？\n");
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，請先停下手邊的事吧。\n");
                message_vision("$N伸手撥開了雜草，走了過去.....\n",me);
                me->move(__DIR__"thief_room");
                tell_room(environment(me),me->query("name")+"穿過雜草堆，走了過來。\n",me);
        return 1;
}



