#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ���|"NOR);

 set("long",@LONG
�o�̦A�V�_���N�O�t���t�W���ѱ��t�u, ���F�_�h�O�Ѥѥj
��, �A�i�H�ݨ����O�B�z�ѱ��̤l�ͬ����J�٩M�p��, �o��
���O�s����h�a�誺��|, �A�o�{�o�̯u�O�W�ƨ�ꪺ[ �T
�B�@�^, ���B�@��. ]
 
LONG
    );
 set("exits",([ "northeast":__DIR__"tree1.c",
                "west":__DIR__"bird7.c",
                "north":__DIR__"water.c",
                "south":__DIR__"bird5.c", 
    ]));
 set("objects", ([__DIR__"npc/birdguard" : 2,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
