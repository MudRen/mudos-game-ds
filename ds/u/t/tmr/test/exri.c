inherit ITEM;
void create()
{
        set_name("牙膏的屍體", ({ "exri corpse", "corpse" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@long
這是一具牙膏(exri)的腐屍，你可以清楚發現到屍體的下身有明顯被
亂刀剁爛的情形，而屍體的胸口寫著：「我解脫了」四個大字，你瞧著礙眼
，把屍體翻轉過來，竟然背心寫著：「我翻身了」四個大字....
long
);
                set("unit", "具");
        }
        set("value",100);
        setup();
}

