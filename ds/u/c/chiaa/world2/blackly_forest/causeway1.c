//u/c/chiaa/world2/blackly_forest/causeway1.c

#include <ansi.h>    
inherit ROOM;

void create()
{
        set("short", "�ۤl��");
        set("long", @LONG
�A���b�@���ѸH�ۤl�Q�������W,�T������,�ܮe���^��,
���_�����B,�����F�}�}�կ������,�V�O�L�h,���G����V��!!
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
    "north"  : __DIR__"road6",       //�����p��6
    "east"   : __DIR__"parting",     //���[��
    "south"  : __DIR__"path2",       //�p�|2
]));
       
            setup();
replace_program(ROOM);
}
