inherit ROOM;
void create()
{
        set("short", "林中小路");
        set("long", @LONG
一棵擁有百年高齡的老柳樹橫在路中央，老樹上的樹枝雜七雜八的似
要向上爭天般的崢嶸而上。你注意到有根粗如人臂的樹枝就在離你頭
頂不高的地方。
LONG
);
        set("exits",([
        "south" : __DIR__"map_7_7",
        "east" : __DIR__"map_6_8",
        ]));
        set("detail",([
                  "樹枝":"一根橫在你頭頂上方的粗樹枝，你自負還能跳(jump)的上去。\n",
        ]));
        set("outdoors","forest");
        setup();
        set("map_long",1);     //show map as long
}
void init()
{
        add_action("do_jump","jump");
}

int do_jump(string arg)
{
        object me=this_player();
        if(!arg || arg!="樹枝" )
                return notify_fail("你要跳到什麼地方？\n");
        if(me->is_busy())
                return notify_fail("你正忙著，沒有空做這個動作。\n");
        message_vision("$N輕巧巧地跳上大樹上的一截樹枝。\n",me);
        me->move(__DIR__"three");
        return 1;
}

