#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIM"eq��s��"NOR);
set("long", @LONG
�o�̬O�N��د�����s���@, �o�̥D�n�O��s�Ҧ����˳ƻP�s�y, ��
�t�d����, �A�٥i�H�o�{�o�̦��\�h���]��, �������l, ���ƻs�y��, ��
�X��, �@�j�����, ���F��F���~��s��, �����F�Z����s��, ���W�i
�^��j�U.
LONG
);
set("light",1);
set("exits", ([ 

                "up"  : __DIR__"workroom_2.c",
                "west"   : __DIR__"wp.c",
                "east"   : __DIR__"it.c",
               
                                    ]));
 setup();
}

