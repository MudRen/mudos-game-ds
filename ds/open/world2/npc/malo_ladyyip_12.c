#include <ansi.h>
inherit NPC;
void create()
{
	set_name("葉太太",({"mr.s yip","mr.s","yip"}) );
	set("long",@LONG
葉太太原來是一個十分開朗的人，不過自從前幾年葉先生過世之後
就變的很沈默。
LONG);
	set("age",41);
	set("title","梅龍鎮民");
	set("level",12);
	set("race","human");
	set("gender","女性");
	set("evil",-5);
	set("talk_reply","聽說有人在公園南邊的樹上看過一隻紅色的怪鳥。");
	set("chat_chance",8); 
        set("chat_msg",({
                (:command("sigh"):),
                (:command("sob"):),
        }) );
        set("inquiry", ([
        "黑影" : "我追那個黑影追到公園之後就沒看到了。\n",
        "公園" : "就是黃梅公園啊..本鎮的西南處。\n",
        "紀念品" : "那是我先生在結婚十二週年紀念日時送給我的一枚戒指。\n",
        ]));
	setup();
	carry_object(__DIR__"../eq/cloth_boots_5")->wear();
	carry_object(__DIR__"../eq/cloth_skirt_6")->wear();
	carry_object(__DIR__"../eq/cloth_robe_12")->wear();
	add_money("dollar",230);
}

void reset_quest()
{
	object ring,mob;
	if(mob=this_object()->query_temp("black_cat"))
	{
		message_vision("$N一個轉身突然跑不見了。\n",mob);
		destruct(mob);
	}
	if(ring=this_object()->query("ring"))
	{
		message_vision("$N突然消失了。\n",ring);
		ring->unequip();
		destruct(ring);
	}
	ring = new_ob(__DIR__"../eq/yip_wed_ring.c");
	mob = new_ob(__DIR__"../npc/beast_cat_4.c");
	ring->move(mob);
	mob->move("/open/world2/lichi_town_1/map_17_2");
	this_object()->set_temp("black_cat",mob);
	this_object()->set("ring",ring);
}

int talk_action(object me)
{
 object book,ring;
 if(!book=me->query_temp("notebook")) return 0;
 if(this_object()->query("have_ring"))
 {
 	command("say 戒指終於又回到我的身邊了。");
 	command("giggle");
 	return 1;
 }
 if(!book->query_step("LostRing") || random(2))
 {
  command("sob");
  command("say 我丈夫留給我的紀念品前幾天晚上被一個黑影給偷走了。");
  command("cry");
  book->add_quests_note("LostRing","葉太太的珍藏紀念品被一個黑影偷走了。");
  if(ring=this_object()->query("ring"))
  {
  	if(!environment(ring)) reset_quest();
  } 
  else 
  {
  	reset_quest();
  }
  return 1;
 }
 return 0;
}

int accept_object(object who, object ob)
{
 int exp;
 object book;
 if(book=who->query_temp("notebook"))
 {
   if(this_object()->query("have_ring"))
   {
   	command("say 我的寶貝戒指已經拿回來了。");
   	command("say 其他的東西對我而言都沒用。");
   	return notify_fail("\n");
   }
   if(ob->id("yip_wedding_ring"))
   {
   	if(!book->query_step("LostRing")) //第一次完成
   	{
   		exp=7000+random(3000);
     		book->add_quests_note("LostRing","將取回的戒指交還給葉太太。[任務完成]");
     		who->add("exp",exp);
		who->add("popularity",1);
     		book->set_quests("LostRing",1);
     		set("chat_msg",({
                (:command("smile"):),
                (:command("ccc"):),
        	}) );
        	this_object()->set("have_ring",1);
    		call_out("delay_messages",1,who,exp,1);
    		return 1;
   	}
   	else
   	{
   		set("chat_msg",({
                (:command("smile"):),
                (:command("ccc"):),
        	}) );
        	this_object()->set("have_ring",1);
                who->add("exp",300);
   		call_out("delay_messages",1,who,300,0);
    		return 1;
   	}
   } else if(ob->id("ring"))
   {
   	message_vision("$N給了葉太太一只$n。\n葉太太拿起$n看了一下...\n",who,ob);
   	command("say 這並不是我的戒指。");
   	message_vision("葉太太將$n還給$N。\n",who,ob);
   	return notify_fail("...\n");
   }
 }
 return notify_fail("\n");
}

void delay_messages(object ppl,int exp,int pub)
{
	object axe; 
	string str="";
	if(!ppl) return;
	if(this_object()->query("send_axe")) return;
	command("say 真是非常謝謝你幫我找回了戒指。");
	command("wear ring");
	command("thank "+ppl->query("id"));
	str=sprintf("你得到了%d點經驗值",exp);
	if(pub) str+=sprintf("，聲望也提升了。\n");
	else {
		str+="，與500元酬勞。\n";
		ppl->receive_money(500);
	}
	tell_object(ppl,str);
	if(axe = new_ob(__DIR__"../wp/stone_axe_18.c"))
	{
		command("say 這是先夫留下的石斧，如果您不嫌棄的話就拿去吧。");
		axe->move(environment(this_object()));
		message_vision("$N從櫃子�堮野X一把$n，並將$n放在地上。\n",this_object(),axe);
		this_object()->set("send_axe",1);
	}
	CHANNEL_D->do_channel( this_object(), "sys", sprintf("玩家(%s)達成任務[遺失的回憶]..EXP: %d Pub: %d\n",ppl->name_id(1),exp,pub));
	return;
}

void reset()
{
	object ring;
	set("chat_msg",({
                (:command("sigh"):),
                (:command("sob"):),
        }) );
        this_object()->delete("have_ring");
        if(ring = present("yip_wedding_ring",this_object()) )
        {
        	ring->unequip();
        	destruct(ring);
        }
        this_object()->delete("ring");
        this_object()->delete("send_axe");
	reset_quest();
}

void die()
{
	object ring;
	if(ring=this_object()->query("ring"))
	{
		message_vision("$N突然消失了。\n",ring);
		ring->unequip();
		destruct(ring);
	}
	::die();
}
