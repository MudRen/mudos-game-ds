#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIC"�j�U"NOR);
set("long", @LONG
�o�̬O�N��د����j�U�]�O�̥D�n���a��, �A�A���W�観���ӶW�j��
�O, �Ӫ��o�̰{�{���, �A�i�H�ݨ��o�̦��ܦh���Ův, �b�o�̲�ѻP��
���߱o, ���_���@�����D, ����O�ϰ��s��, �F��Omob�����,(wiz)
�O���Ův���ť, ���W�i��W�H��, ���U��Feq��s��.
LONG
);
set("light",1);
set("exits", ([ 

                "north"  : __DIR__"a_1.c",
                "west"   : __DIR__"a_2.c",
                "east"   : __DIR__"a_3.c",
                "out"    : __DIR__"workroom_1.c",
                "up"     : __DIR__"piliykt.c",
                "down"   : __DIR__"eq.c",
                "wiz"    : "/d/wiz/hall1",         
                           ]));
 setup();
}

