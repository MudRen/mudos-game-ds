inherit ITEM;
void create()
{
        set_name("石匙",({"rock key","key"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","這是一把用石頭雕成的鑰匙，不知可以開啟什麼。\n");
                set("door","bagi_key");
                set("value", 1);
                set("no_sell",1);
                set("usage","開啟某一扇門");
        }
        setup();
}

