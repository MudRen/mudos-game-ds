// Room: /d/xiangyang/jiangjungate.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "將軍府大門");
	set("long", @LONG
這是將軍府的大門，門板不知是以什麼材料制成，看上去
黝黑一片，似乎極為沉重，上面有兩個擦得晶亮的銅環；在大
門的正上面有個夾著一個高大的木牌坊，上書「將軍府」三個
大字，字跡娟秀飄逸，只是有些模糊了，想必是歲月留下的痕
跡。門內有一株老柏，生得蒼勁挺拔，枝葉茂密。門前東西兩
邊各肅立著兩個腰配大刀的宋兵。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"south" : __DIR__"eastjie1",
		"north" : __DIR__"jiangjunyuan",
	]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
	set("coor/x", -490);
	set("coor/y", -500);
	set("coor/z", 0);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" &&
                objectp(present("song bing", environment(me))))
                                {
                tell_object(this_object(), "宋兵喝道：什麼人膽敢擅闖守備府衙門！\n");
                return 0;
        }

        return ::valid_leave(me, dir);
}
