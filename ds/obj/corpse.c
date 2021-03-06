// corpse.c
#include <ansi.h>

inherit ITEM;

int decayed;

void create()
{
	set_name("無名屍體", ({ "corpse" }) );
	set("long", "這是一具無名屍體。\n");
	set("unit", "具" );
	decayed = 0;
	if( clonep(this_object()) ) call_out("decay", 120, 1);
}

int is_corpse() { return decayed < 2; }
int is_character() { return decayed < 1; }
int is_container() { return 1; }

string short()
{
         string str;
	str = name() + "(" + capitalize(query("id")) + ")"; 
//	if(desc=query("status_desc")) str+=" "+desc;//顯示目前狀態或兇手
	return str;
}

void decay(int phase)
{
	object *inv,env;
	int i;
	decayed = phase;
	if(!this_object()) return;
	env=environment(this_object());
	if(!env)
	{
		destruct(this_object());
		return;
	}
	switch(phase) {
		case 1:
			tell_room(env, query("name") + "開始腐爛了﹐發出一股難聞的惡臭。\n" );
			switch(query("gender")) {
				case "男性":
					set_name("腐爛的男屍", ({ "corpse", "屍體" }) );
				case "女性":
					set_name("腐爛的女屍", ({ "corpse", "屍體" }) );
				default:
					set_name("腐爛的屍體", ({ "corpse", "屍體" }) );
			}
			set("long",	"這具屍體顯然已經躺在這裡有一段時間了﹐正散發著一股腐屍的味道。\n");
			call_out("decay", 200, phase + 1);
			break;
		case 2:
			tell_room(env, query("name") + "被風吹乾了﹐變成一具骸骨。\n" );
			set_name("枯\乾的骸骨", ({ "skeleton", "骸骨" }) );
			set("long", "這副骸骨已經躺在這裡很久了。\n");
			call_out("decay", 100, phase + 1);
			break;
		case 3:
			tell_room(env, "一陣風吹過﹐把" + query("name") + "化成骨灰吹散了。\n" );
			if( environment() )
			{
				inv = all_inventory(this_object());
				if(sizeof(inv)>0)
				for(i=0; i<sizeof(inv); i++) 
				{
					if( inv[i]->query("no_drop") ||
					inv[i]->query("no_put") )
						destruct(inv[i]);
					else inv[i]->move(environment());
				// alickyuen增加以上no_drop no_put設定
				}
			}
			destruct(this_object());
			break;
	}
}

object animate(object who, int time)
{
	object zombie;

	if( !environment() ) return 0;
	if( !who ) return 0;
	if( this_object()->query("race") != "human" && this_object()->query("race") != "人類" ) return 0;

	seteuid(getuid());
	zombie = new("/obj/npc/zombie");
        if( strsrch(query("name"), "的殭屍") == -1 ) zombie->set_name( (string)query("victim_name") + "的殭屍", ({ "zombie" }) );
	else zombie->set_name( (string)query("victim_name") , ({ "zombie" }) );
        tell_room(environment(this_object()), RED"\n\t突然之間，"+this_object()->name()+"發生異變變成殭屍！。\n\n"NOR);
	zombie->move(environment());
	zombie->set("level", who->query("level") + 1);
	CHAR_D->setup_char(zombie);
	foreach(object oo in all_inventory(this_object()) )	{ oo->move(zombie); }
	zombie->animate(who, time);

	destruct(this_object());
	return zombie;
}
