// xiuxishi.c 休息室
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
這是間很大的房間，光線非常昏暗。房里沒有什么別的東西，只有
中間一張小桌，里�朁騊菑@張收拾得舒舒服服的大床，床上的被褥也整
理得整整潔潔的，看著就讓人想睡覺。
LONG	);
	set("exits", ([
		"east" : __DIR__"mudao02",
	]));

        set("objects", ([ /* sizeof() == 1*/
         "/open/world1/obj/pot" : 1,
        ]));      

	setup();
	replace_program(ROOM);
}
