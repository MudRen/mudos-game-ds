//標準商人繼承檔(有存量的)	- by Luky -
//
//	只要NPC繼承此檔, 即可利用以下方式變成商人
//
// void init() 
// {
//   add_action("do_sell","sell");
//   add_action("do_list","list");
//   add_action("do_buy" ,"buy");
// }
// 
//  1. 這裡的 do_sell,do_list,do_buy是固定的, 但是後面的指令字串可以自訂.
//  2. 人物需要設一個暫存貨物的房間, 用 set("storeroom","路徑檔名"); 設定之.
//     檔名不用加".c".
//  3. 關於暫存貨物房間的寫法參考 /u/l/luky/shop.c
//  4. list 可以用< list wp > 列出武器.< list eq >列出防具.
//  5. 可用指令參數:
//		"  看存貨請用 <list>      <list wp>       <list eq>       "
//		"  要買東西用 <buy 物品>  <buy 數量 物品>                 "
//		"  要賣東西用 <sell 物品> <sell all>      <sell 數量 物品>"
//
// 增加試穿功能 (注意修改)
#include <dbase.h>
#include <ansi.h>
inherit F_VENDOR;
object stroom;
string args;
int sort_item(object ob1, object ob2);
void create()
{
	seteuid(getuid());
}

string item_list(object ob,int amount,object ppl,int rule)
{
	if(rule) 
	{
	   return sprintf("  %4d%-4s  %8d .......... %s\n",
	   amount,ob->query("unit"),ob->query("value"),ITEM_D->item_desc(ob,ppl));
	} else
	{
       return sprintf("  %4d      %8d .......... %s  [狀況→%d%%] \n",
       amount,ob->query("value"),ITEM_D->item_desc(ob,ppl),ob->query_durable());
	}
}

int do_sell_all(object me)
{
	object *inv,*goods;
	int i,money,world,cost;
	money=0;
	inv = all_inventory(me);
	for(i=0;i<sizeof(inv);i++)
	{
	 if( inv[i]->query("value")<20 ) continue;
	 if( inv[i]->query("secured") ) continue;
	 if( inv[i]->query("equipped") ) continue;
	 if( inv[i]->query("money_id") ) continue;
	 if( inv[i]->query("no_drop") ) continue;
	 if( inv[i]->query("no_sell") ) continue;
	 if( inv[i]->is_character() ) continue;

     cost = (inv[i]->query("value") * (70+random(10)) / 100) * inv[i]->query_durable() / 100;
	 message_vision("  $N以"+cost+"的價錢將"+inv[i]->name()+"賣給了$n。\n",me,this_object());
	 money+=cost;
	 inv[i]->move(stroom);
	}
	if(money<1)
	{
		tell_object(me,"  你沒有東西可以賣了。\n");
		return 1;
	}
	world = me->money_type();
	if(world!=3) tell_object(me,"\n  你共獲得"+price_string(money,me->money_type())+"。\n");
	else tell_object(me,"你的存款帳號增加了"+money+"個單位電子幣。\n");
	me->receive_money(money);
	goods = all_inventory(stroom);
	if(sizeof(goods)>100)
	{
		for(i=100;i<sizeof(goods);i++)	destruct(goods[i]);
	}
	me->save();
	return 1;
}


