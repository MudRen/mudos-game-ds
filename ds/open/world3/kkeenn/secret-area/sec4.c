#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U���n�D");
        set("long", @LONG
�@���ܱI�R����D�A���G���@�ɳ��ᵲ�F�A�b�o�ا������a��A��ԣ
�@�ӤH���S���O�H�L���������j�ӡA�A���߱��򪺬���_�ӡA�_��N�O��
��Secret City ���������F�A���I�@���٬O���¬��n�A�ҿױ����G���A�i
��N�O���{�b���߱��a�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec3.c",
     "north":__DIR__"sec5.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
