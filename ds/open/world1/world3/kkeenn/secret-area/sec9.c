#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U�����");
        set("long", @LONG
��^�U�|�P�A���Ѵ_�j��������賡���J�𮧦s�b�ۡA��ΫT���A�H
�s���H�x�n�A���H�@�ѻP��~�I�M���P���Pı�A Secret City�G�M���O�@
�y���v�j���A���ۦU���U�˪���^�A�C���@�B�N���H�@�غI�M���P���Pı
�A�o......���ӬO���b 150�~�e�̬y�檺�ڤ۵{���[�c�F�a�H
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "east":__DIR__"sec8.c",
     "north":__DIR__"equip.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
