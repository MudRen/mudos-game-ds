#include <room.h>
inherit ROOM;
void create()
{
 set("short","�շt���q�D");
 set("long",@LONG
�o��Q�������t, �A�Y���I�Ӥ���, �򥻤����D�e�������p,
�q�D�ܯ�, �����D�t�äF����Ⱦ�..........�A���F�_����G�O
���X��.
LONG
    );
 set("exits",([ "northwest":__DIR__"secret1_4",
                "northeast":__DIR__"secret1_9",
                "south":__DIR__"secret1_6",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
