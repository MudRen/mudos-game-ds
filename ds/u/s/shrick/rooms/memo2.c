// memery_st2.c
#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"������"NOR);
        set("long",@LONG
  �o���Sù�����������C�O���n�������Ǥw�G����
�W�^���ҫت��A�o�����b�V���h�K�O�����]�A�̭�
���õ۳\�h��ƩM���m�C
LONG
        );
        set("exits", ([/*sizeof=2*/
                "west"    : __DIR__"memo1",
                "north"    : __DIR__"memo3",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
