// look.c
#include <room.h>
#include <ansi2.h>

inherit F_CLEAN_UP;

int can_look(object env); //new
varargs int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);
int light_inventory(object me); //會發光的東西
varargs string room_describe(object me,object env);  //new
string show_item_status(object ob);
int sort_item(object ob1, object ob2);
string process_item(object me,object *inv);
void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string where,target;
        object obj,bag;
        int result;

	//如果加參數..
	if(arg=="on")
	{
		me->delete("env/brief");
		write("您將顯示模式設為"HIY"正常模式\n"NOR);
		return 1;
	}
 
	if(arg=="off")
	{
		me->set("env/brief",1);
		write("您將顯示模式設為"HIY"簡略模式\n"NOR);
		return 1;
	}

	//未加參數,表示看目前房間

        if( !arg ) return look_room(me, environment(me));

	if(!can_look(environment(me)))
		return notify_fail("你的四周黑漆漆的一片..什麼也看不見!\n");


	if(sscanf(arg,"%s in %s",target,where)!=2)
	{
	// 否則
	// present(arg, me):找尋自己身上的內含物 (first)
	// present(arg,environment(me)):找尋目前房間內的東西 (later)
		if( (obj = present(arg, me)) || (obj = present(arg, environment(me))))
		{
                        if( !obj->is_character() ) result = look_item(me, obj);        //看物
                        else result = look_living(me, obj);                               //看生物
		}
		else result = look_room_item(me, arg);			//看房間物
	}
	else
	{
		if(where=="here")
		{
			result = look_room_item(me, target);			//看房間物
		}
		else if(where=="me")
		{
			if( obj = present(target, me) )
			{
				if( obj->is_character() ) result = look_living(me, obj);	//看人
				else result = look_item(me, obj);				//看物
			}
			else return notify_fail("你身上沒有這個東西。\n");
		} 
		else if( (bag = present(where, me)) || (bag = present(where, environment(me))))
		{
			if(bag->is_character() && bag!=me && !wizardp(me))
				return notify_fail("只有巫師才可以看他人身上的東西。\n");

			if( obj = present(target, bag) )
			{
				if( obj->is_character() ) result = look_living(me, obj);	//看人
				else result = look_item(me, obj);				//看物
			} else return notify_fail("那裡面沒有這個東西。\n");
		}
		else return notify_fail("[look指令]:找不到"+where+"。\n");
	}
	return result;
}


int can_look(object env) 
{
	object *inv;
	
        if(!env) return 0;
	if(env->light()) return 1;	//有設照明

	inv = all_inventory(env);

	// 以下程式由 shengsan 簡化了 ..Luky 再簡化一次..:P
	if( env->query("outdoors") && NATURE_D->query_light() > 1) return 1;	//戶外白天

  	return 0;
}

