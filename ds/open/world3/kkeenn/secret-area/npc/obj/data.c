inherit ITEM;

void create()
{
        set_name("��ƺ�",({"data"}) );
        set("long","�@���M���O���ͤƤH��ƪ������C\n");
     set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else {
          set("no_sell",1);
          set("limit_str",5);
          set("unit","��");       
        }
        setup();
}

