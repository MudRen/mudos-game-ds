#include <ansi.h>
inherit ROOM;

void create()
{
set("short","�R�����p��");
        set("long", @LONG
�o�O�@���g�L�p���Ъ��d�g�p�|�A�o���񪺹A�٤�_�_��N�y�L�֤F�@
�ǡC�b���䦳�۴X���L�C���b���ʡA�ԳҦa½�ۤg�[�C�٦��X�Ӥ��ýs����
�x�l�N��b���̡A�ݨӬO�Ħ����G�ɥΪ��u��C
LONG
        );
        set("exits", ([
     "east":__DIR__"al5",
     "west":__DIR__"al7",
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
