#include <ansi.h>
inherit ITEM;

void create()
{
    set_name( HIG "烤箱" NOR, ({ "mooncake toaster","toaster" }) );
    set_weight(600);

        set("long",@LONG
這是一個用來做蛋黃酥的烤箱，你需要取得做蛋黃酥的三種必要材料：起酥皮、
棗泥、及鹹黃蛋，以一定的比例放進烤箱內烘烤，就能有機會做出香甜好吃的蛋
黃酥。這個烤箱中有一塊魔法鐵板，你可以在上面刻畫(carve)一些字樣，這些字
樣將會印在蛋黃酥上，擁有神奇的魔力。
                        
        1. carve exp 
        2. carve pop  
        3. carve art 
        4. carve money

        特別獎：每一個烤箱都有 (鹹蛋黃個數)/4000 的機率獲得一個蛋黃酥娃娃。

當你放好蛋黃酥的材料之後，只要啟動(switchon)烤箱，耐心等侯烘烤的結果。
你可以使用「inspect」指令來檢視烤箱中已經放了多少材料。
LONG
);
    set_max_capacity(2000);
    set_max_encumbrance(2000);      // 假設一張紙只有一克
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "個");
        set("value", 99);
    }
    setup();
}

void init()
{
    add_action("do_wish","carve");
    add_action("do_light","switchon");
    add_action("do_oil","inspect");
}

int moon_yolk = 0;      // 鹹蛋黃
int moon_crust = 0;     // 起酥皮
int moon_puree = 0;     // 棗泥

void countWeight() {
        int i;
        object* inv;
        
        moon_yolk = 0;
        moon_crust = 0;
        moon_puree = 0;
        
    inv = all_inventory(this_object());
    if( !sizeof(inv) )
        return;

    for(i=0; i<sizeof(inv); i++)
    {
        if( inv[i]->id("_MOON_YOLK_") )
                moon_yolk += inv[i]->query("time");
        else if( inv[i]->id("_MOON_CRUST_") )
                moon_crust += inv[i]->query("time");
        else if( inv[i]->id("_MOON_PUREE_") )
                moon_puree += inv[i]->query("time");
    }   
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
        countWeight();
    return notify_fail( sprintf("目前烤箱中有%3d個共%4d克的起酥皮、%3d團共%4d公克的棗泥、%3d顆共%4d公克的鹹蛋黃。\n",
                                getSize("_MOON_CRUST_"), moon_crust,
                                getSize("_MOON_PUREE_"), moon_puree,
                                getSize("_MOON_YOLK_"), moon_yolk
                               ));
}

int do_wish(string arg)
{
    object me;
    string wish;
    me = this_player();
    if(!arg )
        return notify_fail("你想要刻畫什麼字樣？\n");
    if( query("wish_type") )
        return notify_fail("你這烤箱已經刻畫過字樣了。\n");

    switch(arg) {
    case "exp":
        wish = "經驗值";
        break;
    case "pop":
        wish = "聲望";
        break;
    case "art":
        wish = "戰鬥藝術";
        break;
    case "money":
        wish = "財富";
        break;
    default:
        return notify_fail("你無法刻畫這種字樣。");
    }
    message_vision( CYN"$N細心在烤箱上刻畫「" + wish + "」的字樣。\n" NOR,me);
    set("name", HIG "烤箱 [" + wish + "]" NOR);
    set("wish",wish);
    set("wish_type", arg);
    //set("wish_amount",amount);
    return 1;
}

int isSuccess() {
         return random(100) != 90;
}

int isBurst() {
        // 棗泥是蛋黃的3倍、皮要是蛋黃的2倍
        return moon_puree < moon_yolk 
                        || moon_crust < moon_yolk
                        ;
                //      || random(100) < 10;    // 隨機爆炸
}

// 由系統來計算數量
int getAmount() {
        int am, ct, ee;
        int yolk = moon_yolk * 100 ;

        // 用起酥皮與棗泥的比例，來計算戰藝最小值
    ct = getSize("_MOON_CRUST_");
    ee = getSize("_MOON_PUREE_");
    
    switch(query("wish_type") ) {
        case "money":   // 最容易成功
                am = yolk/13;
                break;
    case "exp":
                am = yolk/123;  
                break;
    case "pop":
                am = yolk/541;
                break;
    case "art":
                am = yolk/765;
                break;
    }
    
    if( ct > 360)
                am = am/3 + random(am*4);
    else if( ct > 180)
                am = am/4 + random(am*3);
    else if( ct > 90)
                am = am/5 + random(am*2);
    else if( ct > 30)
                am = am/6 + random(am);
    else
                am = 1 + random(am);
    if( am < 1) am = 1;
        return am;
}

void light2(object me) {
    string msg;
    string str;
    object cake;
    // 爆炸的可能性
    if( isBurst() ) {
        msg = sprintf(
                  HIM "\n\n\t只見火苗快速竄起，%s啟動的"HIM"%s"HIM"轉瞬間就變成"HIR"大火球"HIM"，發生強烈的爆炸！！！\n\n"NOR, me->query("name"), query("name") );
        message("system",  msg, users() );
        destruct(this_object());
        return;
    }

    if( isSuccess() ) {
        cake = new("/open/world1/tmr/game/2007_moon/mooncake.c");
        cake->set("wish_type", query("wish_type") );
        cake->set("wish_amount", getAmount() );
        str =  cake->query("wish_amount") + " " + query("wish");
        cake->set("name", HIY"" + me->query("name") + "的蛋黃酥" + HIM " [" + str + "]" NOR);
        cake->move(me);

        msg = HIC"\n\t"+me->name()+HIC"的" + name() +HIC"傳出陣陣香味，香甜好吃的" + cake->name() + HIC"出爐了！！\n"NOR;
        
        // 特別獎：doll
        if( getSize("_MOON_YOLK_") > random(4000) ) {
            new("/open/world1/tmr/game/2007_moon/moon_doll.c")->move(me);
            msg += HIG"\n\t\t一個小巧可愛的蛋黃酥娃娃，從烤箱中蹦了出來到 "+me->name()+HIG"的手中。\n"NOR;
        }
        
        message("system",  msg, users() );
    } else {
        message_vision(HIM "可惜$n"HIM"火力失當，裡頭的材料半生不熟，混成一團爛泥了。\n"NOR, me, this_object() );
    }
    
    destruct( this_object() );
}

int do_light(string arg)
{
    object me;
    me = this_player();
    if( !arg || arg != "toaster" )
        return notify_fail("你想要啟動什麼？\n");
    if(me->is_busy() || me->is_fighting() )
        return notify_fail("你正忙著。。\n");
    if( query("ignite") )
        return notify_fail("這烤箱已經啟動了。\n");
    if( !query("wish_type") )
        return notify_fail("這烤箱還沒有刻畫字樣。\n");
    
    countWeight();
    if( moon_yolk < 1 )
        return notify_fail("烤箱中沒有足夠的材料，無法啟動。\n");

    message_vision(HIC"$N啟動$n"HIC"的開關，只見$n"HIC"慢慢加熱起來...\n"NOR, me, this_object() );
    me->start_busy(2);
    set("ignite",1);
    call_out("light2", 2 + random(8), me );
    return 1;
}


