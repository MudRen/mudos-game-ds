#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�q�Q"NOR);
set("long",@LONG
�o�̬O�ѱ����ѨӳX�̥�ͪ��F�k��ɦ�, �A�o�{�o�̥�
�ͤj�����O�Q�U�j�s���C��, �]�\�A�i�H�ݤ@�ݥL�̤Q�U�j�s
�����I, �۫H�L�̤@�w�ַN�i��..
LONG
    );
 set("exits",([ "north":__DIR__"bed3",
            "west":__DIR__"walk5",
]));
 set("objects", ([__DIR__"npc/traveller" : 3,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             
