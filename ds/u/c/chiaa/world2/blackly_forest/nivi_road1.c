//u/c/chiaa/world2/blackly_forest/nivi_road1.c

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
    "south"  : __DIR__"nivi_road2",     //�ԧ��D��2
    "north"  : __DIR__"garrison2",      //�n�u�B2
    "east"   : __DIR__"parade1",        //�m�߰�1
]));
       
            setup();
replace_program(ROOM);
}
