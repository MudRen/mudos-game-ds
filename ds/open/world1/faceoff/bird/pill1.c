#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j��"NOR);

 set("long",@LONG
�o�̬O�ѱ��M�Ĥ@�����j���f, �ۤѱ�������L��k�M��
�W�����~����, �u�Ѥѱ��M�Ĥ@���|�s��Q�U�j�s�s�s����, 
�M�Ĥ@���O�ثe�ѱ�������|��ͦs������, �A���F���Y�i
�i�J�ѱ�, ����h�O�Q�U�j�s.
LONG
    );
 set("exits",([ "east":__DIR__"pill2",
		"west":__DIR__"ten42",
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 2,
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}