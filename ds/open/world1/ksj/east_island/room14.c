#include <room.h>
inherit ROOM;

void create()
{
  set("short","��D");
  set("long",@LONG
�o�̬O��������D�A�b�o��w�g�i�H�ݨ���l�̭����@�ǩЫΤ�
�ؿv�A�H�ӤH���ݰ_�ӫܼ��x�A�F��O���W���s���y�D���A���䦳�@
���p���E�C
LONG);
  set("exits",([ 
      "east":__DIR__"room10",
      "west":__DIR__"room19",
      "south":__DIR__"room13",
      "north":__DIR__"room15",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/asaka":1,
     ]) );
  setup();
}