varargs string room_describe(object me,object env)
{
         int i,j,k;
	object *inv,*items;
	mapping exits,doors;
	string str, *dirs,and,vision_color,long_desc,short_desc,*door_dir;

	if( !env )
	{
		return"空虛之中，只見一片黑暗。\n";
        }
/*
	//顯示look結果 
	if(env->is_house())
	{
		long_desc=env->query_long(1);
		short_desc=env->query_short(1);
	}
	else
	{
		long_desc=env->query_long(1);
		if(!long_desc) long_desc=env->query_temp("long");
		if(!long_desc) long_desc=env->query("long");
		short_desc=env->query_short(1);
		if(!short_desc) short_desc=env->query("short");
	}

*/		long_desc=env->query_long(1);
		if(!long_desc) long_desc=env->query_temp("long");
		if(!long_desc) long_desc=env->query("long");
		short_desc=env->query_short(1);
		if(!short_desc) short_desc=env->query("short");
	if(!can_look(env) )
	{
				
		if(!env->query("outdoors")) 
		{
		  write(short_desc+"\n\n");
		  return "[1;30m  你的四周黑漆漆的一片..什麼也看不見![0m\n\n\n";
		}
		if(NATURE_D->query_light()==1) vision_color = CYN;
		else vision_color = HIB;
		
		//write(HIW+"你覺得有點昏暗\n"+NOR);
		str = sprintf(" %s - %s\n    %s%s%s",
				short_desc,
				(wizardp(me) && !me->query_temp("out_of_power"))? file_name(env): "",
				vision_color,	//add by Luky.
				long_desc+NOR,
				env->query("outdoors")? NATURE_D->outdoor_room_description() : "" 
			);
		if( me->query("level")<3 )
		{
			if(random(2)) str+=HIY+"[新手提示:] 光線不足將看不清楚這裡的東西和出口，找些會發光的東西吧。\n"+NOR;
			else if(random(2)) str+=HIY+"[新手提示:] 多使用map指令可以幫助你了解地形。\n"+NOR;
		}
                  str += NOR""; //恢復顏色
		if( mapp(exits = env->query("exits")) )
		{
			dirs = keys(exits);
			if( sizeof(dirs)==0 )
				str += "    這裡沒有任何明顯的出路。\n";
			else
				str += "    這裡隱約的出口是 " +  dirs[0] + NOR + "。\n";
		} 
		else str += "    這裡沒有任何明顯的出路。\n";
		return str;
	}
	
	str = sprintf( "%s - %s\n    %s%s%s",
		short_desc, 			//簡短描敘
		(wizardp(me) && !me->query_temp("out_of_power"))? file_name(env): "", 	//檔案名稱
		long_desc,			//詳細描敘
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "",
		env->query("outdoors")? NATURE_D->outdoor_room_weather_status(env) : ""  //天氣形容
//		""
		);
	if( mapp(exits = env->query("exits")) )
	{
		dirs = keys(exits);
		if(doors=env->query_doors())
		{
			door_dir=keys(doors);
			for(i=0; i<sizeof(door_dir); i++)
			{
				if( (int)env->query_door(door_dir[i], "status") == DOOR_LOCKED )
				{
					str +="    " + to_chinese(door_dir[i])+"邊的"+env->query_door(door_dir[i], "name")+"是"+HIR+"鎖"+NOR+"著的。\n";
					dirs[i] = 0;
				}
				else if( (int)env->query_door(door_dir[i], "status") == DOOR_CLOSED )
				{
					str += "    " + to_chinese(door_dir[i])+"邊的"+env->query_door(door_dir[i], "name")+"是"+HIW+"關"+NOR+"著的。\n";
					dirs[i] = 0;
				}
				else if( (int)env->query_door(door_dir[i], "status") == DOOR_OPENED )
				{
					str += "    " + to_chinese(door_dir[i])+"邊的"+env->query_door(door_dir[i], "name")+"是開著的。\n";
				}
			}
		}
		dirs -= ({ 0 });
                  str += NOR""; //恢復顏色
		if( sizeof(dirs)==0 )
			str += "    這裡沒有任何明顯的出路。\n";
		else if( sizeof(dirs)==1 )
			str += "    這裡唯一的出口是 " +HIW+  dirs[0] + NOR + "。\n";
		else
		{
			str += sprintf("    這裡明顯的出口是 ");
			k=sizeof(dirs);
			if(k>2) and="、";
				else and="";
			for(i=0;i<k-2;i++)
			{
				str +=HIW+dirs[i]+NOR+"、";
			}
			str +=HIW+dirs[k-2]+" 和 "+dirs[k-1]+NOR+"。\n";
		}
	} else str += "    這裡沒有任何明顯的出路。\n";
	if( mapp(exits = env->query("hide_exits")) &&  wizardp(me) )
	{
		dirs = keys(exits);
		if(sizeof(dirs)!=0)
		for(i=0; i<sizeof(dirs); i++)
		{
			if( (int)env->query_door(dirs[i], "status") == DOOR_LOCKED )
				dirs[i] = 0;
			else if( (int)env->query_door(dirs[i], "status") == DOOR_CLOSED )
				dirs[i] = 0;
		}
		dirs -= ({ 0 });
		k=sizeof(dirs);
		if( k==0 )
			str += "";
		else if( k==1 )
			str += "    [32m(巫師) 隱藏的出口是 " +  dirs[0] + "。[0m\n";
		else
		{
			str += sprintf("    [32m(巫師) 這裡隱藏的出口有 ");
			for(i=0;i<k-2;i++)
				str +=dirs[i]+"、";
			str += dirs[k-2]+" 和 "+dirs[k-1]+"。[0m\n"+NOR;
		} 
	}
	j=1;	//add by luky
	items = all_inventory(env);
	if(sizeof(items)>110)
	{
		str+=HIC"\n  這裡東西太多了，你連自己在哪裡都不知道了。\n\n"NOR;
		return str;
	}
	//inv = F_QUANTITY->sortinv(env);	// add by shengsan for sort env
	
	inv = sort_array(items, "sort_item", this_object());
	k=sizeof(inv);
	if(k>90)
	{
			for(i=0; i<k; i++)
			{
				if(inv[i]->is_character())
				{
				 if(me!=inv[i] && me->visible(inv[i]) ) str+="  "+show_item_status(inv[i]);
				}
			}
			str+=HIW"\n  這裡到處都是東西，一時之間很難看仔細。\n\n"NOR;
			return str;
	}
	else 
	{
		str+=process_item(me,inv);
		return str;
	}
}

