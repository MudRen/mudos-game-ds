#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIC"�R�����s��"NOR);
        set("long", @LONG
�o�̴N�O�R���������a�����f�F�A�]���o�̪��a������e��A���A�a�S
��A���������̥�ͪ����ҡC�o�̪����o���P����f���@�Ʊƪ����C�o��
�ؤF�\�h������A�զ⪺����M���⪺���Φ��ܧ��������C����O�o��
���l���_���A�o�̪��������L�a��j�F�\�h�A���D�]���P���L�A�o�̪�
�����Y�_�Ө㦳�@�ѿW�S������A�O�H�N�S���ɡC�پڻ��㦳���_�����ġA
�Ʀܯ����v�Y���]�k�ҳy�����ˮ`�C
LONG
        );
        set("exits", ([
     "north":__DIR__"al3",
     "south":__DIR__"al5",
     "east":__DIR__"r2",
     "west":__DIR__"r3",
]));
        set("objects", ([
        __DIR__"npc/villager1" :5,
]));


        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
