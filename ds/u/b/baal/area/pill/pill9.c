#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���"NOR);

set("long",@LONG
�o�̬O�x���H�M�ХD�ҤH�����, �A�o�{�o�̩M���U�@��, 
���O�H�C�۬���, �i�O�o�̫o�h�F�@�Ƿ��ɪ���, �Q�ӬO�]
���o�̤]��۱ХD�ҤH�a?
LONG
    );
 set("exits",([ "south":__DIR__"pill7",
    ]));
//set("objects", ([__DIR__"npc/master_walf" : 1,
//    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();                  
}