varargs int look_room(object me, object env)
{
	string str;
	if(!stringp(str=room_describe(me,env))) write("這裡一片黑濛濛的，你什麼都看不到。\n");
	else write(str);
	return 1;
}


string show_item_status(object ob)
{
	object me,ride_ob;
	string str="",ride_type,desc;

	me = this_player();
	if(!ob) return "";
	if(ob->is_character())
	{
        if( !userp(ob) && NEWQUEST_D->hasQuest(me, ob) ) str += BLINK+HIY"！"NOR;
		if(ob->query_temp("killer")) str +=HIR+ "[殺人犯]"+NOR;
		if(ob->is_ghost() ) str += HIB+"(鬼魂)"+NOR;
		if(wizardp(me) && ob->query_temp("invis")) str += "[1;33m(隱身)[0m";
		else {
			if( me->visible(ob) && ob->query_temp("invis") ) str += "[1;32m(隱身)[0m";
	     	     }
	     	     
		if(ob->query_temp("hide") ) str +=HIB+ "(藏匿)"+NOR;
		if(ob->query_temp("stone") ) str +=HIW+ "(石化)"+NOR;
		if(ob->query_temp("freeze") ) str +=HIW+ "(冰凍)"+NOR;
		str += "" + ob->short();

		if( ob->query_temp("sleeping") ) str +=" 正在這裡睡覺";
		else if( ob->query_temp("float") ) str +=" 正漂浮在空中";
		else if( ob->query_temp("fly") ) str +=" 正在空中飛著";
		else if(objectp(ride_ob=ob->query_temp("ride"))) //自訂騎乘顯示
		{
			if(ride_type=ride_ob->query("ride_type")) str +=ride_type;
			else str +=" 正騎在"+ride_ob->name()+"上";
		} else if(living(ob))
			{
            if(ob->query_temp("define_look")) str += ob->query_temp("define_look");
            else {                   
            		if( ob->query("race")=="beast") str +="";
                   else if( ob->query("race")=="human") str+=" 正站在這裡";
                   else str+=" 正在這裡";
                 }
			}

		if( ob->query_temp("netdead") ) str += HIG " <斷線中>" NOR;
		if( in_input(ob) ) str += HIC " <輸入模式>" NOR;
		if( in_edit(ob) ) str += HIY " <編輯檔案>" NOR;
		if( interactive(ob) && query_idle( ob ) > 120 ) str += HIM " <發呆中>" NOR;
        if( ob->is_inactive() ) str += HIW " [閒置模式]" NOR;

	}
	else if(ob->is_vehicle())	// by Shengsan
	{
		str += ob->name()+"("+capitalize(ob->query("id"))+")";
	}
	else
 	{
 		str += "" + ob->short();
 		
 	}
	
       if(desc=ob->query("status_desc")) str+=" "+desc; // 兇手或狀態

	str +="\n";

	return str;
}
// 如果有會發光的東東 return 1
// else 0

