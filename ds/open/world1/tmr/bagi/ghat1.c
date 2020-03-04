// Room: /open/world1/tmr/bagi/ghat1.c

inherit ROOM;

void create()
{
        set("short", "懸崖前");
        set("long", @LONG
你正處在居高臨下的峭壁前，往下望去，只見陣陣白霧環繞，難以望
盡。往北有條山道通向一片白慘慘的雪地，襲襲寒風吹來，不禁令人打了
哆嗦。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"ghat2",
  "down" : __DIR__"glade", 
//    "east" : __DIR__"ghat1_2",
]));
        set("world", "past");
    set("outdoors","snow");
        set("no_clean_up", 0);
        set("forest", "snow");

        setup();
        replace_program(ROOM);
}

