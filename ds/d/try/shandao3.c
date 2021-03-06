// Room: /d/shaolin/shandao3.c

inherit ROOM;

void create()
{
	set("short", "山道");
	set("long", @LONG
這是一條筆直的山路向上方延伸，一直隱沒于云霧之中，山
道的左面是一片翠竹林，小鳥的鳴叫聲和風吹過竹林的沙沙聲交
織成美麗的大自然的旋律。右面是陡峭的山崖。路上經常能看到
几個僧人來來往往，向上一直走就是著名的少林寺了。
LONG
	);

	set("outdoors", "land");

	set("exits", ([ /* sizeof() == 3 */
	"northup" : __DIR__"shandao2",
	"west" : __DIR__"zhulin/entry",
	"southdown" : __DIR__"shandao4",
]));

	setup();
	replace_program(ROOM);
}
