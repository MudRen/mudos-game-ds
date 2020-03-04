// Room: /open/world1/acme/area/senwu3.c
inherit ROOM;

void create()
{
        set("short", "萬靈台");
        set("long", @LONG
在這種鳥不生蛋的地方，竟有人架了這個大靈台，在靈台四方，
各插著「紅」、「黃」、「藍」、「綠」四色的旌旗，在靈台中心，
尚有高台，從高台上傳來陣陣雲霧，說是雲霧也不盡然，卻是冰水遇
到烈焰時散出的蒸氣。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"senwu2",
]));
        set("world", "past");
        set("outdoors","land");
        set("no_clean_up", 0);

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
          if(arg != "高台") return notify_fail("你要爬什麼？\n");
        if( me->is_busy() ) return notify_fail("你正忙著，沒法子做這動作。\n");
            message_vision("$N手腳並用的爬上高台。\n",me);
            me->move(__DIR__"senwu4");
          tell_room(environment(me),me->query("name")+"爬了上來。\n",me );
     return 1;
}
