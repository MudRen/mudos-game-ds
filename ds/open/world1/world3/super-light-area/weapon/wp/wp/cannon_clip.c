inherit ITEM;
inherit F_BULLET;
void create()
{

set_name("等離子彈夾",({"firestrom clip","clip"}));
        if( clonep() )
           set_default_object(__FILE__);
        else {
        set("unit", "塊");
        set("long","一塊金屬製的晶片, 每一塊晶片都含有有5發能源。\n");
        }
        set("value", 1000);
        set_weight(1500);
        set("amount",5);
        set("bullet/damage",60);
        set("bullet/unit","束");
        set("bullet/name","等離子光束");   
        set("type","firestorm"); 
        setup();
         }

