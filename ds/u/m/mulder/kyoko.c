// Npc: /u/m/mulder/npc/1.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name( HIC "深田恭子" NOR , ({"Kyoko Fukada", "kyoko" }) );
	set("long", "她是日本的新進明星，也是小喇叭最愛的人！！\n");
	set("race", "人類");
	set("gender", "女性");
	set("age", 16);
	set("level", 120);
	set_skill("sorgi_sword", 250);
	set_skill("sword", 200);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("combat", 200);
	set_skill("unarmed",150);
	set("title", "『她是小喇叭的女朋友』");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
            (:command("exert sorgi_sword"):),
            }) );

	
	setup();
	carry_object("/u/m/mulder/area/npc/wp/finalsword.c")->wield();
	carry_object("/obj/cloth.c")->wear();
	carry_object("/u/l/luky/obj/fighterneck.c")->wear();
	
}
void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("id") != "mulder")
        
 {	
	message_vision("深田恭子對$N說道：" HIW "你好!你好....^_^。\n" NOR,me);
        command("wink" + me->query("id"));
	
 }
	 
	else
 {
	command("say 小喇叭我好掛念你呀^ˍ^\n");
	command("wink mulder");
	command("kiss mulder");
 }
 }


