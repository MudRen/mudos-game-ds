#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�q�Q"NOR);
set("long",@LONG
�o�̬O�ѱ����ѨӳX�̥�ͪ����F��ɦ�, �A�o�{�o�̥�
�ͤj�����O�@�۪��ѱ��Ю{, �]�\�A�i�H�ݤ@�ݥL�̤ѱ�����
�q�ΫH��..
LONG
    );
 set("exits",([ "north":__DIR__"bed2",
            "south":__DIR__"bed4",
]));
 set("objects", ([__DIR__"npc/prayer" : 3,
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}             