#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIM"���ֺN�m��"NOR,({"bliss ticket","ticket"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("long",
               HIW"�N�m���A�i�V"HIM"´�k�f�f"HIY"��§���C\n"NOR);
             }
        set_weight(100);     
        //set("no_drop",1);
        set("no_auc",1);
        set("no_sell",1);
        
        setup();
} 

