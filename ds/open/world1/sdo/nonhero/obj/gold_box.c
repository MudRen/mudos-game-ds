#include <ansi2.h>
#include <path.h>
inherit ITEM;
void create()
{
        set_name("���c�l", ({"gold box","box"}) );
        set("long", 
"�@�Ӫ����{�{���c�l�A�n���i�H���}���ˤl�C\n"
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
	room=load_object(SDO_PAST+"nonhero/grav5");
	
	if(!me) return 0;
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="box" || str=="���c�l")
	{

	message_vision(
	HIR"\n$N���ǳƥ��}�c�l�ɡA�c�l���M���}�F�C\n"NOR
	HIR"\n�@�η��������A�@�����~�i���R�����ĤF�X�ӡI\n"NOR,me);

	b=new(__DIR__"npc/gold_beast.c" );
	b->move(environment(this_object()) );

	destruct(this_object());

	room->set_temp("opened",1);
	return 1;
	}
}