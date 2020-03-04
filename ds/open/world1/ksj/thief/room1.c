#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit DOOR;

void create()
{
  set("short", HIC"�s��u�|"NOR);
  set("long", @LONG
�A����F�@���U�p���ж��A�o�̪��˹��Y�㺡�ءA�n�������O�o�Ӧa
�Ϫ��F��C�����̦��ӯ}�}���j�c�l�A�����ٱ��ۤ@�Ӥp�ªO�C

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
  create_door("south","�K��","north",DOOR_CLOSED);
//  create_door("south","�K��","north",DOOR_LOCKED,"ironkey");
  setup();
  load_object("/obj/board/thief_b");
//  call_other( "/obj/board/thief_b", "???" );
}
