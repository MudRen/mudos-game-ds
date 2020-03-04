#include <room.h>
inherit ROOM;

void create()
{
  set("short","�j�]��");
  set("long",@LONG
�o�̬O�@�Ӥ��Y�v�����]���A�]����Ǧ����۪Z���������b���^
�A�������A��O�W�]���H���ĵ�١A�ϩ��b���Ƥ�������C
LONG);
  set("exits",([ 
      "east":__DIR__"room15",
      "west":__DIR__"room25",
      "north":__DIR__"room36",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/villager-guard":3,
      __DIR__"npc/autarou":1,
      __DIR__"npc/eq/tower":1,
     ]));
  setup();
}           

int valid_leave(object me, string dir)
{
  object guard;
  if( me->query("village") )
  {
    if( dir == "north")
      return notify_fail("");
  }
  if(me->query("level")<26)
  {
    if( objectp(guard=present("villager guard", this_object())) && dir == "north" )
    {
      message_vision("$n���צb$N�����e���D�G�_��M�I�����A�d�b��������w���C\n",me , guard);
        return notify_fail("");
    }
  }
  else if( objectp(guard=present("villager guard", this_object())) && dir == "north" )
  {
    message_vision("$n��ߪ���$N���D�G�иU�Ƥp�ߡI�I\n",me , guard);
    return ::valid_leave(me, dir);
  }
  return ::valid_leave(me, dir);
}
