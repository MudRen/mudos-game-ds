#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U���F�D");
        set("long", @LONG
�o�̬O�a�U�����F���D�������A�b�o����W���\�h�q�a�W�t������
�[�����a�W�H�A�n�䪺�ȩ����\�h���a�W�D���[���Ϊ��H��J�A�]���\
�h���ũx���b���d�J�L�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "west":__DIR__"sec5.c",
     "east":__DIR__"sec7.c",
     "south":__DIR__"waiter.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