int do_sell(string arg)
{
	object ob,*inv,obj,ob1,ob2,me,*goods;
	string item,who;
	int valu,i,amount,world;
	me=this_player();
	load_object(this_object()->query("storeroom"));
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	if(!arg) return notify_fail("你要賣什麼東西？\n");
	if(sscanf(arg,"%s to %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return 0;
	}
	if(sscanf(arg,"%d %s",amount,item)==2) // AMOUNT
	{
	  if(amount<1) return notify_fail("你要賣幾個啊？\n");
	  if(amount>10) return notify_fail("一次最多賣十個。\n");
	  for(i=0;i<amount;i++)
	  {
	  	do_sell(item);
	  }
	 return 1;
	} //END of AMOUNT

	if(arg=="all")
 	{
		do_sell_all(me);
		return 1;
 	}
	 if(!ob=present(arg,me))
 	 return notify_fail("你沒有這樣東西。\n");
 	 valu=ob->query("value");
 	 if( ob->query("money_id") )
 		return notify_fail("嗯..賣錢? 我不幫人洗錢的。\n");
 	 if( valu<20 )
		 return notify_fail("這東西不值錢。\n");
 	 if(ob->query("secured"))
 		return notify_fail("請先解除保存狀態。\n");
 	 if( ob->query("no_drop") )
 		return notify_fail("這個東西很特別, 你還是自己保管好了。\n");
 	 if( ob->query("no_sell"))
 		return notify_fail("我不收購這種東西。\n");
 	if( ob->is_character() ) return notify_fail("我不收購活的東西。\n");
 	 if(ob->query("equipped"))
 		return notify_fail("請先卸除下來好嗎？\n");

	arg = ob->query("id");
    valu = (valu * (70+random(10)) / 100) * ob->query_durable() / 100;
	world = me->money_type();
	if(world!=3) message_vision("$N賣了一"+ob->query("unit")+ob->query("name")+"給$n, $n給了$N"
		+price_string(valu,me->money_type())+"。\n",me,this_object());
	else message_vision("$N賣了一"+ob->query("unit")+ob->query("name")+"給$n, $n將"
		+valu+"個單位的電子幣存入$N的帳號之中。\n",me,this_object());
	me->receive_money(valu);
	ob->move(stroom);
	goods = all_inventory(stroom);
	if(sizeof(goods)>100)
	{
		for(i=100;i<sizeof(goods);i++)	destruct(goods[i]);
	}
	me->save();
	return 1;
}

int do_list(string arg)
{
	object *goods,stroom,me;
	string list,who;
	int i,amount,k;
	me=this_player();
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	stroom->set("stroom",1);
	amount = 1;
	k=1;
	//stroom=find_object(this_object()->query("storeroom"));
    if(arg && sscanf(arg,"%s from %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return 0;
    } else if(arg && sscanf(arg,"from %s",who)==1)
	{
		if(!this_object()->id(who)) return 0;
		arg="";
	}
	goods = all_inventory(stroom);
	//goods = F_QUANTITY->sortinv(stroom);
	list = "\n\n┌───────────────────────────────┐\n";
	list +="│  存量      單  價            種類  目前可以購買的貨品清單    │\n";   
	list +="└───────────────────────────────┘\n";
	if(stringp(arg))
	{
	  list = "\n\n┌───────────────────────────────┐\n";
	  list +="│  編號      單  價            種類  目前可以購買的貨品清單    │\n";   
	  list +="└───────────────────────────────┘\n";
		for(i=0; i<sizeof(goods); i++)
		{
			if(goods[i]->id(arg))
			{
				list += item_list(goods[i],k,me,0);
				k++;
			}
		}
			list +="\n";	
			if(i==0) return notify_fail(this_object()->query("name")+"對你說: 對不起唷..貨都賣完了。\n");
			else me->start_more(list);
			return 1;
	}
	goods = sort_array(goods, "sort_item", this_object());
	for(i=0; i<sizeof(goods); i++)
	{
	 if( i+1 < sizeof(goods) )
	 {
	  if( base_name(goods[i])==base_name(goods[i+1]) )
	  	amount++;
	  else 
	  {
	    list+= item_list(goods[i],amount,me,1);
	    amount = 1;
	  }
	 } else
	 {
	    list+= item_list(goods[i],amount,me,1);
	 }
	}
	list +="\n";
	if(i==0) return notify_fail(this_object()->query("name")+"對你說: 對不起唷..貨都賣完了。\n");
	else me->start_more(list);
	return 1;	
}

int do_buy(string arg)
{
	int amount,valus,i,world;
	object *goods,ob,me;
	string item,who;
	
	me=this_player();
	
	if(!arg) return notify_fail("你要買什麼東西？\n");
	if(sscanf(arg,"%s from %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return 0;
	}
	load_object(this_object()->query("storeroom"));
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	goods = all_inventory(stroom);
	if(sscanf(arg,"%d %s",amount,item)==2)
	{
	 if(amount < 1) return notify_fail("至少要買一個吧。\n");
	 if(amount >10) return notify_fail("一次最多只能買十個。\n"); //避免迴圈過長
	 for(i=0;i<amount;i++)
	 {
	  do_buy(item);
	 }
	 return 1;
	}
	
	if(ob=present(arg,stroom))
	{
	  if( (ob->query_weight()+me->query_encumbrance())>me->query_max_encumbrance() )   
 		return notify_fail("你拿不動這個東西了。\n");
 	  if( (int)me->query_capacity() + (int)ob->query("volume") > (int)me->query_max_capacity() )
 		return notify_fail("你身上放不下這麼多東西。\n");
 	  if(!me->can_afford(ob->query("value")))
		return notify_fail("你身上的錢不夠。\n");
	  valus=ob->query("value");
	  me->receive_money(-valus);
	  world = me->money_type();
	  if(world!=3) message_vision("$N付了$n"+price_string(valus,me->money_type())+", $n立刻拿了一"+ob->query("unit")+ob->name()+"給$N。\n",me,this_object());
	  else message_vision("$N傳送了"+valus+"個單位的電子幣給$n, $n立刻拿了一"+ob->query("unit")+ob->name()+"給$N。\n",me,this_object());
	  ob->move(me);
	  stroom->save();
	  me->save();
	  return 1;
	}
	else return notify_fail("你想要買什麼啊??\n");
}

int do_try(string arg)
{
	object goods,me;
	string who;
	me=this_player();
	if(!arg) return notify_fail("你要試什麼東西？\n");
	if(sscanf(arg,"%s from %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return 0;
	}
	load_object(this_object()->query("storeroom"));
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	goods = present(arg,stroom);
	if(!goods) return notify_fail("沒有賣這個東西。\n");
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

int sort_item(object ob1, object ob2)
{
	return strcmp(base_name(ob1),base_name(ob2));
}

int is_shopman()
{
	return 1;
}
