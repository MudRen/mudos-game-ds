#include <armor.h>
#include <ansi.h>
inherit LEGGING;
void create()
{
        set_name(HIR"�������H"NOR ,({ "maigu leggings","leggings"}) );
        set("long",@LONG
�������~�֧Φ����@�H,�ݰ_�Ӥ����n�Ϊ��ˤl.
LONG);
                set_weight(1000);
                set("material", "fur");
                set("unit", "��");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 1);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/con", -1);
                set("armor_prop/wit", 0);
                set("armor_prop/bar", 0);
	set("armor_type", "legging");
        setup();
}

void init()
{
/*
        if( userp(environment(this_object()) ) )
        {
                add_action("do_wear", "wear");
                add_action("do_remove", "remove");
        }
*/
}

int do_wear(string arg)
{
        object me;

        me = this_player();
	if( !this_object()->query("equipped") ) {
        if( arg == "leggings" || arg == "maigu leggings" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
                        set("wear_msg",HIW"$N�M�W�F�������H,�b�ɶ��ѷn�a��,�����~�����F�i�J$N���餺!\n"NOR);
                me->add_temp("god_armor", 1);
                me->add_temp("wear_leggings",1);
                set("armor_prop/bar", 2);
                set("armor_prop/wit", 2);
                set_weight(1000);
                set("material", "diamond");
                set("unit", "��");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 3);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
                }
                else {
                   if(me->query_temp("wear_leggings") == 0)
                {
                        me->add_temp("god_armor", 1);
                        me->add_temp("wear_leggings",1);
                }
                }
        }
	}
}

int do_remove(string arg)
{
        object me;

        me = this_player();
        if( this_object()->query("equipped") ) {
        if( arg == "leggings" || arg == "maigu leggings" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
			this_object()->create();
			present("chini boots", environment(this_object()))->create();
			present("chini wrists", environment(this_object()))->create();
			present("maigu gloves", environment(this_object()))->create();
			present("wo cloak", environment(this_object()))->create();
			present("wo waist", environment(this_object()))->create();
			delete("wear_msg");
                        me->add_temp("god_armor", -1);
                        me->add_temp("wear_leggings",-1);
			me->add_temp("apply/bar", -2);
			me->add_temp("apply/wit", -2);

                }
                else
                {
                        me->add_temp("god_armor", -1);
                        me->add_temp("wear_leggings",-1);
                }
	}
        }
}

