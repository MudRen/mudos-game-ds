#include <weapon.h> 
#include <ansi.h>
inherit SWORD; 
void create()
{
        set_name("騎士十字劍", ({ "huge cross sword","sword" }) );
        set_weight(3200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "把"); 
                set("limit_str",50);
                set("long", "
一柄大得誇張的騎士劍，整個劍身比一個人還高，不用說有多重
  了，若是揮動起來想必可以連人帶馬一起斬成兩半。\n");
                set("value", 3500);
        }
        init_sword(55);
        setup();
}

