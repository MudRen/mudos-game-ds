#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIG"西瓜刀"NOR,({ "watermelon blade","blade" }));
        set_weight(1000);
        if( clonep() )
        set_default_object(__FILE__);
        else
        {
        set("long",HIY"一把幫派械鬥時專用的西瓜刀"HIC"\n砍或續砍請輸入(cut xxx)。\n");
        set("unit","把");
        set("value",100);
        }
        setup();
}
void init()
{
add_action("do_cut", "cut");
}
int do_cut(string arg)
{
        object obj,me;
        me=this_player();
        if( !arg )
        return notify_fail("你要拿刀砍誰 ﹖\n");
        if(!(obj = present(arg, environment(me)))
        || !obj->is_character() || obj->is_corpse() )
        return notify_fail("這裡並沒有這個人。\n");
        if( me->is_busy() )
        return notify_fail("你還在忙,不能砍人\n");
        if(obj==me)
        return notify_fail("你要砍自己?\n");
        if(me->query_temp("cutppl2")>100)
        return notify_fail("你以經砍到手酸了.手部一陣劇痛.。\n");
        message_vision(HIR"\n$N拿著西瓜刀瘋狂不斷的的砍向$n...\n\n"NOR,me,obj);
        call_out("cutcut",1,me,obj);
        me->start_busy(1);
        return 1;
        }
void cutcut(object me,object obj)
{   
     if(random(2))
        {
        call_out("cut1",1,me,obj);
        me->add("cutppl2",1);
        return ;
        }
        else
        {
        call_out("cut2",1,me,obj);
        me->add("cutppl2",1); //砍到手酸用
        return ;
}
}
void cut1(object me,object obj)
{
     if(random(2))
{
     message_vision(HIR"$N提起西瓜刀狠狠的砍中了$n的腰部...鮮血噴出起來。\n"NOR,me,obj);
     obj->receive_wound("body",1);
     obj->receive_damage("hp",61);
     return;
}
else
{
object bl;
if(!objectp(bl=present("watermelon blade",obj) ) )
{
        message_vision(HIC"$n一個閃身躲開了$N的這刀.。\n"NOR,me,obj);
        return;
}
else
{
message_vision(HIR"$N不但沒砍著..還被$n反砍了一刀。\n"NOR,me,obj);
me->receive_wound("head",1);
me->receive_damage("hp",72);
return;
}
}
}
void cut2(object me,object obj)
{
     if(random(2))
{
     message_vision(HIR"$N提起西瓜刀狠狠的砍中了$n的背部..留下了一條極深的刀傷。\n"NOR,me,obj);
     obj->receive_wound("body",1);
     obj->receive_damage("hp",69);
     return;
}
else
{
object bl;
if(!objectp(bl=present("watermelon blade",obj) ) )
{
        message_vision(HIC"$N的攻勢卻被$n躲了開來。\n"NOR,me,obj);
        return;
}
else
{
message_vision(HIG"$n隨機應變提起西瓜刀擋下了$N的這刀。\n"NOR,me,obj);
return;
}
}
}
