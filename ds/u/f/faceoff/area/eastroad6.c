#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ��ȩ�"NOR);

 set("long",@LONG
�o�̪��H�s�񤧧��@�I�֤F�\�h, �A���F�ݬ�, �S�����
��, ��ӳo�̴N�O�ѱ��@���۫ݭ��n�ӫȮɩҥΪ��j���ȩ�, 
�A�D��F�@�ѪѪ��ͷϨ�, �ߤ��P��ѱ���󻷤�ӫȪG�M
�O���p�ǻ�����§�ƶg��!! 
LONG
    );
 set("exits",([ "southeast":__DIR__"eastroad5",
                "southwest":__DIR__"eastroad7",
    ]));
set("objects", ([__DIR__"npc/bird_waiter" : 2,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
