// Npc: /u/m/matlab/npc/2.c

inherit NPC;

void create()
{
	set_name("青面小鬼", ({"guard"}) );
set("long", "一個混身惡臭長相噁心的小鬼守衛正在你面前張牙舞爪，狀態囂張，企圖趕你離開。\n");
set("race", "人類");
set("unit", "隻");
	set("age", 15);
set("level", 30);
set("attitude", "heroism");

	setup();

}
