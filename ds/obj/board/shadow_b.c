#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name(HIG"西楚軍令"NOR,({"board"}));
        set("location","/u/s/shadow/workroom.c");
	set("board_id", "shadow_board");
	set("master",({"shadow"}) );
	set("long",
	"這是西楚大軍的"HIG"八千軍魂"NOR"專用留言板。無論你是從
何處飄盪而來的孤魂野鬼，都歡迎您在此留言。\n");
	
	setup();
	set("capacity",100);

}
