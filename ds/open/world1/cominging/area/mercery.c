inherit ROOM;
void create()
{
	set("short", "布店");
	set("long",@LONG
這裡是步靈城中最大的販布店，有各式各樣的布，看了令人眼花撩
亂，在外邊有很多在挑選布料的婦人，也有許多叫價殺價的聲音，也有
許多從店前經過，而被這裡的東西所吸引的人，這裡的布參差不齊，有
好也有壞的，從純棉到不織布都有。
LONG
	);
	set("exits", ([
  "west" : __DIR__"bnorth4.c",
]));
	set("objects", ([
  __DIR__"npc/mercer": 1,
]));
	set("no_clean_up", 0);
	set("light", 1);
	setup();
	replace_program(ROOM);
}