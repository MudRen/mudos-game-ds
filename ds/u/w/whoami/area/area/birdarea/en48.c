#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIW"�F�_"NOR"�A�L");
 set("long",@LONG
�A�~�򩹦�n��, �A�ݨ�a�U���ǫܤj���}�L, �o���ӬO��
�������ʪ��u�d�~����v�үd�U��, �ڻ��o�ǥ���ܥ��r, �ݨ�
�e�̦n�֨�.
LONG);
 set("exits",(["west":__DIR__"en49",
               "northeast":__DIR__"en47",
               ]));
 set("objects",([__DIR__"npc/tfrog" : 4+random(3),
     ]));
 set("outdoors","forest");
 set("no_clean_up", 0);
 setup();
}        

