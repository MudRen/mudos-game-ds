// Spinner
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("劉靖文",({ "liu chen wen","spinner","liu","wen" }));
	set("long",@LONG
她是一個紡織工人，她身形窈窕，留了個馬尾，她專門在從事於紡
織的工作，如果你有從布商那買到一些布，可以給她去做一些衣服
穿，不過前提的是，你一定要有些錢，不然她可是買不到材料去做
的喔。
LONG
	);
	set("nickname","紡織坊");
	set("gender","女性");
	set("age",18+random(10));
	set("no_fight",1);
	set("chat_chance", 3);
	set("chat_msg", ({
  (: command,"sweat" :),
  this_object()->name()+"不停的在編織衣服。\n",
  (: command,"say 最近托我織衣服的人越來越少了...." :),
  this_object()->name()+"想到這不禁掉了幾滴眼淚\...\n",
  (: command,"sigh" :),
}) );
	set("inquiry",([
  "織布" : "織布是我的專長，我從小做到大都是這樣子熬過來的。",
  "help" : "只要給我一塊布，和一點工錢，我就可以幫您做件好衣服。",
]));
	setup();
	add_money("silver", 1);
}

int talk_action(object me)
{
	if(this_object()->query_temp("editing"))
	{
		message_vision("$N似乎因為太專心工作了而沒有聽到$n說的話。\n",this_object(),me);
		return 1;
	}
	message_vision("$N自言自語："HIB"最近所要織的越來越少了，不知道該用什麼以度生活..\n"NOR,this_object());
	message_vision("$N說："HIY"您需要我幫忙(help)做新衣服嗎！\n"NOR,this_object());
	return 1;
}

int accept_object(object me, object ob)
{
	int moneya;
	string money_type;
	if(this_object()->query_temp("editing"))
	{
		return notify_fail("她正在工作中，沒空收你的東西。\n"NOR);
	}
	
	if( !ob->query("cloth") )
	{
		if( !me->query_temp("spinner") )
			return notify_fail("你要先給她一塊布，她才會收你的錢喔... :)\n");
		if( !(money_type=ob->query("money_id")) )
			return notify_fail("她只收布料和工錢。\n");
		if( money_type!="coin" && money_type!="silver" && money_type!="gold")
			return notify_fail("她只古代可以用的錢。\n");
		moneya = ob->value();
		if(moneya<100) return notify_fail("你想了想覺得似乎少了點。\n");
		message_vision("$N給$n了一些"+ob->name()+"。\n",me,this_object());
		call_out("working",0,me,moneya);
                return 1;
	}
		
	if( me->query_temp("giving_1") )
		return notify_fail("劉靖文說："HIY"您已經給我一塊布了, 再給我一些工錢我就可以開始做了。\n"NOR);
	message_vision("$N給了$n一塊"+ob->name()+"。\n",me,this_object());
	tell_object(me,"劉靖文說："HIY"ㄚ.. 太好了, 只要您再給我一些工錢我就可以開始幫您做衣服了。\n"NOR);
	me->set_temp("spinner",ob);
	me->set_temp("giving_1",1);
	return 1;
}

void working(object me,int moneys)
{
	object m;
	int c_out;
	
	m = me->query_temp("spinner");
	command("thank "+me->query("id"));
	message_vision("$n在感謝$N之後，趕緊把$N所給$p的材料放在工作台上開始裁了起來！\n",me,this_object());

	// luky fixed
	if( moneys > 999 ) c_out=0;
	else if( moneys > 499 ) c_out=3;
	else c_out=5;

	call_out("editing",c_out+3  , 0);
	call_out("editing",c_out+7  , 1);
	call_out("editing",c_out+10 , 2);
	call_out("setting",c_out+11 , c_out , m , me);
	return;
}

