inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name( "生牛皮" , ({ "cow skin","skin" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("value", 120);
                set("long", "這是一張剛取下來的生牛皮。\n");
                set("unit", "張");
        }
        setup();
}

