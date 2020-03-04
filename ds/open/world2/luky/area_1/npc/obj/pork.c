inherit ITEM;
inherit F_FOOD;
int fresh;
void create()
{
	set_name("�ަ�",({ "pork" }) );
	set_weight(2000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long","�o�O�@���ѽި��W���U���סC\n");
	set("unit", "��");
	}
	set("value",150);
	set("food_remaining",4);
	set("heal_hp",10);
	setup();
	fresh=1;
}

void init()
{
	object env;
	::init();
	if(env=environment(this_object()))
	{
		if(!userp(env) || !fresh) return;
		call_out("decay",600);
	}
}

int is_meat() { return fresh; }

void decay()
{
	function f;
	object env;
	if(!this_object()) return;
	if(!fresh) return;
	set("name","�G�ꪺ�ަ�");
	set("long",query("long")+"�o���ަפw�g�G�걼�F�A�o�X�}�}�G��C\n");
	if(env=environment(this_object())) tell_room(env,"�ަ׻G��F�A�o�X�}�}�G��C\n");
	set("value",10);
	set("heal_hp",0);
	f = (: call_other, __FILE__, "eat_bad_pork" :);
	//set("food/function", bind(f, ob));
	set("food/function", bind(f,this_object()));
	fresh=0;
	return;
}

int eat_bad_pork(object ob)
{
	if(!ob) return 0;
	this_player()->receive_damage("hp",20);
	this_player()->apply_condition("eat_bad", this_player()->query_condition("eat_bad")+3);
	message_vision("$N�]���Y�F�����b���F��ӭ������r�F�C\n",this_player());
	return 1;
}