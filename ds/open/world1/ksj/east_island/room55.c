#include <room.h>
inherit ROOM;

void create()
{
  set("short","���ۥC");
  set("long",@LONG
�o�̬O�Ѥ@�ǥ��j�����۰令���p�s�C�A�s�C�����\�h���_�A��
�����_�~�����@�ǰ��Y�A�a���W���ô��G�j�p���@���}�L�A���O�H��
�}�L�A�Ϊ���ҫo�S���Ǥ���C
LONG);
  set("exits",([ 
      "west":__DIR__"room54",
      "south":__DIR__"room50",
      "northwest":__DIR__"room56",
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
