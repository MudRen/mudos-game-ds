#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
	set_name("�Z�h�ܭ�", ({ "jedi cloak","cloak" }) );
	set_weight(2500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�OJedi Knight ���ǲΪ��A���A�ݨ����äF�@�ǯ����O�q�C\n");
		set("unit", "��");
		set("material", "silk");
		set("no_give",1);
		set("no_drop",1);
		set("no_sell",1);
		set("no_sac",1);
		set("value",0);
	}
	set("armor_prop/shield",15);
	set("armor_prop/dodge",5);
	set("armor_prop/armor",20);
	setup();
}
void init()
{
	add_action("cover", "cover");
	add_action("discover","discover");
}
int do_cover(string arg)
{
	object me;
	me->set_temp("apply/id",({"masker"}));
	me->set_temp("apply/name",({"�X���H"}));
	me->set_temp("apply/short",({"�X���H(Masker)"}));
	me->set_temp("apply/long",({"�@�ӥζ¦�ܭ��ۥ����������H�C\n"}));
	message_vision("$N���W�F�Z�h�ܭ��C\n",);
}
int do_discover(string arg)
{
	object me;
	me->delete_temp("apply/name");
	me->delete_temp("apply/id");
	me->delete_temp("apply/short");
	me->delete_temp("apply/long");
	message_vision("$N���U�Z�h�ܭ��C\n",);
	return 1;
}
int query_autoload() { return 1; }
