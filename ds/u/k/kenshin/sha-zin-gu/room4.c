// Room: /u/k/kenshin/sha-zin-gu/room4.c

inherit ROOM;

void create()
{
        set("short", "森林出口");
        set("long", @LONG
終於走出那一片黑烏烏的森林了，一出森林往前一望，那一處繁榮
的景象，想必那一定是武林少俠寧采和的所在處，暇日谷了。除了繁榮
的景色，還有那村民和藹可親的對待著遠來的朋友，心裡不禁想了想，
能媲美此地的地方，已經不多了!!
LONG
        );
        set("current_light", 2);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room3",
  "north" : __DIR__"room5",
]));
        set("outdoors", "land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


