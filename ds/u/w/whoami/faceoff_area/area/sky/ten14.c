#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p�ĩ�-����");
 set("long",@LONG
�@���i���ǡA������`�����w�Q�@�����Ĩ��γ��~����
�������N�F�A�b��n�p�s���Ѱ��O�@�Ӧ~���L�G�����֦~
�H�A�@��������A�ݨӴN�O�o���ĩ����D�H�F.
LONG
    );
 set("exits",([   "out":__DIR__"ten13",
    ]));
 set("objects", ([__DIR__"npc/doctor" : 1,
    ]));

set("no_clean_up",0);
set("light",1);
 setup();
}


