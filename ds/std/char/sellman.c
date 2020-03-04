//�зǰӤH�~����(�L�s�q��)	- by Luky -
//
//	�u�nNPC�~�Ӧ���, �Y�i�Q�ΥH�U�覡�ܦ��p�c
//
// void init() 
// {
//	::init();
//   add_action("do_list","list");
//   add_action("do_buy" ,"buy");
// }
// 
//  1. �o�̪� do_list,do_buy�O�T�w��, ���O�᭱�����O�r��i�H�ۭq.
//  2. �H���ݭn�]�w���~�M��, �M�欰 mapping ����, �榡�� "�ɦW" : <���Ӹɵ��I��>
//     �ɦW���Υ[".c", ���a���ɵ��I�ƤW���� <�H������*20> . ���ӫ�|�۰ʺC�C�W�[�ܤW��.
//        set("sell_list",([	
//            "/u/l/luky/npc/item/bag"    : 25, //���ܨC�R�@�ӳU�l�|��15�I�ɵ��I��
//            "/u/l/luky/npc/item/dump"    : 15,
//        ]) );
//  5. �i�Ϋ��O�Ѽ�:
//		"  �ݳf�~�ؿ��Х� <list>   "
//		"  �n�R�F��� <buy ���~>  <buy �ƶq ���~> "
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
	if(ob->query("skill_type")) return HIG+"�Z��"+NOR;
	else if(ob->query("armor_type")) return HIY+"����"+NOR;
	else if(ob->query("heal_hp") || ob->query("heal_mp") || ob->query("heal_ap")) return HIC+"�^�_"+NOR;
	else if(ob->is_food()) return HIM"����"NOR;	// by shengsan
	else return "�D��";
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
		write("�o��p�c�S�����~�C���I\n");
		return 0;
	}
	file =  keys(item);
	supply_cost = values(item);
	list = "\n\n�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n";
	list +="�x �� ��                ����  �ثe�i�H�ʶR���f�~�M��    �x\n";   
	list +="�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
	for(i=0; i<sizeof(file); i++)
	{
	    file[i]=resolve_path("/", file[i]);
	    goods = load_object(file[i]);
	    if(goods) list+= ITEM_D->item_list(goods,me);
	    if(debug) list+= sprintf(GRN+" SP:(%3d)\n"+NOR,supply_cost[i]);
	    	else list+="\n";
	}
	list +="\n";
	if(i==0) return notify_fail(this_object()->query("name")+"��A��: �藍�_��..�f���槹�F�C\n");
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
	if(!arg) return notify_fail("�A�n�R����F��H\n");
	if(sscanf(arg,"%s from %s",arg,who)==2)
	{
		if(!this_object()->id(who)) return notify_fail("�A�n��ֶR�F��H\n");
    	}

	if(!mapp(items = query("sell_list")) )
	{
		write("�o��p�c�S�����~�C���I\n");
		return 0;
	}
	if(sscanf(arg,"%d %s",amount,item)!=2)
	{
	  amount=1;
	  item = arg;
	} else
	if(amount > 20)
	{
		write("����֨t�έt��. �ƶq�N�۰ʽվ㬰�W��20�ӡC\n");
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
		 	return notify_fail("�A���W���������C\n");
	    	 if( (goods->query_weight()*amount+me->query_encumbrance())>me->query_max_encumbrance() )
 			return notify_fail("�A�����ʳo��h�F��C\n");
 		 if( (int)me->query_capacity() + (int)goods->query("volume")*amount > (int)me->query_max_capacity() )
 			return notify_fail("�A���W�񤣤U�o��h�F��C\n");
		 if( me->query("supply_point") < supply_cost[i]*amount)
		 	return notify_fail(this_object()->query("name")+"��A��: �A�w�g�R�F���֪F��F..�٬O���L�@�|��A�ӶR�a.. �C\n");
	    	 if( amount < 1 ) return notify_fail("�ܤ֭n�R�@�ӧa�C\n");
	    	 valus=goods->query("value")*amount;
	    	 me->receive_money(-valus);
	    	 me->add("supply_point",-supply_cost[i]*amount);
	    	 world = me->money_type();
	  	if(world!=3) message_vision("$N��F"+price_string(valus,me->money_type())+"�V$n�R�F"+
	    	 	  		chinese_number(amount)+goods->query("unit")+goods->name()+"�C\n",me,this_object());
	  	else message_vision("$N��F"+valus+"�ӳ�쪺�q�l���V$n�R�F"+
	    	 	  		chinese_number(amount)+goods->query("unit")+goods->name()+"�C\n",me,this_object());

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
	return notify_fail(this_object()->query("name")+"�S����o�تF��C\n");
}

