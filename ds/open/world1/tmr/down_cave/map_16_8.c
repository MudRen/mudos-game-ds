inherit ROOM;
void create()
{
        set("short", "走道");
        set("long", @LONG
走道通到了這裡，忽然就被一面大石壁堵住了，也不知還有沒有路可走。
LONG
);
        set("exits",([
                "north" : __DIR__"map_15_8",
                //"west" : __DIR__"map_16_7",
        ]));
         set("detail",([
                "石壁":"一面頗厚的石壁，上頭沒沾到什麼沙子，似乎常有人跡的樣子。\n"
        ]));
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
        ::init();
        add_action("do_push" , "push" );
}

int do_push(string arg)
{
        object me=this_player();
        if(!arg || arg!="石壁")
                    return notify_fail("你要推什麼？\n");
        if(me->is_busy())
               return notify_fail("你現在沒有空。\n");
        message_vision("$N推開了石壁走了進去...\n",me);
        me->move(__DIR__"map_16_7");
        tell_room(environment(me),me->name()+"推開了石壁走了過來。\n",me);
        return 1;
}

