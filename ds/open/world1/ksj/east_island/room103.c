#include <room.h>
inherit MOBROOM;

void create()
{
  set("short","�s�y");
  set("long",@LONG
�Ө�o�̷ū׺������C�A���]�ܭ��F�A����N�N�a�Pı�ܤ���
�A�A�|�P����쳣�O�k���b���ۤW�ͪ��A����s�s�����a�A�����W��
�\�h�Q�F��i�L������C
LONG);
  set("exits",([ 
      "east":__DIR__"room104",
      "southwest":__DIR__"room102",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("chance",50);
  set("mob_amount",3); 
  set("mob_object",({    
      __DIR__"npc/warrior-ghost2",
     }) );
  setup();
}            
