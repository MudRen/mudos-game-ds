#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"祈福天燈"NOR, ({ "wish lamp","lamp" }) );
        set_weight(600);
        set_max_capacity(2000);
        set_max_encumbrance(2000);      // 假設一張紙只有一克
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long",@LONG
天燈又稱為孔明燈，相傳為三國諸葛亮的發明，也被公認為熱氣球的始祖
，起初是為了傳遞訊息之用，但目前通常則被當成節慶祈福許願(wish)的工具。
你可以許的願望有下列這些，一次只能選擇一個願望：
    1. wish exp   [你想要得到的經驗值數目]
    2. wish pop   [你想要得到的聲望數目]
    3. wish art   [你想要得到的戰鬥藝術數目]
    4. wish money [你想要得到的金錢數目]

    特別獎：每一個天燈都有 (燈油瓶數)/10000 的機率獲得一個元宵娃娃。

在你許完願之後，就要放入足夠的燈油，之後就能點燃(ignite)天燈，讓天燈升
到高空去，如果能成功升空，你就能實現你的願望。
你可以使用「oil」指令來檢視目前天燈中放有多少燈油。
LONG
);
                set("value", 99);
               }
        setup();
}
void init()
{
        add_action("do_wish","wish");
        add_action("do_light","ignite");
        add_action("do_oil","oil");
}
int do_wish(string arg)
{
    object me;
        string type, wish;
        int amount;
        me = this_player();
        if(!arg || sscanf(arg, "%s %d", type, amount) != 2 || amount < 1)
                return notify_fail("你想要許\什麼願？\n");
        if( query("wish_type") )
                return notify_fail("你這天燈已經許\過願望。\n");
        switch(type) {
                case "exp":
                        wish = "經驗值 "+amount+"點";
                break;
                case "pop":
                        wish = "聲望 "+amount+"點";
                break;
                case "art":
                        wish = "戰鬥藝術 "+amount+"點";
                break;
                case "money":
                        wish = "" + amount+"枚銅版";
                break;
                default:
                        wish = type;
        }
        message_vision( CYN"$N誠心誠意地對著天燈許\下「" + wish + "」的願望。\n" NOR,me);
        set("name", HIY"祈福天燈 [" + wish + "]" NOR);
        set("wish",wish);
        set("wish_type", type); 
        set("wish_amount",amount);
    return 1;
}
void light2(object me) {
        string msg;
        int s1,s2;
        s1 = 1;       
//        s2 = isSuccess2();      // 助燃器
        if( s1 || s2 ) {
                switch(query("wish_type") ) {
                case "exp": 
                        me->add("exp", query("wish_amount"));
                break;
                case "pop": 
                        me->add("popularity", query("wish_amount"));
                break;
                case "art": 
                        me->add("war_art", query("wish_amount"));
                break;
                case "money":   // 最容易成功
                        me->add("bank/past", query("wish_amount"));
                break;
                }
                if( s1 = random(2) ) 
                        msg = HIC"\n\t只見"+me->name()+HIC"的 " + name() +HIC" 帶著許\下的願望，升到很高很高的天際。\n"NOR;
                else 
                        msg = HIC"\n\t只見"+me->name()+HIC"的 " + name() +HIC" 帶著許\下的願望，宛如"HIR"著火"HIC"一樣，在天空中化為一顆"HIR"火球"HIC"！！\n"NOR;

                // 特別獎：doll
//              if( getOils() > random(10000) ) {
//                      new("/open/world1/tmr/game/2007_light/wish_lamp_doll.c")->move(me);
//                      msg += HIG"\n\t\t只見一個小巧可愛的天燈娃娃從天際緩緩落到 "+me->name()+HIG"的手中。\n"NOR;
//                }
        message("system",  msg, users() );
        } else {
            message_vision(HIM "可惜$n"HIM"歪歪斜斜，一下子就掉落到不知道何方...\n"NOR, me, this_object() );
        }
        destruct(this_object());
}

int do_light(string arg)
{
    object me;
        me = this_player();
        if( !arg || arg != "lamp" )
                return notify_fail("你想要點燃什麼？\n");
        if( query("ignite") )
                return notify_fail("這天燈已經點燃，正在升空中。\n");
        if( !query("wish_type") )
                return notify_fail("你這天燈還沒有許\過願。\n");
//        if( getOil() < 1 )
//                return notify_fail("這天燈中沒有燈油，無法點燃。\n");

    message_vision(HIC"$N點燃$n"HIC"中的燈油，只見$n"HIC"緩緩的升上天去...\n"NOR, me, this_object() );
        me->start_busy(2);
        set("ignite",1);
        call_out("light2", 2 + random(8), me );
        return 1;
}

