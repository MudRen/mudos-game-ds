#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);

 set("long",@LONG
�A�n���e���b�k���W���@�B�y�L�Y�X������, ��
�O�A�M�w�b���y�@��, �A���U�F�@�U�|�P, ���F����
�٬O����, �A���T��ҳo�k�����W�쩳������F��, �A
�S���U��F��, �o�{�A�w�g�P�a�����n�@�q�Z���F, �A
�ߤ��Q���٭n�~�򩹤W����?

LONG
    );
 
 set("exits",(["up":__DIR__"bird3",
               "down":__DIR__"bird1",
     ]));
 set("no_clean_up", 0);
 set("limit_dodge",15);
 setup();
 replace_program(ROOM);
}           
