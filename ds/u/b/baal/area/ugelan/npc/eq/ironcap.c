#include <ansi.h>
#include <armor.h>
inherit HEAD;

void create()
{
        set_name("鐵盔",({"iron cap","cap"}) );
        set("long",@LONG
由矮人國度運來的上好鐵礦經由巧手鐵匠鍛造而成的鐵
盔，護耳以雄鷹展翅的雙翼做為裝飾，看來神氣無比。
LONG
);
        set_weight(2000); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "頂");       
                set("value",1500);          
                set("volume", 3);                       
                set("material", "iron");   
        }
        set("armor_prop/armor", 20);
        set("armor_prop/dex",-2);
        setup();
}

