#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","��l");

 set("long",@LONG
�o�̬O��l�����A�Ѱ�, �A�o�{���@�Ǩ��Ҫ����[�~���b��
�Ԫ��u�@, ���O�o�̪��g�[�u�����A�X�ѧ@, �N��A�V�O�u�@, 
�����]�۷���.
LONG
    );
 set("exits",([	"south":__DIR__"ten32",
		"north":__DIR__"ten30",
    ]));
 set("objects", ([__DIR__"npc/farmer" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();                    
}