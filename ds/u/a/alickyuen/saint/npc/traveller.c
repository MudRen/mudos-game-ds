// Npc: /u/a/alickyuen/npc/3.c

inherit NPC;

void create()
{
	set_name("遊客", ({"traveller"}) );
	set("long", "一個從外地來這裡的遊客，每逄假日都有一堆堆的旅行團。\n");
	set("race", "人類");
	set("age", 30);
	set("level", 10);
    set("chat_chance",10);
        set("chat_msg",({
     (: random_move :),
                         }));

	setup();

}
