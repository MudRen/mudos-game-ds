#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���@�k��"NOR);

 set("long",@LONG
�A�S���W���F�@�q�Z��, �o�{�A�����ǥX�{����, 
�A�S�ݤF��, ����! �O�ն�! ��ӧA�w�g��F���h���F,
�A���W�ݤF��, �٬O�ݤ��쳻�b����, �A���T�`�Ȱ_��,
���O�A�߷Q�J�M�w�g��o�򰪤F, �����٭n�U�h? ��O
�A�M�w�w���Y���~�򩹤W��, �b�A���񦳭Ӥp�}�C 

LONG
    );
 
 set("exits",(["up":__DIR__"bird5",
               "down":__DIR__"bird3",
               "enter":__DIR__"hole",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
