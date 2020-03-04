// Npc: /u/t/truewind/npc/1.c

inherit NPC;

void create()
{
	set_name("申子平", ({"tsiping"}) );
	set("long", "申子平是一名路過華山的旅客。\n");
	set("race", "人類");
	set("age", 20);
	set("level", 20);
        set("chat_chance", 10);
        set("chat_msg", ({
             "申子平說道：來此一遊，方知五嶽果然名不虛傳。\n",
             "申子平望著遠方的天空，讚嘆的發起呆來。\n",
        }));

	setup();

}
