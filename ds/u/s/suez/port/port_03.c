#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�V��p�D");
        set("long",@LONG
�o���񪺱V���W�Q�}�P�X�@���������p���A���۳o�p���N�i�H��F�O
��A�o���p���i��]�O���F�o�ӥت��~�v�_���a�C
LONG 
);
        set("exits",([
            "east":__DIR__"port_06",
            "westup":__DIR__"port_02"
                ]));
        set("world","world1");
        set("outdoor","mount");

        setup();
        replace_program(ROOM);

}

