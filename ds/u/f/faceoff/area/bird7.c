#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ��J��"NOR);

 set("long",@LONG
�A�@��i����, �N�o�{�ѱ���Z�@�����J�ٳ��M�p���_�S, 
��Ӥѱ��̤l���ɳ��O�a�Q�b�Ť���! �A���T�P��n��, �o�O
�P���L�̪��Ь��l����?�٬O����L����]? �q�o�̩��_���i
�w��ѱ����p��, ���F�h�i�H�^��ѱ���|.
LONG
    );
 set("exits",([ "north":__DIR__"bird8",
                "east":__DIR__"bird6",
                "west":__DIR__"bird9",
    ]));
set("objects", ([__DIR__"npc/bird_apprentice" : 4,

    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
