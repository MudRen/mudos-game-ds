//u/c/chiaa/world2/blackly_forest/road1.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "�˪L�~�B");
        set("long",@LONG
�A���i�F�o���˪L�������p�ϰ�,�Pı��Ů𪺷s�A,
��W���@�ǳD����¶,���G�٦�����D���ˤl,
�b�A���}�U���@���H�ͦb��F�W����ۣ,
���L�ݰ_���A�v,�γ\�a���@�r�]�����@�w!
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "southeast"  : __DIR__"vacancy1",     //�L���Ŧa1
  ]));
       
            setup();
replace_program(ROOM);
}
