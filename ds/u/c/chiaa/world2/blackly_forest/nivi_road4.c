//u/c/chiaa/world2/blackly_forest/nivi_road4.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "�D��");
        set("long", @LONG
�A�����b�Ԫ̧����@���D��,���W����H��A�o�� 
�N�~���X��,���G���s�۫ܰ���ĵ�٤ߩM�n�_��!!
�n�䤣���B�i�ݨ�@�ǩФl!!
LONG
        );
        set("exits", ([ /* sizeof() ==  */
    "south"  : __DIR__"hourse1",           //�Фl1
    "north"  : __DIR__"nivi_road3",        //�ԧ��D��3
]));
       
            setup();
replace_program(ROOM);
}


