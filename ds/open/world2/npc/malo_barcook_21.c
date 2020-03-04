#include <ansi.h>
inherit NPC;
inherit F_VENDOR;
//inherit SHOPMAN;
void create()
{
//=========================�򥻳]�w==========================

        set_name( "�P�´I", ({ "cook zhou","zhou","cook"}));
        set("long",@LONG
        �@�ӽG�G�����~�k�H�A���a���e�ݵۧA�C
	==============================================
	��F�� <sell �׫~> <sell �ƶq �׫~>
	==============================================
LONG);
        set("level",21);
        set("title","[1;33m�j�p[m");
        set("gender", "�k��");
        set("race", "human");
        set("age", 45);
        set("evil",-10);			//���c�� 20 (�������c, �t���})

	set("attitude", "peaceful");   //�ũM�� NPC�C
	set("talk_reply","�p�G�A���s�A���׫~�A�i�H��(sell)���ڳ�!!");
	set("storeroom",__DIR__"bar_shoproom");	//�`�N. �n�إߤ@��room��F��

//===========================���D�^��==================================
set("inquiry/name", @LONG
  [1;36m �ڥs���P�´I.. �Цh����!![m
LONG );
        setup();
      add_money("dollar", 1100);		//�a����
      carry_object(__DIR__"../eq/cloth_pants_5")->wear();
      carry_object(__DIR__"../eq/cloth_hat_5")->wear();
      carry_object(__DIR__"../eq/cloth_boots_5")->wear();
      carry_object(__DIR__"../eq/cloth_clothes_5")->wear();
      carry_object(__DIR__"../wp/iron_blade_22")->wield();
}

void init()
{
	::init();
//	add_action("do_list","list");
//	add_action("do_buy","buy");
	add_action("do_sell","sell");
}

int do_sell(string arg)
{
	object ob,*inv,obj,ob1,me,*goods,stroom;
	string item;
	int valu,i,amount,world;
	me=this_player();
	if(!stroom=load_object(this_object()->query("storeroom"))) return 0;
	if(!arg) return notify_fail("�A�n�椰��F��H\n");
	if(sscanf(arg,"%d %s",amount,item)==2) // AMOUNT
	{
	  if(amount<1) return notify_fail("�A�n��X�ӰڡH\n");
	  if(amount>10) return notify_fail("�@���̦h��Q�ӡC\n");
	  for(i=0;i<amount;i++)
	  {
	  	do_sell(item);
	  }
	 return 1;
	} //END of AMOUNT
	 if(!ob=present(arg,me)) return notify_fail("�A�S���o�˪F��C\n");
	if(!ob->is_meat() )
	{
		return notify_fail(this_object()->name()+"�n�n�Y��: �ڥu�������C\n");
		if( ob->query("name") == "�G�ꪺ����" ) return notify_fail(this_object()->name()+"�n�n�Y��: �o���w�g���s�A�F�C\n");
	}
 	if(ob->query("secured"))
 		return notify_fail("�Х��Ѱ��O�s���A�C\n");
 	if( ob->query("no_drop") )
 		return notify_fail("�o�ӪF��ܯS�O, �A�٬O�ۤv�O�ަn�F�C\n");
 	if( ob->query("no_sell"))
 		return notify_fail("�ڤ����ʳo�تF��C\n");
 	if( ob->is_character() && !ob->is_corpse()) return notify_fail("�ڤ����ʬ����F��C\n");
 	if(ob->query("equipped"))
 		return notify_fail("�Х������U�Ӧn�ܡH\n");
	if(ob->query("gender")=="fish")
	{
		ob->set("value",50);
		ob1=new_ob(__DIR__"../obj/fish_soup_120");
		if(!ob1) return notify_fail("�ڤ����ʳo�تF��C\n");
	}
	else
	if(!ob1=new_ob(__DIR__"../obj/"+ob->query("cook"))) return notify_fail(this_object()->name()+"�n�n�Y��: �o�ئקڤ��|�Ʋz�C\n");
 	valu=ob->query("value");
 	if( valu<20 )
		 return notify_fail("�o�F�褣�ȿ��C\n");
	arg = ob->query("id");
	
	valu=valu*4/5;
	world = me->money_type();
	if(world!=3) message_vision("$N��F�@"+ob->query("unit")+ob->query("name")+"��$n, $n���F$N"
		+price_string(valu,me->money_type())+"�C\n",me,this_object());
	else message_vision("$N��F�@"+ob->query("unit")+ob->query("name")+"��$n, $n�N"
		+valu+"�ӳ�쪺�q�l���s�J$N���b�������C\n",me,this_object());
	me->receive_money(valu);
	ob1->move(stroom);
	destruct(ob);
	goods = all_inventory(stroom);
	if(sizeof(goods)>100)
	{
		for(i=100;i<sizeof(goods);i++)	destruct(goods[i]);
	}
	me->save();
	return 1;
}
