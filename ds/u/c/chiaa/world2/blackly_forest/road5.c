//u/c/chiaa/world2/blackly_forest/road5.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", "�����p��");
        set("long", @LONG
�A�����b�@���L�����p��,�|�g�����ۤ@���H��,�ٳz�ۤ@���H��,
�ݨ쪺�����ɬO������ݤ��ƲM��,���n�g���`�B�@�h,��G�դ@��,
�u�Ȩ��o�i�h,�䤣����X��...
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
    "west"         : __DIR__"road3",         //�L���p��3
    "north"        : __DIR__"road4",         //�L���p��4
    "southeast"    : __DIR__"causeway2",     //�ۤl��2
]));
       
            setup();
replace_program(ROOM);
}


