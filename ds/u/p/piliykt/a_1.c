#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIG"���ب��D"NOR);
set("long", @LONG
�o�O�@���W�������ب��D, �o�̪��a�O���ζ����E�y�Ӧ�, �o�����D
����٦��\�h���j��, ���A�ݪ��R������.
LONG
);
set("light",1);
set("exits", ([ 

                "north"  : __DIR__"workroom.c",
                "south"  : __DIR__"workroom_2.c",
                                                
                           ]));
 setup();
}

