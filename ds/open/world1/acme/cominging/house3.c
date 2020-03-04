inherit ROOM;

void create()
{
	set("short", "兵房");
	set("long", @LONG
一間為了衙門中入兵手續而開闢的房間，這裡有幾個壯丁正接受著
兵部尚書的測試，好像並不怎麼的容易通過，兵部尚書似乎挺悠哉的樣
子，在旁拿著書，看著那群壯丁測試著，地上鋪著一條地毯，上面有著
各式各樣的圖案。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"path4",
]));
	set("no_clean_up", 0);
	set("objects",([
  __DIR__"npc/m_soldier.c":1,
]));
        set("light",1);
	setup();
	replace_program(ROOM);
}
