#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�o��Q�������t, �A�Y���I�Ӥ���, �򥻤����D�e�������p,
�q�D�ܯ�, �����D�t�äF����Ⱦ�..........
LONG
    );
 set("exits",([ "southeast":__DIR__"secret1_7",
                "southwest":__DIR__"secret1_3",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
