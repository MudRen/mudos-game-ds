#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ���|"NOR);

 set("long",@LONG 
�o�̬O�ѱ�������h�ӫ�誺��|, �A�o�{��W�����F�m��
�ѼS�P�k�Ϊ��F�], �H�ΥΨӽm�߻��\���ۼ�, ��M�o�̬O�ѱ�
�̤l���m�߳��a, �A�̦n�����o��, �H�K�Q��p��Ӫ��P���W��
, �����P���O����������....
LONG
    );
 set("exits",([  "northeast":__DIR__"eastroad5",
                 "northwest":__DIR__"eastroad7",
                 "south":__DIR__"eastroad3",
    ]));
set("objects", ([__DIR__"npc/bird_apprentice" : 3+random(3),
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM); 
}
