// /u/s/shengsan/mob/swimmaster.c	by shengsan  1999.01.27
// 游泳教練 亞立


#include <ansi.h>
inherit NPC;
inherit GUILDMASTER;
void randomsay();

void create()
{
	set_name("元元",({"yuan","master"}));
	set("gender", "男性");
	set("long","朝氣十足的他正在這邊。\n");
	set("adv_class",1);		// 設定導師的職業為第三級
	set("class","adventurer");	// 第一級職業為 adventurer
	set("no_join",1);
	set("level",20);
	set("age",38);
	set_skill("swim",99);
        set("guild_skills",([	// 難度, 等級1可學的上限, 上限
		"swimming":({32,3,99}),	// 游泳技能
        ]) );

        set("chat_chance", 50);
        set("chat_msg", ({
	    "元元快樂地在這邊享受大自然的朝氣。\n",
	    "元元在你面前調整了他那件鬆垮垮的泳褲，哈哈，好遜喔。\n",
                (:random_move:),
                (: randomsay :),
                (: randomsay :),
        }) );

        set("inquiry/join","阿？我現在可沒有收徒的打算，不過我倒是可以指點(list)你一下。");
	set("inquiry/swimming","還不會游泳嗎？那你也太遜囉！");
	set("inquiry/master","呵呵，誇獎了，我不是什麼工會領袖啦，只是一個游泳教練而已。");

   	setup();

	add_money("coin",30);
}

void randomsay()
{
	switch(random(5)) {
	    case 0 : command("say 請問你曾經到過傳說中的冰域嗎？"); break;
	    case 1 : command("say 嗨!!你好...我熱愛游泳，你呢？"); break;
	    case 2 : command("say 還不會游泳嗎？那你也太遜囉！趕快(list)學喔。"); break;
	    case 3 : command("snicker"); break;
	    case 4 : command("say 好久沒跟維克多聚聚了，他可是我多年的好友喔。"); break;
	    default : break;
	}

}