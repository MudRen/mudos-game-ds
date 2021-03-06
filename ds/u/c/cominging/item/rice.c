// 可以吃的飯 rice.c
// Wed Nov 27 10:23:41 CST 1996 by Lsr@FSS

#include <ansi.h>

inherit ITEM;

string *RICE_MSG = ({
                CYN"$N"CYN"拿起小湯匙，眼睛叮著炒飯。\n\n"NOR,
                CYN"炒飯的香味使得$N的胃開始急速分泌胃液。\n\n"NOR,
                CYN"$N用舀了一匙快速放入口中，露出飢餓的眼神 @_@ \n\n"NOR,
                CYN"$N突然用極快的速度把盤子高高地端起來。\n\n"NOR,
                CYN"$N張開史萊姆般的大嘴巴，一口把炒飯吞進去 ..:D\n\n"NOR,
                CYN"$N把盤子從嘴裡拉出來，露出滿意的眼神  :D~~~\n\n"NOR,
                });

void rice_msg(object me,int x);

void create()
{
        set_name(HIW"炒飯"NOR, ({ "rice" }) );
        set("long",@LONG
紙盤子上裝著香香的蛋炒飯，旁邊擺著一支小湯匙。
LONG
        );
        set("unit", "盤");
        set("base_weight", 200);
        set("value", 300);
}

void init()
{
        if( this_player()==environment() )
        add_action("xdo_eat","eat");
}

int xdo_eat(string arg)
{
        object me;
        me = this_player();
        if( !arg ) return notify_fail("你想吃什麼呢? \n");
        if( arg == "rice" )
        rice_msg(me,0);
        return 1;
}

void rice_msg(object me,int x)
{
        message_vision(RICE_MSG[x],me);
        if( ++x < sizeof(RICE_MSG) ) {
                call_out("rice_msg", 1, me, x);
        }
        else destruct(this_object());
        return;
}

