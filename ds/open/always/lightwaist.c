#include <armor.h>
#include <ansi2.h>

inherit WAIST;

void create()
{
	set_name(HIW"�p�۸y�a"NOR ,({ "diamond waist", "waist" }) );
	set_weight(10000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("long", @long
�o�Ӧ��p�@��˥ҭ����p�۸y�a�A�O�Ѧh���p�ۥ��y�Ӧ����A�O����
�����~�פ���`�y�O���v�v�z���ɤj���A�a�W���p�۱ƦC���ǡA�Φ�
�F�X�Ӧr�y����`�ּ֡z�A�Ө����p�ۥѩ�Ӥj�����Y�A�{�{�o���A
���۷ө����@�ΡC

Mid-Autumn Festival Gifts By -Alickyuen@The.Dream.Of.Seven
long);
		set("unit", "��");
                set("value", 1);
                set("no_sell", 1);
		set("material", "diamond");
	}
	set("armor_prop/con",1);
	set("armor_prop/int",1);
	set("armor_prop/shield",15);
	set("armor_prop/armor",25);
	setup();
}

int query_autoload() { return 1; }

void init()
{
	object me= this_player();
        string id;

	add_action("do_wear", "wear");

	if( !me ) return;
	if( !userp(me) ) return;
        id = me->query("id");
        if( id != "bug"
        &&  id != "ttoopp"
        &&  id != "arboria"
        &&  id != "chchiyau"
        &&  id != "alickyuen"
        &&  id != "release"
        )
        {
                tell_object(me, HIW"��M�����A"+this_object()->name()+HIW"�����~�����F�C\n"NOR);
                this_object()->delete("armor_prop");
                this_object()->set("value", 0);
                this_object()->set("name","�����y�a");
                this_object()->start_light(0);
		this_object()->set_durable(0);
                return;
        }
        if( this_object()->query("name") == "�����y�a" ) this_object()->create();
	if( environment(this_object()) == me )
	{
		if( !this_object()->query_light() ) this_object()->start_light(1);
  	}
}

int do_wear(string arg)
{
	object me;
	me = this_player();

	if( arg == "waist" || arg == "diamond waist" ) 
	{
		if( !this_object()->query_durable() )
			return notify_fail("�A�èS������۳o��ӢߡC\n");
	}
}
