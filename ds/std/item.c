// item.c

#include <ansi2.h>
#include <dbase.h>
#include <move.h>
#include <name.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME;


void setup()
{

	seteuid(getuid());
	if(!stringp(this_object()->query("unit"))) this_object()->set("unit","��"); //luky
	if(!this_object()->query("volume")) this_object()->set("volume",1); //luky
	if(!this_object()->query_temp("durable")) this_object()->set_temp("durable",100);
	//�@�[�פ��w�Ȭ�100
}

int is_broken()
{
	if(this_object()->query_temp("durable")<0) return 1;
	else return 0;
	
}

int query_durable()
{
	return this_object()->query_temp("durable");
}

int set_durable(int amount)
{
	int value;
          object env;
	this_object()->set_temp("durable",amount);
	if(!env=environment(this_object())) return 0;
	if(amount<0)
	{
		this_object()->unequip();
		this_object()->set_temp("no_combine",1);
        this_object()->set("status_desc",NOR+HIW+BLK"[�l�a]"NOR);
		value=this_object()->query("value");
		if(value > 1 && !this_object()->query("init_value"))
		{
			this_object()->set("init_value",value);
			this_object()->set("value",1);
		}
		if(env->is_character())
            message_vision(HIC+BLINK"$N��$n"HIC+BLINK"�]���l�a�ӵL�k�ϥΤF�I�I\n"NOR,env,this_object());
	}
	else
	{
		if(value=this_object()->query("init_value")) this_object()->set("value",value*2/3);
		this_object()->delete("status_desc");
	}
	return amount;
}

varargs int receive_damage(string type,int damage,object who)
{
	switch(type)
	{
		case "durable":
				if(who) this_object()->set_temp("last_damage_from",who->query("name"));
				return this_object()->set_durable(this_object()->query_temp("durable")-damage);
		default:
				return 0;
	}
}

int is_item() { return 1; }
