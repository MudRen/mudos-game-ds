#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short",HIR"�j��"NOR);
 set("long",@LONG
�o�̬O�ѱ��M�Ĥ@�����j���f, �ۤѱ�������L��k�M���W
�����~����, �u�Ѥѱ��M�Ĥ@���|�s��Q�U�j�s�s�s����, �M��
�@���O�ثe�ѱ�������|��ͦs������, �A�������Y�i�i�J�ѱ�
, ����h�O�Q�U�j�s.
LONG);
 set("exits",([ "enter":__DIR__"pill2",
                "west":__DIR__"ten12",
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 2+random(2),
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 create_door("enter","�p���","out",DOOR_CLOSED,"nokey");
}

