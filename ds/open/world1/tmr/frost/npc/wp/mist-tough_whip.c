#include <weapon.h>
inherit WHIP;

void create()
{
        set_name("霄遨韌鞭" , ({ "mist tough whip","whip" }) );
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "條");
                set("long",@long
這是一條倚霄峰上才有的特製韌鞭，此鞭長有十數丈，粗若長棍，殺傷
力煞是驚人，但是要揮舞這麼長的鞭子，倒也不是容易的事。
long
);
                set("material", "silver");
                set("value",4000);
        }
        set("weapon_prop/dex",2);
        set("limit_dex",20);
        init_whip(40);
        setup();
}


