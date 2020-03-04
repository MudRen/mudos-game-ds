// Room: /u/a/aring/tomb/12.c

inherit ROOM;

void create()
{
        set("short", "大墓園－墳墓");
        set("long", @LONG
你正站在一座墳墓的上頭，四周散落著幾個棺木，不知道是被挖出
來，還是根本沒掩埋，總之空氣中滿佈屍臭味，真是令人難以忍受。
LONG
        );
        set("light", "0");
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"13.c",
  "west" : __DIR__"11.c",
]));
        set("current_light", 1);

        setup();
        replace_program(ROOM);
}

