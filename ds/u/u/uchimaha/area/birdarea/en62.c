#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L���d�h�ϡ�");
 set("long",@LONG
�A�Ө�F�_�A�L���˪L�d�h��, �o�ഺ�⪺����, 
�ϧA�߸̤��, ������ť��ǥs�n, ���ӬO�������W
���ʪ��ҵo�X���a.

LONG
    );
 
 set("exits",(["north":__DIR__"en57",
               "south":__DIR__"en67",
               ]));
 set("objects",([__DIR__"npc/fly" : 4,
               ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