int do_try(string arg)
{
	int i,check=0;
	object goods,me;
	string *file;
	mapping items;

	me=this_player();
	if(!arg) return notify_fail("�A�n�դ���F��H\n");
	if(!mapp(items = query("sell_list")) )
	{
		write("�o��p�c�S�����~�C���I\n");
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
	if(!check) return notify_fail("�S����o�ӪF��C\n");
	if(goods->query("skill_type")) //weapon
	{
		if(me->query("race")!="human")
		{
			if(!goods->query(me->query("race")+"_weapon_prop"))
			{
				return notify_fail("�o��"+goods->name()+"�ä��A�X�A�ϥΡC\n");
			}
		} else
		if(!goods->query("weapon_prop"))
		{
			return notify_fail("�o��"+goods->name()+"�ä��A�X�A�ϥΡC\n");
		}
		if( goods->query("female_only")	&& (string)me->query("gender") != "�k��" )
			return notify_fail(goods->name()+"�O�k�H�M�Ϊ��Z���C\n");
		if( goods->query("male_only") && (string)me->query("gender") != "�k��" )
			return notify_fail(goods->name()+"�O�k�H�M�Ϊ��Z���C\n");
		if( goods->query("limit_lv") > me->query("level") )
			return notify_fail("�A�����ŤӧC�A�L�k�˳�"+goods->name()+"�C\n");
		if( goods->query("limit_con") > me->query_con() )
			return notify_fail("�A���髬�����A�L�k�˳�"+goods->name()+"�C\n");
		if( goods->query("limit_str") > me->query_str() )
			return notify_fail("�A���O�q�����A������"+goods->name()+"�C\n");
		if( goods->query("limit_int") > me->query_int() )
			return notify_fail("�A�����o���A�����o���ϥ�"+goods->name()+"�C\n");
		if( goods->query("limit_dex") > me->query_dex() )
			return notify_fail("�A�յ۸˳�"+goods->name()+"�A�i�O�A�����ӺC�F���p�ߥ���ۤv�C\n");
		if( goods->query("limit_skill") > me->query_skill((string)goods->query("skill_type"),1) )
			return notify_fail("�A���ըϥ�"+goods->name()+"�A�i�O�A���ޥ������C\n");
		
		write("�A�յۨϥ�"+goods->name()+"���Z���A�Pı�_���٤����C\n");
		return 1;
	}
	 else if(goods->query("armor_type"))
	{
		if(me->query("race")!="human")
		{
			if(!goods->query(me->query("race")+"_armor_prop"))
			{
				return notify_fail("�o��"+goods->name()+"�ä��A�X�A�ϥΡC\n");
			}
		} else
		if(!goods->query("armor_prop"))
		{
			return notify_fail("�o��"+goods->name()+"�ä��A�X�A�ϥΡC\n");
		}
		if( goods->query("female_only")
		&&	(string)me->query("gender") != "�k��" )
			return notify_fail(goods->name()+"�O�k�ʱM�Ϊ��˳ơC\n");
		if( goods->query("male_only")
		&&	(string)me->query("gender") != "�k��" )
			return notify_fail(goods->name()+"�O�k�ʪ��M�θ˳ơC\n");
		if( goods->query("limit_lv") > me->query("level") )
			return notify_fail("�A�����ŤӧC�A�L�k�˳�"+goods->name()+"�C\n");
		if( goods->query("limit_con") > me->query_con() )
			return notify_fail("�A���髬�����A�L�k�˳�"+goods->name()+"�C\n");
		if( goods->query("limit_str") > me->query_str() )
			return notify_fail("�A���O�q�����A�L�k�˳�"+goods->name()+"�C\n");
		if( goods->query("limit_int") > me->query_int() )
			return notify_fail("�A�����o���A�����o���˳�"+goods->name()+"�C\n");
		if( goods->query("limit_dex") > me->query_dex() )
			return notify_fail("�A�Q�n�˳�"+goods->name()+"�A�i�O�A�ʧ@�C�]�]���A�藍�W�h�C\n");
		if( goods->query("max_lv") < me->query("level") && goods->query("max_lv")>1)
			return notify_fail(goods->name()+"�O�C���űM�Ϊ��˳ơC\n");
		
		write("�A�յ۸˳�"+goods->name()+"�A�Pı�ܦX���C\n");
		return 1;
	}
	return notify_fail("�A�Q�ե�"+goods->name()+"�A�u��"+this_object()->name()+"�ܺôb���ݵۧA�C\n");
}


int is_sellman()
{
	return 1;
}