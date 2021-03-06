#include <ansi.h>
inherit NPC;
void consider();
void create()
{
	set_name("方印大師", ({ "fung ying bonze", "bonze"}) );
	set("gender", "男性");
     set("level",35);
	set("age", 60);
	set("long","他是一位得道高僧，不知為何會在此處。\n");
        set("talk_reply","吾等被困於此，無法脫身啊！我看你是幫不上忙的。");
        set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: consider :),
	}) );
	set_skill("unarmed", 80);
	set_skill("staff", 70);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 90);
	setup();
        carry_object(__DIR__"wp/staff")->wield();
        carry_object(__DIR__"eq/b_cloth")->wear();
        carry_object(__DIR__"eq/neck")->wear();
        carry_object(__DIR__"eq/b_boots")->wear();
}
void consider()
{
	int i, flag = 0;
	object *enemy;

	enemy = query_enemy() - ({ 0 });
	for(i=0; i<sizeof(enemy); i++) {
		if( !living(enemy[i]) ) continue;
		if( enemy[i]->query_temp("weapon") ) {
			flag++;
			if(	!query_temp("weapon") ) {
				command("say " + RANK_D->query_respect(enemy[i]) + "既然使兵刃﹐老納空手接招未免不敬。");
				command("wield staff");
				command("say 進招吧﹗");
				break;
			}
		}
	}
	if( !flag && query_temp("weapon") ) {
		if( sizeof(enemy) > 1 )
			command("say 嗯... 既然" + chinese_number(sizeof(enemy)) + "位都是空手﹐老納理當奉陪﹗");
		else
			command("say 既然" + RANK_D->query_respect(enemy[0]) + "不使兵刃﹐老納自然奉陪﹗\n");
		command("unwield staff");
                command("come");
	}
}
