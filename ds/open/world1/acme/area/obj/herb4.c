inherit ITEM;
void create()
{
    set_name("�M�H�ۺ�G", ({ "green fruit","fruit" }) );
    set_weight(10);
    if( clonep() )
       set_default_object(__FILE__);
    else {
      set("long","�o�O�@���Q����w���G��A�~���q�ۤ@�h��⪺�~�֡C\n");
       set("unit","��");
       set("value",1);
    }
     setup();
}
