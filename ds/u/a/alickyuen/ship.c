// Room: /tmr/ship/ship.c

inherit ROOM;

void create()
{
	set("short", "渡船上");
	set("long", @LONG
這是一艘竹紮的渡船，雖然頗為老舊，卻也堅固耐用。
LONG
	);
	set("no_clean_up", 0);
	set("no_kill",1);
	set("no_magic",1);
	set("no_recall",1);
	setup();
}
