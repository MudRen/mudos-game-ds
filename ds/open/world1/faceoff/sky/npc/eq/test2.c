#include <armor.h>
#include <ansi.h>
inherit WRISTS;
void create()
{
        set_name(HIR"�_�ٰ��N"NOR ,({ "chini wrists","wrists"}) );
        set("long",@LONG
�_�٪��~���f�Φ����@��,�ݰ_�Ӥ����n�Ϊ��ˤl.
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
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
        setup();
}

void init()
{
        if( userp(environment(this_object()) ) )
        {
                add_action("do_wear", "wear");
        }
}

int do_wear(string arg)
{
        object me;

        me = this_player();

        set("wear_msg", "�A�˳ƤW"+this_object()->query("name")+"�C\n");

        if( arg == "wrists" || arg == "chini wrists" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
                        set("wear_msg",HIW"$N�M�W�F�_�ٰ��N,�b�ɶ��ѷn�a��,�����~�����F�i�J$N���餺!\n"NOR);
                }
                else {
                   if(me->query_temp("wear_wrist") == 0)
                {
                        me->add_temp("god_armor", 1);
                        me->add_temp("wear_wrist",1);
                }
                }
        }
}
