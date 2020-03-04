inherit ROOM;

void create()
{
	set("short", "洞窟內");
	set("long", @LONG
你走到這裡，忽然覺得毛骨悚然。因為地上竟然散亂著一地的白
骨，旁邊還有火堆和懸掛在架子上的鍋子。而真正令人害怕的是，地
上散落的白骨裡竟然有人類的頭骨！
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 3 */
  		"southeast" : __DIR__"gcave13",
  		"east" : __DIR__"gcave10",
  		"northeast" : __DIR__"gcave9",
	]));

	setup();
	replace_program(ROOM);
}
