#include <ansi.h>
inherit ROOM;
void create()
{
 set("short","�p���");

 set("long",@LONG
�A�Ө�p��̭�, �o���G�O�@���װ��Ϊ��p��, �b�A����
�䦳�@�i��l, �Ӧb�A���k��O�@��Q�A��M���i���~�쪺�k
�l�E
LONG
    );
 set("item_desc",([
     "��l":"��l���W���\\���F����, �O�H���C�T�ءE\n",
     ]));
 set("exits",(["out":__DIR__"kus1",
       ]));
 set("objects",([__DIR__"npc/man" : 1,
     ]));
 set("light",1);
 setup();
} 
