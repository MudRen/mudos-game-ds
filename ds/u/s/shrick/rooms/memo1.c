// memery_st1.c
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
                "east"    : __DIR__"memo2",
               "west"    : __DIR__"center",
                ]) );
        set("outdoors","workroom.c");
        setup();
        replace_program(ROOM);
}
