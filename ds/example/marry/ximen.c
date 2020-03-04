// /d/ruzhou/ximen.c 汝州西門
inherit ROOM;

void create()
{
	set("short", "汝州西門");
	set("long", @LONG
這里是汝州的西城門。從這里是通向西域去的必經要道，一旦有
大案發生或是戰事起來，立即會在此設卡盤查，平時，官兵也懶得過
來多事，城門下一片太平盛世景象。
LONG
	);

	set("exits", ([
		"west" : __DIR__"xi-yidao1",
                "east" : __DIR__"wangxi-lu",
	]));

        set("objects", ([
//                "/d/city/npc/wujiang" : 1,
//                "/d/city/npc/bing" : 3,
        ]));

	set("outdoors", "ruzhou");
	setup();
	replace_program(ROOM);
}



