#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
�A���b�@�ʾ֦��Z�K�K�����j�𩳤U, �j�P������
���A�C���}��, �A�����䦳�@�Ӥp�c, �L���b��z�L��
�F��, �A�p�Gı�o�{�l�j, �i�H�R�I�F��ӦY, �A���F
���N�O�L�H���˪L�`�B�F�C
LONG
    );
 
 set("exits",(["east":__DIR__"en6",
               "south":__DIR__"en3",
     ]));
 set("objects",([__DIR__"npc/waiter3" : 1,
     ]));
 set("no_fight", 1);
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 set("outdoors","forest");
 setup();
 replace_program(ROOM);
}           
