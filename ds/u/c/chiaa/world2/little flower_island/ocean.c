//u/c/chiaa/world2/little flower_island/ocean.c

#include <ansi.h>   
inherit ROOM;

void create()
{
        set("short", HIB"����"NOR);
        set("long",@LONG
�@���L�v�L�ڪ��j��,�����i��½�˶���,�E�_�|�|������,
�祴�۪u��,�A��ı�P�Ĥj�۵M�����j�P�H�������p,
�ݵ۳o�˪�����,���G��A�����ߧ��ӳ��i���F!!


LONG
        );
        set("exits", ([ /* sizeof() == 1 */
      
        "southwest"   : __DIR__"sand1",      //�F�y1
  
       
    ]));
       
            setup();
replace_program(ROOM);
}
