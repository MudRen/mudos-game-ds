// guild.c���vendor.c
#include <dbase.h>
inherit ROOM;
#include <ansi.h>
#define STOREDROOM __DIR__"temp/rest"
object stroom;
void create()
{
set("light",1);
set("short","[1;35m�����R���j����[m");
set("long",@LONG

  �o�̬O����̷̳R�Ӫ��a��M���M�o�̪����C�D�`���R�M��
����o�Q���X�z�C�A�ݨ���W�K�F�@�i�i��[1;32m�}[1;36mnote[1;32m�~[0m�C

__      o
��_____/_\______                        /��\\
�� @ = =   @= ��   ,_____,______,  6   ///|��\
�ááááááâ�   T\  :.    -=- \_/\    _|_
�áááááá�     I T============T /_   \_/
                     I            I/||

LONG
);
set("light",1);
set("exits",([
"north" : __DIR__"pearl_6",
]));
set("objects",([
__DIR__"npc/ovelia": 1,
__DIR__"npc/guest": 1,
]));
set("no_clean_up", 0);
set("item_desc",([
"note":@NOTE
�A�i�H�� list �Ӭݬݦ�����F��i�H�R�ӦY.
NOTE
,
]));
setup();
 load_object(__DIR__"pearl_35");
}

void init()
{
add_action("do_vendor_list","list");
 add_action("do_buy","buy");
 add_action("do_supply","supply");
}
int do_vendor_list()
{
object *goods,stroom;
mixed amount;
string list, *name;
int i,cost,level,maxlv;
load_object(STOREDROOM);
if(query_temp("stop"))
return notify_fail("���Ѧ����餣�ΪA,����~�F\n");
	stroom=find_object(STOREDROOM);
	goods = all_inventory(stroom);
list = "�A�i�H�ʶR�U�C�o�ǪF��:           �ʶR�ƶq            �� \n";   
 list += "==========================================================\n";
	for(i=0; i<sizeof(goods); i++)
	          { 
		list += sprintf("%-15s �R           %-7d          %-7d   \n",
			goods[i]->short(),goods[i]->query("amount"),goods[i]->query("value")
			 );
			 }
	write(list);
	return 1;	
}
int do_buy(string arg)
{
int amount;
object *goods,ob,ob2,npc,item;
if(!arg) return 0;
load_object(STOREDROOM);
stroom=find_object(STOREDROOM);
goods = all_inventory(stroom);
this_player()->add_temp("cmds",1);
if(sscanf(arg,"%d %s",amount,item)==2)
{
if(!objectp(ob=present(item,stroom)))
return notify_fail("xxx\n");
if(ob=present(item,stroom))
{
if(ob->query_amount()<1)
return notify_fail("�o�ح����槹�F\n");
if(this_player()->query("coin")<ob->query("value")*amount)
return notify_fail("�F��....�S���ٴ��ӳo�̶R�F��\n");
if ( (ob->query_weight()*amount+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
return notify_fail("�A���O�q����,�L�k���F��\n");
ob2=new(base_name(ob));
ob2->set_amount(amount);
if(ob2->query_amount()>ob->query("amount"))
return notify_fail("�������f�S�o��h\n");
ob->add("amount",-amount);
ob2->delete("secured");
ob2->move(this_player());
ob->delete("secured");
ob->delete("no_sell");
this_player()->add("coin",-ob->query("value")*amount);
 this_player()->save();
stroom->save();
message_vision("$N�R�F"+ob->name()+"\n",this_player());
}
else return notify_fail("�S�o�تF��\n");
return 1;
}
if(ob=present(arg,stroom))
{
if(ob->query("amount")<1)
return notify_fail("���ѫܤ������槹�F,�Ʊ�A��ѦA�ӥ��{\n");
if ( (ob->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )   
 return notify_fail("�A���O�q����,�L�k���F��\n");
 if(this_player()->query("coin")<ob->query("value"))
return notify_fail("�F��....�S���Q�Y�Q������\n");
if(query_temp("stop"))
return notify_fail("���Ѧ����餣�ΪA,����~�F\n");
this_player()->add("coin",-ob->query("value"));
message_vision("$N�R�F"+ob->name()+"\n",this_player());
if(ob->query("amount"))
 {
ob2=new(base_name(ob));
ob2->delete("secured");
ob2->move(this_player());
ob->add("amount",-1);
}
else 
ob->move(this_player());
stroom->save();
this_player()->save();
return 1;
}
else return notify_fail("�A�Q�n�Y�����\n");

}
int do_supply(string arg)
{
object *goods,ob,ob2,npc,obj;
int valu,exp,v,lck;
load_object(STOREDROOM);
stroom=find_object(STOREDROOM);
if(!arg) return notify_fail("�A�n�ɤ���f\n");
if(this_player()->query("class")!="worker")
return notify_fail("�A����ɳf\n");
if(this_player()->query_temp("supply"))
return notify_fail("�A�٦b�ɳf\n");        
this_player()->set_temp("supply",1);
goods = all_inventory(stroom);
if(obj=present(arg,this_player()))
if(arg=="rice")
{
if(obj=present(arg,this_player()))
if(!obj->query("supply"))
return notify_fail("�ڭ̤����o�F��\n");
valu=obj->query("value");
v=random(valu);
valu=valu+v;
valu=50+random(40);
exp=obj->query("value");
lck=this_player()->query("lck")*this_player()->query("level");
exp=exp+lck/3+random(lck/2)+this_player()->query_skill("product",1);
if(this_player()->query("lck")<random(this_player()->query("level")*10))
exp=200+random(200);
else
exp=400+random(200);
arg="rices";
if(ob=present(arg,stroom))
{
if(ob->query("amount")>90)
return notify_fail("�ثe���ݭn�ɳf�F\n");
ob2=new(base_name(ob));
ob2->set("amount",1);
ob->add("amount",2);
ob->add("amount",10);

message_vision("[1;32m$N�q����e��"+obj->name()+"[1;32m��o"+valu+"�T�ɪO���S��[0m\n",this_player());
message_vision("[1;32m$N[1;32m�b�Ҳ֪��ȳ~����o"+exp+"�I�g���[0m\n",this_player());
this_player()->add("coin",valu);
this_player()->add("exp",exp);
stroom->save();
return 1;
}
}
 if(obj=present(arg,this_player()))
if(obj=present(arg,this_player()))
if(arg=="corpse")
{
if(obj=present(arg,this_player()))
if(!obj->query("supply"))
return notify_fail("�ڭ̤����o�F��\n");
if(!obj)
 return notify_fail("�A���W�S���f\n");
valu=obj->query("value");
v=random(valu);
valu=65+random(55);
valu=(int)valu;
exp=obj->query("value");
if(this_player()->query("lck")<random(this_player()->query("level")*10))
exp=1100+random(1100);
else
exp=2200+random(1100);
exp=exp/2+random(exp/2)+lck;
exp=(int)exp;
arg="meat";
if(ob=present(arg,stroom))
{
if(ob->query("amount")>99)
return notify_fail("�ثe���ݭn�ɳf�F\n");
message_vision("[1;32m$N�q����e��"+obj->name()+"[1;32m��o"+valu+"�T�ɪO���S��[0m\n",this_player());
message_vision("[1;32m$N�b�Ҳ֪��ȳ~����o"+exp+"�I�g���[0m\n",this_player());
this_player()->add("coin",valu);
this_player()->add("exp",exp);
if(ob=present(arg,stroom))
if(ob->query("amount")<100)
 {
if(ob=present(arg,stroom))
{
if(ob->query("amount")>90)
return notify_fail("�ثe���ݭn�ɳf�F\n");
ob->add("amount",10);
}
this_player()->save();
stroom->save();
destruct(obj);
return 1;
}
return 1;
}
else return notify_fail("�S�o�تF��\n");
}
}
