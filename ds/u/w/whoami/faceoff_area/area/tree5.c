#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�|");

 set("long",@LONG
�A�V�}�U�ݤF�@��, �u���o�Ӥp�|�W��������~�����h�F
�ܦh, �i���o�̩Ҩ��L���H��h, �A���G�b�_�軷�B�ݨ�F�@��
�p��, �Ӧb�F��o���G���@�˰����X�_�����, �A�ߩ��@��, ��
�Ӥ��|�N�O�Ѥѥj��a....?
LONG);
 set("exits",([ "west":__DIR__"tree3",
                 "north":__DIR__"tree7",
                 "northeast":__DIR__"tree9",
    ]));
 set("objects", ([__DIR__"npc/woodguard" : 2+random(3),
    ]));
 set("no_clean_up",0);
 set("outdoors","land");
 setup();
 replace_program(ROOM);
}

