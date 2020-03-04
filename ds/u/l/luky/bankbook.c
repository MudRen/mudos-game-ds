// bankbond.c

inherit ITEM;
inherit F_AUTOLOAD;
int balance = 0;

void create()
{
 set_name(this_player()->query("name")+"的存款簿", ({ "bankbook"}));
	set_weight(1);
	set("no_drop",1);
set("no_get",1);
set("no_auc",1);
set("no_give",1);
	if( !clonep() ) {
set("unit","本");
set("long",
"這是蘭卡銀行發行的存款簿,打balance,可以看你銀行的餘額\n");
	}
	setup();
}
void init()
{
add_action("do_balance","balance");
}
int do_balance()
{ 
int bal;
if(this_player()->query("balance/coin")>0)
{
bal=this_player()->query("balance/coin");     
bal=(int)bal;
write("你銀行存有"+bal+"枚銅板\n");
}
if(this_player()->query("balance/silver")>0)
{
bal=this_player()->query("balance/silver");
write("你銀行存有"+bal+"枚銀幣\n");
}
if(this_player()->query("balance/gold")>0)
{
bal=this_player()->query("balance/gold");
write("你銀行存有"+bal+"枚金幣\n");  
}
if(this_player()->query("balance/platinum")>0)
{
bal=this_player()->query("balance/platinum");
 write("你銀行存有"+bal+"枚白金\n"); 
}
return 1;
}
int query_autoload()
{ 
return 1;
}
