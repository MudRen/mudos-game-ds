#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�A���_��M�F�賣���q�D�i�H��, �i�O�F�誺�q�D�Q�@�D
�۪����d��F, �ӥB���G�n�_�ͤ~����k�}��. ����n��h�N
�O�@�����Y.
LONG
    );
 set("exits",([ "east":__DIR__"secret3_4",
                "north":__DIR__"secret3_3",
                "southwest":__DIR__"secret3_1",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
