#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"�y����"NOR"��"HIW"�s��"NOR);
 set("long",@LONG
�o�̬O�y�������s��, �]�O�����̪����|��, ����Өө���
���H�̤���h, �i�O�]���໡��, �b�y�����̪��H��, ���O�y�H
�K�O´����, �L�̹�A����Ӧ��G�D�`���n�_.
LONG
    );
 
 set("exits",(["west":__DIR__"village3",
               "north":__DIR__"village12",
               "south":__DIR__"village5",
           ]));
  set("objects",([__DIR__"npc/villager" : 1+random(2),
     ]));
 set("outdoors","land");
 set("no_clean_up", 0);
 setup();
}        

