// Room: /u/c/chiaa/hourse/hourse3.c
#include <room.h>
inherit ROOM;
inherit DOOR;
void create ()
{
  set("short", "大頭狗的讀書室");
  set("long", @LONG
這裡是大頭狗最不喜歡的地方!來到這個房間大頭狗就要開始用功!
但是大頭狗只想過悠閒的日子!
LONG
        );
        set("valid_startroom", 1);
        set("no_magic", 1);
        set("no_die", 1);
  set("exits", ([ /* sizeof() == 1 */
"north" : __DIR__"hourse0",

]));
setup();
create_door("north","木板門","south",DOOR_CLOSED);  //北邊的木板門是關著的
                                                    //兩邊門方向要相對

}
