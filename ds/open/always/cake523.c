#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
	set_name(HIC"�j"HIG"��"HIY"�J"HIM"�|"NOR,({ "admin cake","cake" }) );
	set_weight(1);
	if( clonep() )
	set_default_object(__FILE__);
	else {
	set("long",@LONG
                 	��  ��       
                 	�i  �i       
                 	�i  �i      
            	   ����������������  
            	   ���ˡˡˡˡˡ���  
           	  ������������������ 
         	����������������������
	 	���H�H�H�H�H�H�H�H�H�� 
	        ����������������������
	�o�ӥͤ�J�|�ݰ_�ӤQ�����R�A�J�|���뺡�F
	�U���U�˪��s�A���G�A�W���٥��A���o���X�F
	�@���s�����ϮסC
LONG);
	set("unit", "��");
	set("material","food2");
	}
	setup();
	set("value",23000);
	set("food_remaining",55);
	set("heal_hp",500);
	set("heal_mp",500);
	set("heal_ap",500);
	set("volume",0);
}

void init()
{
	if(CLOCK_D->query_current_day() != 23) //����ϥΤ��
	{
		set("heal_hp",20);
		set("heal_ap",20);
		set("heal_mp",20);
		set("food_remaining",5);
		set("value",1000);
	}
          if(getuid(this_player())=="tmr") add_action("do_giveall","giveall");
	::init();
}

int do_giveall(string arg)
{
	int i;
	string *list=({}),*temp=({});
	object *ppl,cake;
	ppl=users();
	if(this_object()->query("gived")) list = this_object()->query("gived");
	for(i=0;i<sizeof(ppl);i++)
	{
		if(getuid(ppl[i])=="luky") continue;
		if(!cake=new(base_name(this_object()))) continue;
		if(present("admin cake",ppl[i])) continue;
		if(sizeof(list))
		{
			if(member_array(getuid(ppl[i]),list)!=-1) continue;
		}
		
		if(cake->move(ppl[i]))
		{
			tell_object(ppl[i],HIC+"\n\t�i  �@���i�R���p�s���ѨϬ�M�q�Ѫŭ��F�U��  �j\n"+NOR);
			temp+=({getuid(ppl[i])});  //����
			if(ppl[i]->query("level")<6)
			{
				tell_object(ppl[i],"\n    �p�s���ݧA���Ť������F�A�@�Ǹg��ȩM���A���A�[�o����C\n");
				ppl[i]->receive_money(5230);
				ppl[i]->add("exp",5230);
			}
			tell_object(ppl[i],HIY+"\n\t       �p�s�����F�A�@�ӳJ�|�N�C�C�����F\n"+NOR);
		} else tell_object(ppl[i],HIG+"\n�@���p�s���q�a�U���F�X�ӬݤF�ݧA�A�n�n�Y�N���F�C\n"+NOR);
	}
	write("�@�@�e���F"+sizeof(temp)+"�Ӫ��a�J�|�C\n");
	temp+=list;
	this_object()->set("gived",temp); //�x�s����
	return 1;
}
