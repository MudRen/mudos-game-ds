#include <room.h>
inherit MOBROOM;

void create()
{
  set("short","�s�y");
  set("long",@LONG
�Ө�o�̷ū׺������C�A���]�ܭ��F�A����N�N�a�Pı�ܤ���
�A�A���U���שY�i�H���^�s�U�C
LONG);
  set("exits",([ 
      "northeast":__DIR__"room103",
      "down":__DIR__"room101",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("chance",50);
  set("mob_amount",3); 
  set("mob_object",({    
      __DIR__"npc/warrior-ghost1",
     }) );
  setup();
}     

int valid_leave(object me, string dir)
{
  if( me->query("orochi_beast_2") )
  {
    if( dir == "down")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}         
