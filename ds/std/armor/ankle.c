// ankle.c
// 足踝部位 Tmr 2006/10/21
#include <armor.h>
inherit EQUIP;
void setup()
{
        int g,total;
        ::setup();
        if( clonep(this_object()) ) return;
        set("armor_type", TYPE_ANKLE);
        if(query("auto_set")==2) //現代標準
        {
                g=weight();
                if(g>42000) total=((g-42000)/2300)+40;
                else if(g>25000) total=((g-25000)/1700)+30;
                else if(g>13000) total=((g-13000)/1200)+20;
                else if(g>5000) total=((g-5000)/800)+10;
                else total=g/500;
                set("armor_prop/armor",total);
                set("value",weight()*3/8);
                if(!query("limit_con")) set("limit_con",weight()/1200);
                if(!query("armor_apply/dodge") && weight() > 6000 )
                set("armor_prop/dodge", - weight() / 4500 );
                return;
        }
        if( !query("armor_apply/dodge")
        &&      weight() > 3000 )
                set("armor_prop/dodge", - weight() / 1500 );
        if(!query("limit_con")) set("limit_con",weight()/700);
        if(!query("armor_prop/armor")) set("armor_prop/armor",weight()/500);
}

int is_armor(){ return 1; }

