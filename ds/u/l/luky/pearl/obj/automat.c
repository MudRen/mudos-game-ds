#include <ansi.h>
#include <path.h>
//inherit F_CLEAN_UP;
#include <dbase.h>
#include <ansi.h>
inherit ITEM;
#define STOREDROOM LUKY+"pearl/temp/auto"
object stroom;
void create()
{
object ob, obj;
seteuid(getuid());
set_name("�۰ʳc���",({"automat"}));
set("unit", "�x");
set("incoin",0);
set("long",@LONG
�o�O�@�x�۰ʳc����C�W�����X�ӫ��s... (�ϥΤ�k�Х�help automat)

 0.�h��  1. �³��(300��)  2. �ʳf  3. �ʳf

LONG
);
set("no_sac", 1);
set("no_get", 1);
set_max_encumbrance(9999999);
setup();
}


void init()
{
add_action("do_vendor_list","list");
add_action("do_insert","insert");
add_action("do_press","press");
}

int do_vendor_list(string arg)
{
object *goods,stroom;
mixed amount;
string list, *name;
int i,cost,level,maxlv;
load_object(STOREDROOM);
stroom=find_object(STOREDROOM);
goods = all_inventory(stroom);
list = "�A�i�H��ܤU�C�o�Ǫ��~:           �ʶR�ƶq          ���� \n";
list += "==========================================================\n";
for(i=0; i<sizeof(goods); i++)
 {
  list += sprintf("%d %-22s �R        %7d         %7d   \n",
  (i+1),goods[i]->short(),goods[i]->query("amount"),goods[i]->query("value")
  );
 } 
write("[�c����̭��٦� "+query("incoin")+" �T�ɹ�]\n\n");
write(list);
return 1;
}

int do_insert(string arg)
{
object automat,me;
int coins;
if(!arg) return notify_fail("�榡: insert <�Ʀr> \n");
if(sscanf(arg, "%d", coins)==1)
 {
  automat=this_object();
  me=this_player();
  if(me->query("coin")<coins) return notify_fail("�A���W�S���o��h�ɹ�\n");
  if(automat->query("incoin")>100000) return notify_fail("�c����ˤ��U��h���F\n");
  add("incoin",coins);
  me->add("coin",-coins);
  message_vision("$N�q�f�U�ǥX�F"+coins+"�ӻɪO���۰ʳc����̭�\n",this_player());
  return 1;
 }
 return notify_fail("�榡: insert <�Ʀr> \n");
}

int do_press(string arg)
{
 object *goods,box,ob,obj,me;
 string str,file;
 int button, cost, amount, i;
 me=this_player();
 box=this_object();
 load_object(STOREDROOM);
 stroom=find_object(STOREDROOM);
 goods = all_inventory(stroom);
 if(!arg) return notify_fail("�n��������s? \n�榡: press <�Ʀr> \n");
 if(sscanf(arg, "%d", button)==1)
 {
  if(button==0) 
  {
   if(query("incoin")>0)
   {
    obj=new("/obj/money/coin");
    obj->set_amount(query("incoin"));
    obj->move(box);
    message_vision("$N���U�h���s, �@�}�M�ժ��n��, �����f���X"+query("incoin")+"�ӻɹ���\n",me);
    set("incoin",0);
    return 1;
   }
   return notify_fail("�A���F�h���s... �i�O����Ʊ����S���o��.\n");
  }
  if(button==1) arg="green tea"; 
  else if(button==2) return notify_fail("���w�g�g[�ʳf��]�F�A�٫�?\n");
  else if(button==3) return notify_fail("���w�g�g[�ʳf��]�F�A�٫�?\n");
  else return notify_fail("�S���o�ӫ��s.\n");
  ob=present(arg,stroom);
  if(!ob) return notify_fail("�䤣��o�ӪF��! ���p���Ův.\n");
  cost=ob->query("value");
  amount=query("incoin")/ob->query("value");
  if(amount>ob->query("amount")) amount=ob->query("amount");
  if(ob->query("amount")<1) return notify_fail("�o�F��槹�F\n");
  if(amount<1) return notify_fail("�c����S������..�i��O�몺������\n");
  for(i=0;i<amount;i++)
  {
   ob->add("amount",-1);
   box->add("incoin",-cost);
   if(obj=present("green tea",box))
   {
    obj->add_amount(1);
   } else
   {
    obj=new(base_name(ob));
    obj->move(box);
   }
  }
  message_vision("$N���U�c����W�����s, �B���@�n,�����f�u�X"+amount+obj->query("unit")+"$n��\n",me,ob);
  return 1;
 }
 return notify_fail("�n��������s? \n�榡: press <�Ʀr> \n");
}
