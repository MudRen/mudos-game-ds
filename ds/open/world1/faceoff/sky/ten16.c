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
        set("room_type","hotel");       //���]
        set("no_fight", 1);
        set("light",1);
        set("no_clean_up", 0); 
        set("no_drop",1);
        setup();
}

void init()
{
     ::init();
     if( sizeof(filter_array( children(__DIR__"npc/chen_chi"), (: clonep :) )) == 0 ) 
     new(__DIR__"npc/chen_chi")->move(this_object());
}
