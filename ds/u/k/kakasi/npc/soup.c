inherit ITEM;
inherit F_WATER;

void create()
{
        set_name("����", ({ "chicken soup","soup" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","�@�J���j���p������, �n���� ~~~~ \n");
                set("unit","�J");
        }
        set("value",40);
        set("heal_ap",1000); 
        set("heal_hp",1000);       
        set("water_remaining",999999999);
        setup();
}
int query_autoload() { return 1; }

