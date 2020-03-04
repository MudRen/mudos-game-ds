// liquid.c

#include <dbase.h>
#include <name.h>

void init()
{
	add_action("do_drink", "drink");
	add_action("do_fill", "fill");
}

string extra_long()
{
	int amount, max;
	string str;

	if( amount = query("liquid/remaining") ) {
		max = query("max_liquid");
		if( amount == max )
			str = "�̭��˺��F" + query("liquid/name") + "�C\n";
		else if( amount > max/2 )
			str = "�̭��ˤF�C�B�K������" + query("liquid/name") + "�C\n";
		else if( amount >= max/3 )
			str = "�̭��ˤF���B��������" + query("liquid/name") + "�C\n";
		else if( amount > max/2 )
			str = "�̭��ˤF�ֳ\\��" + query("liquid/name") + "�C\n";
		return str;
	}
	else return 0;
}

int do_drink(string arg)
{
	object env;
	if( !this_object()->id(arg) ) return 0;
	if(! env = environment(this_object())) return 0;
	if(env !=this_player() && !this_object()->query("no_get")) return 0;
	if( this_player()->is_busy() )
		return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
	if( !query("liquid/remaining") )
		return notify_fail( name() + (query("liquid/name") ? "�w�g�Q�ܱo�@�w�]���ѤF":"�O�Ū��C\n"));
	if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
		return notify_fail("�A�w�g�ܤӦh�F�M�A�]�餣�U�@�w���F�C\n");

	add("liquid/remaining", -1);
	message_vision("$N���_" + name() + "�B�P�P�a�ܤF�X�f" + query("liquid/name")
		+ "�C\n", this_player());
	this_player()->add("water", 30);
	if( this_player()->is_fighting() ) this_player()->start_busy(1);
	if( !query("liquid/remaining") )
		write("�A�w�g�N" + name() + "�̪�" + query("liquid/name")
			+ "�ܱo�@�w�]���ѤF�C\n");

	// This allows customization of drinking effect.
	if( query("liquid/drink_func") ) return 1;

	switch(query("liquid/type")) {
		case "alcohol":
			this_player()->apply_condition("drunk",
				(int)this_player()->query_condition("drunk") 
				+ (int)query("liquid/drunk_apply"));
			break;
	}
	
	return 1;
}

int do_fill(string arg)
{
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
	if( !environment(this_player())->query("resource/water") )
		return notify_fail("�o�̨S���a��i�H�ˤ��C\n");

	if( query("liquid/remaining") )
		message_vision("$N�N" + name() + "�̳ѤU��" + query("liquid/name") + "�˱��C\n", this_player());
	message_vision("$N�N" + name() + "�˺��M���C\n", this_player());

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	set("liquid/type", "water");
	set("liquid/name", "�M��");
	set("liquid/remaining", query("max_liquid"));
	set("liquid/drink_func", 0);

	return 1;
}
