#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","���D");
 set("long",@LONG
�o�O�@���q���s�뤺�����D, �A���e�ݤF�@��, �o�{�e�観
��h���H����, �ݨӳo�Ӥs���b�j�����Y, �o�ˤ@�Q, �x�L�n
���󤣥i����i�ӤF�K
LONG);
 set("exits",([ 
                "southwest":__DIR__"bandit4", 
                "eastup":__DIR__"bandit6",
    ]));

 set("no_clean_up",0);
 set("light",0);
 setup();

}

