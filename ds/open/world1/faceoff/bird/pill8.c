#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�j�U"NOR);

 set("long",@LONG
�q�o�̩��n���i�H��ѱ��M�Ĥ@�����ħ���, ���_�h�i�H
�^��j�U����������, ���L�o�̵̨M�i�H���쨺�ڤj�j���W�l, 
���ޫ���, �٬O�h�ݬ��ħ��ǧa.
LONG
    );
 set("exits",([ "northwest":__DIR__"pill6",
		"northeast":__DIR__"pill12",
                "south":__DIR__"pill10",
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
