#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIY"mob��s��"NOR);
set("long", @LONG
�o�̬O�N��د�����s��, �D�n�O�ΨӬ�smob���a��, �o�̥D�n
�O�гymob, ����mob���j��, �Τ@��mob���]�w, �o�̪��]�Ʒ�M�O��
���i��, �b�A������N���@�x�ͪ��s�y��, �i�H�Ψӻs�y�d�ʺ�mob, ��
�_��Omob���ճ�.
LONG
);
set("light",1);
set("exits", ([ 
                                
                "west"   : __DIR__"workroom_2.c",
                "north"  : __DIR__"b_1.c",
                                    ]));

 setup();
}

