#include <ansi.h>
#include <room.h>
inherit MOBROOM;

void create()
{
 set("short","�����p��");
 set("long",@LONG
�o�̬O���������p���A�p���W�i�H�ݨ촲�����Q�ɤΨ��߸H���A
���}��b���W�o�X�ذճذժ��n���A���Ǫ���[�W�ε۳����٦�����
�������A�Ů𤤺��O�����򳽰������D�C
LONG
    );
   set("exits",([ 
       "west":__DIR__"room5",
       "northeast":__DIR__"room2",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("chance",25);
   set("mob_amount",2);  
   set("mob_max",6);
   set("mob_object",({    
        __DIR__"npc/fisher",
      }) );
   setup();
}            
