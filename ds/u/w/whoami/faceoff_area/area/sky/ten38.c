#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",YEL"�����p"NOR);
 set("long",@LONG
��W�F��a���Pı���A�S�i��j�W, �����S���`�N��A
�������٦��@��θ�_�����ѭ�, �ӳo�̪������]�������[
, �u���A�}�U�A��@��,�Q���N�O�F�_�A�L�F�a, �Ө��ؿv��
�ثe�O�b�A���n��U��X�V�B, �����D�쩳�O����?
LONG
    );
 set("exits",([  "north":__DIR__"ten37",
    ]));
set("objects", ([    __DIR__"npc/monk" : 1,
]));

set("no_clean_up",0);
set("outdoors","land");
 setup();
 replace_program(ROOM);
}

