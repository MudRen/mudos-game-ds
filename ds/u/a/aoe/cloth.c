#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name("＠測試補充", ({ "test receive", "test","cloth","receive" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("west",1);
                set("value",8000);
                set("base_unit", "件");
                set("unit", "件");
        }
        setup();
}

void init()
{
        call_out( "heart_beat" ,1,this_player());
}

void heart_beat(object me)
{
        if( me->is_fighting() )
        {
                message_vision(HIG"$n發出陣陣的閃光，$N身上的傷口漸漸的複合了起來。\n"NOR,me,this_object());
                this_player()->receive_heal("hp",random(5)+1);
        }
        call_out("heart_beat", 5+random(10),me);
        return;
}

