#include <room.h>
inherit ROOM;
void create()
{
 set("short","�j��U");

 set("long",@LONG
�A���b�@�ʾ֦��Z�K�K�����j�𩳤U, �j�P���������A�C��
�}��, �A�����䦳�@�Ӥp�c, �L���̦���ܦh�F��, �ӥB�A�ȺA
�פ]����, �A�i�H�ݬݦ��椰��F��, �A������ѱ��Ъ��m�\
���C
LONG
    );
 
 set("exits",(["west":__DIR__"bird25",
     ]));
 set("objects",([__DIR__"npc/waiter2" : 1,
     ]));
 set("no_fight", 1);
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 replace_program(ROOM);
}           

