#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�C�۴Y"NOR);

 set("long",@LONG
�۴Y��ǥ��O�u��, �ӭӪ�ض�C, �����۸y���P��, �a��ĵ��
�߬ݵۧA, ���n�ݳz�A���ߤ@��, �ݪ��A�����o��, �ݨӧA�b�o�u�n�ߤ�
�y�s���, �N�|�Q�o�Ǧu�ü����H��, �b���D�Ǧ��Ӷ���q��W��, ��,
�b�o��h�u�ê������U, �A���T�}�l�Ҽ{�ۤv���w��... 
LONG
    );
 set("exits",([ "east":__DIR__"center1",
                "west":__DIR__"center3",
                "northup":__DIR__"hall",
    ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}

