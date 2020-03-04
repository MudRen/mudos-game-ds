#include <ansi.h>
inherit F_AUTOLOAD;
inherit ITEM;

void create()
{
        set_name(HIY"搖錢扇"NOR, ({"money fan","fan","money"}));
        set("long",
                "用法: wave <數量> <貨幣種類>\n");
        set("unit", "把");
        set("weight", 100);
        setup();
}

void init()
{
        if( this_player()==environment() ) 
        add_action("do_wave","wave");
}
int do_wave(string arg)
{
        string from;
        float amount;
        object from_ob, me, ob;

        me = this_player();
        ob = this_object();
        if( !arg || sscanf(arg, "%d %s", amount, from)!=2 )
                return notify_fail("指令格式﹕wave <數量> <貨幣種類>\n");
        if( file_size("/obj/money/" + from + ".c") < 0)
             return notify_fail("你想變出那種錢? \n");
        if( amount < 1 ) amount = 1;
        from_ob = new("obj/money/"+from);
        from_ob->set_amount(amount);
        from_ob->move(me);
        tell_room(environment(me),me->query("name")+"用力的搖著"+ob->query("name")+"結果從"+ob->query("name")+"掉出了"+chinese_number(amount)+from_ob->query("base_unit")+from_ob->query("name")+"\n",me);
        tell_object(me,"你用力的搖著"+ob->query("name")+"結果從"+ob->query("name")+"掉出了"+chinese_number(amount)+from_ob->query("base_unit")+from_ob->query("name")+"\n");
        return 1;
}


