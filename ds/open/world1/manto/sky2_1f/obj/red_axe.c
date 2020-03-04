
#include <ansi.h>

inherit ITEM;
void create()
{
    set_name(HIR"血紅鐵斧"NOR,({"red axe","axe"}));
        set("unit", "把");
        set("long",@LONG
這是一把沾滿著天地各堂主及護法們鮮血的鐵斧，它象徵著各堂主及護法們
以鮮血悍衛天地會的忠心不二，更代表著他們為天地所付出的辛勞及努力。
你默然地注視著，不由自主地深感到由斧中傳來那莊嚴豪邁的氣勢，且也替
為了天地打拚而努力下了一計強心計。

LONG
);
        set_weight(999999);
        set("material","steel");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set("no_clean_up",1);
        setup();
}

void init()
{
        add_action("do_blood","blood");
}

int do_blood(string arg)
{
        object me;
        me=this_player();
        
        if(arg!="red axe" && arg!="axe" )
        {
                notify_fail("你要對什麼滴血?\n");
                return 0;
        }

        message_vision(HIW"$N滴下一滴鮮血在$n上面。\n"NOR,me, this_object());

        write(this_object()->name()+""HIC"似乎閃動了一下，隨即又回復了原狀。\n"NOR);
        return 1;
}
