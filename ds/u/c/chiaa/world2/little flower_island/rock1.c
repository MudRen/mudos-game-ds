//u/c/chiaa/world2/little flower_island/rock1.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HBK"���۰�"NOR);
        set("long",@LONG
�o�̬O�p��骺���۰�,��B���O�ѥ��j�����۩Ҳզ�,�g�L
���ɶ������j����,�C�����۳����ۯS���Ϊ�,�c���@�ة_��
�����[,�b�C�����ۤ����n�����ͪ����ʵ�!!


LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       "east"      : __DIR__"forest3",      //�˪L3
       "north"     : __DIR__"sand4",        //�F�y4  
  ]));
       
            setup();
replace_program(ROOM);
}
