#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create() {
        set_name(CYN"�R�H"NOR,({"ghost blade","blade"}));
        set("long",@LONG
�H�R�����H���@�����j�M.
LONG
);
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_str",25);
        set("unit", "��");        
        set("value",800);
        set("volume",2);        
        set("material","blacksteel");       
              }        
        init_blade(36);
        setup();
}    

