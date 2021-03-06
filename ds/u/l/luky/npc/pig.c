// 小豬豬			by shengsan
// 可以騎乘的範例
// 註: 不僅是活的生物可以騎乘, 就算是沒有生命的東西也可以, 例如 筋斗雲
//     只要加上 set("ridable",1); 就可以騎乘
inherit NPC;

void create()
{
	
	set_name("小毛豬",({"pig"}) );
	set("race", "野獸");
	set("level",10);
	set("age",31);
	set("long", "一隻可愛的小毛豬。\n");
	set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"}));
	set("verbs", ({"bite"}));
	set("ridable",1);		// 設定為可騎乘的
	setup();
}

int ride_before_action(object me)	// 騎乘之前會執行函式
{
	int s = me->query("str");
	if( s<10 || !s )
	{
		message_vision("由於$N的力量不夠，無法控制"+this_object()->name()+"，因而被"+this_object()->name()+"從小豬背上摔了下來！\n",me);
		return 0;		// 回傳 0 就是代表不能騎乘
	}
	else 	message_vision("$N拿出皮鞭對著"+this_object()->name()+"揮動幾下。\n",me);
		return 1;		// 回傳 1 就是代表可以騎乘

}

int ride_after_action(object me)	// 騎乘之後會執行函式
{
	message_vision("$N騎上了"+this_object()->name()+"露出一副很得意的樣子。\n",me);
	return 1;			// 必須要回傳 1
}


int ride_off_action(object me)		// 離開座騎之後會執行函式
{
	message_vision("$N如釋重負, 高興的齁齁叫。\n",this_object());
	return 1;			// 必須要回傳 1
}

int accept_object(object me,object obj)
{
	message_vision("$N乖乖的趴了下來。\n",this_object());
	return 1;
}