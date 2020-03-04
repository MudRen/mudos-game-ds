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
      "north":__DIR__"room75",
      "south":__DIR__"room80",
      "southwest":__DIR__"room81",
      "northeast":__DIR__"room74",
      "northwest":__DIR__"room76",
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
  if( objectp(guard=present("white tengu", this_object())) && !me->query("tengu"))
  {
    if( dir == "southwest")
    {
      message_vision("$n���צb$N�����e���D�G�Q��ϧL�A�L�F�ڳo���A���C\n",me , guard);
      return notify_fail("");
    }
  }
  if( objectp(guard=present("tengu", this_object())) && !me->query("tengu") && !random(3))
  {
    message_vision("$n���צb$N�����e���D�G���A�d�U�R�ӧa�C\n",me , guard);
      return notify_fail("");
  }
  if( me->query("tengu") )
  {
    if( dir == "southwest")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}        
