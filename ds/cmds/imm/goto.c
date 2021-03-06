// goto.c
#include <ansi.h>
inherit F_CLEAN_UP;
void go(object me,string env);
int main(object me, string arg)
{
	int goto_inventory = 0;
	object obj,where;
	string msg;

	if( !arg ) return notify_fail(@WHERE
	
 你要去哪裡﹖

     巫 師        古 代         現代           未來           幫會
============== ============ ============= ============== ===============
1:巫師交誼廳    6:朝天樓    11:新芳鄰旅館 16:礦區酒館    21:狂龍幫
2:夢幻旅館      7:步靈城    12:梅龍鎮旅館 17:            22:月族
3:古代會議室	8:天  城    13:           18:            23:天地會
4:現代會議室    9:孟村郵局  14:           19:            24:神族會議室
5:未來會議室   10:          15:           20:            25:明教

   其   他
==============
26: 凌雲寺
27: 工讀生室
28: 禁閉室


WHERE
	);

	if( sscanf(arg, "-i %s", arg) ) goto_inventory = 1;

	if( !arg ) return notify_fail("你要去哪裡﹖\n");
	if( environment(me) )
		if(environment(me)->query("no_goto_cmd")) return notify_fail("這裡不能使用GOTO指令,請使用go以清除身上的暫時物件。\n");
	switch(arg)
	{
        	case "1":go(me,"/d/wiz/hall1");break;
		case "2":go(me,"/open/world2/anfernee/start/login");break;
		case "3":go(me,"/open/world1/meetroom");break;
		case "4":go(me,"/open/world2/meetroom");break;
		case "5":go(me,"/open/world3/meetroom");break;
		case "6":go(me,"/open/world1/tmr/area/hotel");break;
		case "7":go(me,"/open/world1/cominging/area/boo-lin");break;
		case "8":go(me,"/open/world1/acme/area/hotel");break;
		case "9":go(me,"/open/world1/tmr/area/post_office");break;
		case "11":go(me,"/open/world2/shengsan/aovandis/room079");break;
		case "12":go(me,"/open/world2/lichi_town_2/map_5_26");break;
		case "16":go(me,"/open/world3/tmr/basic/hotel");break;
		case "21":go(me,"/open/world1/cominging/area/dragon/dragon");break;
		case "22":go(me,"/open/world1/acme/area/moon/room3");break;
		case "23":go(me,"/open/world1/acme/area/sky/room25");break;
                case "24":go(me,"/open/world1/god_club/boardroom");break;
                case "25":go(me,"/open/world1/baal/ming_club/saintming");break;
		case "26":go(me,"/open/world1/acme/bonze/b16");break;
		case "27":go(me,"/open/world2/obj/workroom");break;
		case "28":go(me,"/open/always/ppl_jail");break;
	default:
		{
			obj = find_player(arg);
			if(!obj) obj = find_living(arg);
			if(!obj || !me->visible(obj))
			{
				arg = resolve_path(me->query("cwd"), arg);
				if( !sscanf(arg, "%*s.c") ) arg += ".c";
				if( !(obj = find_object(arg)) )
				{
					if( file_size(arg)>=0 )
						return me->move(arg);
					return notify_fail("沒有這個玩家、生物、或地方。\n");
				}
			}
			where=find_object("/open/always/ppl_jail");
			if( environment(obj)==where &&  wiz_level(me) < 2)
				return notify_fail("對方正在監獄服刑, 你最好不要去免的出不來。\n");
			if(!goto_inventory && environment(obj))	obj = environment(obj);
			
			if( !obj ) return notify_fail("這個物件沒有環境可以 goto。\n");
			
			if(!me->query_temp("invis"))
			{
    			  if( stringp(msg = me->query("env/msg_mout")) )
        			message_vision(msg+"\n", me);
			  else
				message_vision(HIW"只見一陣煙霧過後﹐$N"HIW"的身影已經不見了。\n"NOR, me);
			}
			me->move(obj);
			if(!me->query_temp("invis"))
			{
			  if( stringp(msg = me->query("env/msg_min")) )
        			message_vision(msg+"\n", me);
			  else
				message_vision(HIW"$N"HIW"的身影突然出現在一陣煙霧之中。\n"NOR, me);
			}
		}
	}
	return 1;
}

void go(object me,string env)
{
 if(!me->query_temp("invis"))
 message_vision(HIW" 『閃人囉~ 』只見$N"HIW"往天空一躍﹐化身為一隻小蝙蝠﹐啪啪啪~的飛走了。\n"NOR, me);
 me->move(env);
 if(!me->query_temp("invis")) message_vision(HIW"『轟~~』$N"HIW"突然出現在一陣煙霧之中。\n"NOR, me);                    
}
int help(object me)
{
write(@HELP
指令格式 : goto [-i] <目標>
 
這個指令會將你傳送到指定的目標. 目標可以是一個living 或房間
的檔名. 如果目標是living , 你會被移到跟那個人同樣的環境.
如果有加上 -i 參數且目標是 living, 則你會被移到該 living 的
的 inventory 中.
 
HELP
    );
    return 1;
}
