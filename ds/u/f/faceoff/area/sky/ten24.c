#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",CYN"�s���̹D"NOR);
 set("long",@LONG
�j�N�����n�̹D -- �s���̹D�N�O���o�̤F, �b�j��, 
�o�O�ߤ@�@���q�������Ѱꪺ�D��, �o�@���W, �s���̹D��
���s��p, �F�_�A�L, ��Ѿ�......�������I, �o���D����
�b�O�j�N�u�{���̨Ψ�d.
LONG
    );
 set("exits",([  "northwest":__DIR__"ten25",
                 "south":__DIR__"ten23",
    ]));
 set("objects", ([__DIR__"npc/sky_guard" : 2,
    ]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

int valid_leave(object me, string dir)
{
        if( dir== "northwest" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}

