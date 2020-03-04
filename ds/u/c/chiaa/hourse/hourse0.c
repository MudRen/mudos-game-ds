// Room: /u/c/chiaa/hourse/hourse0.c
#include <room.h>
inherit ROOM;
inherit DOOR;

void create ()
{
  set("short", "大頭狗的窩");
  set("long", @LONG
這裡是大頭狗最喜歡的地方!也是屬於牠的私人房間!
大頭狗的至理名言是~~~我只想過著悠閒的日子~~~
LONG
        );
        set("valid_startroom", 1);  //使該房間成為下一次連線進來的地方
        set("no_magic", 1);         //房間為禁止施法區域
        set("no_die", 1);
  set("exits", ([ /* sizeof() == 3 */
"enter" : __DIR__"hourse1",
"west" : __DIR__"hourse2",
"south" :__DIR__"hourse3",
]));
setup();
create_door("south","木板門","north",DOOR_CLOSED);  //往南邊的門是關著的
                                                    //兩邊門的方向要相對
}
