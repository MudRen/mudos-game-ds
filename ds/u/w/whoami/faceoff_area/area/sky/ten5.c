#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�_�ٮp"NOR);
 set("long",@LONG
�o�̦��@�y�C�⪺�J���A�ݰ_�ӬO�ѫC�Х۩Ҩ覨�A�q
���b�H�~���Ӭݦ��G�O�@���i���R�������s�A�����J�u�ݮ�
�p�͡A����������ݰ_�Ӧ��G�|�H�ۭ���Ÿ�X�A�A�]�P�ɥi
�H�ݨ��A�����N�O�������x�A�ݫC�s���ˤl�A�����G��ĵ
�i�۷Q�n����ӤJ�����c���{�A�ө��F���@�y���G�O���q��
�ؿv....
LONG
    );
 set("exits",([  "northwest":__DIR__"ten21",
              "west":__DIR__"ten7",
               "southwest":__DIR__"ten3",
                 "eastdown":__DIR__"ten42",
    ]));
 set("objects",([__DIR__"npc/sky_guard" : 2,
                 __DIR__"npc/sky_leader" : 1,
    ]));

set("no_clean_up",0);
set("outdoors","land");
 setup();
}
int valid_leave(object me,string dir)
{
        if( dir== "eastdown" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me,dir);
}



