inherit ITEM;
inherit F_WATER;
void create()
{
        set_name("油膩膩的肉羹湯", ({ "greasy meat soup" , "soup" }) );
        set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一碗油膩到了極點的肉羹湯，不知放了
多久的肉羹之間滿是油漬。\n");
                set("drink_msg","$N捏著鼻子，努力的灌下這碗油膩到了極點的肉羹。\n");
                set("eff_msg","
一股噁心的感覺從胃裡衝了上來，你努力的壓抑這
種感覺，在一段時間的努力後，雖然體力恢復了點
，說不定等等的腹瀉會讓你陷入更悲慘的處境。\n");
                set("unit","碗");
                    set("value",300);
           set("heal_hp",5);
                set("water_remaining",2);
        }
     setup();
}

