#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U���_���D");
        set("long", @LONG
�o�̬O�@����������D�A�b��D�����䦳�@�a���b�{�{�ۻ��H���O
�i�O�A��ӬO�����j�W���S��D�㩱�A�n��O���a�U�����n���D�����A
�Ӧb�_��h�O�����D�Фl���h�A�b�o�̦��@�ǩU���^�����A���b�V�O��
����D�O�����b�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec10.c",
     "north":__DIR__"sec12.c",
     "west":__DIR__"combat_shop.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
