#include <room.h>
inherit ROOM;

void create()
{
  set("short","���~�p��");
  set("long",@LONG
�o�̬O�����~��q���˪L���D���A�ѩ�֦��H�g�L�A�����W����
�F�p��A���ǥߤF�L�򹳡A���ʤ֤H���@����o�����ֲ֡C
LONG);
  set("exits",([ 
      "west":__DIR__"room37",
      "south":__DIR__"room20",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"statue":1,
     ]));
  setup();
}            
