#include <room.h>
inherit ROOM;
void create()
{
 set("short","���h��");
 set("long",@LONG
�o�䪺���׬�M�U���F�@��, �ӥB�A�]�����n����w�ۤ~��e
�i, �����D���U�ӷ|�q������, �e���������G�Q�j�Y����F, �ݨ�
�A�o���M���j�Y�A��.
LONG
    );
 set("exits",([ "northwest":__DIR__"secret2_13",
                "pass":__DIR__"secret4_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
