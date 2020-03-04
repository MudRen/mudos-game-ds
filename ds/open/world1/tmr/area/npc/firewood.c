#include <ansi.h>
#define DELAY 20
inherit ITEM;

void create()
{
	set_name("��K",({"firewood","wood"}));
	set("long","�@�ڲʮ�K�A�h�O�Q�I�U(fire)�ӳ��(around)���l�ӿN�Ҥ��ġC\n");
	set_weight(500);
	if(clonep() )
		set_default_object(__FILE__);
	else 
	{
	set("value",30);
	set("unit","��");
	set("fire_power",5); //���O
	}
	setup();
}

void init()
{
	add_action("do_fire","fire");
	add_action("do_around","around");
}

int do_fire(string arg)
{
	object me,ob;
	me=this_player();
	ob=this_object();
	if(query("on_fire") ) 
		return notify_fail("�o�ڮ�K�w���b�U�N�F�C\n");  
	if(me->is_busy() || me->is_fighting() )
		return notify_fail("�A�����ۡA�S�����I���C\n");
	message_vision("$N�I�U�F�⤤����K�C\n",me);
	ob->set("on_fire",1);
	ob->set("no_sac",1);
	ob->set("no_sell",1);
	set_name("��K["+HIR"�U�N��"+NOR"]",({"firewood","wood"}));
        call_out("deca",DELAY,0,ob);
	return 1;
}

int do_around(string arg)
{
	object me,paper,ob,f;
	ob=this_object();
	me=this_player();

	if(!arg || arg!="furnace") return notify_fail("�A�o���K��¶�b���l�Ǥ~���γB�C\n");
	if(!ob->query("on_fire") ) return notify_fail("�A�o�����K�I�U�~���C\n");
	if(!objectp(f=present("furnace",environment(me) ) ) )
		return notify_fail("�o�̨S�����l�C\n");
	if(!objectp(paper=present("alchemy paper",me ) ) )
		return notify_fail("�A�����Ҥ����k�A�����p��ƪk�C\n");
	if(ob->query("around") ) return notify_fail("�o�ڮ�K�w��¶�b���l�ǤF�C\n");
	message_vision("$N��@���I�U����K��¶�b�@�Ӥ��l�ǡC\n",me);
	ob->set("around",1);
	ob->move(environment(f) );
	return 1;
}


void deca(int flag,object ob)
{
	object *inv;
	int i;
	inv = all_inventory(environment() );
	if( sizeof(inv) )
	{
	for(i=0;i<sizeof(inv);i++)
	{
		if(inv[i]->query("id")=="furnace" && inv[i]->query("setup_down")==1 )
		{
		if(ob->query("around") ) inv[i]->fire_pill(ob);
		}

/* 
��b�P�ϪQ�����ӷ|�s�a�Q�N�_�ӡA��

destruct(this_object),call_out �禡�N�|���_�A��ͬO�n�O�H�H

		if( inv[i]->query("id")=="firewood" && inv[i]->query("on_fire")!=1 )
		{
		tell_object(this_player(),inv[i]->query("name")+"\n" );
		inv[i]->set("on_fire",1);
		inv[i]->set("no_sac",1);
		inv[i]->set("no_sell",1);
		inv[i]->set_name("��K["+HIR"�U�N��"+NOR"]",({"firewood","wood"}));
		}
*/

	}

	}
	destruct(ob);
}
