#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
//inherit SHOPMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�s������", ({ "bar boss","boss"}));
        set("long",@LONG
        �@�ӷL�D���k�H�A���b��ۧA���y�C
	==============================================
	�d�ߵ�� <list>
	�R�F�� <buy ���~> <buy �ƶq ���~>
	==============================================
LONG);
        set("level",17);
        set("gender", "�k��");
        set("race", "human");
        set("age", 33);
        set("evil",-10);			//���c�� 20 (�������c, �t���})

	set("attitude", "peaceful");   //�ũM�� NPC�C
	set("talk_reply","�u�n�p�Ф��ʧ��ơA�o�̪����\\�i�O�@���Ϊ���!!");
	set("storeroom",__DIR__"bar_shoproom");	//�`�N. �n�إߤ@��room��F��

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs���P�¥�.. �Цh����!![m
LONG );
        setup();
      add_money("dollar", 1100);		//�a����
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
	if(ob->query("skill_type")) return HIG+"�Z��"+NOR;
	else if(ob->query("armor_type")) return HIY+"����"+NOR;
	else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap") ) return HIC+"�^�_"+NOR;
	else return "�D��";
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
	list = "\n\n�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n";
	list +="�x  �s�q      ��  ��            ����  �ثe�i�H�ʶR�����M��    �x\n";   
	list +="�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
	if(stringp(arg))
	{
	  list = "\n\n�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n";
	  list +="�x  �s��      ��  ��            ����  �ثe�i�H�ʶR�����M��    �x\n";   
	  list +="�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
		for(i=0; i<sizeof(goods); i++)
		{
			if(goods[i]->id(arg))
			{
				list += item_list(goods[i],k,0);
				k++;
			}
		}
			list +="\n";	
			if(i==0) return notify_fail(this_object()->query("name")+"��A��: �藍�_��..�f���槹�F�C\n");
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
	if(i==0) return notify_fail(this_object()->query("name")+"��A��: �藍�_��..�׳��Χ��F�C\n");
	else me->start_more(list);
	return 1;	
}

int do_buy(string arg)
{
	int amount,valus,i,world;
	object *goods,ob,me,stroom;
	string item;
	
	me=this_player();
	if(!arg) return notify_fail("�A�n�R����F��H\n");
	//load_object(this_object()->query("storeroom"));
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	goods = all_inventory(stroom);
	if(sscanf(arg,"%d %s",amount,item)==2)
	{
	 if(amount < 1) return notify_fail("�ܤ֭n�R�@�ӧa�C\n");
	 if(amount >10) return notify_fail("�@���̦h�u��R�Q�ӡC\n"); //�קK�j��L��
	 for(i=0;i<amount;i++)
	 {
	  do_buy(item);
	 }
	 return 1;
	}
	
	if(ob=present(arg,stroom))
	{
	  if( (ob->query_weight()+me->query_encumbrance())>me->query_max_encumbrance() )   
 		return notify_fail("�A�����ʳo�ӪF��F�C\n");
 	  if( (int)me->query_capacity() + (int)ob->query("volume") > (int)me->query_max_capacity() )
 		return notify_fail("�A���W�񤣤U�o��h�F��C\n");
 	  if(!me->can_afford(ob->query("value")))
		return notify_fail("�A���W���������C\n");
	  valus=ob->query("value");
	  me->receive_money(-valus);
	  world = me->money_type();
	  if(world!=3) message_vision("$N�I�F$n"+price_string(valus,me->money_type())+", $n�ߨ讳�F�@"+ob->query("unit")+ob->name()+"��$N�C\n",me,this_object());
	  else message_vision("$N�ǰe�F"+valus+"�ӳ�쪺�q�l����$n, $n�ߨ讳�F�@"+ob->query("unit")+ob->name()+"��$N�C\n",me,this_object());
	  ob->move(me);
	  stroom->save();
	  me->save();
	  return 1;
	}
	else return notify_fail("�A�Q�n�R�����??\n");
}
