// quit.c
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
        set("name", "離線指令");
        set("id", "quit");
}

int main(object me, string arg)
{
        int i,world;
	object *inv, link_ob,*team,ride;
	string ip_addr,where;
//if( base_name(environment(me))!="/obj/void")
// me->set("startroom",base_name(environment(me)));

//if(query_ip_name(me)=="192.192.69.194") 
//	return notify_fail("你的連線位置不可以Quit!!\n");
   if(me->query_temp("killer"))
	  return notify_fail("你殺了人暫時不可以Quit!!\n");
   if(me->query_temp("invader"))
     return notify_fail("你攻擊了玩家暫時無法Quit!\n");
	if( me->query_temp("no_quit") ) // add by -alickyuen@ds-
		return notify_fail("你可能正在拍賣中，現在並不能離線，如不是請找線上巫師求助。\n");
	if(me->is_busy())
		return notify_fail("你還在忙, 無法Quit!\n");

// 
if(team=me->query_team())
{
	if(arrayp(team) && sizeof(team)>1 )
	{
		for(i=0;i<sizeof(team);i++)
		{
			tell_object(team[i],HIW"【隊伍】"+me->name(1)+"離開了這個隊伍。\n"+NOR);
			me->dismiss_team();
		}
	}
}

if( !wizardp(me) )
{
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
        {
          if(inv[i]->query("secured")) inv[i]->delete("secured");
          if( inv[i]->query("base_value") ) continue;
	  if( inv[i]->query_autoload()  ) continue;
	  if(inv[i]->query("equipped")) inv[i]->unequip();
              DROP_CMD->do_drop(me, inv[i]);
        }
}

if( !stringp(where = me->query("startroom")))
{
        world=me->money_type();
	if(world==1) me->set("startroom",START_ROOM_PAST);
	else if(world==2) me->set("startroom",START_ROOM_NOW);
	else if(world==3) me->set("startroom",START_ROOM_FUTURE);
	else me->set("startroom","/open/world2/anfernee/start/login");
}
 else if(!wizardp(me))
{
	where = area_domain(where);

	if(where!="none")
	{
		world=me->money_type();
		if(world==1 && where!="world1") me->set("startroom",START_ROOM_PAST);
		else if(world==2 && where!="world2") me->set("startroom",START_ROOM_NOW);
		else if(world==3 && where!="world3") me->set("startroom",START_ROOM_FUTURE);
		else if(world==0) me->set("startroom","/open/world2/anfernee/start/login");
	}

}
 me->remove_all_killer();
 me->remove_all_enemy();
 me->delete("award/note");
 me->save();
 link_ob = me->query_temp("link_ob");
 // We might be called on a link_dead player, so check this.
 if( link_ob )
 {
                // Are we possessing in others body ?
	if( link_ob->is_character() )
	{
        	write("你的魂魄回到" + link_ob->name(1) + "的身上。\n");
                exec(link_ob, me);
                link_ob->setup();
                return 1;
        }

	me->delete("cmdcount");          // add by shengsan

        link_ob->set("last_on", time());
        link_ob->set("last_from", query_ip_name(me));
        link_ob->set("level",me->query("level")); //讓login_ob紀錄等級
        link_ob->save();
        destruct(link_ob);
}
 if(ride=me->query_temp("ride"))
 {
	message_vision("$N從"+ride->name()+"上跳了下來。\n",me);
	ride->delete_temp("riden");
	ride->move(environment(me));
	me->delete_temp("ride");
	
 }
 ip_addr=query_ip_name(me);
write("\n∼∼ 辛苦了! 休息一下吧 ∼∼\n\n");
message("system", me->name(1) +"依依不捨的離開這個世界。\n", environment(me), me);
if( wiz_level(me) < 5 || arg!="invis")
CHANNEL_D->do_channel(this_object(), "sys",
 me->name(1) +"("+me->query("id")+") 離開遊戲。["+ip_addr+"]");
 
 ROOM_D->moveout(environment(me),me); //add by luky
 me->save();
 destruct(me);

 return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : quit

當你(妳)想暫時離開時, 可利用此一指令。
HELP
    );
    return 1;
}
