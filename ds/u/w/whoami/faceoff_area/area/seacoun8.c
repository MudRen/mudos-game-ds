#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���F�q-�e�x");
set("long",@LONG
�o�̴N�O���F�q�F, �A�o�{�o�̰�n�F�ܦh�@�]�@�]���f
��, ���O�٥��g���F�q�ַǪ��f��, �]���S��k���, ���L�p
���ݨ�, ���F�q���ʧ@�ٯu�C...
LONG
    );
 set("exits",([ "enter":__DIR__"seacoun9",
		"out":__DIR__"seacoun7",
]));
 set("objects", ([__DIR__"npc/seaguard" : 2,
		  __DIR__"npc/guard_leader": 1,
    ]));

 set("no_clean_up",0);
 set("light",1);
set("no_fight",1);
 setup();
}             

