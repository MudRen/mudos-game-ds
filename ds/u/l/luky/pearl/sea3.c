// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "沙地");
set("long", @LONG
你正走在一片軟軟的沙地上，踩上去的每一步都留下了一個很深的腳印。
旁邊有一個大石頭，十分光滑，可以讓人坐上去休息。許多貝殼散落在沙子裡
，你看到有一個灰黃相間尖長型貝殼十分好看，忍不住多看了兩眼。
LONG
);
set("exits", ([ 
  "west" : __DIR__"sea2",
  "east" : __DIR__"sea4",
  "south" : __DIR__"sea10",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
 if( dir=="south")
 {
  return notify_fail("那裡還沒有開放喔!!\n");
 }
 return ::valid_leave(me, dir);
}