#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�U"NOR);

 set("long",@LONG
�o�̵̨M�i�H���쨺�ڤj�����Ъ��W�l, �A�P�ɤ]�o�{��
�n��ǨӤ@�}�ĭ���, ���G�n��O�ѱ��M�Ĥ@�����ħ���, �]
�\�A�i�H�h���n�I�ħ�.
LONG
    );
 set("exits",([ "north":__DIR__"pill4",
		"southeast":__DIR__"pill8",
    ]));
 set("item_desc",([
        "�W�l":"�@�ڤj�j���W�l, �A�o�{�W�����@�Ǧr:\n"
	          	HIY"�|���k��, �|���B�{.\n"NOR
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);                      
}
