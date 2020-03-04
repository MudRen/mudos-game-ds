// This is a room made by roommaker.
inherit ROOM;
void create()
{
set("short", "沙地");
set("long", @LONG
你不小心踢到了一個大石頭, 痛的差點叫出聲來! 西邊不遠的地方有個高
塔, 和附近的地形比較起來顯得十分的醒目。東邊是一個險坡, 似乎可以通往
大海的最底端。邪惡的氣味從東北方不斷的吹過來, 你開始考慮是不是該走下
去。
LONG
);
set("exits", ([ 
  "eastdown" : __DIR__"sea17",
  "north" : __DIR__"sea6",
  "west" : __DIR__"tower",
  "south" : __DIR__"sea4",
]));
set("no_clean_up", 0);
set("outdoors",1);
setup();
//replace_program(ROOM);
}
/*
int valid_leave(object me, string dir)
{
 if( dir=="eastdown")
 {
  if(!wizardp(me)) return notify_fail("那裡還沒有開放喔!!\n");
 } 
 return ::valid_leave(me, dir);
}
*/
