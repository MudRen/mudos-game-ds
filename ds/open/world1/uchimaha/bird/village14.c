#include <room.h>
inherit ROOM;
void create()
{
 set("short","�����a");
 set("long",@LONG
�A��F�����a, �A�ݬݥ|�P, ����W���F�Ǭé_��
�~���Х�, ���ӬO�����~���ɩ��y�Ӫ�, ��W�ٱ��F�@
�����һs���}, �ݰ_�����ӫܤ[�S�ΤF.
LONG
    );
 
 set("exits",(["west":__DIR__"village13",
              ]));
 set("objects",([__DIR__"npc/man2" : 1,
     ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}        
