//u/c/chiaa/world2/blackly_forest/road6.c

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
        set("exits", ([ /* sizeof() == 1 */
    "south"    : __DIR__"causeway1",     //�ۤl��1
    
]));
           setup();
replace_program(ROOM);
}
