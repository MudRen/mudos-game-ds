#include <room.h>
inherit ROOM;

void create()
{
  set("short","����W");
  set("long",@LONG
����o�̬O����������A�z�L���W���}�}�i�H�ݨ���檺�ˬy�A
���I�m���e�ɡA���������𪺮��k�A����ƷƦa�ᤣ�n���C
LONG);
  set("exits",([ 
      "east":__DIR__"room60",
      "west":__DIR__"room62",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            
