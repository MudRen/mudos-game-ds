#include <armor.h>
#include <ansi.h>

inherit F_UNIQUE; //only one
inherit HANDS;

void create()
{
        set_name(HIY"日月"HIC"護星手" NOR ,({ "sun-moon gloves","gloves" }) );
        set("long",@LONG
這是一雙造型非常富有巧思的護手，這雙護手上繡有一幅「日月拱星」
的巧工圖，繡工之精，直把這幅難以繪製的圖發揮到盡善盡美、讚為觀止
的境界，真可謂是巧奪天工也不為過。
在你細細的賞玩之際，忽然發現繡圖上有一小串字：
        「天陰地陽，日正月反，浩然正氣，常居其中」
似乎在指示你可以以陰陽之氣，換取浩然正氣？(powerin)(regenerate)
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "雙");
                set("value",2500);
                                set("replica_ob",__DIR__"wu_gloves2");
        }
                set("power",0);
        set("armor_prop/armor",8);
        set("armor_prop/dex",1);
        set("armor_prop/con",1);
        setup();
}

/* 補AP 特殊功能 */
void init()
{
        add_action("do_powerin","powerin");
        add_action("do_regenerate","regenerate");
}

int do_powerin(string arg)
{
        object me=this_player();
        if(me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙著，沒有空做這動作。\n");
        if(me->query("hp")<query("max_hp")/2)
                return notify_fail("你目前的身體狀態並不好。\n");
        if(me->query("level")<20)
                return notify_fail("你角色的等級，無法做此動作。\n");
        if( me->query_temp("armor/hands")!=this_object() )
                return notify_fail("你必須要穿載起來，才有用處。\n");
        if(query("power")>=100)
                return notify_fail("你感覺到護手的能量十分充足。\n");
        if(me->query("gender")=="男性")
                message_vision(HIY "$N對著日月護星手細細地吐出一口陽氣，陽氣一陣纏繞之後，被護手吸了進去。\n" NOR,me);
        else
                message_vision(HIB "$N對著日月護星手細細地吐出一口陰氣，陰氣一陣纏繞之後，被護手吸了進去。\n" NOR,me);
        me->start_busy(3);
        me->receive_damage("hp",(1+random(4))*10);
        add("power",me->query("level"));
        return 1;
}

int do_regenerate(string arg)
{
        object me=this_player();
        if(me->is_busy() )
                return notify_fail("你正忙著，沒有空做這動作。\n");
        if(me->query("level")<20)
                return notify_fail("你角色的等級，無法做此動作。\n");
        if( me->query_temp("armor/hands")!=this_object() )
                return notify_fail("你必須要穿載起來，才有用處。\n");
        if(!query("power"))
                return notify_fail("護手上的能量已經消失了，你無法再使用此功\能了。\n");
        message_vision(HIB "$N身上的護手瀰漫出一股忽冷忽熱的雲霧，緩緩地包住了$N的身體。\n" NOR,me);
        tell_object(me,CYN "(你體內的內勁恢復不少了。)\n" NOR);
        me->receive_heal("ap",query("power")*3);
        set("power",0);
        me->start_busy(3);
        return 1;
}


