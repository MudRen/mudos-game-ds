#include <room.h>
inherit ROOM;
void create()
{
 set("short","�_����");
 set("long",@LONG
�A�~�򩹥_��, �o�̨S���b���u��, �N�N�M�M��, ��
�W�٦��X�ӦѤ���, �ѱC�C�b���a, �b�A�����, �O�@��
�Ѥ~´���֤k���a, �b�A���F��N�O�Q�U�j�s�����V.
LONG
    );
 
 set("exits",(["west":__DIR__"village16",
               "east":__DIR__"village18",
               "south":__DIR__"village13",
              ]));
 set("objects",([__DIR__"npc/oldman" : 2,
                 __DIR__"npc/oldwoman" : 2,
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        
