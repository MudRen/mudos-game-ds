#include <armor.h>
#include <ansi2.h>

inherit SURCOAT;

int check(object me);

void create()
{
        set_name(HIR"����ܪ�"NOR ,({ "red cloak", "cloak" }) );
        set_weight(15000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
		set("long", @long
�o�O�@���n�������⪺���A�ݰ_�ӨèS������S�O�A�O���������~�t
�ϸ`���S�O§�~�C

2001 Christmas Gifts By -Alickyuen@The.Dream.Of.Seven-
long);
                set("unit", "��");
                set("value", 1);
                set("no_sell", 1);
                set("material", "cloth");
	}
        set("armor_prop/con", -2);
        set("armor_prop/bar", 1);
        set("armor_prop/bio", -1);
        set("armor_prop/armor", -5);
	setup();
}

int query_autoload() { return 1; }

void init()
{
	object me= this_player();

	add_action("do_wear", "wear");

	if( !me ) return;
	if( !userp(me) ) return;

	check(me);
}

int check(object me)
{
	string id;

        id = me->query("id");
        if( id != "jill" // �Ĥ@�W
        &&  id != "tear" // �ĤG�W
        &&  id != "opek" // �ĤT�W
        &&  id != "alickyuen"
&& id !="jangshow"
        )
        {
                tell_object(me, HIW"��M�����A"+this_object()->name()+HIW"���ܱo�t�H�L��F�C\n"NOR);
                this_object()->delete("armor_prop");
                this_object()->set("value", 0);
                this_object()->set("unit", "��");
                this_object()->set("name", "�ꥬ");
                this_object()->set("long", @long
�o�O�@���n�������⪺���A�ݰ_�ӨèS������S�O�A�O���������~�t
�ϸ`���S�O§�~�C������������{�b�ܱo�t�H�L���C

2001 Christmas Gifts By -Alickyuen@The.Dream.Of.Seven-
long);
		this_object()->set_durable(0);
		return 1;
        }
        if( this_object()->query("name") == "�ꥬ" ) this_object()->create();
	if( environment(this_object()) == me )
	{
                this_object()->set("armor_prop/name", ({ "�­�������"+me->query("name") }) );
  	}
	return 1;
}

int do_wear(string arg)
{
	object me;
	me = this_player();

        if( arg == "cloak" || arg == "red cloak" ) 
	{
		if( !this_object()->query_durable() )
			return notify_fail("�A�èS������۳o��ӢߡC\n");
	}
}

