#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ��ѥ���"NOR);

 set("long",@LONG 
�o�̴N�O�G�Q�~�e�W�_���򪺤ѥ���, �ѱ����j�p�аȳ��O
�g�Ѧ��B�V�ХD���i, �{�p�j�N�����Ҧ���, �]�]���p���ӾD��
�x��������, ���L����w�g�S���j�ɪ����p, �o�̲{�b���F�ѱ�
��Z�@�����ХD�H�~, �F��誺�j�Y�]�q���U�B�����n�]�I. ��
�_�h�O���W���ѱ��t�u....
LONG
    );
 set("exits",([ "east":__DIR__"eastroad1",
                "west":__DIR__"westroad1",
                "north":__DIR__"bird6",
                "south":__DIR__"bird2", 
    ]));
 set("objects", ([__DIR__"npc/yuh_chyr_wanq" : 1,
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}


