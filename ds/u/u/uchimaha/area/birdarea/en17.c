#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","����");

 set("long",@LONG
�A�Ө�F�o��, �o�{�|�P�t������, ���O�o���۫�
�@���ͯ��, �٦��}�}���C�q�n, �A����ı�P��S�n��
�@���j�ԤF!
LONG
    );
 
 set("exits",(["southwest":__DIR__"en16",
              ]));
 set("objects",([__DIR__"npc/kfox" : 1,
                 __DIR__"npc/fox5" : 2,
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
