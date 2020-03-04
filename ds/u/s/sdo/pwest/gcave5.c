inherit ROOM;

void create()
{
	set("short", "洞窟內叉路");
	set("long", @LONG
你看到前方不遠處好像有微弱的光線透射出，但是因為實在是太
微弱了，所以實在是沒有什麼照明的效果。不過既然有光線，那就是
代表這個洞窟是有某種高等智慧的生物在居住的。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"gcave6",
  "south" : __DIR__"gcave3",
]));

	setup();
	replace_program(ROOM);
}
