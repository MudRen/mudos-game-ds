//u/c/chiaa/world2/blackly_forest/nivi_road2.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "�D��");
        set("long", @LONG
�A�����b�Ԫ̧����@���D��,���W����H��A�o�� 
�N�~���X��,���G���s�۫ܰ���ĵ�٤ߩM�n�_��!!
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "south"  : __DIR__"nivi_square1",       //�s��1
    "north"  : __DIR__"nivi_road1",         //�ԧ��D��1
    "west"   : __DIR__"nivi_road3",         //�ԧ��D��3
]));
       
            setup();
replace_program(ROOM);
}


