#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
	set_name(HIG"�跡�x�O"NOR,({"board"}));
        set("location","/u/s/shadow/workroom.c");
	set("board_id", "shadow_board");
	set("master",({"shadow"}) );
	set("long",
	"�o�O�跡�j�x��"HIG"�K�d�x��"NOR"�M�ίd���O�C�L�קA�O�q
��B�����ӨӪ��t����A���w��z�b���d���C\n");
	
	setup();
	set("capacity",100);

}
