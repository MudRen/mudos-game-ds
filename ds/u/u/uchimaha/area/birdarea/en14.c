#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");

 set("long",@LONG
�A�~�򩹲`�B���U�h, �S�ݨ��F�@�s���W, �o�̪����W
���G�񤧫e�����W�󬰥��r�j��, ���̤@�ݨ��A, �N���o�F
�Ʀ������W��, �i�f�K�r, �A���F���U�h, �u�n��L�̥��F
�_�ӤF.....
LONG
    );
 
 set("exits",(["northeast":__DIR__"en15",
               "southwest":__DIR__"en13",
           ]));
 set("objects",([__DIR__"npc/fox4" : 3,
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
