// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "沙灘");
set("long", @LONG
你正走在一片軟軟的沙地上。走著走著..你開始發現沙灘的顏色似乎越來
越灰暗了，而且還開始有了一些小石頭。四周還有些許的野生海藻，但是看起
十分整齊，就像是剛剛有人修剪過一樣。
LONG
);
set("exits", ([ 
  "north" : __DIR__"sand1",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
// load_object(__DIR__"ship");
}
