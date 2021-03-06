// guild.c改自vendor.c
#include <dbase.h>
inherit ROOM;
#include <ansi.h>
#define STOREDROOM __DIR__"temp/store1"
object stroom;
void create()
{
set("light",1);
set("short","[1;33m阿爾加斯道具屋[m");
set("long",@LONG
你走進一家十分寬敞的商店，兩旁的玻璃櫃放了各種形形色色的道具
和裝備，正中間是一個四方形的櫃檯，上面有個價目表，你可以用[[1;36mlist[m]
來看看有那些東東，再考慮看看要不要買[[1;36mbuy[m]。
LONG
);
set("light",1);
set("exits",([
"south" : __DIR__"pearl_18",
]));
set("objects",([
__DIR__"npc/buddy": 1,
]));
setup();
}

void init()
{
add_action("do_vendor_list","list");
add_action("do_buy","buy");
add_action("do_supply","supply");
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
if(arg=="shield"){ //if loop
list =  "你可以購買下列這些東西:           購買數量          價錢 \n";
list += "==========================================================\n";
for(i=0; i<sizeof(goods); i++)
{    //for loop
printf("%s\n",goods[i]->query("name"));
printf("%s\n",goods[i]->short());
if(goods[i]->query("id")!=arg) continue;
printf("%s\n",goods[i]->query("short"));
list += sprintf("%-22s ﹕          %7d         %7d   \n",
goods[i]->short(),goods[i]->query("amount"),goods[i]->query("value")
);
   }// for loop
} else {    //else loop
list = "你可以購買下列這些東西:           購買數量          價錢 \n";
list += "==========================================================\n";
 for(i=0; i<sizeof(goods); i++)
 {
  list += sprintf("%-22s ﹕        %7d         %7d   \n",
  goods[i]->short(),goods[i]->query("amount"),goods[i]->query("value")
  );
 } //for loop
} // else loop
write(list);
return 1;
}
int do_buy(string arg)
{
object *goods,ob,ob2;
if(!arg) return 0;
load_object(STOREDROOM);
stroom=find_object(STOREDROOM);
goods = all_inventory(stroom);
if(ob=present(arg,stroom))
{
if ( (ob->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
 return notify_fail("你的力量不夠,無法拿東西\n");
if(this_player()->query("coin")<ob->query("value"))
return notify_fail("幹嘛....沒錢還敢來這裡買東西\n");
if(ob->query("amount")<1)
return notify_fail("這東西賣完了\n");
this_player()->add("coin",-ob->query("value"));
message_vision("$N買了"+ob->name()+"\n",this_player());
if(ob->query("amount"))
 {
  ob2=new(base_name(ob));
  ob2->set("amount",1);
  ob2->move(this_player());
  ob->add("amount",-1);
 }
else
ob->move(this_player());
return 1;
}
else return notify_fail("沒這種東西\n");
}

int do_supply(string arg)
{
object *goods,ob,ob2,npc,obj;
int valu,exp,v,lck;
load_object(STOREDROOM);
stroom=find_object(STOREDROOM);
if(!arg) return notify_fail("你要補什麼貨\n");
if(this_player()->query("class")!="worker")
return notify_fail("你不能補貨\n");
goods = all_inventory(stroom);
if(obj=present(arg,this_player()))
if(arg=="wood")
{
if(obj=present(arg,this_player()))
if(!obj->query("supply"))
return notify_fail("我們不收這東西\n");
if(!obj)
 return notify_fail("你身上沒有貨\n");
valu=obj->query("value");                           
v=random(v);
valu=valu+v;
valu=50+random(20);
exp=obj->query("value");
lck=this_player()->query("lck")*this_player()->query("level");
if(this_player()->query("lck")>random(this_player()->query("level")*10))
exp=200+random(100);
else
exp=100+random(100);
exp=(int)exp;
arg="torch";
if(ob=present(arg,stroom))    
{
if(ob->query("amount")>90)
return notify_fail("目前不需要補貨了\n");
message_vision(HIY"$N從遠方送來"+obj->name()+"獲得"+valu+"枚銅板的酬勞\n"NOR,this_player());
message_vision("$N在勞累的旅途中獲得"+exp+"點經驗值\n",this_player());
this_player()->add("coin",valu);
this_player()->add("exp",exp);
ob2=new(base_name(ob));
ob2->set("amount",1);
ob->add("amount",10);
ob->delete("secured");
ob->delete("out");
destruct(obj);
return 1;
}           
else return notify_fail("沒這種東西\n");
}
 else return notify_fail("你身上沒有這樣東西\n");
} 
