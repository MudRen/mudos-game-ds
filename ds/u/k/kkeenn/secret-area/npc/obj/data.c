inherit ITEM;

void create()
{
        set_name("資料碟",({"data"}) );
        set("long","一塊專門記載生化人資料的晶片。\n");
     set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else {
          set("no_sell",1);
          set("limit_str",5);
          set("unit","塊");       
        }
        setup();
}

