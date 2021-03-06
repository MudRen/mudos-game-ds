// Room: /open/world1/tmr/wujian/jian2.c

inherit ROOM;

void create()
{
	set("short", "空無間");
	set("long", @LONG
無間是佛教傳說中所提到部份人死後所到的地獄中，刑法最殘酷
的一個。《涅盤經》第十九卷「八大地獄之最，稱為無間地獄，為無
間斷遭受大苦之意，故有此名」；無間有三：時無間，空無間，受業
無間，犯五遂罪者永墮此界，盡受終極之無間。這邊的霧氣非常濃，
難以識物，沉重的寂靜聲中，越加凸顯出你內心的恐懼。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"snake-room6d",
]));
	set("current_light", 3);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
