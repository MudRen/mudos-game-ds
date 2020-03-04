// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "白沙地");
set("long", @LONG
你正走在一片軟軟的沙地上。走著走著..你開始發現沙灘的顏色似乎越來
越灰暗了，而且還開始有了一些小石頭。四周還有些許的野生植物，但是看起
十分整齊，可能是最近有人來修剪過。
LONG
);
set("exits", ([ 
  "east" : __DIR__"sea7",
  "south" : __DIR__"sea1",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
