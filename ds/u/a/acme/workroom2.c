// Room: /u/a/acme/workroom2.c

inherit ROOM;

void create()
{
        set("short", "三千格房間");
	set("long", @LONG

         [36m◢◣      ◢◣[0m
[36m         ◤◥◣  ◢◤◥[0m
[36m            ◢██◣[0m
[36m            █[35m◎◎[36m█[33m                  [36m◢[0m
[36m          ＼████◢██████◣◢◤[0m
[36m          ＿████████████◤[0m
[36m            ◥██◤████████[0m
[36m                    ◥██████◤[0m
[36m          [33m             <><>    <><>[0m

LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"workroom.c",
]));
	set("objects", ([ /* sizeof() == 1 */
]));
	set("no_clean_up", 0);
        set("light",1);

	setup();
	replace_program(ROOM);
}
