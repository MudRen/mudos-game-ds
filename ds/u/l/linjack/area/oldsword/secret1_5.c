#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�o��Q�������t, �A�Y���I�Ӥ���, �򥻤����D�e�������p,
�q�D�ܯ�, �����D�t�äF����Ⱦ�..........�A�Pı�o��A���n
�䪺����G���O��ߪ�.
LONG
    );
 set("exits",([ "east":__DIR__"secret1_6",
                "northwest":__DIR__"secret1_3",
                "south":__DIR__"secret1_8",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
