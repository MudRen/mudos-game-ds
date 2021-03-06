#include <ansi.h>
#include <armor.h>
inherit ARMOR;
void create()
{
    set_name(HIR"戰爭禮讚"NOR ,({ "war plate","plate","armor"}));
    set("long",@LONG
【戰神】阿瑞斯親手剝下一千個值得敬重對手的頭皮所做成的皮鎧，
鎧面上無數血紅的紋路組成了奇異的魔紋，能夠為佩帶著帶來無與倫
比的信念。
LONG);
    set_weight(5000);
    if ( clonep() )
        set_default_object(__FILE__);
    else
    {
        set("material", "leather");
        set("volume",4);
        set("unit", "件");
        set("value",15000);
    }
    set("limit_con",50);
    set("limit_lv",40);
    set("armor_prop/armor",54);
    set("armor_prop/shield",25);
    set("armor_prop/con", 5);
    set("armor_prop/str", 2);
    set("armor_prop/dex", -4);
    set("armor_prop/hit", 5);
    setup();
    call_out("receive_by_plate", 60);
}

void receive_by_plate()
{
    object me; 
    int effect;
    if( !this_object() ) return;
    me = environment(this_object());
    if( !me || !interactive(me) || me->query_temp("armor/armor") != this_object() ) {
         //沒有人使用中
       call_out("receive_by_plate", 90); 
        return ;
    }
    effect = me->query("max_mp");
    if( me->query("mp") < effect*4/5 ) {
        me->receive_heal("mp", effect/18);
        message_vision("從$N漸漸瀰漫出來濃厚的血色霧氣，$n陶醉地吸了幾口，施法的暈眩感也因此減輕了不少。\n"NOR,this_object(), me);
        call_out("receive_by_plate", 45);
    } else call_out("receive_by_plate", 90);
}

