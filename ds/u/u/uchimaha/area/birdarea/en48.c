#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");
 set("long",@LONG
�A�~�򩹦�n��, �A�ݨ�a�U���ǫܤj���}�L, �o
���ӬO�ǻ������ʪ��u�d�~����v�үd�U��, �ڻ��o��
����ܥ��r, �ݨ�e�̦n�֨�.

LONG
    );
 
 set("exits",(["west":__DIR__"en49",
               "northeast":__DIR__"en47",
               ]));
 set("objects",([__DIR__"npc/tfrog" : 4,
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
