//標準商人繼承檔(無存量的)	- by Luky -
//
//	只要NPC繼承此檔, 即可利用以下方式變成小販
//
// void init() 
// {
//	::init();
//   add_action("do_list","list");
//   add_action("do_buy" ,"buy");
// }
// 
//  1. 這裡的 do_list,do_buy是固定的, 但是後面的指令字串可以自訂.
//  2. 人物需要設定物品清單, 清單為 mapping 型式, 格式為 "檔名" : <消耗補給點數>
//     檔名不用加".c", 玩家的補給點數上限為 <人物等級*20> . 消耗後會自動慢慢增加至上限.
//        set("sell_list",([	
//            "/u/l/luky/npc/item/bag"    : 25, //表示每買一個袋子會扣15點補給點數
//            "/u/l/luky/npc/item/dump"    : 15,
//        ]) );
//  5. 可用指令參數:
//		"  看貨品目錄請用 <list>   "
//		"  要買東西用 <buy 物品>  <buy 數量 物品> "
//
#include <dbase.h>
#include <ansi.h>
inherit F_VENDOR;
string args;

void create()
{
	seteuid(getuid());
}
/*
string item_desc(object ob)
{
	if(ob->query("skill_type")) return HIG+"武器"+NOR;
	else if(ob->query("armor_type")) return HIY+"防具"+NOR;
	else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap")) return HIC+"回復"+NOR;
	else if(ob->is_food()) return HIM"食物"NOR;	// by shengsan
	else return "道具";
}

string item_list(object ob)
{
	   return sprintf("%8d .............. %4s %s%-26s",
	   ob->query("value"),item_desc(ob),ob->query_autoload()? HIR"*"NOR:" ",ob->short()
	   );
}
*/
int do_list(string arg)
{
	object goods,me;
	mapping item;
	string list, *file,who;
	int i,*supply_cost,debug;
	
	me=this_player();
	
	if(wizardp(me) && me->query("env/debug")) debug=1;
		else debug=0;
    if(arg && sscanf(arg,"%s from %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return 0;
    } else if(arg && sscanf(arg,"from %s",who)==1)
	{
		if(!this_object()->id(who)) return 0;
		arg="";
	}
	if(!mapp(item = query("sell_list")) )
	{
		write("這位小販沒有物品列表！\n");
		return 0;
	}
	file =  keys(item);
	supply_cost = values(item);
	list = "\n\n┌───────────────────────────┐\n";
	list +="│ 價 錢                種類  目前可以購買的貨品清單    │\n";   
	list +="└───────────────────────────┘\n";
	for(i=0; i<sizeof(file); i++)
	{
	    file[i]=resolve_path("/", file[i]);
	    goods = load_object(file[i]);
	    if(goods) list+= ITEM_D->item_list(goods,me);
	    if(debug) list+= sprintf(GRN+" SP:(%3d)\n"+NOR,supply_cost[i]);
	    	else list+="\n";
	}
	list +="\n";
	if(i==0) return notify_fail(this_object()->query("name")+"對你說: 對不起唷..貨都賣完了。\n");
	else me->start_more(list);
	return 1;	
}

int do_buy(string arg)
{
	int amount,valus,i,j,*supply_cost,world;
	object goods,ob,me;
	string item,*file,who;
	mapping items;

	me=this_player();
	if(!arg) return notify_fail("你要買什麼東西？\n");
	if(sscanf(arg,"%s from %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return notify_fail("你要跟誰買東西？\n");
    	}

	if(!mapp(items = query("sell_list")) )
	{
		write("這位小販沒有物品列表！\n");
		return 0;
	}
	if(sscanf(arg,"%d %s",amount,item)!=2)
	{
	  amount=1;
	  item = arg;
	} else
	if(amount > 20)
	{
		write("為減少系統負擔. 數量將自動調整為上限20個。\n");
		amount=20;
	}
	file =  keys(items);
	supply_cost = values(items);
	for(i=0; i<sizeof(file); i++)
	{
		file[i]=resolve_path("/", file[i]);
	    goods = load_object(file[i]);
	    if(goods)
	    {
	    	if(goods->id(item))
	    	{
	    	 if(!me->can_afford(goods->query("value")*amount))
		 	return notify_fail("你身上的錢不夠。\n");
	    	 if( (goods->query_weight()*amount+me->query_encumbrance())>me->query_max_encumbrance() )
 			return notify_fail("你拿不動這麼多東西。\n");
 		 if( (int)me->query_capacity() + (int)goods->query("volume")*amount > (int)me->query_max_capacity() )
 			return notify_fail("你身上放不下這麼多東西。\n");
		 if( me->query("supply_point") < supply_cost[i]*amount)
		 	return notify_fail(this_object()->query("name")+"對你說: 你已經買了不少東西了..還是等過一會兒再來買吧.. 。\n");
	    	 if( amount < 1 ) return notify_fail("至少要買一個吧。\n");
	    	 valus=goods->query("value")*amount;
	    	 me->receive_money(-valus);
	    	 me->add("supply_point",-supply_cost[i]*amount);
	    	 world = me->money_type();
	  	if(world!=3) message_vision("$N花了"+price_string(valus,me->money_type())+"向$n買了"+
	    	 	  		chinese_number(amount)+goods->query("unit")+goods->name()+"。\n",me,this_object());
	  	else message_vision("$N花了"+valus+"個單位的電子幣向$n買了"+
	    	 	  		chinese_number(amount)+goods->query("unit")+goods->name()+"。\n",me,this_object());

	    	 for(j=0;j<amount;j++)
	    	 {
	    	  ob = new_ob(file[i]);
	    	  if(ob->is_character()) ob->move(environment(me));
	    	  else ob->move(me);
	    	  me->save();
	    	 }
	    	 return 1;
	    	}
	    }
	}
	return notify_fail(this_object()->query("name")+"沒有賣這種東西。\n");
}

int do_try(string arg)
{
	int i,check=0;
	object goods,me;
	string *file;
	mapping items;

	me=this_player();
	if(!arg) return notify_fail("你要試什麼東西？\n");
	if(!mapp(items = query("sell_list")) )
	{
		write("這位小販沒有物品列表！\n");
		return 0;
	}

	file =  keys(items);
	check=0;
	for(i=0; i<sizeof(file); i++)
	{
	    file[i]=resolve_path("/", file[i]);
	    goods = load_object(file[i]);
	    if(goods->id(arg)){
	    	 check = 1;
	    	 break; 
	    }
	}
	if(!check) return notify_fail("沒有賣這個東西。\n");
	if(goods->query("skill_type")) //weapon
	{
		if(me->query("race")!="human")
		{
			if(!goods->query(me->query("race")+"_weapon_prop"))
			{
				return notify_fail("這個"+goods->name()+"並不適合你使用。\n");
			}
		} else
		if(!goods->query("weapon_prop"))
		{
			return notify_fail("這個"+goods->name()+"並不適合你使用。\n");
		}
		if( goods->query("female_only")	&& (string)me->query("gender") != "女性" )
			return notify_fail(goods->name()+"是女人專用的武器。\n");
		if( goods->query("male_only") && (string)me->query("gender") != "男性" )
			return notify_fail(goods->name()+"是男人專用的武器。\n");
		if( goods->query("limit_lv") > me->query("level") )
			return notify_fail("你的等級太低，無法裝備"+goods->name()+"。\n");
		if( goods->query("limit_con") > me->query_con() )
			return notify_fail("你的體型不夠，無法裝備"+goods->name()+"。\n");
		if( goods->query("limit_str") > me->query_str() )
			return notify_fail("你的力量不夠，拿不動"+goods->name()+"。\n");
		if( goods->query("limit_int") > me->query_int() )
			return notify_fail("你不夠聰明，不懂得怎麼使用"+goods->name()+"。\n");
		if( goods->query("limit_dex") > me->query_dex() )
			return notify_fail("你試著裝備"+goods->name()+"，可是你反應太慢了不小心打到自己。\n");
		if( goods->query("limit_skill") > me->query_skill((string)goods->query("skill_type"),1) )
			return notify_fail("你嘗試使用"+goods->name()+"，可是你的技巧不夠。\n");
		
		write("你試著使用"+goods->name()+"當武器，感覺起來還不錯。\n");
		return 1;
	}
	 else if(goods->query("armor_type"))
	{
		if(me->query("race")!="human")
		{
			if(!goods->query(me->query("race")+"_armor_prop"))
			{
				return notify_fail("這個"+goods->name()+"並不適合你使用。\n");
			}
		} else
		if(!goods->query("armor_prop"))
		{
			return notify_fail("這個"+goods->name()+"並不適合你使用。\n");
		}
		if( goods->query("female_only")
		&&	(string)me->query("gender") != "女性" )
			return notify_fail(goods->name()+"是女性專用的裝備。\n");
		if( goods->query("male_only")
		&&	(string)me->query("gender") != "男性" )
			return notify_fail(goods->name()+"是男性的專用裝備。\n");
		if( goods->query("limit_lv") > me->query("level") )
			return notify_fail("你的等級太低，無法裝備"+goods->name()+"。\n");
		if( goods->query("limit_con") > me->query_con() )
			return notify_fail("你的體型不夠，無法裝備"+goods->name()+"。\n");
		if( goods->query("limit_str") > me->query_str() )
			return notify_fail("你的力量不夠，無法裝備"+goods->name()+"。\n");
		if( goods->query("limit_int") > me->query_int() )
			return notify_fail("你不夠聰明，不懂得怎麼裝備"+goods->name()+"。\n");
		if( goods->query("limit_dex") > me->query_dex() )
			return notify_fail("你想要裝備"+goods->name()+"，可是你動作慢吞吞的，穿不上去。\n");
		if( goods->query("max_lv") < me->query("level") && goods->query("max_lv")>1)
			return notify_fail(goods->name()+"是低等級專用的裝備。\n");
		
		write("你試著裝備"+goods->name()+"，感覺很合身。\n");
		return 1;
	}
	return notify_fail("你想試用"+goods->name()+"，只見"+this_object()->name()+"很疑惑的看著你。\n");
}


int is_sellman()
{
	return 1;
}
