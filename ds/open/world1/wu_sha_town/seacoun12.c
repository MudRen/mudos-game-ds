#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�Ʈv��");
set("long",@LONG
�o�̬O���D���F���F�䪺�F�Ʈv��, �A�i�H�q�A�{�b��
��m�ݨ�@�Ӥj���M���F�q���x�@�˦��o���i�}�檺�F�Ʈv, 
�L���b����s�����R....
LONG
    );
 set("exits",([ "west":__DIR__"seacoun11",
]));
 set("objects", ([__DIR__"../npc/bladeguard" : 1,
		  __DIR__"../npc/east_secretary" : 1,
    ]));

 set("no_clean_up",0);
  set("light",1);
 setup();
 replace_program(ROOM);
}             
