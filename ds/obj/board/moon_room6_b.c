// wizard_b.c

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
    set_name(BLU"���l���O"NOR, ({ "arrest board","board" }) );
    set("location", "/open/world1/acme/area/moon/room6");
    set("board_id", "moon_room6_b");
	set("long",
        "�o�O�@��Acme�S�O���n�����ʪ���کҥߪ��l���O�C\n" );
	setup();
	set("capacity", 99);
}
