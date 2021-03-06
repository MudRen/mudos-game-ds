// Room: /open/world1/tmr/bagi/rift.c
#include <ansi.h>
#include <path.h>
#include <room.h>

inherit ROOM;

inherit DOOR;
void create()
{
        set("short", "山壁前");
        set("long", @LONG
在你面前有面大山壁，其間夾一山縫，約可容一人側身而過，時有微
風從中而來，穿過山縫時因相磨而帶有哨聲。壁上遍是雜草、雜花，且削
壁光滑，想攀爬上山壁，絕無可能。
LONG
        );
        set("item_desc", ([ /* sizeof() == 2 */
  "east" : (: look_door,     "east" :),
  "山縫" : "開於山壁之間的夾縫，似乎為人工挖削出來。
",
]));
        set("world", "past");
        set("outdoors", "land");
        set("exits", ([ /* sizeof() == 2 */
//"north" : "/open/world1/baal/ming_club/cablecar",
  "east" : "/open/world1/tmr/area/s_house",
]));
        set("no_clean_up", 0);

        setup();
      create_door("east", "後門", "west", DOOR_CLOSED);
}
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="山縫" ) return 0;
        message_vision("$N一縮身，就往山壁中的山縫擠了進去。 \n",me);
        me->move(__DIR__"rift1");
          tell_room(environment(me),me->query("name")+"擠了過來。\n",me );
        return 1;
}
