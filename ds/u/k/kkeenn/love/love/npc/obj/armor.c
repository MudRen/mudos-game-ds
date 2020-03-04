#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIR"烈情"HIW"※"HIC"寒冰"NOR ,({ "frame ice armor","armor" }) );
        set("long",@LONG        
    這是一件傳說中武林十大名器屬【防】屬性的護具，以
南海島的純陽神勁配上北方冰島的純陰真氣而成，使用者會
感到一股溫暖的氣息環繞，十分舒服，難怪被列為十大名器
。        
LONG
);
        set_weight(8800);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("unit", "件");
                set("limit_level",15);
        }
        set("no_sac",1);
        set("no_give",1);
    set("wear_msg", "$N的身旁突然衝突兩道截然不同的氣息- $n！\n");
    set("unequip_msg", "$N運氣震開了身上的兩種氣- $n！\n");
        set("no_put",1);
        set("no_sell",1);
        set("monster_armor_prop/con",3);
        set("armor_prop/show_damage",1);
        set("monster_armor_prop/armor",42);
        set("monster_armor_prop/shield",18);
        set("monster_armor_prop/dodge",4);
        
        set("armor_prop/dex",3);
        set("armor_prop/con",2);
        set("armor_prop/armor",36);
        set("armor_prop/shield",8);
        setup();
        call_out("receive", 60);
        call_out("receive2", 120);
}
void receive()
{
        object me = environment(this_object());
        int p_hp;

        if( !this_object() || !me ) return;
        if( interactive(me) && me->query_temp("armor/armor") == this_object())
        {
                p_hp = me->query("max_hp");
                if( me->query("hp") < p_hp )
                {
                        me->receive_heal("hp", p_hp*5/37);
message_vision("$N"HIW"發出一道寒冷的氣勁，$n"HIW"受到的外傷似乎有些恢復！\n"NOR, this_object(), me);
                }
                else
                {
  message_vision("$N"HIW"發出一道寒冷的氣勁，但是沒有什麼事發生！\n"NOR, this_object());
                }
        }
        call_out("receive", 50);
}
void receive2()
{
        object me = environment(this_object());
        int p_ap;

        if( !this_object() || !me ) return;
        if( interactive(me) && me->query_temp("armor/armor") == this_object())
        {
                p_ap = me->query("max_ap");
                if( me->query("ap") < p_ap )
                {
                        me->receive_heal("ap", p_ap*3/40);
message_vision("$N"HIR"發出一道高溫的火氣，$n"HIR"受到的內傷似乎有些恢復！\n"NOR, this_object(), me);
                }
                else
                {
                        message_vision("$N"HIR"發出一道高溫的火氣，但是沒有什麼事發生！\n"NOR, this_object());
                }
        }
        call_out("receive2", 60);
}


