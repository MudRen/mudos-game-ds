#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U���_�D");
        set("long", @LONG
�o�̬O�@����������D�A�b��D���|�P���\�h���ê��p���A���L��
�i�u�e�o�U�@�ӤH���k�A�n��O���a�U�����������������A�Ӧb�_��h
�O���_�����A�b�o�̦��@�ǩU���^�����A���b�V�O������D�O�����b�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec5.c",
     "west":__DIR__"court.c",
     "north":__DIR__"sec11.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
