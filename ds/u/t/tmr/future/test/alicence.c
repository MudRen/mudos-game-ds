inherit ITEM;

void create()
{
        set_name("公民證照",({ "citizen licence","licence"}) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","這是一張A 級公民證照，看來並沒殊異之處。\n");
                set("value",1);
                set("no_sell",1);
                set("no_sac",1);
                set("card_level",1); //證照等級 A
        }
        setup();
}

int query_autoload() { return 1; }

