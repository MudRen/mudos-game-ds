inherit ITEM;
void create()
{
        set_name("�ƦZ���Y�`",({"queen ant's head","queen","ant's","head"}) );
        set("long",@LONG
�@���ƦZ���Y�`�C
LONG);
        set_weight(1000);
        if(clonep() )
                set_default_object(__FILE__);
  else
   {
          set("value",1);
          set("unit","��");
        }
        setup();
}
