#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(HIC"大"HIG"神"HIY"蛋"HIM"糕"NOR,({ "admin cake","cake" }) );
	set_weight(1);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
                 	★  ★       
                 	█  █       
                 	█  █      
            	   ����������������  
            	   �齱芊芊芊芊芊垀�  
           	  �齱陛陛陛陛陛陛娶� 
         	����������������������
	 	�齰H％％％％％％％％�� 
	        ����������������������
	這個生日蛋糕看起來十分華麗，蛋糕中塞滿了
	各式各樣的新鮮水果，上面還用鮮奶油擠出了
	一個龍蝦的圖案。
LONG);
	set("unit", "塊");
	set("material","food2");
	}
	setup();
	set("value",23000);
	set("food_remaining",55);
	set("heal_hp",500);
	set("heal_mp",500);
	set("heal_ap",500);
	set("volume",0);
}

void init()
{
	if(CLOCK_D->query_current_day() != 23) //限制使用日期
	{
		set("heal_hp",20);
		set("heal_ap",20);
		set("heal_mp",20);
		set("food_remaining",5);
		set("value",1000);
	}
          if(getuid(this_player())=="tmr") add_action("do_giveall","giveall");
	::init();
}

int do_giveall(string arg)
{
	int i;
	string *list=({}),*temp=({});
	object *ppl,cake;
	ppl=users();
	if(this_object()->query("gived")) list = this_object()->query("gived");
	for(i=0;i<sizeof(ppl);i++)
	{
		if(getuid(ppl[i])=="luky") continue;
		if(!cake=new(base_name(this_object()))) continue;
		if(present("admin cake",ppl[i])) continue;
		if(sizeof(list))
		{
			if(member_array(getuid(ppl[i]),list)!=-1) continue;
		}
		
		if(cake->move(ppl[i]))
		{
			tell_object(ppl[i],HIC+"\n\t【  一隻可愛的小龍蝦天使突然從天空飛了下來  】\n"+NOR);
			temp+=({getuid(ppl[i])});  //紀錄
			if(ppl[i]->query("level")<6)
			{
				tell_object(ppl[i],"\n    小龍蝦看你等級不高給了你一些經驗值和錢，幫你加油打氣。\n");
				ppl[i]->receive_money(5230);
				ppl[i]->add("exp",5230);
			}
			tell_object(ppl[i],HIY+"\n\t       小龍蝦給了你一個蛋糕就慢慢飛走了\n"+NOR);
		} else tell_object(ppl[i],HIG+"\n一隻小龍蝦從地下爬了出來看了看你，搖搖頭就走了。\n"+NOR);
	}
	write("一共送給了"+sizeof(temp)+"個玩家蛋糕。\n");
	temp+=list;
	this_object()->set("gived",temp); //儲存紀錄
	return 1;
}
