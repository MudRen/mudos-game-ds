inherit ITEM;
void create() 
{
          set_name("���P",({"gold plate","plate"}) );
           set("long","�@�����q�l�޽u�����P�A�ݨӻ������Ӥ��K�y�I\n");
               set("value",2000);
          set_weight(2000);
          if(clonep() ) 
            set_default_object(__FILE__);
           else {
          set("unit","��");
}
setup();
}
