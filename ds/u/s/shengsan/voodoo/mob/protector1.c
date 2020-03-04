#include <path.h>
inherit NPC;

void create()
{
	set_name("貼身護法", ({"body protector","body"}) );
	set("race", "人類");
	set("gender", "男性");
	set("level",64);
	set("age", 32);
	set("long", "他正在保護教主的安全\n");
        set_skill("unarmed", 70);
        set_skill("dodge", 150);
	set_skill("whip", 180);
	setup();

	add_money("coin",500);
	carry_object(SHENGSAN+"voodoo/eq/goldwhip")->wield();
}

void init()
{
  if (this_player()->query_temp("voodoo")==1)
  {
	say("一條人影從你身旁飛了過來﹐身手矯健﹐顯是武功\不弱。\n");
	command("say 教主, 屬下來遲, 待我將這賊人解決再向您請罪﹗\n");
	kill_ob(this_player());
  }
}
