#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�s���̹D"NOR);
 set("long",@LONG
�q�o�̦A���_�h, �N�O���٤ѤU�Ĥ@�I���s��p�F, �j
�ɿv�s���̹D��, �N�ݳo�@�q���˳̬��G��, �ҥH��ɫU��
���m �������s��p, �L���L��Ѿ� �n�N�O�o�@�q�̹D���v
���̨μg�ӤF.
LONG
    );
 set("exits",([  "north":__DIR__"ten26",
                 "southeast":__DIR__"ten24",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

