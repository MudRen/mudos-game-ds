#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create() {
        set_name(HIY"�g���@"NOR, ({ "crazy voice whip", "whip" }) ) ;
        set ("long", @LONG
�@���ʴN�|���ͱj�j�}���n���@�l�A�G�W�u�g���v�C
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_dex",25);
        set("unit", "��");        
        set("value",800);
        set("volume",3);        
        set("material","gold silk");       
              }        
        init_whip(47);
        setup();

}
