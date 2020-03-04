// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "白沙地");
set("long", @LONG
你正走在一片軟軟的沙地上。沙灘越來越窄了，四週也漸漸出現各種的海 
中生物，而且沙灘上還有了一些大石頭。四周還有些許的野生植物，但是看起
十分整齊，可能有人整理過。
LONG
);
set("exits", ([ 
"east" : __DIR__"sea6",
"west" : __DIR__"sea8",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
