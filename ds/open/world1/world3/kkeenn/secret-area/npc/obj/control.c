inherit ITEM;

void create()
{
        set_name("�ͤƱ��",({"robot control","control"}) );
        set("long","�@���M������ͤƤH�Ϊ������C\n");
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

