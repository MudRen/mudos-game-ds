#include <room.h>
inherit ROOM;

void create()
{
  set("short","������");
  set("long",@LONG
�o�̬O���˸޲����˪L�A�ѩ󰭩Ǫ��Ϯ��ϱo���𾮭��A���~�@
���E�������A���b�o��Pı�����D�D���A���ɦ��_�Ǫ��s�n�q�˪L��
�ǨӡA���ת����ϱo�|�P�R���@�ѻG�䪺���D�C
LONG);
  set("exits",([ 
      "east":__DIR__"room44",
      "west":__DIR__"room42",
      "south":__DIR__"room39",
      "north":__DIR__"room48",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  set("objects",([
      __DIR__"npc/gaki":1,
     ]) );
  setup();
}            
