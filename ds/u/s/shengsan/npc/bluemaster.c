// /u/s/shengsan/npc/bluemaster.c	by shengsan
// 藍天導師				1999.03.28
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("藍天導師",({"blue","master"}));
	set("gender", "男性");
	set("long",@LONG
他是藍天工會裡資深的導師，這是藍藍的天用手捏出來的範例導師。

	list	列出可學的技能與法術列表
	train	訓練技能
	learn	學習法術
	join	加入工會
	advance	升級或增加屬性

LONG
	);
	set("level",30);		// 設定導師的等級
	set("age",40);			// 設定導師的年齡

// ========================================================================
//	adv_class: x	x = 數值(1~2)
//	此參數是說明此玩家或NPC目前的職業是第幾級, 1 就是第一級, 也就是最初
//	的職業等級, 2 就是第二級, 依此類推...
// ========================================================================
	set("adv_class",1);		// 設定他的職業等級是初級(值為1)

// ========================================================================
//	class1: x       x = 職業字串(英文)
//	這是第一級職業的職業英文名稱, 不管此玩家或NPC目前為第幾級的職業, 這
//	個參數一定要定義, 否則程式就不會正常工作... 記住, 職業歷程要完整...
// ========================================================================
	set("class1","gigi");		// 設定職業的名稱

// ========================================================================
//	工會導師可以教授的技能列表
// ========================================================================
        set("guild_skills",([	// 難度, 等級1可學到的技能等級倍率, 上限
		"dodge":({32,2,105}),	// 基本閃躲
		"blade":({30,2,90}),	// 刀法技巧
		"relieve":({30,2,30}),	// 解救技巧
        ]) );

// ========================================================================
//	工會導師可以教授的法術列表
// ========================================================================
	set("guild_spells",([		// 難度, 等級1可學, 上限
		"laugh":({60,2,105}),	// 搞笑法術
		"summon_ghost":({60,2,105}),
		"lightwall":({60,2,105}),
		"god-benison":({60,2,105}),
		"force_push":({60,2,105}),
		"god-fire":({30,2,30}),
	]) );

// ========================================================================
//	導師的屬性分配表(權數) 請 more /doc/wiz/屬性與素質.txt
// 	設定屬性分配表, 每一項的值在負9至正10之間
// 	而且四項的總和要剛好等於 20
// ========================================================================
	set("guild_gifts",({10,5,-3,8}));

   	setup();

	add_money("coin",1000);
}

void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
	add_action("do_spell_train","learn");
	if(!query("no_join") || query("no_join")!=1)
		add_action("do_guild_join","join");
	if(!query("no_advance"))
		add_action("do_advance","advance");
}

int do_spell_train(string arg)
{
	GUILDMASTER->do_spell_train(this_object(),this_player(),arg);
	return 1;
}

int do_skill_list(string arg)
{
	GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
	this_player()->set("no_check_class",1);	// 避免列出檢查職業的訊息
	write("\n");
	GUILDMASTER->do_spell_list(this_object(),this_player(),arg);
	this_player()->delete("no_check_class");
	return 1;
}

int do_skill_train(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	GUILDMASTER->do_skill_train(ob,me,arg);
	return 1;
}

int do_guild_join(string arg)
{
	object ob, me;
	int i;

	ob = this_object();
	me = this_player();

// ========================================================================
// join 加入職業, 必須要使用 do_guild_join(),
// 如果巫師要使用自己的回應方式, 請用 do_guild_join_with_no_message()
// 傳回數值, 再使用這些數值作您想做的回應方式.
// ========================================================================
	i = GUILDMASTER->do_guild_join_with_no_message(ob,me,arg);
	switch(i)
	{
		case 0:	break;
		case -1: command("say 玩家已經加入其他組織。");break;
		case -2: command("say 玩家已經加入了與導師同級或更高級的組織。");break;
		case -3: command("say 玩家目前的組織並不適合加入本組織。");break;
		case -4: command("say 玩家等級不夠。");break;
		case -5: command("say 玩家的 termstr 並沒有大於 termnum 值。");break;
		case -6: command("say 玩家的 termstr 並沒有等於 termnum 值。");break;
		case -7: command("say 玩家的 termstr 並沒有小於 termnum 值。");break;
		case -8: command("say 玩家輸入的組織錯誤或沒有輸入要加入的組織名。");break;
		default: command("say Yes...你就是我要找的人。");
	}
	
	return 1;
}

int do_advance(string arg)
{
	object ob, me;

	ob = this_object();
	me = this_player();

	GUILDMASTER->do_advance(ob,me,arg);
	return 1;
}

// ========================================================================
// 使用 advance 升級時會參考到 guild_rank() 這個函數, 這個函數可以改變
// 玩家的職業rank.
// ========================================================================
string guild_rank(object me)
{
	string rank;
	int lv;
	lv = me->query("level");

	lv = lv/10;	// 將 rank 分為六個層次

	if( me->query("gender") == "女性" )
	{
		switch( lv )
		{
			case 0: rank = HIC"GIGI派的天真少女"NOR; break;
			case 1:	rank = HIY"GIGI派的親善天使"NOR; break;
			default: rank = HIM"GIGI派的性感女神"NOR;
		}
	}
	else
	{
		switch( lv )
		{
			case 0: rank = HIC"GIGI派的清純少男"NOR; break;
			case 1: rank = HIY"GIGI派的偷心大使"NOR; break;
			default: rank = HIM"GIGI派的性感天神"NOR;
		}
	}
	return rank;
}