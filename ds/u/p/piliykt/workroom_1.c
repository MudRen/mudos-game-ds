#include <weapon.h>
#include <ansi.h>
inherit ROOM;
void create()
{
set("short",HIC"�N"HIR"��"HIY"��"HIM"��"NOR);
set("long", @LONG
�o�̥��O�j�W�������]�k�Ǯ��N��د�, �b�A���e�����j�ؿv�����O
�N��د�������, �A���e��N���@���j�K��, �K���ǯ��F�\�h���]�k�@��
, ����A�H�K��o�o��, �]���N��د��i�O����\�h���n�p���������`��
�M���V�a�I. 
LONG
);
set("valid_startroom", 1);     
set("light",1);
set("exits", ([ 
                "enter"   : __DIR__"workroom_2.c",
                                    ]));

 setup();
        
}

