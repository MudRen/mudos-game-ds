inherit ITEM;

void create()
{
        set_name("鐵鏟",({"iron shovel","shovel"}) );
        set("long",@long
這是一把用鐵打造而成的鏟子，專門用來翻挖泥土。
long
);
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",100);
                set("material","iron");
                set("volume",1);
                set("unit","把");
        }
        setup();
}
