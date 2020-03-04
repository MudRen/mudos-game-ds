// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "沙地");
set("long", @LONG
你正走在一片軟軟的沙地上。你看到西北方不遠處有個塔, 大概是用來瞭
望遠方的觀測塔吧。周圍佈滿了各式各樣的珊瑚礁岩石, 這裡一點聲音都沒有
, 安靜的讓人害怕, 你感覺到似乎有什麼神秘的生物在監視著你的一舉一動。
LONG
);
set("exits", ([ 
  "west" : __DIR__"sea3",
  "north" : __DIR__"sea5",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
replace_program(ROOM);
}
