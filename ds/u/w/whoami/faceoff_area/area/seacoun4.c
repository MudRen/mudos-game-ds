#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�L����");
set("long",@LONG
�A�����e�N�O�L����F, �u���H�鬤��, ��B���O�s���n, 
�i���o�̬O�@�Ӭ۷��c�a���Ӵ�, ���L�T�~�e�i���O�o��, �T�~
�e�o�̳B�B�O�Q��, ��������L�c�a�W���~�N��g�禨�ӷ~����
, �~�����Ѫ��L����, �q�o�̩��_�|����F�q, ���n�h�|�쳽��
��.
LONG
    );
 set("exits",([ "north":__DIR__"seacoun5",
		"west":__DIR__"seacoun3",
		"south":__DIR__"seacoun20",
		"east":__DIR__"seacoun29",
]));
 set("objects", ([__DIR__"npc/seaguard" : 2,
    ]));

 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}             
