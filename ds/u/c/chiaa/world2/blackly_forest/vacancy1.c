//u/c/chiaa/world2/blackly_forest/vacancy1.c

#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "�L���Ŧa");
        set("long", @LONG
�o�O�L�����@�p���Ŧa,��ꤣ�L�Ƥ�,��ǰ��F�C����,
���ɥi�ݨ����Ƥ������p���ΡA�]�iť�o���s�ζ�,
�i�H���樫�b�˪L���H,�b�o�̼Ȯɱo���!!
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
     "southeast"  : __DIR__"path2",           //�p�|2
     "northwest"  : __DIR__"road1",          //�˪L�~�B
]));
       
        setup();
replace_program(ROOM);
}
