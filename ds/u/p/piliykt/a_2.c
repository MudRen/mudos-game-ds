#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIR"�ϰ��s��"NOR);
set("long", @LONG
�o�̬O�N��د�����s��, �D�n�O�ΨӬ�sds�ϰ쪺�a��, �A�i�H��
��o�̦��̥��i���ìP�ɯ�q��, ��W�ﺡ�F��L�Ův�����i�P�p��, �A
�����٦��Ӥp�����, �Ψӹ���Ѯ𷧪p,(land,forest,snow,desert)
��(area)�i��F�s�ϰ�, �����F�j�U.
LONG
);
set("light",1);
set("exits", ([ 
                
                
                "east"   : __DIR__"workroom_2.c",
                "area"   : "/u/p/piliykt/area/road_6.c",
                                    ]));

 setup();
}

