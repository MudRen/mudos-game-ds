inherit ROOM;
void create()
{
	seteuid(getuid(this_object()));
	set("short","�ӤH shop");
	set("long","\n");
	set("light",1);
	set("no_clean_up",1);
	set("objects",([
	]));
	set("exits",([
  "out": __DIR__"temproom.c",
]));
	setup();
}

