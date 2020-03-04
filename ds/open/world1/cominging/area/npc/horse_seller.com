#include <dbase.h>
#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�P�Գs", ({ "horse seller" , "seller" }) );
	set("long",
        "�o�O�B�F�����s�}���s�԰��\\���D�H�A�L���Τߪ����U�����C\n"
	    "�A�i�H�ݰݥL���樺�ذ�(list)�A�άO�V�L�ʶR�U�ث~�ت���(buy)\n"
	);
	set("level", 10);
	set("no_fight",1);
	set("age",   50);
	set("chat_chance", 1);
	set("chat_msg", ({
  (: command("say �̪�u�O���r..") :),
  (: command("sigh") :),
  (: command("say �����D�ٷ|���ȤH�W���_ ?") :),
}) );
	set("sell_list",([	
		__DIR__"horse": 4,
	]));
	setup();
	add_money("coin",50);
}

void init()
{
	add_action("do_buy","buy");
	add_action("do_list","list");
}


int do_buy_amount()
{

}

string item_list(object ob)
{
	int b;
	b=ob->query("value");
	return sprintf(" %7d �w�w�w�w�w�w�w�w  %-26s",
		b,ob->short()
		);
}

int do_list(string arg)
{
	object goods,me;
	mapping item;
	string list, *file;
	int i,*supply_cost,debug;
        
	me=this_player();

	if(wizardp(me) && me->query("env/debug")) debug=1;
		else debug=0;

        if( ! mapp( item = query("sell_list") ) )
        {
                write("�o��p�c�S�����~�C��I\n");
                return 0;
        }

	file =  keys(item);
	supply_cost = values(item);
	list = "\n\n\n�z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{\n"
		    +"�x �� ��                          �ثe�i�H�ʶR�����زM��    �x\n"
		    +"�|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}\n";
	for( i=0 ; i<sizeof(file) ; i++)
	{
		goods = load_object(file[i]);
		if(goods) list+= item_list(goods);
		if(debug) list+= sprintf(GRN+" SP:(%3d)\n"+NOR,supply_cost[i]);
			else list+="\n";
		list +="\n";
	}
	list +="\n";
	if( i==0 ) return notify_fail(this_object()->query("name")+"��A��: �藍�_��..�f���槹�F�C\n");
	else {
		tell_object(me,"\n");
		me->start_more(list);
	}
	return 1;       
}

int do_buy(string arg)
{
	int valus,j,world;
	object goods,ob,me;
	string item,*file;
	mapping items;
	
	items = query("sell_list");
	me = this_player();

	if( arg!="horse" ) return notify_fail("�A�n�R����F��H\n");

	file = keys(items);
//	int *supply_cost;
//	supply_cost = values(items);
	goods = load_object(__DIR__"horse.c");
	valus=goods->query("value");

	if( !me->can_afford( valus ) )
		return notify_fail("�A���W���������C\n");

	me->receive_money(-valus);
	me->add("supply_point",-50);

	world = me->money_type();
	message_vision("$N��F "+price_string(valus,me->money_type())+" �V$n�R�F�@"+goods->query("unit")+goods->name()+"�C\n", me , this_object() );

	ob = new(__DIR__"horse.c");
	call_out("buy1",0,me,ob);
	call_out("buy2",7,me,ob);
//	ob->move(environment(me));
	me->save();
	return 1;
}

void buy1(object me,object ob)
{
	message_vision("�P�Գs��$N���R$n�O�a�H�е��|��I\n",me,ob);
	message_vision("�P�Գs��۰��٩Զ}���V�[�ܹD�G�Ӱ��I\n",me);
	return;
}

void buy2(object me,object ob)
{
	message_vision("�٤����p�G�@���W��ۺq��$n���o�F�X�ӡC\n"
		+"�P�Գs��$N���G�ȭ��A�z��$n�ӤF�I\n"
		+"�P�Գs���q�����ٲo�X�Ӫ�$n��$N���e�C\n"
		, me , ob );
	ob->move(environment(me));
	me->save();
	return;
}
