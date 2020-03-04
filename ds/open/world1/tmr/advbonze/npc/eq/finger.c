#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
        set_name(HIW "如來佛指舍利" NOR ,({ "rulaifo finger","finger" }) );
        set("long",@LONG
這是一對「如來佛祖」遺留在人間的一對佛指舍利，當你手中捧著這
對舍利時，你的心中彷彿已經遠離塵世間的喧囂，對於人生似乎有更深一
層的認知。
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "對");
                set("value",4000);
        }
        set("wear_msg",HIY"$N把佛指舍利穿戴在雙手上，登時全身發出一陣慈祥的佛光。"NOR);

        switch(random(3))
        {
        case 0:        
                set("armor_prop/int",1);
                set("armor_prop/str",1);
                set("armor_prop/hit",20);
        break;
        case 1:
                set("armor_prop/dex",1);
                set("armor_prop/con",1);
                set("armor_prop/hit",20);
        break;
        case 2:
                set("armor_prop/int",1);
                set("armor_prop/str",1);
                set("armor_prop/dex",1);
                set("armor_prop/con",1);
        break;
        }
          set("armor_prop/armor",10);

        setup();
}
