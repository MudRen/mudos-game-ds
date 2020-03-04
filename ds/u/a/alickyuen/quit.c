// quit.c
#include <ansi.h>
#include <command.h>
#include <login.h>

inherit F_DBASE;
inherit F_CLEAN_UP;

void create()
{
        seteuid(getuid());
        set("name", "���u���O");
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
//	return notify_fail("�A���s�u��m���i�HQuit!!\n");
   if(me->query_temp("killer"))
	  return notify_fail("�A���F�H�Ȯɤ��i�HQuit!!\n");
   if(me->query_temp("invader"))
     return notify_fail("�A�����F���a�ȮɵL�kQuit!\n");
	if( me->query_temp("no_quit") ) // add by -alickyuen@ds-
		return notify_fail("�A�i�ॿ�b��椤�A�{�b�ä������u�A�p���O�Ч�u�W�Ův�D�U�C\n");
	if(me->is_busy())
		return notify_fail("�A�٦b��, �L�kQuit!\n");

// 
if(team=me->query_team())
{
	if(arrayp(team) && sizeof(team)>1 )
	{
		for(i=0;i<sizeof(team);i++)
		{
			tell_object(team[i],HIW"�i����j"+me->name(1)+"���}�F�o�Ӷ���C\n"+NOR);
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
        	write("�A����z�^��" + link_ob->name(1) + "�����W�C\n");
                exec(link_ob, me);
                link_ob->setup();
                return 1;
        }

	me->delete("cmdcount");          // add by shengsan

        link_ob->set("last_on", time());
        link_ob->set("last_from", query_ip_name(me));
        link_ob->set("level",me->query("level")); //��login_ob��������
        link_ob->save();
        destruct(link_ob);
}
 if(ride=me->query_temp("ride"))
 {
	message_vision("$N�q"+ride->name()+"�W���F�U�ӡC\n",me);
	ride->delete_temp("riden");
	ride->move(environment(me));
	me->delete_temp("ride");
	
 }
 ip_addr=query_ip_name(me);
write("\n��� ���W�F! �𮧤@�U�a ���\n\n");
message("system", me->name(1) +"�̨̤��˪����}�o�ӥ@�ɡC\n", environment(me), me);
if( wiz_level(me) < 5 || arg!="invis")
CHANNEL_D->do_channel(this_object(), "sys",
 me->name(1) +"("+me->query("id")+") ���}�C���C["+ip_addr+"]");
 
 ROOM_D->moveout(environment(me),me); //add by luky
 me->save();
 destruct(me);

 return 1;
}

int help(object me)
{
        write(@HELP
���O�榡 : quit

��A(�p)�Q�Ȯ����}��, �i�Q�Φ��@���O�C
HELP
    );
    return 1;
}
