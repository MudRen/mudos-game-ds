#include <room.h>
inherit ROOM;

void create()
{
  set("short","���~�p��");
  set("long",@LONG
�o�̬O�����~��q���˪L���D���A����D���w�Q����������ұ�
�S�A�A�����}�Q����Ҳ̡A�n�n�̨̮��o�ܯT�V�A�_��i�H�ݨ��@�j
�����˪L�A�b�o��N��P���o��q�˪L���o���M�`���޲���^�C
LONG);
  set("exits",([ 
      "east":__DIR__"room36",
      "north":__DIR__"room39",
     ]));
  set("no_clean_up",0);
  set("no_map",1);
  set("no_recall",1);
  set("no_horse_member",1);
  set("outdoors","land");
  setup();
}            
