//u/c/chiaa/world2/blackly_forest/nivi_road3.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "�D��");
        set("long", @LONG
�A�����b�Ԫ̧����@���D��,���W����H��A�o�� 
�N�~���X��,���G���s�۫ܰ���ĵ�٤ߩM�n�_��!!
���䤣���B�i�ݨ�@���ө�!!
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "south"  : __DIR__"nivi_road4",        //�ԧ��D��4
    "east"   : __DIR__"nivi_road2",        //�ԧ��D��2
    "west"   : __DIR__"store",             //�ө�
]));
       
            setup();
replace_program(ROOM);
}
