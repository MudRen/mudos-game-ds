#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�ѱ��J��"NOR);

 set("long",@LONG
�o�̬O�ѱ��ĤQ�C�N�̤l���𮧳���, �u���Ǥ������]�۷�
��²��, ���F�@�j�i�q�Q�H�~�N�u���@�ǳ��ª����M��ȥH��
�@���C�ɶ즨���j��, �b�o�̩��_���N�i�H��F�ѱ��̤l�����|
���Ҥνm�Z��, ���F�h�i�^��Q�K�N�̤l�����.
LONG
    );
 set("exits",([ "north":__DIR__"bird10",
                "east":__DIR__"bird7",
    ]));
set("objects", ([__DIR__"npc/bird_apprentice" : 3+random(3),
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}

