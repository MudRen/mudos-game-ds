#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", CYN"�@���ȴ� - �G��"NOR);
        set("long", @LONG
�@�W�ӤG�ӡA�����U����^�󬰿@�p�A�G�Ӫ�����O
�ѫC�˩ҽs���A�L���������q�_���j�J�A�Ӧb���㲴����m
�A���ۤ@�쨭��ʥ��m���~�l�A�L������í���ӤS����o�b
���A�]�\�A�ӦP�L�k���k��..
LONG
        );
        set("exits", ([   "down":__DIR__"ten15.c",
]));
      set("objects", ([__DIR__"npc/chen_chi" : 1,
    ]));
           set("room_type","hotel");       //���]
        set("no_fight", 1);
        set("light",1);
        set("no_clean_up", 0);
        setup();
}
