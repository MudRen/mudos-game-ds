// 軍品店老闆的倉庫

inherit ROOM;

void create()
{
	seteuid(getuid(this_object()));
	set("short","軍品店老闆的倉庫");
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
		"out":	__DIR__"room074",
	]));

	set("light",1);
	set("no_clean_up",1);
	set("objects",([
		"/u/l/luky/npc/item/bag":1,
		"/u/l/luky/npc/eq/blackjacket":3,
		"/u/l/luky/npc/wp/kaisan_b":1,
	]));

	setup();

}