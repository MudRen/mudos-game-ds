#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�Ķ�");

 set("long",@LONG
�q�o�̶i�h�N�O�ѱ����Ķ�F, �ۤѱ��Ь��H��, �N�@���O
�b�o�̺ش��ħ�, �ѱ�������, �M�Ĥ@�����J�Q�U�j�s��, �N��
�U�F�o���Ķ�.
LONG
    );
 set("exits",([ "east":__DIR__"med2",
		"south":__DIR__"med21",
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 2,
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);                      
}