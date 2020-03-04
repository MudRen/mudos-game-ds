// fight glove   make by chilice
#include <mudlib.h>
#include <ansi.h>
#include <armor.h>
#include <command.h>
inherit ITEM;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;


void create()
{
        set_name("戰鬥手套",({"fight glove","glove"}) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@LONG
這是一雙受過魔崇神--拿各--詛咒的手套,能帶給人無窮的爆發力但只有擁有巫師神力的人才能使用它,否則將會招到天譴的(砍檔)

用法:add <技巧> <數值>

用法:change <屬性> <數值>

屬性: kee,gin,sen,force,mana,atman,bellicosity,food,water
        max_kee,eff_kee

用法:trans <種類> <名稱> 

example->trans name 白痴
LONG);
set("unit","雙");
        set("value",1750);
        set("material","crimsonsteel");
        set("armor_prop/armor", 8);
        }
        setup();}

int query_autoload()
{
if(this_player())
  if (wizardp(this_player()))
    return 1;
  else return 0;
}

void init()
{
  object me;
  seteuid(geteuid());

  me = this_player();
  if (me)
        set_name (me->name(1)+ "戰鬥手套", ({ "fight glove","glove" }));
  else
        set_name ("戰鬥手套", ({ "fight glove","glove" }));
add_action("do_add","add");add_action("do_change","change");
add_action("do_trans","trans");
  this_player()->set_temp("heat",1);
}

int do_add(string str){
        int amount;
        string skil;
        object me;
if (!wizardp(this_player())) {
        write("hmm.......想被砍檔喔!!\n");
}
if(!str||sscanf(str, "%s %d",skil,amount)!=2)
        return notify_fail("[glove]:add <技巧> <數值>\n");
        me=this_player();
        me->set_skill(skil,amount);
message_vision( sprintf("$N手套的四周忽然射出"+CYN+"詭異的藍光"+NOR+",%s暴增為%d！！！\n",skil,amount),me);
return 1;
}

int do_change( string str) {
        int num;
        string po;
        object me;
if (!wizardp(this_player())) {
        write("hmm.......想被砍檔喔!!\n");
return 1;
}
if(!str||sscanf(str, "%s %d",po,num)!=2)
        return notify_fail("[glove]:change <屬性> <數值>\n");
        me=this_player();
        me->set(po,num);
message_vision( sprintf("$N的手套忽然發出強烈的"+CYN+"藍色異光"+NOR+",%s變為%d！！！\n",po,num),me);
return 1;

}

int do_trans(string str){
        string ch1,ch2;        object me;

if (!wizardp(this_player())) {
        write("hmm.......想被砍檔喔!!\n");
return 1;
}
if(!str||sscanf(str, "%s %s",ch1,ch2)!=2)
return notify_fail("[glove]:trans <種類> <名稱>\n");
        me=this_player();
        me->set(ch1,ch2);
        message_vision( sprintf("$N的%s改為%s\n",ch1,ch2),me);
return 1;
}


