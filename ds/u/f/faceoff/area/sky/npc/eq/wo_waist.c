#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
        set_name(HIR"霧氣之纏"NOR ,({ "wo waist","waist"}) );
        set("long",@LONG
霧獸之氣形成的腰帶,看起來不怎麼好用的樣子.
LONG);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(1000);
                set("material", "fur");
                set("unit", "對");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
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
                add_action("do_remove", "remove");
        }
}

int do_wear(string arg)
{
        object me;

        me = this_player();

        if( arg == "waist" || arg == "wo waist" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
                        set("wear_msg",HIW"$N套上
了霧氣之璧,剎時間天搖地動,眾神獸的元靈進入$N的體內!\n"NOR);
                me->add_temp("god_armor", 1);
       
         me->add_temp("wear_waist",1);
                set("armor_prop/bar", 3);
                set("armor_prop/wit", 3);
                set_weight(1000);
                set("material", "diamond");
                set("unit", "對");
                set("value",100);
                set("volume",3);
                set("armor_prop/armor", 5);
                set("limit_con",10);
                set("limit_str",10);
                set("armor_prop/dex", 1);
                }
                else {
                   if(me->query_temp("wear_waist") == 0)
                {
                        me->add_temp("god_armor", 1);
                        me->add_temp("wear_waist",1);
                }
                }
        }
}

int do_remove(string arg)
{
        object me;

        me = this_player();

        if( arg == "waist" || arg == "wo waist" || arg == "all")
        {
                if( me->query_temp("god_armor") >= 5 )
                {
                        set("wear_msg",HIW"$N的眾神獸之氣漸漸散去!....n"NOR);
                        me->add_temp("god_armor", -1);
                        me->add_temp("wear_waist",-1);

                }
                else
                {
                        me->add_temp("god_armor", -1);
                        me->add_temp("wear_waist",-1);
               }
        }
}
