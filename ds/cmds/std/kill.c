// kill.c

#include <ansi.h>
#define PK_AREA "/open/world1/alickyuen/match/area"

inherit F_CLEAN_UP;

void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
          int i,num=0;
	object obj,owner,*inv;
          string callname,fuzzyname,*items,tar;
	if( !arg )
		return notify_fail("你想殺誰﹖\n");

	if(!objectp(obj = present(arg, environment(me)))) {
		inv=all_inventory(environment(me));
		i=sizeof(inv);
		if(sscanf(arg,"%s %d",tar,num)==2) {
			arg=tar;
		}
		while(i--) {
                        // 對玩家不使用 auto id complete 
                        if( userp(inv[i]) ) continue;

			items=inv[i]->parse_command_id_list();
			if(fuzzyname=COMMAND_D->auto_string_complete(arg,items, 2)) {
				if(!num)
				{
					write("[" + arg + " => " + fuzzyname + "]\n");
					obj = present(fuzzyname, environment(me));
				}
				else
				{
					write("[" + arg + " " + num + " => " + fuzzyname + " "+num+"]\n");
					obj = present(sprintf("%s %d",fuzzyname,num), environment(me));
				}
				break;
			}
		}
		if(!obj) return notify_fail("這裡沒有這個人。\n");
	}

	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一點﹐那並不是生物。\n");
	if( strsrch(file_name(environment(me)), PK_AREA) == -1 )
	{
	if(userp(me) && me->query("level")<3)
	{
		if(me->query("level") < obj->query("level")-10)
			return notify_fail("請愛惜生命。\n");
	}

 	if(!me->can_fight(obj))
		return me->can_fight(obj);

	if(!userp(me) && (owner=me->query("creater")) && userp(obj) )
	{
		if(userp(owner))
		{
 		 if(!owner->can_fight(obj))
 		 tell_object(owner,"你不可以攻擊此人!!\n");
		 return owner->can_fight(obj);
		}
	}

	if(userp(me) && userp(obj))
        {
	        if(me->is_fighting(obj)) return notify_fail("加油。\n");
           if(obj->query_temp("invader") && !obj->query_temp("killer") )
              shout("\n"HIR+me->query("name")+HIR"("+me->query("id")+")喝道: "
                        +HIR+obj->query("name")+HIR"("+obj->query("id")+")你居然敢動手動腳, 真是太歲頭上動土!!!\n"NOR);
           else if(obj->query_temp("killer"))
              shout("\n"HIR+me->query("name")+HIR"("+me->query("id")+")罵道: "
                        +HIR+obj->query("name")+HIR"("+obj->query("id")+")你這可惡的殺人犯去死吧!!!\n"NOR);
           else
	           shout("\n"HIR+obj->query("name")+HIR"("+obj->query("id")+")悲慘的淒涼吶喊: 救命阿!! 救命阿!!! "
	                     +me->query("name")+HIR"("+me->query("id")+")想謀殺我!! \n"NOR);

 	       me->set_leader(0); //解除follow
 	       obj->set_leader(0); //解除follow
		obj->set_temp("no_follow",1);//以上三行add by luky
	}
	}
	callname = RANK_D->query_rude(obj);

	message_vision("\n$N對著$n喝道﹕「"
		+ callname + "﹗今日不是你死就是我活﹗」\n\n", me, obj);

	me->kill_ob(obj);
	obj->kill_ob(me);

	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : kill <人物>

這個指令讓你主動開始攻擊一個人物﹐並且嚐試殺死對方﹐kill 和 fight 最大的
不同在於雙方將會真刀實槍地打鬥﹐也就是說﹐會真的受傷。由於 kill 只需單方
面一廂情願就可以成立﹐因此你對任何人使用 kill 指令都會開始戰鬥﹐通常如果
對方是 NPC 的話﹐他們也會同樣對你使用 kill。

當有人對你使用 kill 指令時會出現紅色的字樣警告你﹐對於一個玩家而言﹐如果
你沒有對一名敵人使用過 kill 指令﹐就不會將對方真的打傷或殺死( 使用法術除
外)。

其他相關指令: fight

有關 fight 跟 kill 的區分請看 'help combat'.
HELP
    );
    return 1;
}
 
