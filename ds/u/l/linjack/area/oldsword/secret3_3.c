#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");
 set("long",@LONG
�A�Ө�F�@�������̭�, �o�̤��򳣨S��, �A�`ı�o�A�Q
�o�Ӹ޲����a�D���M�ˤF.
LONG
    );
 set("exits",([ "south":__DIR__"secret3_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
