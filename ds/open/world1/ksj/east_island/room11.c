#include <room.h>
inherit ROOM;

void create()
{
 set("short","��D");
 set("long",@LONG
�o�̬O��������D�A�b�o��w�g�i�H�ݨ���l�̭����@�ǩЫΤ�
�ؿv�A�H�ӤH���ݰ_�ӫܼ��x�A����@�B�s�諸�Ŧa�O�������V�m��
�C
LONG
    );
   set("exits",([ 
       "east":__DIR__"room7",
       "west":__DIR__"room16",
       "north":__DIR__"room12",
   ]));
   set("objects",([
      __DIR__"npc/dog":2,
     ]) );
   set("no_clean_up",0);
   set("outdoors","land");

   setup();
}            
