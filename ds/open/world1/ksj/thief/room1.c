#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
  set("short", HIC"盜賊工會"NOR);
  set("long", @LONG
你走到了一間狹小的房間，這裡的裝飾琳瑯滿目，好像都不是這個地
區的東西。角落裡有個破破的大箱子，旁邊還掛著一個小黑板。

LONG
);
  set("exits", ([ /* sizeof() == 2 */
      "east" : __DIR__"room2",
      "south": "open/world1/cominging/area/beast2",
     ]));
  set("objects",([
      __DIR__"npc/eq/box":1,
     ]));
  set("no_clean_up", 0);
  set("light", 1);
  set("free_lock/south",1); 
//  set("valid_startroom",1);
  create_door("south","鐵門","north",DOOR_CLOSED);
//  create_door("south","鐵門","north",DOOR_LOCKED,"ironkey");
  setup();
  load_object("/obj/board/thief_b");
//  call_other( "/obj/board/thief_b", "???" );
}
