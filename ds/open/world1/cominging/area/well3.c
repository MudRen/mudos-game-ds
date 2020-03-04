inherit ROOM;
void create()
{
	set("short", "井底旁");
	set("long",@LONG
這裡是井底下，在這裡有一些些的生物，像是青蛙一類的，正在向
你瓜瓜大叫，不過他對你而言沒有什麼傷害力可言，而在北方是井底，
從那有串串水流流過來，在這裡的邊邊有些蘚苔，似乎可以刮(scrape)
的樣子。
LONG
	);
	set("exits", ([
  "north" : __DIR__"well.c",
]));
	set("item_desc", ([
  "蘚苔" : "長在陰暗地方的一種植物, 呈綠的.\n",
]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_scrape","scrape");
}

int do_scrape(string arg)
{
	object me;
	me = this_player();
	if( random(100) > 50 && !query_temp("musci") )
	{
		write("你刮下了一些些的鮮苔。\n");
		new(__DIR__"npc/obj/musci.c")->move(me);
		set_temp("musci",1);
		set("long",@LONG
這裡是井底下，在這裡有一些些的生物，像是青蛙一類的，正在向
你瓜瓜大叫，不過他對你而言沒有什麼傷害力可言，而在北方是井底，
從那有串串水流流過來。
LONG
		);
		call_out("delay",600,this_object());
	}
	else
	{
		write("..... 你用盡全力還是刮不下來。\n");
	}
	return 1;
}

void delay(object tob)
{
	delete_temp("musci");
	set("long",@LONG
這裡是井底下，在這裡有一些些的生物，像是青蛙一類的，正在向
你瓜瓜大叫，不過他對你而言沒有什麼傷害力可言，而在南方是井底，
從那有串串水流流過來，在這裡的邊邊有些蘚苔，似乎可以刮(scrape)
的樣子。
LONG
	);
	return;
}
