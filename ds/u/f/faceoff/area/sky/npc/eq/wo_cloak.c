#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIR"霧氣之璧"NOR ,({ "wo cloak","cloak"}) );
        set("long",@LONG
霧獸之氣形成的護背,看起來不怎麼好用的樣子.
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(1000);
                set("material", "fur");
                set("unit", "件");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/con", 1);
        }
        setup();
}

void init()
{
        if( userp(environment(this_object()) ) )
        {
                add_action("do_wear", "wear");
                add_action("do_remove", "remove");
        }
}

int do_wear(string arg)
{
        object me;

        me = this_player();
        if( arg == "cloak" || arg == "wo cloak" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
                        set("wear_msg",HIW"$N套上了霧氣之璧,剎時間天搖地動,眾神獸的元靈進入$N的體內!\n"NOR);
                me->add_temp("god_armor", 1);
                me->add_temp("wear_cloak",1);
                set("armor_prop/bar", 2);
                set("armor_prop/wit", 2);
                set_weight(1000);
                set("material", "diamond");
                set("unit", "件");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
                }
                else {
                   if(me->query_temp("wear_cloak") == 0)
                {
                        me->add_temp("god_armor", 1);
                        me->add_temp("wear_cloak",1);
                }
                }
        }
}

int do_remove(string arg)
{
        object me;

        me = this_player();

        if( arg == "cloak" || arg == "wo cloak" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
                        set("wear_msg",HIW"$N的眾神獸之氣漸漸散去!....n"NOR);
                        me->add_temp("god_armor", -1);
                        me->add_temp("wear_cloak",-1);

                }
                else
                {
                        me->add_temp("god_armor", -1);
                        me->add_temp("wear_cloak",-1);
                }
        }
}
