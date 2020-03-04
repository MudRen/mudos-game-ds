// Room: /u/k/kenshin/sha-zin-gu/room16.c

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
雖然越走越脫離暇日谷的中心，但是寧靜與空氣卻是成反比，嚮往
大自然寧靜可以來這裡看看，或許會有不一樣的享受。再往西走，便能
到達鎮上唯一的客棧『九龍客棧』。
LONG
        );
        set("outdoors", "land");
        set("current_light", 3);
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room17",
  "east" : __DIR__"room15",
]));
        set("no_clean_up", 0);

        setup();
replace_program(ROOM);
}

