// Room: /d/gumu/shishi5.c
// Last Modifyed by Winder on Jan. 14 2002

#include <ansi.h>
inherit ROOM;

void create()
{ 
	set("short",HIB"石室"NOR);
	set("long", @LONG
你突然覺得眼前一亮，前方石室透過來一絲微弱的光，給了你一絲
希望。但還是只聽見遠遠傳來你腳步的回音，空蕩蕩的感覺使你心中只
有恐懼，甚至忘記孤獨。四周如此寂然無聲。只能靠摸索前行。
LONG	);
	set("exits", ([
		"west"  : __DIR__"shishi4",
		"enter" : __DIR__"lingshi",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
