#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ���|"NOR);

 set("long",@LONG
�A�i�H�b�o�̬ݨ�T�T��⪺�ѱ��ĤQ�K�N,�ĤQ�E�N��
�l�b�o�̽ͤѻ��a, �b�L�̪����Ǧ��@�ǲ��I, �o�̯u�i�H��
�O�ѱ����𮧫ǤF, �A�߸̤��T�����e�����H, �P��@�Ѳ��W���Y
��, �o�~�O�A�ߤ����ѱ���!! 
LONG
    );
 set("exits",([ "northwest":__DIR__"eastroad6",
                "southwest":__DIR__"eastroad4",
    ]));
set("objects", ([__DIR__"npc/bird_apprentice" : 2,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
