#include <room.h>
inherit ROOM;

void create()
{
  set("short","��D");
  set("long",@LONG
�o�̬O��������D�A�b�o��w�g�i�H�ݨ���l�̭����@�ǩЫΤ�
�ؿv�A�H�ӤH���ݰ_�ӫܼ��x�A�F��ǨӰ}�}�����A��ӬO���Ʋz��
�C
LONG);
  set("exits",([ 
      "east":__DIR__"room8",
      "west":__DIR__"room17",
      "south":__DIR__"room11",
      "north":__DIR__"room13",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  set("objects",([
      __DIR__"npc/eq/water-pot":1,
     ]) );
  setup();
}            
