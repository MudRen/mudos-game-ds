#include <room.h>
inherit ROOM;
void create()
{
 set("short","�y����");
 set("long",@LONG
�A���i�F�o���Τl, ���U�F�|�P, ����W�����F�Y
�㺡�ت����ֻs�~, �b�������@�[´������@�i�Ȥl,
���@�ӤH���b�Ȥl�W, �L���G���Ƿдo���ˤl....
LONG
    );
 
 set("exits",(["west":__DIR__"village10",
               ]));
 set("objects",([__DIR__"npc/wang" : 1,
     ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}        
