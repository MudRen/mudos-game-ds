#include <room.h>
inherit ROOM;
void create()
{
 set("short","�p���");
 set("long",@LONG
�o�̬O�������a, �A�|�P�ݬ�, �o���\�ǧ�������
�Ϋ~, �Ať��γ��W���ǳ\�ݮ��n, �L�̹�A���X�{��
��Y�åB������, �A�̦n���I���}�o.
LONG
    );
 
 set("exits",(["west":__DIR__"village15",
              ]));
 set("objects",([__DIR__"npc/child" : 1,
                 __DIR__"npc/villager2" : 1,
               ]));
 set("light",1);
 set("no_clean_up", 0);
 setup();
}        


