inherit ITEM;

void create()
{
        set_name("紅鐵礦",({ "red iron mineral","mineral" }) );
        set("long",@long
一小塊剛挖出來的紅鐵礦，還參雜著其他無用的礦物，看來未經提鍊，
也是沒什麼用處。
long
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","堆");
                set("value",100);
        }
        setup();
}

