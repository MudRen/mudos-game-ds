#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_�ٮp"NOR);
 set("long",@LONG
�_�ٮp�N��o�̵����F�A�ө��_���s���N�O�ۦW���s��
�̹D�F�A�ѩ�w�g�L�F�_�ٮp�A�o�̦A�]�Pı����_�ٮp�W
�j�P������F�A�ө��n���D���h�|�^��_�ٮp.
LONG
    );
 set("exits",([  "north":__DIR__"ten24",
               "southwest":__DIR__"ten22",
             "southeast":__DIR__"ten21",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