int editing(int flag)
{
	if( flag == 0 ) message_vision(HIC"$N把裁好的布料拿到縫紉機上開始 [ 噠噠噠..]的縫製起來。\n"NOR,this_object());
	if( flag == 1 ) message_vision(HIG"$N繼續努力的在縫紉機前工作。\n"NOR,this_object());
	if( flag == 2 )
	{
		this_object()->delete_temp("editing");
		message_vision(HIY"$N拿起縫好的衣服修剪了一下, 一件衣服就這麼完成了！！\n"NOR,this_object());
	}
	return 1;
}

void setting(int c,object m,object me)
{
	int kind;
	object d_cloth;
	d_cloth = new(__DIR__"eq/defaulteq.c");

	// 0 烏蠶絲布, 1 紫梓布, 2 藍布,3 銀絲,4 絲絨,5 粗蠶布,6 錦緞
	kind=m->query("cloth")-1;
	switch( kind )
	{
	 case 0: // 烏蠶絲布
		d_cloth->set_name(WHT"烏蠶寶衣"NOR,({ "gray silkworm dress","dress"}));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",8+random(4));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",5+random(3));
				break;
//luky			case 5:
			default:
				d_cloth->set("armor_prop/armor",3+random(3));
				break;
		}
		break;
	 
	 case 1: // 紫梓布
		d_cloth->set_name(MAG"紫色長袍"NOR,({ "purple robe","robe" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",6+random(5));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",4+random(4));
				break;
			default:
				d_cloth->set("armor_prop/armor",3+random(3));
				break;
		}
		break;

	 case 2: // 藍布
		d_cloth->set_name(HIC"藍色寶衣"NOR,({ "blue cloth","cloth" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",7+random(4));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",5+random(4));
				break;
			default:
				d_cloth->set("armor_prop/armor",3+random(3));
				break;
		}
		break;
		
	 case 3: // 銀絲
		d_cloth->set_name(HIM"銀絲衣"NOR,({ "argentine cloth","cloth" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",6+random(4));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",4+random(4));
				break;
			default:
				d_cloth->set("armor_prop/armor",2+random(4));
				break;
		}
		break;
	 
	 case 4: // 絲絨
		d_cloth->set_name(HIW"絲絨衫"NOR,({ "villosity dress","dress" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",4+random(3));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",3+random(3));
				break;
			default:
				d_cloth->set("armor_prop/armor",2+random(3));
				break;
		}
		break;
	 
	 case 5: // 粗蠶布
		d_cloth->set_name(WHT"粗蠶布衣"NOR,({ "coarseness bombyx cloth","cloth" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",7+random(4));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",5+random(4));
				break;
			default:
				d_cloth->set("armor_prop/armor",3+random(4));
				break;
		}
		break;
	 
	 default: // 錦緞(6)
		d_cloth->set_name(HIY"錦袍"NOR,({ "filamentus robe","robe" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",5+random(4));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",4+random(4));
				break;
			default:
				d_cloth->set("armor_prop/armor",3+random(4));
				break;
		}
		break;
	}
	
	if(!me) //凡是有delay都要考慮玩家斷線或quit
	{
	 return;
	}
	
	if(environment(me)!=environment(this_object())) //玩家離開了?
	{
		d_cloth->set("long",d_cloth->query("long")+"\n這是專為"+me->name(1)+"量身定做的。\n");
		d_cloth->move(environment(this_object()));
	 	me->delete_temp("spinner");
		me->delete_temp("giving_1");
		tell_object(me,"你突然想到, 剛才訂做的衣服應該好了吧...\n");
		destruct(m);
		return;
	}
	
	message_vision("$n給了$N一件"+d_cloth->name()+"。\n",me,this_object());
	d_cloth->move(me);
	d_cloth->set("long",d_cloth->query("long")+"[這是專為"+me->name(1)+"量身定做的"+d_cloth->name(1)+"。]\n");
	me->delete_temp("spinner");
	me->delete_temp("giving_1");
	destruct(m);
	return;
}
