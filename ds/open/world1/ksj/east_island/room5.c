#include <ansi.h>
#include <room.h>
inherit MOBROOM;

void create()
{
 set("short","�����p��");
 set("long",@LONG
�o�̬O���������p���A��ǬO���Y��ˤl�f�ت��p�ΡA�ݰ_�Ӧ�
�I�}�¡A�q�θ̺��X�����Ϻ������A�����D�A�@�Ǫ��Ŧa�W��۬���
��H�����Q��A�b�����U��o�{ģ���ءC
LONG
    );
   set("exits",([ 
       "east":__DIR__"room4",
       "southwest":__DIR__"room6",
   ]));

   set("no_clean_up",0);
   set("outdoors","land");
   set("chance",30);
   set("mob_amount",3);  
   set("mob_max",9);
   set("mob_object",({    
        __DIR__"npc/fisher",
      }) );
   setup();
}            
