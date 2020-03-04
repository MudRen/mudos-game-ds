#include <ansi2.h>

inherit ROOM;

string *rooms = ({
	"/open/world1/alickyuen/match/area-a/map_7_14.c",
	"/open/world1/alickyuen/match/area-b/map_8_1.c",
	"/open/world1/alickyuen/match/area-c/map_8_14.c",
        "/open/world1/alickyuen/match/area-d/map_5_3.c",
	"/open/world1/alickyuen/match/area-a/map_1_1.c",
	"/open/world1/alickyuen/match/area-b/map_8_11.c",
        "/open/world1/alickyuen/match/area-c/map_1_1.c",
        "/open/world1/alickyuen/match/area-d/map_1_1.c",
});
void create()
{
	set("short", "�ǰe�I");
        set("long", @LONG

LONG
);
	set("exits",([
	"west" : __DIR__"map_7_13",
	]));
	set("outdoors","forest");
	set("no_recall",1);
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
	add_action("do_transfer", "transfer");
}

int do_transfer()
{
	object me, room;
	me = this_player();
	room = load_object(rooms[random(sizeof(rooms))]);

	if( me->is_busy() )
		return notify_fail("�A�٦b�����I\n");

	message_vision(HIY"\n�A�����e��M�X�{�@�}�j���K�K�A�i�}���H��o�{�P�����Ҧn�����@�ˤF�K�K\n\n"NOR, me);
	me->move(room);
	me->start_busy(2);

	return 1;
}
