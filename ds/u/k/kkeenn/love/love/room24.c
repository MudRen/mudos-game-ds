#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIC"�������E���}["HIW"�C"HIC"]"NOR);
        set("long", @LONG
�A�����b���������E���}�A�u���o�|�g�ɬO�@�������A���⤣������
�A�b�}�}�@�����������A���ۤ@��վv���C�����@���k�A�@���b�o������
��¶�۴N�O�񤣤F�o�����Ǥ��ءA�ݨӨ���k�l�]���۷��\�O.....
LONG
        );
        set("exits", ([ /*�����I[�{]file_name room18*/
//  "south" : __DIR__"room9", 
//  "northeast"  : __DIR__"room18",
//  "northwest"  : __DIR__"room20",
//  "southeast"  : __DIR__"room21",
//  "southwest"  : __DIR__"room22",
  "east"  : __DIR__"room18",
//  "down"  : __DIR__"room24",
//  "north"  : __DIR__"room25",
]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/she" : 1,
]));
        set("light",1);
        setup();
        replace_program(ROOM);
}

