#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name(HIM"六芒星"HIC"護膝"NOR ,({ "six-star leggings","leggings" }) );
      set("long", @LONG
在七夕的時候，織女在一次的郊遊中，看到一位老婆婆跪坐在地上好像
很痛苦的樣子，織女就順手拉他了一把，便送她回到了她的住處，突然
間老婆婆遙身大變成王母娘娘，然後看到織女的真誠心，便送此防具，
之此謝禮。

LONG
);
           set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "雙" );
                set("value",1);
                set("valme",1);
               set("no_sac",1);
                              
                set("no_auc",1); 
                set("no_sell",1);                
                set("armor_prop/armor", 14);
                set("armor_prop/dex",1);
                set("armor_prop/str",1);    
    }

        setup();
}

int query_autoload() { return 1; }

