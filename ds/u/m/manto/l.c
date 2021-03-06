#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"祈福天燈"NOR, ({ "wish lamp","lamp" }) );
    set_weight(600);

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
    set_max_capacity(2000);
    set_max_encumbrance(2000);      // 假設一張紙只有一克
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "口");
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

int getOil() {
    object *inv;
    int i, total;
    inv = all_inventory(this_object() );
    if( !sizeof(inv) )
        return 0;

    total = 0;
    for(i=0; i<sizeof(inv); i++)
    {
        if( !inv[i]->id("_LAMP_OIL_") ) continue;
        total += inv[i]->query("time");
    }

    return total;
}

int getSize(string type) {
    object *inv;
    int i, total;
    inv = all_inventory(this_object() );
    if( !sizeof(inv) )
        return 0;

    total = 0;
    for(i=0; i<sizeof(inv); i++)
    {
        if( !inv[i]->id(type) ) continue;
        total ++;
    }

    return total;
}

int do_oil()
{
    return notify_fail( sprintf("目前天燈中有 %4d瓶共 %4d公克的燈油、%2d瓶助燃器、%2d個調節器及%2d個觸媒。\n",
                                getSize("_LAMP_OIL_"), getOil(), getSize("_LAMP_OIL_TOOL_"),
                                getSize("_OIL_REGULATOR_"), getSize("_OIL_CATALYST_"),
                               ));
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
        return notify_fail("你無法許\這種願望。");
    }
    message_vision( CYN"$N誠心誠意地對著天燈許\下「" + wish + "」的願望。\n" NOR,me);
    set("name", HIY"祈福天燈 [" + wish + "]" NOR);
    set("wish",wish);
    set("wish_type", type);
    set("wish_amount",amount);
    return 1;
}

// 取得願望所需要的花費, 單位為 1克 : 100
// 200,000 二十萬 -> 一千萬
#define MAX_OIL 200000

#define MONEY_BASE 1    // 可以換200萬
#define EXP_BASE 10             //  可以換20萬
#define POP_BASE 498     //  可以換2萬
#define ART_BASE 4987   //  可以換2千

int isSuccess2() {
    int oil = getSize("_LAMP_OIL_");      // 以公克為單位
    int ts = getSize("_LAMP_OIL_TOOL_"); // 以瓶為單位

    if( query("wish_amount") > 8000000 + random(4000000) ) return 0;

    // 一個助燃器有0.5%的成功率
    if( ts > 300 ) ts = 300;
    // 至少要 500克的油，20%
    if( oil >= 500 && ts > random(1500) )
    {
        switch( query("wish_type") ) {
        case "exp":
            return query("wish_amount") < 12345678;
        case "pop":
            return query("wish_amount") < 123456;
        case "art":
            return query("wish_amount") < 10000;
        case "money":   // 最容易成功
            return query("wish_amount") < 12345678;
        }
    }

    return 0;
}

int isSuccess() {
    int oil = getOil() * 100;       // 可用油數*100

    // 最大值
    if( query("wish_amount") > 8000000 + random(4000000) ) return 0;

    switch(query("wish_type") ) {
    case "exp":
        return query("wish_amount")  <= oil/EXP_BASE && random(100) < 95;
    case "pop":
        return query("wish_amount")  <= oil/POP_BASE && random(100) < 90;
    case "art":
        return query("wish_amount")  <= oil/ART_BASE && random(100) < 80;
    case "money":   // 最容易成功
        return query("wish_amount")  <= oil/MONEY_BASE;
    }

    return 0;
}

int isBurst() {
    int ts, cs, rs, p;
    ts = getSize("_LAMP_OIL_TOOL_"); // 以瓶為單位
    cs = getSize("_OIL_CATALYST_"); // 以瓶為單位
    // 減少爆炸
    rs = getSize("_OIL_REGULATOR_"); // 以瓶為單位

    p = ts + cs - rs;
    return p > random(100);
}

void light2(object me) {
    string msg;
    int s1,s2;
    int rs, oils;
    // 爆炸的可能性
    if( isBurst() ) {
        msg = sprintf(
                  HIM "\n\n\t只見火苗快速竄起，%s點燃的"HIM"%s"HIM"轉瞬間就變成"HIR"大火球"HIM"，發生強烈的爆炸！！！\n\n"NOR, me->query("name"), query("name") );
        message("system",  msg, users() );
        destruct(this_object());
        return;
    }

    s1 = isSuccess();
    s2 = isSuccess2();      // 助燃器
    if( s1 || s2 ) {
        if( s1 )
        {
            msg = HIC"\n\t只見"+me->name()+HIC"的 " + name() +HIC" 帶著許\下的願望，升到很高很高的天際。\n"NOR;
        } else  {
            msg = HIC"\n\t只見"+me->name()+HIC"的 " + name() +HIC" 帶著許\下的願望，宛如"HIR"著火"HIC"一樣，在天空中化為一顆"HIR"火球"HIC"！！\n"NOR;
        }

        oils = getSize("_LAMP_OIL_TOOL_");
        rs  = 0;
        if( oils >= 10 ) {
            rs = getSize("_OIL_CATALYST_"); // 觸媒
            if(rs>30) rs = 30;
            if( rs > 0 ) {  // 有觸媒
                msg += sprintf(
                           HIY "\n\t無數燦爛絢麗的"HIM"煙火"HIY"從%s"HIY"中綻發出來，在天空幻化成朵朵的蝴蝶！！\n"NOR, query("name") );

                add("wish_amount", query("wish_amount")*rs/100);
            }
        }

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

        // 特別獎：doll
        if( getSize("_LAMP_OIL_") > random(10000) ) {
            new("/open/world1/tmr/game/2007_light/wish_lamp_doll.c")->move(me);
            msg += HIG"\n\t\t只見一個小巧可愛的天燈娃娃從天際緩緩落到 "+me->name()+HIG"的手中。\n"NOR;
        }
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
    if(me->is_busy() || me->is_fighting() )
        return notify_fail("你正忙著，沒有空點天燃。\n");
    if( query("ignite") )
        return notify_fail("這天燈已經點燃，正在升空中。\n");
    if( !query("wish_type") )
        return notify_fail("你這天燈還沒有許\過願。\n");
    if( getOil() < 1 )
        return notify_fail("這天燈中沒有燈油，無法點燃。\n");

    message_vision(HIC"$N點燃$n"HIC"中的燈油，只見$n"HIC"緩緩的升上天去...\n"NOR, me, this_object() );
    me->start_busy(2);
    set("ignite",1);
    call_out("light2", 2 + random(8), me );
    return 1;
}


