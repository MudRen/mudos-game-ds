//u/c/chiaa/world2/little flower_island/rock3.c

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
       "north"    : __DIR__"rock2",      //���۰�2
       "enter"    : __DIR__"cave1",      //�}��1
     
  ]));
       
           setup();
replace_program(ROOM);
}
