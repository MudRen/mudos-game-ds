#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�p�|"NOR);

 set("long",@LONG
�o�̬O�ѱ��ȩЩ��F�n���X�f�ҳq�V���p�|, �u���Ťѥ�
��, �b�Ǳ`����ʦ~���C, �A�ߤ����M�ư_���Z�Y�O�ܬ��o
�y�ܨ�, �u�O�n�@�T���R���M���ѤW������!! 
LONG
    );
 set("exits",([ "northeast":__DIR__"eastroad6",
                    "southeast":__DIR__"eastroad4",
    ]));
set("objects", ([__DIR__"npc/bird_apprentice" : 2,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
