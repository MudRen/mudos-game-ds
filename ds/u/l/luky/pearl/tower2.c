// This is a room made by roommaker.

inherit ROOM;

void create()
{
set("short", "海神塔二樓");
set("long", @LONG
這裡的台階佈滿了灰塵, 更增添了幾分的神秘氣息。在陰暗的光線中你發
現牆壁上寫了幾句經文, 由於年代太久遠了以至於不少字都已經被風化而模糊
不清了。除此之外, 這個空蕩的樓梯間實在是沒有什麼好逗留的。
LONG
);
set("objects",([
__DIR__"npc/towersoldier":2,
]));
set("exits", ([ 
  "up" : __DIR__"tower3",
  "down" : __DIR__"tower",
]));
set("no_clean_up", 0);
setup();
replace_program(ROOM);
}
