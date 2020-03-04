inherit ROOM;
void create()
{
set("short","山壁");
set("long", @LONG
你終於走出黑暗的地方, 你看了一下四周, 發現你正站在山壁上, 你
才了解剛剛那條通道, 原來是可以通到這裡, 這裡周圍長滿了野花綠草風
景優美.
LONG
);
set("outdoors", "forest");
set("exits", ([ 
                "enter"  : __DIR__"tree4.c",
                           ]));
set("item_desc",([
        "山縫":"只有一點點的小洞,不知道可不可以鑽過去,不過你可以試試(enter)。\n",
        ]) );
setup();
}

void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
       me=this_player();
        if (!arg || arg!="山縫" ) return 0;
        message_vision("$N把全身縮的像一隻烏龜一樣,很勉強才擠進去。\n",me);
        me->move(__DIR__"lllll");
        tell_room(environment(me),me->query("name")+"從山縫裡爬了出來。\n",me);
        return 1;
}
        



