#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�U"NOR);

 set("long",@LONG
�o�̵̨M�i�H���쨺�ڤj�����Ъ��W�l, �A�P�ɤ]�o�{��
�n��ǨӤ@�}�@�}�N�J�����D, �ݨӫn��O�ѱ��w�b�@�����w
�b��, ���u��, �o�Ѩ��D���A�Q�R...
LONG
    );
 set("exits",([ "north":__DIR__"pill4",
                "southeast":__DIR__"pill8",
    ]));
 set("item_desc",([
        "�W�l" : "�@�ڤj�j���W�l.\n",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
