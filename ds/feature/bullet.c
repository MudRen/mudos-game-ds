// bullet.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_reload", "reload");
}

int do_reload(string arg)
{
	string type,msg;
	object weapon,ob;
	if( !this_object() ) return 0;

	if(!arg)
	{
		notify_fail("你想裝填什麼??\n");
		return 0;
	}
	if( !this_object()->id(arg) ) return 0;
	if(!this_object()->query("no_get")) //不是放在地上的
	{
		ob=present(arg,this_player());
		if(ob != this_object()) return 0;
	}

	if(!weapon = this_player()->query_temp("weapon"))
		return notify_fail("你並沒有使用槍械類武器。\n");
	if( this_player()->is_busy() )
		return notify_fail("你上一個動作還沒有完成。\n");
	if(weapon->query_temp("loaded")==weapon->query("max_load"))
		return notify_fail("這個武器的裝彈量已經是滿的了。\n");
	if(weapon->query("bullet_type")!=query("type"))
		return notify_fail("這個武器無法使用這種彈藥。\n");

	weapon->set_temp("loaded",weapon->query_temp("loaded")+query("amount"));
	if(weapon->query_temp("loaded") > weapon->query("max_load"))
		weapon->set_temp("loaded",weapon->query("max_load"));

	weapon->set_temp("bullet",query("bullet"));	//附加屬性於槍上
	
	if( this_player()->is_fighting() ) this_player()->start_busy(2);
		else this_player()->start_busy(1);
	
	if(stringp(msg=query("load_msg")))
		message_vision(msg+"\n", this_player(),this_object());
	else message_vision("$N取出$n, 熟練的裝入"+weapon->name()+"中。\n", this_player(),this_object());
	tell_object(this_player(),weapon->name()+"目前的存彈量為"+weapon->query_temp("loaded")+"發。\n");

	destruct(this_object());
	return 1;
}

