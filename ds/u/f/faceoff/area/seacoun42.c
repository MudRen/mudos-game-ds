#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�n�L���y�f");
set("long",@LONG
�A��F�o�̤~���D�O����Ʃ��F, �A�ݨ�@�Ӳ�ҥ���
�ӫȭ��|�u�j�n!  �]�\�N�O�]���o�ˤ~���F�ӫȭ̧a? �ܤ�
�h��, �O�D���a���y�[�d!
LONG
    );
 set("exits",([ "west":__DIR__"seacoun41",
]));
 set("objects", ([__DIR__"npc/boatman" : 1,
    ]));
  set("no_clean_up",0);
 set("outdoors","land");
 setup();
}            





