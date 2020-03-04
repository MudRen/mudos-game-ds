inherit ITEM;
inherit F_FOOD;
int fresh;
void create()
{
	set_name("����",({ "fish meat","meat" }) );
	set_weight(300);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
�o�O�@���ѳ����W���U���סA��ͳ��������C
LONG);
	set("unit", "��");
	set("material","food2");
	}
	set("value",50);
	set("food_remaining",2);
	set("heal_hp",5);
	set("cook","fish_soup_120");
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
		call_out("decay",300);
	}
}

int is_meat() { return fresh; }

void decay()
{
	function f;
	object env;
	if(!this_object()) return;
	if(!fresh) return;
	set("name","�G�ꪺ����");
	set("long",query("long")+"�o�����פw�g�G�걼�F�A�o�X�}�}�G��C\n");
	if(env=environment(this_object())) tell_room(env,"���׻G��F�A�o�X�}�}�G��C\n");
	set("value",0);
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