inherit ITEM;

void create()
{
    set_name("黃牙石", ({"golden tooth", "tooth"}));
    if( !clonep() ) {
        set("long", "黃牙石也就是俗稱的金牙，聽說精魅之物才會長出黃牙石。");
        set("value", 10);
        set("unit", "粒");
        set("weight", 10);
        set("value",10);
        } else
		   set_default_object(__FILE__);
    setup();
}
