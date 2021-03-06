#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
    set_name(HIW+BLK"夜月"NOR+YEL"寶鑑"NOR, ({ "night moon book", "book", "moon", "night" }));
    set("long", "散發著淡黃色月光的神奇寶典，不過閉合處卻怎麼也打不開，看來只\n"
                "有特定的主人才能使用這個物品。\n");

    set_weight(1200);
    if( clonep() ) set_default_object(__FILE__);
    else {
        set("unit", "本");
        set("value", 0);
    }
    set("limit_lv", 80);
    set("armor_prop/armor", 200);
    set("armor_prop/shield", 200);
    set("armor_prop/dodge", 10);
    set("armor_prop/str", 10);
    set("armor_prop/con", 10);
    set("armor_prop/int", 10);
    set("armor_prop/dex", 10);
    call_out("heal_book", 10);
    setup();
}

int query_autoload() { return 1; }

void init()
{
    add_action("do_open", "openbook");
    add_action("do_close", "closebook");
}
void heal_book()
{
    object me = environment(this_object());

    if( !this_object() || !me ) return;
    if( !me->is_fighting() ) {
        call_out("heal_book", 60);
        return;
    }
    if( me->query_temp("openbook") == 1 && me->query_temp("armor/shield") == this_object() ) {
        switch( random(2) ) {
            case 0: me->receive_heal("hp", me->query("max_hp"));
                    me->receive_heal("ap", me->query("max_ap"));
                    me->receive_heal("mp", me->query("max_mp"));
                    message_vision("\n$N"HIY"閃耀著皎潔的月光，治療了$n"HIY"身上的傷口。\n\n"NOR, this_object(), me);
                    break;
            case 1: me->receive_curing("head", 1);
                    me->receive_curing("body", 1);
                    me->receive_curing("left_arm", 1);
                    me->receive_curing("left_leg", 1);
                    me->receive_curing("right_arm", 1);
                    me->receive_curing("right_leg", 1);
                    message_vision("\n$N"HIR"反射了太陽的微弱亮光，治療$n"HIR"所受的內傷。\n\n"NOR, this_object(), me);
                    break;
            default: message_vision("$N稍微閃爍了一下，但是沒發生任何事。\n"NOR, this_object(), me);
                    break;
        }
    }
    call_out("heal_book", 30);
}
int do_open(string arg)
{
    object me = this_player();

    if( me->query_temp("openbook") == 1 ) return notify_fail("你已經將寶典打開了。\n");

    if( wizardp(me) && me->query_temp("armor/shield") == this_object() ) {
        message_vision(HIM"\n$n將魔力配合內勁在$N"HIM"上劃出一道符文，只漸符文消失後$N"HIM"震動了起來...\n"NOR, this_object(), me);
        message_vision(HIW"$N"HIW"發出強烈的閃光直衝天際，原本書上的封印居然就此解開，所含的能量全數灌入$n體內。\n\n"NOR, this_object(), me);
        me->set_temp("openbook", 1);
    } else {
        message_vision("$n使盡吃奶的力氣想打開$N，但是$N依然毫無所動。\n"NOR, this_object(), me);
        if( wizardp(me) ) tell_object(me, "你必須先裝備後才能使用功\能。\n");
    }
    return 1;
}
int do_close(string arg)
{
    object me = this_player();

    if( me->query_temp("openbook") != 1 ) return notify_fail("寶典根本就沒有打開，是要關什麼東西。\n");

    message_vision(HIM"$n低聲的唸了一些咒文，$N"HIM"又逐漸合了起來。\n"NOR, this_object(), me);
    me->delete_temp("openbook");
    return 1;
}
