// cave.c

inherit ROOM;

void create()
{
	set("short","天地會地道");
	set("long", @LONG
當你步進這裡，感覺在隱密處似乎有人正窺伺著你，隱隱聽見有
人喊著：「天有天罡，地有地剎，天地之間，留有正法。」原來這裡
是天地會的正法堂，據聞這裡是天地會維持天地正法的所在，藏有一
群不為人知的高手。

LONG
	);
	set("objects",([
//__DIR__"item/greensword2" :1,
]));
	set("exits", ([
	"up": __DIR__"room36",
	]));
	set("objects", ([
		"/open/world1/npc/goldman4" : 1,
		"/open/world1/npc/goldman5" : 1,
		"/open/world1/npc/goldman6" : 1,
	]));
	set("light",1);
//        set("no_kill",1);
//set("no_goto",1); cancel two settings by alickyuen@ds 1)放golem 2)meaningness
	setup();
//	call_other( "/obj/board/sky_room05_b", "???" );
}
