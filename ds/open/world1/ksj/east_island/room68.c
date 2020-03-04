#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIM"���L"NOR);
  set("long",@LONG
�o�̬O���L�����L�|�A�|�P���O�j�j�p�p������A�b�v���R
������H�۷L�������n�\�A�M�ӥX�����⪺�ѪšC
LONG);
  set("exits",([ 
      "northeast":__DIR__"room67",
      "southeast":__DIR__"room71",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  set("objects",([
      __DIR__"npc/black-tengu":1,
     ]) );
  setup();
}            
