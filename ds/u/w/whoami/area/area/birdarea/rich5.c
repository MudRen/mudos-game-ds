#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","�I�v�j�U");
 set("long",@LONG
�A�Ө�F�y�������}�@�����I�����a��, �o�̪��G�m�M���]
�S���@�ˤ��O�Q���~�H��, �ݨӦ�b�o���u�����O��������, �b
�A���e���@��ѯΦ��G�N�O�o�̪��D�H�F
LONG);

 set("objects",([__DIR__"npc/richman" : 1,
                ]));
 set("exits",(["south":__DIR__"rich4",
              ]));  
 set("reborn",150); setup();
}        

