#include <ansi.h>
inherit ROOM;

void create()
{
set("short","�R�����s���n");
        set("long", @LONG
�o�O�R�����s�����n��A�A���n���N�O���ФF�A�o����}�l���@�ǳ³�
�b���ӭ��h�C�³��O�R�����̤j���׮`�A�C�~�����A�Ҭ��F���³��Ө��W��
�w�C�o�̪F�_�䦳�@�����j���A�١A���O�R�����������a�C
LONG
        );
        set("exits", ([
     "north":__DIR__"al4",
     "west":__DIR__"al6",
     "southwest":__DIR__"f00",
]));
        set("objects", ([
        __DIR__"npc/sparrow" :2,
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

