// bankbond.c

inherit ITEM;
inherit F_AUTOLOAD;
int balance = 0;

void create()
{
 set_name(this_player()->query("name")+"���s��ï", ({ "bankbook"}));
	set_weight(1);
	set("no_drop",1);
set("no_get",1);
set("no_auc",1);
set("no_give",1);
	if( !clonep() ) {
set("unit","��");
set("long",
"�o�O���d�Ȧ�o�檺�s��ï,��balance,�i�H�ݧA�Ȧ檺�l�B\n");
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
write("�A�Ȧ�s��"+bal+"�T�ɪO\n");
}
if(this_player()->query("balance/silver")>0)
{
bal=this_player()->query("balance/silver");
write("�A�Ȧ�s��"+bal+"�T�ȹ�\n");
}
if(this_player()->query("balance/gold")>0)
{
bal=this_player()->query("balance/gold");
write("�A�Ȧ�s��"+bal+"�T����\n");  
}
if(this_player()->query("balance/platinum")>0)
{
bal=this_player()->query("balance/platinum");
 write("�A�Ȧ�s��"+bal+"�T�ժ�\n"); 
}
return 1;
}
int query_autoload()
{ 
return 1;
}
