#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_���D"NOR);
 set("long",@LONG
�o�̤w�g����F�o���������_���D�����Y�F, �A���e���N
�O�M�����Ѥѱ������̥𮧪��q�Q�F, ���_��èS���ǥX�n�x
���n��, ��M�����̲`�����Ȥ��D.
LONG
    );
 set("exits",([ "north":__DIR__"walk7",

            "south":__DIR__"walk3",

            "east":__DIR__"bed4",
]));
 set("objects", ([__DIR__"npc/prayer" : 2,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
