#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�o����G���@���p���i�H���U��, �ݰ_�ӫܰ~���ˤl,
�������~, �F�_�誺�q�D�O�ߤ@���X��.
LONG
    );
 set("exits",([ "northeast":__DIR__"secret2_2",
                "down":__DIR__"secret3_7",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);

}
