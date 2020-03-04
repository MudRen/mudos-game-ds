#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s�y");
  set("long",@LONG
�Ө�o�̷ū׺������C�A���]�ܭ��F�A����N�N�a�Pı�ܤ���
�A�A�|�P����쳣�O�k���b���ۤW�ͪ��A����s�s�����a�A�����W��
�\�h�Q�F��i�L������C
LONG);
  set("exits",([ 
      "west":__DIR__"room109",
      "northeast":__DIR__"room107",
      "northup":__DIR__"room117",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            

int valid_leave(object me, string dir)
{
  if( me->query("orochi_beast_2") )
  {
    if( dir == "northup")
      return notify_fail("");
  }
  return ::valid_leave(me, dir);
}         
