// wizard_b.c

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(HIC"��ڨ�T��"NOR, ({ "chat board","board" }) );
	set("location", "/open/world1/acme/area/moon/room4");
	set("board_id", "moon_room4_b");
	set("long",
		"�o�O�@�Ӥ�ڱڤH�����Ψӥ洫�߱o���d���O�C\n" );
	setup();
	set("capacity", 99);
  set("master",({ "jawei" }));
}
