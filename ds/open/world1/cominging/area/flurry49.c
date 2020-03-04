inherit ROOM;

void create()
{
	set("short", "疾風右使之房");
	set("long", @LONG
這裡是疾風門的右使楊雙亟的房間，疾風門的每一個長老都會有各
自的房間，楊雙亟也不例外，在這的門口旁，有一串串的鈴鐺，當風吹
來時，就會有叮叮噹噹響亮清脆的聲音，在這裡有幾張桌子，上面都有
許多刀劍刮過的痕跡，顯示這裡曾有許多鬥爭，楊雙亟在江湖上的名聲
極為有名，跟傲過大概不分上下。
LONG
	);
	set("exits", ([
  "west" : __DIR__"flurry48.c",
]));
        set("valid_startroom", 1);
	set("light",1);
	set("objects",([
  __DIR__"npc/master.c":1,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
