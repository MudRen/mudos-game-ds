#include <room.h>
inherit ROOM;

void create()
{
  set("short","�X���s��");
  set("long",@LONG
�o�̬O�X���s���s���A�|�B�����b��A�G�������ճ��A�j�l���N
�����a�����¶�b���ۤ����A�A�`�N�즳�����������n���Q����F��
�i�L�����A��o������ơA�A���G�D��@�@���{���ƴ��b�Ů𤤡C
LONG);
  set("exits",([ 
      "north":__DIR__"room112",
      "southdown":__DIR__"room109",
      "northwest":__DIR__"room111",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","snow");
  setup();
}        

int valid_leave(object me, string dir)
{
  object guard;
  if( objectp(guard=present("head", this_object())) && !me->query("orochi") && !random(3) && guard->is_character() )
  {
    message_vision("$n���j��������צ�$N���X���A$N�@�ɤ⨬�L���A�@�y��W�C\n",me , guard);
    me->add_busy(1);
    return notify_fail("");
  }
  if( me->query("orochi_beast_3") )
  {
    if( dir == "southdown")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}             
