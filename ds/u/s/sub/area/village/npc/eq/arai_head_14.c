#include <armor.h>
inherit HEAD;

void create()
{
        set_name("Arai安全帽",({"arai helmet","helmet"}) );
        set("long",@LONG
這是一頂日本進口的Arai RR3安全帽，上面有藍色條紋的彩繪，還有
為數不少的通氣孔，讓使用者不會感到任何的不適。
LONG);
        set_weight(3520);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material","plastic");
                set("unit", "頂");
                set("limit_level",30);
        }
        set("armor_prop/armor",14);
        setup();
        set("value",25000);
        set("volume", 4);
}
int query_autoload() { return 1; }
