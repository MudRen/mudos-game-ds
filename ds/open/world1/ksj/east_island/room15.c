#include <room.h>
inherit ROOM;

void create()
{
  set("short","��D");
  set("long",@LONG
�o�̬O��������D�A�b�o��w�g�i�H�ݨ���l�̭����@�ǩЫΤ�
�ؿv�A�H�ӤH���ݰ_�ӫܼ��x�A������i�H�ݨ���̥ΨӨ��m�ĤH��
�]�����A��O�A�F��O�@�������C
LONG);
  set("exits",([ 
      "east":__DIR__"bank",
      "west":__DIR__"room20",
      "south":__DIR__"room14",
     ]));
  set("no_clean_up",0);
  set("outdoors","land");
  setup();
}            
