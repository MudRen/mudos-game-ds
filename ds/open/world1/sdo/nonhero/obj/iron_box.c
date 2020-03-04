#include <ansi2.h>
#include <path.h>
inherit ITEM;
void create()
{
        set_name("�K�c�l", ({"iron box","box"}) );
        set("long", 
"�@���K�����c�l�A�n���i�H���}���ˤl�C\n"
);
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("no_get",1);
	set("no_drop",1);
        set("unit", "��");
        set("volume",1000);
        set("value",500);
        }
        setup(); 
}

void init()
{
	add_action("open_box","open");
}

int open_box(string str)
{
	object me=this_player();
	object b,room;
	room=load_object(SDO_PAST+"nonhero/grav6");
	
	if(!me) return 0;
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="box" || str=="�K�c�l")
	{

	message_vision(
	HIG"\n$N���}�c�l��A�c�l���M�g�X�@�D����C\n"NOR
	HIG"\n�����������A�o�{�u�@���~�w�g���b$N�����e�C\n"NOR,me);
	
	b=new(__DIR__"npc/wood_beast.c" );
	b->move(environment(this_object()) );

	destruct(this_object());
	
	room=set_temp("opened",1);
	return 1;
	}
}