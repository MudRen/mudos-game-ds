inherit ROOM;

void create()
{
   set("short","小麥草練功\房");
   set("long", @LONG
這裡是小麥草的練功房,是小麥草無聊的時後來這裡練功的
但你發現四周沒有辦個武器,也沒有一絲殺氣,可見小麥草
有多肉腳。
LONG );
  set("light", 1);
  set("exits", ([/* sizeof() == 2 */
"south" : "/u/s/sexking/workroom/sexking_room2.c"
]));
setup();
} 
