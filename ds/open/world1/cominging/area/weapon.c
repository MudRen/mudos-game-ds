inherit ROOM;
void create()
{
	set("short", "武器舖");
	set("long",@LONG
你來到了一個有點給人熱熱的感覺的地方，這裡是步靈城中一家武
器舖，專門製造武器一類的用具，店內有許多打鐵的鐵匠，也有許多在
招呼客人的販子，他們所擺出要賣的武器似乎很好的樣子，不過價錢卻
有點......。
LONG
	);
	set("exits", ([
  "west" : __DIR__"boo-lin3.c",
]));
	set("objects", ([
  __DIR__"npc/smith": 1,
]));
	set("no_clean_up", 0);
	set("light", 1);
	setup();
	replace_program(ROOM);
}