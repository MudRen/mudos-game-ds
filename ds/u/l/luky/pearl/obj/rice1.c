inherit COMBINED_ITEM;

void create()
{
set_name("����",({"rices"}));
set_weight(170);
set("value",80);
if( clonep() )
 set_default_object(__FILE__);
else {
set("long","�o���λD�_�Ӧn����....���H�a���{�l�n�j��\n");
set("amount",1);
}
set_amount(1);
set("unit","��");
}

void init()
{
 add_action("eat_rice","eat");
}

int eat_rice(string arg)
{
 int num;
 object ob;
 if(!this_player()) return 0;
 if(!arg) return 0;
 if(arg!="rices") return 0;
 ob=present(arg,this_player());
 if(!ob) return notify_fail("�A�Q�n�Y�����\n");
 else if(ob==this_object())
 {
  num=ob->query_amount();
  if(this_player()->query("max_ap")==this_player()->query("ap"))
  {
   write("�A����O�Q���n\n"); 
   return 1;
  }
  if(this_player()->query("ap")+80 > this_player()->query("max_ap"))
  {
   this_player()->set("ap",this_player()->query("max_ap"));
   write("�A����O������t�F\n");
   num--;
   if(num==0) destruct(ob);
   else ob->set_amount(num);
   return 1;
  }
  
  this_player()->add("ap",80);
  write("�A�@�f�f���Z�۶���,��...�u�O�n�Y..�n�Q�A�Y�@��\n");
  num--;
  if(num>0)
  { 
   set_weight(this_object()->query_weight()-170);
//me->set_encumbrance(me->query_encumbrance()-1000);
   set_amount(num);
  } else destruct(this_object());
  return 1;
 }
}

