#include <ansi.h>
inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("陶製水缸", ({ "pot" }) );
        set_weight(9900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("no_sac",1);
                set("long", "一個大水缸, 裡面裝的是山泉水喔....@_@, 不過怎麼缸裡閃閃發亮..? 也許\你應該搜索(search)一下。\n");
                set("unit", "缸");
                set("value", 20);
                set("heal_ap",10);
                set("heal_mp",10);
                set("heal_hp",10);
                set("water_remaining",50);
                set("drink_msg","$N彎下腰喝了幾口$n裡的山泉水。\n");

        }
        
        setup();
}

void init()
{
        add_action("do_drink", "drink");
      add_action("do_search", "search");
      add_action("do_take", "take");
}

int do_drink(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        me=this_player();
    if(me->query("level")>5)
        {
return notify_fail("你注意到水缸上貼了張佈告: 本用水只提供等級五級以下的玩家
飲用。\n");
        }
        else 
        {
                set("heal_ap",40+random(10));
                set("heal_mp",40+random(10));
                set("heal_hp",40+random(10));
                return ::do_drink(arg);
        }
}

int do_search(string arg)
{
        object me,where1;
        string a;
        me = this_player();
        where1 = load_object(__DIR__"ten41");
        if( me->is_busy() )
                return notify_fail("你還在忙！\n");
        if( me->is_fighting() )
                return notify_fail("你還在戰鬥中，沒有空去做這種事！\n");
        if( !arg || sscanf(arg, "%s", a )!=1 )
                return notify_fail("你要搜索什麼?\n");
        if( a!="pot" && a!="陶製水缸" )
                return notify_fail("你眼睛瞎了嗎? 這裡沒有這種東西!\n");
      tell_object(me, HIY"你發現缸底似乎有一株金色植物，你可以把它撿(take)出來!\n"NOR);
          me->move(where1);
        return 1;
}


void clear() {
        set("long", "一個大水缸, 裡面裝的是山泉水喔....@_@, 不過怎麼缸裡閃閃發亮..? 也許\你應該搜索(search)一下。\n");
        delete_temp("get_plant");
}

int do_take(string arg)
{
        object me,golden;
        me = this_player();
        golden = new(__DIR__"gold_plant.c");
        if( random(70) > 55 && !query_temp("get_plant") )
        {
                message_vision("$N用一雙大手在水缸裡亂掏，抓出了一株金色的植物！\n",me);
                golden->move(me);
                set_temp("get_plant",1);
                set("long",@LONG
一個大水缸, 裡面裝的是山泉水喔....@_@
LONG
                );
                call_out("clear",600+random(300) );
        } else {
                message_vision("$N用一雙大手在水缸裡亂掏，但是除了被村漢罵到臭頭以外，沒有別的收穫！\n",me);
        }
        return 1;
}


