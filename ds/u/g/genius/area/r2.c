#include <ansi.h>
inherit ROOM;

void create()
{
set("short",HIG"�����a"NOR);
        set("long", @LONG
�o�̬O�R�����������a�A�@�i���N�i�H�Pı�P�M�`���A�٤��P�C�R����
�������O�@�W���g�@�ƪ��~�ѾԤh�A���M��O���w�j���p�e�A�����W���M�O
���ۤ@�ѭ^������C�e�誺����W���F�@�Ư}�ª����ҡA�O�����~���ɭԥM
�q��L�d�U�Ӫ��_���C
LONG
        );
        set("exits", ([
      "west":__DIR__"al4",
]));
        set("objects", ([
        __DIR__"npc/mayor" :1,
]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
