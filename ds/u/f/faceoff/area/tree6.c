#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�s��");

 set("long",@LONG
�A�B�ܩ�, �ߨ�P��@�ѱ��𼳭��Ө�, �ϧA���H�ӷX, ��
�A�٬O����P�³o����a�ϧA����A���樣�쪺����, �A�J�Ӥ@
��, �o�{�|�P��a��������L������, �Ϫ��󪺥ͪ���V�@�P, 
�A�߸̤@�H, ���D�o�̬O�ѱ��@��Ϫ����|�a!?
LONG
    );
 set("exits",([ "south":__DIR__"tree4",
                 "north":__DIR__"woodvillage1",
    ]));
set("objects", ([__DIR__"npc/woodguard" : 2,
    ]));

 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}