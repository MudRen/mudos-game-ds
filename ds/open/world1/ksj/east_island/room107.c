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
      "southwest":__DIR__"room108",
      "north":__DIR__"room105",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/five-head-snake":1,
     ]) );
  setup();
}            
