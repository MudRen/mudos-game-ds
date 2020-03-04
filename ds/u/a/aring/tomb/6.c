// Room: /u/a/aring/tomb/6.c

inherit ROOM;

void create()
{
        set("short", "大墓園－泥路");
        set("long", @LONG
這裡是大墓園中的一條泥巴小路，兩旁都是墳墓和雜草，走在這裡
感覺到又滑又黏，前方的路上還有一些似人非人的腳印。
LONG
        );
        set("no_clean_up", 0);
        set("light", "0");
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"8.c",
  "northeast" : __DIR__"1.c",

]));
        set("current_light", 2);

        setup();
        replace_program(ROOM);
}

