inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("���}��", ({ "hot water" , "water" }) );
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�@�M���}��...���M�A�H���|�Oԣ�H...\n");
                set("unit","�M");
                    set("value",100);
                set("water_remaining",10);
        }
     setup();
}

