inherit ROOM;

void create()
{
        set("short", "疾風門入口大門");
        set("long", @LONG
這裡就是疾風門的大門了，這裡有兩扇用鑌鐵所做成的大門，堅硬
到連炮都打不破，門的旁邊有兩個守門衛兵在守衛著，似乎防備很嚴的
樣子，並不容易攻破。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"flurry1.c",
  "north" : __DIR__"flurry3.c",
]));
        set("objects",([
  __DIR__"npc/fguard": 2,
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("light",1);
        setup();
        replace_program(ROOM);
}

