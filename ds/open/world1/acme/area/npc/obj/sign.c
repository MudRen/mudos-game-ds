inherit ITEM;
void create()
{
        set_name("殘破的告示牌", ({ "sign" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long",
                        "一個用木板製成的告示牌，不知放在這有多久了，歷經風吹雨打，已顯得\n"
                      
                        "殘破不堪。上面還依稀能看到一些字：「鬼....林，生..勿近，如遇鬼怪\n"
                         
                        "....神，當即..跪九..，..保..命，切....記！！」\n");
         set("no_get",1);
        set("no_sac",1);
        }
     setup();
}
