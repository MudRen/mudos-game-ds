inherit ITEM;

void create()
{
        set_name("生化控制器",({"robot control","control"}) );
        set("long","一片專門控制生化人用的晶片。\n");
     set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else {
          set("no_sell",1);
          set("limit_str",5);
          set("unit","片");       
        }
        setup();
}

