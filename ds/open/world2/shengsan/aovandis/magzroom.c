// 圖書館的雜誌庫
inherit ROOM;

void create()
{
	seteuid(getuid(this_object()));
	set("short","圖書館的雜誌庫");
	set("long",@LONG
                 [1;33m︵ ︵ ︵                    ︵ ︵ ─╮[m
                   [1;33m╭ （╭ ' ）                （ ' ╮）  ╮[m
                   [1;33m��==)）[31mp[33m（    [37m願有情人終成  [33m ）╮（））│[m
                   [1;31m◣  [33m（ [37m│[33m ）      [37m眷屬         │[33m ）／／[m
                  [1;33m（ ）([37m┬��[33m(    [31m◢█◣◢█◣     [37m╰┬[33m)（[m
                   [1;33m(）[37m|︵\  [32m*.[31m@[32m. [31m██████ [32m.[31m@[32m.*  [37m/︵|[m
                [1;31m◣[33m(）[37m（   ）[32m.[31m@＠[32m.[31m◥████◤[32m.[31m＠@[32m.[37m（   ）[m
              [1;33m（╭��[31m◣[37m） ��-[35m◢[31m@[32m.'' [31m◥██◤ [32m''.[31m@[35m◣[37m╯  （[m
                [1;33m��  [37m／    ┬[35m◤[32m'.     [31m◥◤     [32m.'[35m◥[37m-┬  ＼[m
                  [1;37m／      │                       │ │            [30m[m
LONG
	);

	set("exits", ([	//出口設於NPC位置,可以不設
		"out":	__DIR__"room121",
	]));

	set("light",1);
	set("no_clean_up",1);
	set("objects",([
		__DIR__"npc/obj/magz000":1,
		__DIR__"npc/obj/magz001":1,
		__DIR__"npc/obj/magz002":1,
		__DIR__"npc/obj/magz003":1
	]));

	setup();

}