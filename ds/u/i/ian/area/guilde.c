#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"���N�t�Y"NOR);
 set("long",@LONG
�o���q�V�ѱ����������e�j���Y�����ƥH�ʭp�����N, �b���D�W����
��, ��s��, �b�A�Y�W���R��, �ȺޥL�̨èS���ˮ`�A���|��, �A���T��
�O�L�L���P��`��. 
LONG
    );
 set("exits",([ "south":__DIR__"guildc",
                "north":__DIR__"guildf",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
