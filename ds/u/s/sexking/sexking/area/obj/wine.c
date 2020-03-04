inherit ITEM;
inherit F_WATER;
void create()
{
        function f;
        set_name("櫻花酒", ({ "in hua wine","wine" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
一瓶用櫻花浸泡，十分烈的久，很少有人喝了不醉的。
LONG);
                set("unit", "瓶");
        }
        set("value", 160);    
        set("heal_mp",30);
        set("heal_ap",30);
        set("water_remaining", 1);
        setup();
        f = (: call_other, __FILE__, "do_drunk" :);
        set("water/function",f);
        }
int do_drunk()
{
        this_player()->apply_condition("drunk", this_player()->query_condition("drunk")+10);
        return 1;
}

