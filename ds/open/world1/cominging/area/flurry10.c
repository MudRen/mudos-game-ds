inherit ROOM;

void create()
{
	set("short", "階級前");
	set("long", @LONG
這裡是一個階梯的前面，在這裡的旁邊有許多的欄杆和花草，在北
方的花園之中有許多蟲鳴和鳥叫，令人心曠神怡，不覺煩悶，只要休閒
時不妨出來看看花草也不錯。
LONG
	);
	set("exits", ([
  "northdown" : __DIR__"flurry11.c",
  "south" : __DIR__"flurry3.c",
]));
	set("no_clean_up", 0);
	set("light",1);
	setup();
	replace_program(ROOM);
}