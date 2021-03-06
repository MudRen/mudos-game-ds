#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
//inherit SHOPMAN;
void create()
{
//=========================基本設定==========================

        set_name( "酒店老闆", ({ "bar boss","boss"}));
        set("long",@LONG
        一個微胖的男人，正在對著你哈腰。
	==============================================
	查詢菜單 <list>
	買東西 <buy 物品> <buy 數量 物品>
	==============================================
LONG);
        set("level",17);
        set("gender", "男性");
        set("race", "human");
        set("age", 33);
        set("evil",-10);			//邪惡度 20 (正的表邪惡, 負表善良)

	set("attitude", "peaceful");   //溫和的 NPC。
	set("talk_reply","只要廚房不缺材料，這裡的排餐\可是一極棒的喔!!");
	set("storeroom",__DIR__"bar_shoproom");	//注意. 要建立一個room放東西

//===========================問題回答==================================
set("inquiry/name", @LONG
  [1;36m 我叫做周朝先.. 請多指教!![m
LONG );
        setup();
      add_money("dollar", 1100);		//帶的錢
      carry_object(__DIR__"../eq/cloth_pants_5")->wear();
//      carry_object(__DIR__"../eq/cloth_hat_5")->wear();
      carry_object(__DIR__"../eq/cloth_boots_5")->wear();
      carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
}

void init()
{
	::init();
	add_action("do_list","list");
	add_action("do_buy","buy");
//	add_action("do_sell","sell");
}

int sort_item(object ob1, object ob2)
{
	return strcmp(base_name(ob1),base_name(ob2));
}
string item_desc(object ob)
{
	if(ob->query("skill_type")) return HIG+"武器"+NOR;
	else if(ob->query("armor_type")) return HIY+"防具"+NOR;
	else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap") ) return HIC+"回復"+NOR;
	else return "道具";
}

string item_list(object ob,int amount,int rule)
{
	if(rule) 
	{
	   return sprintf("  %4d%-4s  %8d .......... %4s  %s\n",
	   amount,ob->query("unit"),ob->query("value"),item_desc(ob),ob->short()
	   );
	} else
	{
	   return sprintf("  %4d      %8d .......... %4s  %s\n",
	   amount,ob->query("value"),item_desc(ob),ob->short()
	   );
	}
}
int do_list(string arg)
{
	object *goods,stroom,me;
	string list;
	int i,amount,k;
	me=this_player();
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	stroom->set("stroom",1);
	amount = 1;
	k=1;
	//stroom=find_object(this_object()->query("storeroom"));

	goods = all_inventory(stroom);
	//goods = F_QUANTITY->sortinv(stroom);
	list = "\n\n┌───────────────────────────────┐\n";
	list +="│  存量      單  價            種類  目前可以購買的菜色清單    │\n";   
	list +="└───────────────────────────────┘\n";
	if(stringp(arg))
	{
	  list = "\n\n┌───────────────────────────────┐\n";
	  list +="│  編號      單  價            種類  目前可以購買的菜色清單    │\n";   
	  list +="└───────────────────────────────┘\n";
		for(i=0; i<sizeof(goods); i++)
		{
			if(goods[i]->id(arg))
			{
				list += item_list(goods[i],k,0);
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
	    list+= item_list(goods[i],amount,1);
	    amount = 1;
	  }
	 } else
	 {
	    list+= item_list(goods[i],amount,1);
	 }
	}
	list +="\n";
	if(i==0) return notify_fail(this_object()->query("name")+"對你說: 對不起唷..肉都用完了。\n");
	else me->start_more(list);
	return 1;	
}

int do_buy(string arg)
{
	int amount,valus,i,world;
	object *goods,ob,me,stroom;
	string item;
	
	me=this_player();
	if(!arg) return notify_fail("你要買什麼東西？\n");
	//load_object(this_object()->query("storeroom"));
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
