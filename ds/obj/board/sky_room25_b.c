// wizard_b.c
#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
    set_name(HIW"�Ѧa�|�ưȪO"NOR, ({ "terra board","board" }) );
	set("location", "/open/world1/acme/area/sky/room25");
	set("board_id", "sky_room25_b");
	set("long",
		"�o�O�@�ӤѦa�|�����G�s�ƶ��άO���n�����ҥΪ��d���O�C\n" );
	setup();
	set("capacity", 99);
}
