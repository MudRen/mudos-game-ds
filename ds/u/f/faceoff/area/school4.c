#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�˪ŮѰ|�G��"NOR);

 set("long",@LONG
���ߧA�ש�q�L�F�g�c, �˪ŮѰ|�w�g�S������i�H�ЧA��
�F��F, �Ʊ�A�w������L�M�q, ��uDs���W�h, �����@�ӥO
�H�q�ت��n���a! ���O! ���O! 

LONG
    );
 set("exits",([ "in":"/open/world1/tmr/area/inn_2f", 
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}