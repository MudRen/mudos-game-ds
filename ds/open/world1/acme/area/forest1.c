// Room: /u/a/acme/area/forest1.c
#include <path.h>

inherit MOBROOM;

void create()
{
	set("short", "�˪L");
	set("long", @LONG
�A�����b��������A�|�P���j��A���q�J���A���ѽ��šA�����Ӯg��
�i�ӡA���U�@���A�uı�����t�t���A�O�Hı�o���Ѳ��W�����O�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"pass8",
  "south" : TMR_PAST+"ghost-forest/forest16",
  "east" : __DIR__"forest",
]));
	set("no_clean_up", 0);
       set("objects",([
          __DIR__"npc/hap" : 1,
       ]) );
     set("outdoors","land");

        set("chance",10);
       set("mob_amount",1);
        set("mob_object",({     //�]�w�Ǫ��ɦW.
            __DIR__"npc/bear",
        }) );
	setup();
}
