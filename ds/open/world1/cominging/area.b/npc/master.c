#include <ansi.h>
#include <path.h>
inherit NPC;
void create()
{
    set_name(WHT"楊雙亟"NOR,({"master yang","yang","master"}));
	set("long" ,"他，就是疾風門近來武功\突飛猛進的人，在進日以來\n"
	            "常有許\多武林上的高手找他挑戰，但都是敗傷而去，\n"
		    "頗有青出於藍於軒轅武的樣子。\n");
	set("nickname", "傲嘲江湖" );
	set("attitude", "friendly"); 
	set("age", 35);
	set("gender","男性");
	set("combat_exp", 79000+random(4500));
    set("level", 40);
	set("title","《疾風門》光明右使" );
	set("class1","疾風門");
	create_family("疾風門",10,"光明右使");

	set_skill("unarmed", 80);
	set_skill("sword",70);
	set_skill("dodge", 80);
	set_skill("force", 70);
	set_skill("parry", 100);
    set_skill("fogseven",60);
	set_skill("sorgi_sword",70);
    map_skill("dodge","fogseven");
	map_skill("sword","sorgi_sword");

	set("guild_skills",([
		"dodge" : ({ 140,2,50 }),
		"parry" : ({ 140,2,50 }),
		"unarmed":({ 150,2,50 }),
		"sorgi_sword" : ({ 140,2,50 }),
		"sword" : ({ 145,3,50 }),
        "fogseven" : ({ 160,2,40 }),
	]));
	// 設定屬性分配表, 每一項的值在負9至正10之間
	// 而且四項的總和要剛好等於 20			by shengsan
	set("guild_gifts",({8,5,0,7}));
	set("adv_class",1);
	set("chat_chance",5);
	set("chat_msg", ({
	"楊雙亟不停的在房子裡走來走去，似乎有些煩腦。\n",
	(:command("sigh"):),
	}));
    set("chat_chance_combat",75);
    set("chat_msg_combat",({(:command,"exert sorgi_sword":)}));
	set("inquiry/小狅","他就是我兒子，有什麼事嗎？\n");
	setup();
    carry_object(__DIR__"eq/shangsword")->wield();
}
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
	add_action("do_advance","advance");
	add_action("do_join","join");
}

int do_skill_list(string arg)
{
	return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
	return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}

int do_join(string arg)
{
	tell_object(this_player(),"對不起喔..現在維修期間還不能加入本門。\n");
	return 1;
}

int do_advance(string arg)
{
	if (this_player()->query("family/family_name")=="疾風門") return GUILDMASTER->do_advance(this_object(),this_player(),arg);
	else return notify_fail("你不是疾風門的弟子。\n");
}
