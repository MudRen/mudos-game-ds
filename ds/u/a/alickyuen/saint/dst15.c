// updated by alickyuen 27/12

inherit ROOM;

void create()
{
	set("short", "[1;36mST。Road＠West[2;37;0m");
	set("long", @LONG
聽到一些像廣告歌的歌曲，就抬頭一看，發現天空上一個個廣告的氫
氣球，在大力宣傳。你拿到一張傳單，就是說這裡新開一條食物街，而且
新張期內有特價，你就想快些跑到那裡看看。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dst16.c",
//  "northdown" : "/u/s/steps/area/door",  暫不開
  "east" : __DIR__"dst14.c",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/guard.c" : 1,
]));
   set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
