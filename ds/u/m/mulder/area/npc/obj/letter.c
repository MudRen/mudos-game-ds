inherit ITEM;
void create()
{
        set_name("血信", ({ "letter" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一封染滿鮮血的信。\n");
                set("unit", "封");
                set("value",100);
}
        
              setup();
}

