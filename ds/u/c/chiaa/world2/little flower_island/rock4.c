//u/c/chiaa/world2/little flower_island/rock4.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HBK"���۰�"NOR);
        set("long",@LONG
�o�̬O�p��骺���۰�,��B���O�ѥ��j�����۩Ҳզ�,�g�L
���ɶ������j����,�C�����۳����ۯS���Ϊ�,�c���@�ة_��
�����[,�b�C�����ۤ����n�����ͪ����ʵ�!!
�b�n����񦳤@�y�a�V!!

LONG
        );
        set("exits", ([ /* sizeof() == 2 */
       "south"    : __DIR__"cliff2",        //�a�V2
       "east"     : __DIR__"champaign6",    //����6
  ]));
       
            setup();
replace_program(ROOM);
}
