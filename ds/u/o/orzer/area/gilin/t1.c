#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","���F�˪L�f");
        set("long",@LONG
�A�Ө�F�˪L�J�f�e�A���M�˪L�����ۤ@�}�}���H��A�i�O�A�̵M
�٦��۫i��A�٦��ۤ@���s��������A�o���q�ߵۤ@�Ӥ�P�A��P�W��
�����Ǥ�r�A�˪L����������A�ݨӳq�����P��V�C
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t12",
  "southwest" : __DIR__"t2",
   "south" : __DIR__"m7",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        set("item_desc", ([
            "��P" : "�§ʸT�a�A���H�Ŷi�A�H��"HIR"���L�j\n"NOR
                     "              "HIY"�Ѵ�  "HIC"�j�N�x���O\n"NOR
            ]));        
        setup();
        replace_program(ROOM);
}







