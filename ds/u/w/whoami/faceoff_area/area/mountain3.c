#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIG"�ùD"NOR);

 set("long",@LONG
�o�̬O�@�ӤT�ø��f, ���F���@���p�p�����¥۪O��, ��
��h�O�@���ѩx���׽r���̹D, �ө��n�h�q���A�ҨӪ��D��,
�A�|�ؤ@��, �Q�U�j�s�ۦW���k���N���ު��ݥߦb�A�����e, 
�A�ߤ���b�����w�D�N�n�����@��....
LONG
    );
 set("exits",([ "south"__DIR__"ten_mountain3",
                "east":__DIR__"ten_mountain5", 
                "west":__DIR__"ten_mountain8",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
