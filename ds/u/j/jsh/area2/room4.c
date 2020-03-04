#include <room.h>

inherit ROOM;

inherit DOOR;
void create()
{
          set("short", "大廳");
          set("long", @LONG 
  你走到一個有光線的地方，原來這裡是這洞穴的大廳，在大廳的西南方都
  是以白色為主，而且擺的非常整齊，還是以八卦陣的形式下去排的，想必這裡
  的人定大大有來頭。
LONG
           );
           set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"masterroom", 
  "west" : __DIR__"master2room",
  "east" : __DIR__"room3",  
  "down" : __DIR__"under/startroom",
]));
  set("objects", ([ /* sizeof() == 1*/
  __DIR__"wang" : 1,
]));      
  set("no_clean_up", 0); 
  set("no_pick",1);
  setup(); 
  create_door("down","鋼筋門","up",DOOR_LOCKED,"whitekey"); 
}

