#include <room.h>
inherit ROOM;

void create()
{
 set("short","��D");
 set("long",@LONG
�o�̬O��������D�A�b�o��w�g�i�H�ݨ���l�̭����@�ǩЫΤ�
�ؿv�A�H�ӤH���ݰ_�ӫܼ��x�A���䪺�K�E�O�����A��B�Z�����ӷ�
�C
LONG
    );
   set("exits",([ 
       "east":__DIR__"room9",
       "west":__DIR__"room18",
       "south":__DIR__"room12",
       "north":__DIR__"room14",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/yonago":1,
     ]));
   setup();
}            
