#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create() {
        set_name(HIY"狂音鞭"NOR, ({ "crazy voice whip", "whip" }) ) ;
        set ("long", @LONG
一揮動就會產生強大破空聲的鞭子，故名「狂音」。
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_dex",25);
        set("unit", "條");        
        set("value",800);
        set("volume",3);        
        set("material","gold silk");       
              }        
        init_whip(47);
        setup();

}
