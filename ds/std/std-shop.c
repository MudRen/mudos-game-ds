// shop���herb.c
//chamber 99.1.15�ק�
#include <dbase.h>
#include <ansi.h>
object stroom;
string args;
void create(){
	seteuid(getuid());

}
void init()
{
add_action("do_sell","sell");
add_action("do_buy","buy");
add_action("do_id","id");
add_action("do_list","list");
}
int do_sell(string arg)
{
object ob,*inv,obj,me,link_ob,ob1,ob2,item;
int valu,i,can,unit,u,amount;
load_object(this_object()->query("storeroom"));
stroom=find_object(this_object()->query("storeroom"));
me=this_player();
if(!arg) return notify_fail("�A�n�椰��F��H\n");
if(sscanf(arg,"%d %s",amount,item)==2) // AMOUNT
{
 if(!ob=present(item,this_player()))
 return notify_fail("�A�S���o�˪F��.\n");
 valu=ob->query("value");
 if( ob->query("money_id") )
 return notify_fail("�o�O�u���v�M�A�S���L�ܡS\n");
 if( !valu )
 return notify_fail("�o�F�褣�ȿ�\n");
 if(ob->query("secured"))
 return notify_fail("�A����榳�аO���F��\n");
 if( ob->query("no_drop") )
 return notify_fail("�A�����o�F��\n");
 if( ob->query("no_sell"))
 return notify_fail("�A�����o�F��\n");
 if(ob->query("equipped"))
 return notify_fail("�A�����o�F��\n");
 if(ob->query_temp("has_light"))
 return notify_fail("�ڭ̤��R�U�N�������~\n");
 arg = ob->query("id");
 valu=valu/2;
 if(amount<1)
 return notify_fail("�ܤ֭n��1��\n");
 if(ob->query_amount())
 {
  ob->set("amount",ob->query_amount());
  ob->set_amount(1);
 }
 if(!ob->query("amount")) ob->set("amount",1);
 if(ob->query("amount")<amount)
 {
  if(ob->query_amount())
  {
   ob->set_amount(ob->query("amount"));
   ob->set("amount",1);
  }
  return notify_fail("�A���W���F�褣��\n");
 }
 message_vision(HIC"$N�汼"+amount+ob->query("unit")+ob->query("name")+"��o"+valu*amount+"�T�ɪO\n"NOR,this_player());
 this_player()->add("coin",valu*amount);
 link_ob=me->query_temp("link_ob");
 if(ob2=present(arg,stroom))
 {
  if(ob->query("amount")>amount)
  {
   ob2->add("amount",amount);
   ob->add("amount",-amount);
  } else
  { 
   ob2->add("amount",amount);
   destruct(ob);
  }
 } else
 {
  if(ob->query("amount")>amount){
  ob1=new(base_name(ob));
  ob1->set("amount",amount);
  ob1->move(this_object()->query("storeroom"));
  ob->add("amount",-amount);
 } else
 {
  ob1=new(base_name(ob));
  ob1->set("amount",amount);
  ob1->move(this_object()->query("storeroom"));
  destruct(ob);
 }
}
link_ob->set("last_from", query_ip_name(me));
me->save();
(int)link_ob->save();
if(ob)
if(ob->query_amount())
{
ob->set_amount(ob->query("amount"));
ob->set("amount",1);
}
return 1;
} //END of AMOUNT
if(arg=="all")
{
 inv = all_inventory(this_player());
 while( i < sizeof(inv) )
 {
  do_sell(inv[i++]->query("id")) ;
 }
 return 1;
}
if(!(ob=present(arg,this_player())) )
return notify_fail("�A�n�椰��F��H\n");
valu=ob->query("value");
if( ob->query("money_id") )
return notify_fail("�o�O�u���v�M�A�S���L�ܡS\n");
if( !valu )
return notify_fail("�o�F�褣�ȿ�\n");
if(ob->query("secured"))
return notify_fail("�A����榳�аO���F��\n");
if( ob->query("no_drop") )
return notify_fail("�A�����o�F��\n");
if( ob->query("no_sell"))
return notify_fail("�A�����o�F��\n");
if(ob->query("equipped"))
return notify_fail("�A�����o�F��\n");
if(ob->query_temp("has_light"))
return notify_fail("�ڭ̤��R�U�N�������~\n");
arg = ob->query("id");
valu=valu/2;
if(ob->query_amount())
{
ob->set("amount",ob->query_amount());
amount = ob->query_amount();
ob->set_amount(1);
} else amount =1;
message_vision(HIC"$N�汼"+amount+ob->query("unit")+ob->query("name")+"��o"+valu*amount+"�T�ɪO\n"NOR,this_player());
this_player()->add("coin",valu*amount);
link_ob=me->query_temp("link_ob");
if(ob2=present(arg,stroom))
{
if(ob->query("amount")>amount)
 {
 ob2->add("amount",amount);
 ob->add("amount",-amount);
 } else
 { 
 ob2->add("amount",amount);
 destruct(ob);
 }
} else
{
if(ob->query("amount")>amount)
{
 ob1=new(base_name(ob));
 ob1->set("amount",amount);
 ob1->move(this_object()->query("storeroom"));
 ob->add("amount",-amount);
} else
{
ob1=new(base_name(ob));
ob1->set("amount",amount);
ob1->move(this_object()->query("storeroom"));
destruct(ob);
}
}
link_ob->set("last_from", query_ip_name(me));
me->save();
(int)link_ob->save();
if(ob)
if(ob->query_amount())
{
ob->set_amount(ob->query("amount"));
ob->set("amount",1);
}
return 1;
}

