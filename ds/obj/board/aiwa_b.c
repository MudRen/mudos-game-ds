#include <ansi.h>

inherit BULLETIN_BOARD;

void create()
{
	set_name(HIY+"�i�Ův�j���(Aiwa): �֨ӯd�Ө��a�C"+NOR,({"aiwa board","board",}));
	set("location","/u/a/aiwa/workroom");
	set("board_id","aiwa_b");
	set("long","���Ƨֻ��d�����C\n");
	setup();
	set("capacity",150);

}
