#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��Ʈv��");
set("long",@LONG
�o�̬O���D���F�����䪺��Ʈv��, �o�̻P�F�Ʈv����
�P���O....�o�̨S���H! �o�زצ~���o���i�}�檺���, �~�M
�̭��n�����F�q��Ʈv�S��....?!
LONG
    );
 set("exits",([ "east":__DIR__"seacoun11",
]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
