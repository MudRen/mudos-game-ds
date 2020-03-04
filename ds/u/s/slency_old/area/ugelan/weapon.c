// Room: /u/s/slency/area/ugelan/weapon.c

inherit ROOM;

void create()
{
	set("short", "武器店");
	set("long", @LONG
這裡是本城最出名的武器店，所賣刀劍為其雙絕，鋒利輕盈為其特
色，聽說本店的打鐵師父是用北方極寒地帶所運送回來的精剛做惟材料
，加上超群的手藝，所鑄刀劍是天下聞名的，不過也因此價格稍貴了些
，往南可回到街道上。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"road2",
]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
	replace_program(ROOM);
}
