#include <ansi.h>
#include <armor.h>
inherit LEGGING;

void create()
{
        set_name("魔鳥翼",({"magic bird wing","leggings","wing"}) );
        set("long",@LONG
石魔鳥的翅膀，傳說將之綁在腳上能日行千里。
LONG
);
        set_weight(0); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("limit_dex",15);
                set("unit", "對");       
                set("value",1100);          
                set("volume", 3);                       
                set("material", "meat");   
        }
        set("armor_prop/armor",3);       
        set("armor_prop/dex",2);
        setup();
}

