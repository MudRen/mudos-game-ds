#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"���p-�s�y"NOR);
 set("long",@LONG
�o���s���O�s�����p�Ω_�ٮp���D�n�D���A���_�|�q��
�ᦳ���W�����p�A�ө��n�h�|�^��Q�U�j�s���̰��p�A�_��
�p....
LONG
    );
 set("exits",([  "southup":__DIR__"ten21",
                     "northup":__DIR__"ten50",
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