int light_inventory(object me)
{
	object *inv;
	int i,p;

	inv=all_inventory(me);
	p=sizeof(inv);
	if(!p) return 0;    //沒有東東
	for(i=0;i<p;i++)
	{
		if(inv[i]->query("is_light")) return 1;
	}
	return 0;
}


int look_item(object me, object obj)
{
	string str;
	object *inv;

	tell_room(environment(me),me->name()+"正若有所思的看著"+obj->name()+"。\n",({me}));
	if(obj->outside_vision(me)) return 1;
//	if( obj->is_vehicle() && stringp(obj->query("vlong")) )		// by Shengsan
//		str = obj->query("vlong");
//	else
	str=obj->long();
	if(obj->is_box()) str+=obj->show_cover_status();
	me->start_more(str);
	inv = all_inventory(obj);
	//以上新增by Luky
	if( sizeof(inv) && !obj->is_house())
	{
//		inv = map_array(inv, "inventory_look", this_object() );
//		message("vision", sprintf("裡面有﹕\n  %s\n",
//		implode(inv, "\n  ") ), me);
		if(obj->is_box())
		{
			if(obj->can_access_box())  message("vision", sprintf("裡面有﹕\n%s\n",process_item(me,inv)), me);
		}
		else message("vision", sprintf("裡面有﹕\n%s\n",process_item(me,inv)), me);
	}
	return 1;
}


int look_living(object me, object obj)
{
          string str, pro, gender,*spell,name,ob_name;
        mixed *inv;
          mapping spells;
        if(!wizardp(me))
        {
	  if( !me->visible(obj))
		return notify_fail("你要看什麼?\n");
        }
        name = me->name();
        ob_name=obj->name();
	if(me->query_temp("hide")+me->query_temp("invis") < 1 )
	{
		if( me!=obj )
		{
		 	message("vision", name + "歪著頭, 上下打量了你一眼。\n", obj);
		        tell_room(environment(me),name +"正上下打量著"+ ob_name +"﹐不知道在打什麼主意。\n",({me,obj}));
		}
		else
		{
			switch(me->query("race"))
			{
				case "robot":
						gender="它";
						break;
				case "zerg":
				case "beast":
				case "monster":
						gender= "牠";
						break;
				case "human":
				case "evil":
                case "tiger":
                case "titan":
				case "ogre":
				case "protoss":
				case "meda":
	  					if(me->query("gender")=="女性") gender = "她";
	  					else gender = "他";
	  					break;
	  			default:
	  				gender = "他";
	  		}
			tell_room(environment(me),name +"正在檢查"+gender+"身上的裝備。\n",({me}));
		}
	}
	//=====以上新增by Luky======
	str = obj->short()+"。\n";
	if(stringp(obj->query("long"))) str += obj->long();
	pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));
	
    str += sprintf("%s看起來約%s歲左右，為"HIY"%s級"NOR"的"HIG"%s種族"NOR"，攻擊素質為"HIY"%s"NOR"。\n", 
    	pro, 
		chinese_number(obj->query("age")) ,
		chinese_number(obj->query("level")) ,
		to_chinese(obj->query("race")),
		to_chinese(COMBAT_D->query_attack_merits(obj))
    );

	if( obj->query("hp") )
		str += pro + COMBAT_D->eff_status_msg((int)obj->query("hp") * 100 / (int)obj->query("max_hp")) + "\n";

	if(obj->query_condition("blooding"))
		str += HIM+pro+"身上還有許\多傷口，正在流著血。\n"NOR;

        inv = all_inventory(obj);
        if( sizeof(inv) )
	{
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s的遺物有﹕\n%s\n" : "\n  %s身上帶著﹕\n\n%s\n\n",
                                pro, implode(inv, "\n") );
        }
 
 	if( mapp(spells=obj->query_temp("spell")) )	//luky 新增 for magic
 	{
          spell = keys(spells);
 	  if(sizeof(spell)) str += "\n\n  "+pro+"身上的特殊效果有: \n\n";
 	  if(obj->query_temp("spell/bless")) str +="    [1;32m(祝福的光芒)[0m\n";
 	  if(obj->query_temp("spell/shield")) str +="    [1;33m(聖  光  盾)[0m\n";
	  if(obj->query_temp("spell/armor")) str +="    [1;32m(魔 法 護 甲)[0m\n";
 	} 
 	
        message("vision", str, me);

        if( obj!=me && living(obj) && !userp(obj)
        &&  random((int)obj->query("evil")) > 100 ) //太evil的動物會因為你看他而攻擊
	{
		write( obj->name() + "突然轉過頭來瞪你一眼。\n");
		COMBAT_D->auto_fight(obj, me, "berserk");
        }

        return 1;
}


