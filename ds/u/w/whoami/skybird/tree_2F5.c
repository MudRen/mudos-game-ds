#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","���N��");

 set("long",@LONG 
�o�̴N�O���o�X�@�P���t�𮧪����N��, �o�̪����t�𮧨�
�A�����N�P��̭���F�@����I�F�ʪ����N, �A�J�ӬݤF�ݥ޾�
, �o�{���O�D�`�u���������öQ���󸭩ί��һs����. �i����
�������N�]��q���Ĥ���.....
LONG
    );
 set("exits",([ "west":__DIR__"tree_2F1",
                "east":__DIR__"tree_2F1",
                "north":__DIR__"tree_2F5",
                "south":__DIR__"tree_2F1",
    ]));
set("objects",([__DIR__"npc/holy_eagle":1,

]));
 set("no_clean_up", 0);
 set("no_map",1);
 setup();
 replace_program(ROOM);
}

