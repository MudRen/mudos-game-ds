#include <room.h>
inherit ROOM;
void create()
{
        set("short", "���D����");
        set("long", @LONG
�o�̬O�a�U�����D���a�A�A�ݵۦb�Y�W���R���Q�O�A���o�u������
�u�O�H�P���X�@�ѷŷx���Pı�A�b�A�e�������j�F�o�W���ۤ@��~��
�w�����ѤH�a�A�A�ݵۥL�A��M�@�}���W���P�˴�W���Y�C
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "west":__DIR__"sec12.c",
     
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
__DIR__"npc/king.c"    :1,
]));

        setup();
        replace_program(ROOM);

}
