#include <room.h>
inherit ROOM;

void create()
{
  set("short","���ۥC");
  set("long",@LONG
�o�̬O�Ѥ@�ǥ��j�����۰令���p�s�C�A�s�C�����\�h���_�A��
�����_�~�����@�ǰ��Y�A�n�����Ƕ¼v�b���۶�����A���_�i�H�ݨ�
�@�Ӹ��j�����}�C
LONG);
  set("exits",([ 
      "east":__DIR__"room55",
      "west":__DIR__"room53",
      "south":__DIR__"room49",
      "north":__DIR__"room56",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","forest");
  set("objects",([
      __DIR__"npc/ferity-apeman":2,
     ]) );
  setup();
}            
