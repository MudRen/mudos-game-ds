#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�a�U���n���D");
        set("long", @LONG
�@�}�}�M�s���Ů�w�w���j�L�ӡA���B�b�o�̦n��ּ֤Ѱ�A�A���T
�߷Q�G�i�o�̪��H�ٯu�|�ɨ��A�S�Q�}�o�������G�M�A�X�𶢡I�j����
�~���A�����D�]�h���̤F�A�դj����D���M�ݤ���@�ӤH�v�A���������o
�F[ ���ߤu�@�g ]�ܡC
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
    "south":__DIR__"sec2.c",
    "north":__DIR__"sec4.c",
    "east":__DIR__"shop.c",
]) );
        set("light",1);

        setup();
        replace_program(ROOM);

}


