// Room: /open/world1/tmr/dragoncity/house4w.c

inherit ROOM;

void create()
{
	set("short", "少帥府－書房");
	set("long", @LONG
這是寇仲的書房。右邊是書架，上面陳列著道家和儒家的一些典籍，
卻沒有一本與武學有關的書。左邊靠窗的地方擺著一張木桌，上面放著筆
墨紙硯，邊上放著幾本書，擺放得整整齊齊，搽拭得一塵不染，閣裡到處
被打掃得一塵不染，窗明幾淨，可以看到外面鬆竹掩映，時有微風入戶，
門後桌上還燃著一爐檀香，氳氳的香氣輕輕橫散，使人俗念盡消，心情完
全平靜下來。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"house4",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
