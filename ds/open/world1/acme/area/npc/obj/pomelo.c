inherit ITEM;
void create()
{
       set_name("�c�l", ({ "pomelo" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@�����G�A�~�h�]�ۤ@�h�p�p���G�֡A�A���U(denude)���C\n");
                set("unit", "��");
                set("value",400);
        }
     setup();
}
void init()
{ 
         add_action("do_denude","denude");
}
int do_denude(string arg)
{
          object me,furit,peel,obj;
          me=this_player();
          obj=this_object();
          if(arg != "pomelo") return notify_fail("�A�n�餰��H\n");
          else {
            message_vision("$N�ϫl����۬c�l�֡C\n",me);
            furit=new(__DIR__"furit");
            peel=new(__DIR__"peel");
furit->move(me);
peel->move(me);
            destruct(obj);
            return 1;
          }
}
