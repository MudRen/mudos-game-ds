#include <room.h>
inherit ROOM;

void create()
{
  set("short","�s��");
  set("long",@LONG
�o�̬O�@�B�Z�`���s���A�Y���W���ƪ��s���C�C�w�ۦB�N�����w
�A���U�ắ�J�a�O���A�o�X�w���w�����^���A�@�Ǫ��������ӥξ�K
���󰵦����O�@�Ӥj�_���F��C
LONG);
  set("exits",([ 
      "east":__DIR__"room94",
     ]));
  set("no_clean_up",0);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/umaro":1,
     ]) );
  setup();
}            
