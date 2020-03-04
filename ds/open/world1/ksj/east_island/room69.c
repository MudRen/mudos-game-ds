#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set("short",HIM"���L"NOR);
  set("long",@LONG
�o�̬O���L�����L�|�A�|�P���O�j�j�p�p������A�b�v���R
������H�۷L�������n�\�A�M�ӥX�����⪺�ѪšC
LONG);
  set("exits",([ 
      "east":__DIR__"room63",
      "west":__DIR__"room70",
      "north":__DIR__"room64",
      "southwest":__DIR__"room74",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  setup();
}            

int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("tengu", this_object())) && !me->query("tengu") && !random(3))
  {
    message_vision("$n���צb$N�����e���D�G���A�d�U�R�ӧa�C\n",me , guard);
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}         
