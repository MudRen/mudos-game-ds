inherit ITEM;
inherit F_WATER;
void create()
{
        function f;
        set_name("Fuzzy Navel", ({ "fuzzy navel","navel" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�M�ή�l�P�s�M��Ļs�������s�A�s�𭻾J�C\n");
                set("unit", "�~");
                set("value",18000);
                set("heal_ap",3000);
                set("water_remaining",1);
        }
        setup();
        f = (: call_other, __FILE__, "do_drunk" :);
        set("water/function",f);
}

int do_drunk()
{
        this_player()->apply_condition("drunk", this_player()->query_condition("drunk")+20);
        return 1;
}
