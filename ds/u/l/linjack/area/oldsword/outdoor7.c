#include <room.h>
inherit ROOM;
void create()
{
 set("short","�U�D");
 set("long",@LONG
�A�q�۪����W���F�U��, �Ө�@���U�D����, �j������
�T�ӤH���e��, �o���U�D�����D�O�q����̪�, �̦n�p�ߤ@
�I����n.
LONG
    );
 set("exits",([ "west":__DIR__"outdoor8",
                "eastup":__DIR__"outdoor6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}