int do_list()
{
object *goods,stroom;
mixed amount;
string list, *name;
int i,cost,level,maxlv;
load_object(this_object()->query("storeroom"));
if(query_temp("stop"))
return notify_fail("���Ѧ����餣�ΪA,����~�F\n");
stroom=find_object(this_object()->query("storeroom"));
goods = all_inventory(stroom);
list = "�A�i�H�ʶR�U�C�o�ǪF��:                 �ʶR�ƶq      �� �� \n";   
list += "==============================================================\n";
for(i=0; i<sizeof(goods); i++)
{ 
 list += sprintf("%-10s (%-8s) �R%20d  %13d   \n",
 goods[i]->query("name"),goods[i]->query("id"),goods[i]->query("amount"),goods[i]->query("value")
 );
}
if(i==0) return notify_fail("�ثe�ʳf��\n");
write(list);
return 1;	
}

int do_buy(string arg)
{
int amount,valus;
object *goods,ob,ob2,item;
if(!arg) return 0;
load_object(this_object()->query("storeroom"));
stroom=find_object(this_object()->query("storeroom"));
goods = all_inventory(stroom);
if(sscanf(arg,"%d %s",amount,item)==2)
{
args=arg;
if(!objectp(ob=present(item,stroom)))
return notify_fail("???????\n");
if(ob=present(item,stroom))
{
if(this_player()->query("coin")<ob->query("value")*amount)
return notify_fail("�F��....�S���ٴ��ӳo�̶R�F��\n");
if ( (ob->query_weight()*amount+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
return notify_fail("�A���O�q����,�L�k���F��\n");
ob2=new(base_name(ob));
if(amount>ob->query("amount"))
return notify_fail("�������f�S�o��h\n");
ob2->set("amount",amount);
ob->add("amount",-amount);
if(ob2->query_amount())
{
ob2->set_amount(amount);
ob2->set("amount",1);
}
ob2->move(this_player());
valus=ob->query("value")*amount;
this_player()->add("coin",-ob->query("value")*amount);
this_player()->save();
stroom->save();
message_vision("$N��F"+valus+"�ӻɪO�R�U"+amount+ob->query("unit")+ob->name()+"\n",this_player());
if(ob->query("amount")==0)
destruct(ob);
}
else 
{
 if(query("check")==0)
 {
  set("check",1);
  do_buy("1 "+args);
 } else
 {
  set("check",0);
  return notify_fail("�S�o�تF��\n");
 }
}
return 1;
}
if(ob=present(arg,stroom))
{
if ( (ob->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )   
 return notify_fail("�A���O�q����,�L�k���F��\n");
 if(this_player()->query("coin")<ob->query("value"))
return notify_fail("�F��....�S���ٴ��ӳo�̶R�F��\n");
if(query_temp("stop"))
return notify_fail("���Ѧ����餣�ΪA,����~�F\n");
valus=ob->query("value");
this_player()->add("coin",-ob->query("value"));
message_vision("$N��F"+valus+"�ӻɪO�R�U�@"+ob->query("unit")+ob->name()+"\n",this_player());
if(ob->query_amount())
{
if(ob->query("amount")>1)
{
ob2=new(base_name(ob));
ob2->move(this_player());
ob->add("amount",-1);
}else
{
ob2=new(base_name(ob));
ob2->move(this_player());
destruct(ob);
}
} else 
{
if(ob->query("amount")>1)
 {
ob2=new(base_name(ob));
ob2->delete("secured");
ob2->move(this_player());
ob->add("amount",-1);
}
else 
ob->move(this_player());
}
stroom->save();
this_player()->save();
return 1;
}
else return notify_fail("�A�Q�n�R�����??\n");
}

int do_id(string arg)
{
int amount,valu,level,sk;
string type;
object *goods,ob,ob2,item;
if(!arg) return 0;
load_object(this_object()->query("storeroom"));
stroom=find_object(this_object()->query("storeroom"));
goods = all_inventory(stroom);
if( !arg )
return notify_fail("�A�nŲ�w���򪫫~�H\n");
if(!ob=present(arg,stroom))
return notify_fail("�o�̨S���o�ت��~�C(ps:�H�����������W�r����,�`�N�j�g�C)
\n");
valu=ob->query("value")/10;
if(this_player()->query("coin")>valu)
{
message_vision("$N��F"+valu+"�ӻɪOŲ�w�F"+ob->short()+"\n",this_player());
this_player()->add("coin",-valu);
if(ob->query("usage"))
{
 tell_object(this_player(),ob->short()+"���\\��:"+ob->query("usage")+"\n");
} 
if(ob->query("limit_lv"))
{
level=ob->query("limit_lv");
tell_object(this_player(),ob->short()+"�ݭn����"+level+"�~���\n");
}
else {
if (ob->query("sword"))
{
type="sword";
sk=ob->query("sword");
}
else if(ob->query("blade"))
{
type="blade";
sk=ob->query("blade");
}
else if(ob->query("spear"))
{
type="spear";
sk=ob->query("spear");
}
else if(ob->query("staff"))
{
type="staff";
sk=ob->query("staff");
}
else if(ob->query("claw"))
{
type="claw";
sk=ob->query("claw");
}
else if(ob->query("axe"))
{
type="axe";
sk=ob->query("axe");
}
else if(ob->query("hammer"))
{
type="hammer";
sk=ob->query("hammer");
}
else if(ob->query("dagger"))
{
type="dagger";
sk=ob->query("dagger");
}
else if(ob->query("whip"))
{
type="whip";
sk=ob->query("whip");
}
else if(ob->query("throwing"))
{
type="throwing";
sk=ob->query("throwing");
}
else if(ob->query("wand"))
{
type="wand";
sk=ob->query("wand");
}
else if(ob->query("bow"))
{
type="bow";
sk=ob->query("bow");
}
else if(!ob->query("limit_lv"))
{
tell_object(this_player(),"�o���~�L�k�˳�\n");
return 1;
}
tell_object(this_player(),ob->short()+" �ݩ�"+type+" ��, �һݧޯ�"+sk*2+"�C\n");
}
                return 1;

        } else {
tell_object(this_player(),"�藍�_.. �A���W����������!!\n");
                return 1;
        }
}
