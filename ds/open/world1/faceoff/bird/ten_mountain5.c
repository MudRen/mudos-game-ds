#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�۪O��"NOR);

 set("long",@LONG
�ܤ֥ثe�o�����ٻᬰ�e��, �A���k���O�Q�U�j�s���s��, 
�A���G�w�g��i�F�Q�U�j�s�d�U���������@, �ר�O�A��Y��
�O, �F�誺���|���G��o�̤S���F�\�h, �A�ߤ������D�쩳�n
���n���U�h...
LONG
    );
set("exits",([ "east":__DIR__"ten_mountain6", 
            "west":__DIR__"ten_mountain4", 
    ]));
set("outdoors","land");
set("no_clean_up",0);
 setup();
 replace_program(ROOM);
}
