#include <room.h>
inherit ROOM;

void create()
{
 set("short","����");
 set("long",@LONG
�o�̬O�p�q��������A�F�y�W���Q�۫󥭪��۪O�A�Φ��@�����Q
���A�Q�������L�L���������ƯB�b�����W���b�z���Q�ءA�Q���̬y��
�p�B�����w�N�Q���Τ쥶�E������C
LONG
    );
   set("exits",([ 
       "north":__DIR__"room2",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("objects",([
      __DIR__"npc/salt-maker":3,
     ]));

   setup();
}            