string inventory_look(object obj, int flag)
{
        string str;

        if( obj->query("equipped") )
                str = obj->item_describe(1);
        else if( !flag )
                str = "            " + obj->short();
        else
                return 0;

        return str;
}


int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;
	string name;

        if( !objectp(env = environment(me)) )
		return notify_fail("這裡只有灰濛濛地一片﹐什麼也沒有。\n");

        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) )
        {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                name=me->name();
		if(me->query_temp("hide")+me->query_temp("invis") < 1 ) tell_room(environment(me),name +"看了看這裡的"+ arg +"。\n",({me}));
                return 1;
        }
        else
        if( mapp(item = env->query("hide_item_desc")) && !undefinedp(item[arg]) )
        {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                name=me->name();
		if(me->query_temp("hide")+me->query_temp("invis") < 1 ) tell_room(environment(me),name +"看了看這裡的"+ arg +"。\n",({me}));
                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("你要看什麼﹖\n");
}

string process_item(object me,object *inv)
{
	int i,k,j;
	string str="";
	k=sizeof(inv);
	if(k<1) return "  那裡什麼也沒有。\n";
	if(k>140) return "東西實在太多了，你眼花撩亂無法看清楚。\n";
	inv = sort_array(inv, "sort_item", this_object());
	j=1;
		for(i=0; i<k; i++)
        	{
        		if(inv[i]==me) continue;
        		if(!me->visible(inv[i])) continue;
			if( i+1 < k )
			{
				if( inv[i]->query("name") == inv[i+1]->query("name") 
				    && !userp(inv[i])
				    && !userp(inv[i+1])
				    && !inv[i]->query_temp("no_combine")
				    && !inv[i+1]->query_temp("no_combine")
				    && me->visible(inv[i+1])
				    ) j++;
				else
				{
					str+="  ";
					if(!inv[i]->query_amount())
					{
				 		if(j>1)		//luky 兩個以上再顯示數量
				 		{		//luky
				 			str += chinese_number(j);
				 			str += inv[i]->query("unit")  ? inv[i]->query("unit"):"個";
				 		}		//luky
					}
					str += show_item_status(inv[i]);
					j = 1;
				}
			}
			else
			{
				str+="  ";
				if(j>1)		//luky 兩個以上再顯示數量
				{		//luky
					str += chinese_number(j);
					str += inv[i]->query("unit")  ? inv[i]->query("unit"):"個";
				}		//luky
				str += show_item_status(inv[i]);
			}
		}
		return str;
}

int sort_item(object ob1, object ob2)
{
	string file1,file2;
	if(userp(ob1) && !userp(ob2)) return 1;
	if(!userp(ob1) && userp(ob2)) return -1;
		
	file1=base_name(ob1);
	file2=base_name(ob2);
	if(file1==file2)
	{
		return getoid(ob2)-getoid(ob1);
	}
	return strcmp(file1,file2);
}

int help (object me)
{
        write(@HELP
指令格式: look [on|off|<物品>|<生物>|<方向>] < in 指定位置>

說明: 這個指令讓你查看你所在的環境、某件物品、生物、或是方向。

附註: 
(1) look on 是完整模式. look off是簡略模式.
(2) 指定位置可以是 <in box> <in here> <in me> 等等.

HELP
	);
        return 1;
}
