#include <ansi.h>;
inherit __DIR__"room";
void create()
{
        set("short", HIC"�������E���}["HIW"�{"HIC"]"NOR);
        set("long", @LONG
�A�����b���������E���}�A�u���o�|�g�ɬO�@�������A���⤣������
�A�b�}�}�@�����������A���ۤ@��վv���C�����@���k�A�@���b�o������
��¶�۴N�O�񤣤F�o�����Ǥ��ءA�ݨӨ���k�l�]���۷��\�O.....
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"room9", 
  "northeast"  : __DIR__"room19",
  "northwest"  : __DIR__"room20",
  "up"  : __DIR__"room21",
  "down"  : __DIR__"room22",
  "east"  : __DIR__"room23",
  "west"  : __DIR__"room24",
  "north"  : __DIR__"room25",
]));
        set("no_recall",1);
        set("objects", ([
 __DIR__"npc/jan" : 1,
]));
        set("light",1);
        setup();
}

