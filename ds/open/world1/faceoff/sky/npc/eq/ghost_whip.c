#include <ansi.h>
#include <weapon.h>
inherit WHIP;

void create() {
        set_name(CYN"�R��"NOR, ({ "ghost bone", "bone" }) ) ;
        set ("long", @LONG
�o�O�@�����R������թһs�����n�@.
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
        set("material","blacksteel");       
              }        
        init_whip(36);
        setup();

}

