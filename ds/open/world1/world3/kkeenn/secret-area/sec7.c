#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U���F��");
        set("long", @LONG
�o�̬O�a�U�����F���D�����Y�A�b�o����W���\�h�q�a�W�t������
�[�����a�W�H�A�_�䪺�q�D�q���a�U�����M���q�|�A�\�h���q�u���H�E
�~�쨺�̥h�A�H��K�u�@�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "west":__DIR__"sec6.c",
     "north":__DIR__"min1.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
