#include <room.h>
inherit ROOM;
void create()
{
 set("short","�γ��W");
 set("long",@LONG
�A��F�@�ɤ�Ϊ��γ��W, ��M�ݨ����@����F����
���H���b����, �ݦa�W�����, �o�]�\�֤���F, �A�i�H
���U�γ��h�y����.
LONG
    );
 
 set("exits",(["down":__DIR__"village15",
              ]));
 set("objects",([__DIR__"npc/purpler" : 1,
               ]));
 set("outdoors","land");
 set("no_fight",1);
 set("no_clean_up", 0);
 setup();
}        
