inherit ITEM;
inherit F_WATER;
void create()
{
        function f;
        set_name("���s", ({ "in hua wine","wine" }) );
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
�@�~�������w�A�Q���P���[�A�ܤ֦��H�ܤF���K���C
LONG);
                set("unit", "�~");
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

