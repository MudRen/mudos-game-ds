#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"���~�p��"NOR);
	set("long", @LONG

�o�̬O�e�����|�j�٤��@�����~�p�١A�W�G���A��M�O���\�h��
���~�|�s�����~�A�b�p�٩P��S�����j����L�A�ҥH���j�ɡA�p�ٸ�
�N�|�R���F�F�l�A��M�]�|����D�֡C

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"flurry37.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
}

void init()
{
	call_out("delay",2,this_player());
}

void delay(object me)
{
	if( environment(me)!=this_object())return;
	else {
		write(HIY"�A�o�{�o�̪����S�O���j�I\n"NOR);
		return;
	}
}
