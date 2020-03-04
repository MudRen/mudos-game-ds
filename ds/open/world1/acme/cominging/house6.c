inherit ROOM;

void create()
{
	set("short", "吏房");
	set("long", @LONG
這是一間為了管理官吏人事之間題之處，在這裡似乎人群少了很多
，並不有什麼人來到這，常常看見裡面的人在打瞌睡，也經常都沒有人
來，所以官吏間有時會並不怎麼和平。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"path7",
]));
        set("light",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
