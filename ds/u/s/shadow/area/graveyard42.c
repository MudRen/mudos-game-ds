/**
 * Shadow's area [荒廢漁村 - 義莊 - graveyard42]
 */ 
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG"義莊"NOR);
	set("long",@LONG
這兒是義莊的西北隅，只有一座小小的涼亭座落在此，想必是供
前來祭祖的人休憩之用。涼亭上有石椅三個，然而卻已遍佈青苔，看
來你即使想在石椅上歇息也屬難事。
LONG
	);
	set("outdoors","land");
	set("light", 0);
	set("exits",([
		"east": __DIR__"graveyard22",
		"south": __DIR__"graveyard41",
	]));
  
	setup();
	replace_program(ROOM);
}
