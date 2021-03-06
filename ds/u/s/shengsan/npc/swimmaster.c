// swimmaster.c		游泳教練	by Shengsan@DS
// 此範例中 master 的技能可以讓任何職業的人學習
inherit NPC;

void create()
{
	set_name("藍天級游泳教練",({"instructor","master"}));
	set("gender", "男性");
	set("long","他是藍天工會裡資深的游泳教練。\n");
	set("adv_class",2);
	set("class1","gigi");
	set("class2","blue");
	// 如果 no_join 有設非 0 的值, 任何人都可以學此導師身上的技能
	set("no_join",1);
	set("level",50);
	set("age",40);
        set("guild_skills",([	// 難度, 等級1可學, 上限
		"swim":({30,2,50}), // 游泳技能
        ]) );
   	setup();
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
}

int do_skill_list(string arg)
{
	return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}

int do_skill_train(string arg)
{
	return GUILDMASTER->do_skill_train(this_object(),this_player(),arg);
}
