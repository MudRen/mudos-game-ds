#include <room.h>
inherit ROOM;

void create()
{
  set("short","����");
  set("long",@LONG
�o�̬O���ۥC���W��A�}�U���ۭ��Z���b���㪺�A�n�����g�L��
��A�����W�ؤF�y���¡A���¥~�\�F�@�Ӥj��A��l�����F�Ǯ��
���b�U�N�C
LONG);
  set("exits",([ 
      "down":__DIR__"room56",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/cat-oldwoman":1,
      __DIR__"npc/eq/big-pot":1,
     ]) );
  setup();
}            
