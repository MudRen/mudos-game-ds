#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s����");

 set("long",@LONG
�A���ǴN�O�q�V�s�f���k��, ���_�h�q�V�Q�U�j�s������
�������p, �A�o�{�A���|�P���O�@�ǰ~�k������, �ߤ@���X��
���G�u�����_���F.
LONG
    );
 set("exits",([ "north":__DIR__"ten2",
		"down":__DIR__"ten_mountain4",
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}
