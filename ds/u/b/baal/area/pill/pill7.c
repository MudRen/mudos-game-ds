#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�U"NOR);

 set("long",@LONG
�o�̬O�ѱ��w�b�@�����_��j�U, �A�`�N��o�̪��C�Ȥw
�g�֤F�ܦh, �i���o�̤ѱ��ä���~�}��, �ܦ��i��ѱ��w�b
�@�����k������b��.
LONG
    );
 set("exits",([ "southwest":__DIR__"pill5",
                "southeast":__DIR__"pill11",
                "north":__DIR__"pill9",
    ]));
 set("item_desc",([
        "�W�l" : "�@�ڤj�j���W�l, �q�o�Ө��׬ݤ��X�����򲧱`\n", 
    ]));
// set("objects", ([__DIR__"npc/birdguard" : 1,
//    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}

