#include <armor.h>
#include <ansi2.h>
inherit FINGER;
void create()
{
        set_name(HIW"���H�٫�"NOR, ({ "snowman ring","ring" }) );
        if( clonep() )
        	set_default_object(__FILE__);
        else 
        {
        	set("long",@LONG
�o�u�٫��O���������~���ﳷ�H���ʪ����~�A�y���O�@�Ӥp�p�����H
�A�ˤl�D�`�i�R�A�ӥB���������ٷ|�o�ۥ��G�C
					           by sdo@DS
LONG
	);
                set("unit", "�u");
        	set_weight(600);
       		set("no_sell",1);
       		set("no_drop",1);
        }
        set("material","jade");
        set("armor_prop/armor", 15);
        set("armor_prop/con",2);
        set("armor_prop/int",1);
       	set("armor_prop/dex",1);
        setup();
}

int query_autoload() { return 1; }

void init()
{
        object me= this_player();
        string id;

        add_action("do_wear", "wear");

        if( !me ) return;
        id = me->query("id");
        if( id != "tear"
        &&  id != "wait"
        &&  id != "roba"
        &&  id != "rex"
        &&  id != "waited"
        &&  id != "sdo"
        )
        {
                tell_object(me, HIW"��M�����A"+this_object()->name()+HIW"�����~�����F�C\n"NOR);
                this_object()->delete("armor_prop");
                this_object()->set("value", 0);
                this_object()->set("name","�_��H�٫�");
                this_object()->start_light(0);
                this_object()->set_durable(0);
                return;
        }
        if( this_object()->query("name") == "�_��H�٫�" ) this_object()->create();
        if( environment(this_object()) == me )
        {
                if( !this_object()->query_light() ) this_object()->start_light(1);
        }
}

int do_wear(string arg)
{
        object me;
        me = this_player();

        if( arg == "ring" || arg == "snowman ring" ) 
        {
                if( !this_object()->query_durable() )
                        return notify_fail("�A�èS������۳o��ӢߡC\n");
        }
}