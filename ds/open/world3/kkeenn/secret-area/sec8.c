#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U����D");
        set("long", @LONG
�|�P�������Q���u���g�H�A���������w�w���عL�A���y�e�A�@�}�x�N
�ۤ��Y�ɰ_�A�a�W�W�r�������p���Y���G�]�ܦ����Z���f�o���A�o�̪���
�^²���i�B���H���P�ҡA���ۨ��ۨ���F�Ĥ@�a�s�u�D���������A���f��
�H�s�۹ꤣ�֡A�ݨӥi��O�ݩ�[ �D���[���� ]���H�a�H
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "east":__DIR__"sec5.c",
     "west":__DIR__"sec9.c",
     "enter":__DIR__"boot.c", 
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
