#include <room.h>
inherit ROOM;
void create()
{
 set("short","���h��");
 set("long",@LONG
�x? �A�o�{�e�����q�D���G���@�I���u�q�a�O�W�_�X��, 
�ݨӦ��ǥȾ�, �A�̦n�L�h�ݬ�.
LONG
    );
 set("exits",([ "back":__DIR__"secret2_14",
                "pass":__DIR__"secret4_2",]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
