// Spinner
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�B�t��",({ "liu chen wen","spinner","liu","wen" }));
	set("long",@LONG
�o�O�@�ӯ�´�u�H�A�o���ί����A�d�F�Ӱ����A�o�M���b�q�Ʃ�
´���u�@�A�p�G�A���q���Ө��R��@�ǥ��A�i�H���o�h���@�Ǧ�A
��A���L�e�����O�A�A�@�w�n���ǿ��A���M�o�i�O�R������ƥh��
����C
LONG
	);
	set("nickname","��´�{");
	set("gender","�k��");
	set("age",18+random(10));
	set("no_fight",1);
	set("chat_chance", 3);
	set("chat_msg", ({
  (: command,"sweat" :),
  this_object()->name()+"�������b�s´��A�C\n",
  (: command,"say �̪񦫧�´��A���H�V�ӶV�֤F...." :),
  this_object()->name()+"�Q��o���T���F�X�w���\\...\n",
  (: command,"sigh" :),
}) );
	set("inquiry",([
  "´��" : "´���O�ڪ��M���A�ڱq�p����j���O�o�ˤl���L�Ӫ��C",
  "help" : "�u�n���ڤ@�����A�M�@�I�u���A�ڴN�i�H���z����n��A�C",
]));
	setup();
	add_money("silver", 1);
}

int talk_action(object me)
{
	if(this_object()->query_temp("editing"))
	{
		message_vision("$N���G�]���ӱM�ߤu�@�F�ӨS��ť��$n�����ܡC\n",this_object(),me);
		return 1;
	}
	message_vision("$N�ۨ��ۻy�G"HIB"�̪�ҭn´���V�ӶV�֤F�A�����D�ӥΤ���H�ץͬ�..\n"NOR,this_object());
	message_vision("$N���G"HIY"�z�ݭn������(help)���s��A�ܡI\n"NOR,this_object());
	return 1;
}

int accept_object(object me, object ob)
{
	int moneya;
	string money_type;
	if(this_object()->query_temp("editing"))
	{
		return notify_fail("�o���b�u�@���A�S�Ŧ��A���F��C\n"NOR);
	}
	
	if( !ob->query("cloth") )
	{
		if( !me->query_temp("spinner") )
			return notify_fail("�A�n�����o�@�����A�o�~�|���A������... :)\n");
		if( !(money_type=ob->query("money_id")) )
			return notify_fail("�o�u�����ƩM�u���C\n");
		if( money_type!="coin" && money_type!="silver" && money_type!="gold")
			return notify_fail("�o�u�j�N�i�H�Ϊ����C\n");
		moneya = ob->value();
		if(moneya<100) return notify_fail("�A�Q�F�Qı�o���G�֤F�I�C\n");
		message_vision("$N��$n�F�@��"+ob->name()+"�C\n",me,this_object());
		call_out("working",0,me,moneya);
                return 1;
	}
		
	if( me->query_temp("giving_1") )
		return notify_fail("�B�t�廡�G"HIY"�z�w�g���ڤ@�����F, �A���ڤ@�Ǥu���ڴN�i�H�}�l���F�C\n"NOR);
	message_vision("$N���F$n�@��"+ob->name()+"�C\n",me,this_object());
	tell_object(me,"�B�t�廡�G"HIY"��.. �Ӧn�F, �u�n�z�A���ڤ@�Ǥu���ڴN�i�H�}�l���z����A�F�C\n"NOR);
	me->set_temp("spinner",ob);
	me->set_temp("giving_1",1);
	return 1;
}

void working(object me,int moneys)
{
	object m;
	int c_out;
	
	m = me->query_temp("spinner");
	command("thank "+me->query("id"));
	message_vision("$n�b�P��$N����A�����$N�ҵ�$p�����Ʃ�b�u�@�x�W�}�l���F�_�ӡI\n",me,this_object());

	// luky fixed
	if( moneys > 999 ) c_out=0;
	else if( moneys > 499 ) c_out=3;
	else c_out=5;

	call_out("editing",c_out+3  , 0);
	call_out("editing",c_out+7  , 1);
	call_out("editing",c_out+10 , 2);
	call_out("setting",c_out+11 , c_out , m , me);
	return;
}

int editing(int flag)
{
	if( flag == 0 ) message_vision(HIC"$N����n�����Ʈ����_�����W�}�l [ ������..]���_�s�_�ӡC\n"NOR,this_object());
	if( flag == 1 ) message_vision(HIG"$N�~��V�O���b�_�����e�u�@�C\n"NOR,this_object());
	if( flag == 2 )
	{
		this_object()->delete_temp("editing");
		message_vision(HIY"$N���_�_�n����A�װŤF�@�U, �@���A�N�o�򧹦��F�I�I\n"NOR,this_object());
	}
	return 1;
}

void setting(int c,object m,object me)
{
	int kind;
	object d_cloth;
	d_cloth = new(__DIR__"eq/defaulteq.c");

	// 0 �Q������, 1 ���ꥬ, 2 �ť�,3 �ȵ�,4 ����,5 ������,6 �A�v
	kind=m->query("cloth")-1;
	switch( kind )
	{
	 case 0: // �Q������
		d_cloth->set_name(WHT"�Q���_��"NOR,({ "gray silkworm dress","dress"}));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",8+random(4));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",5+random(3));
				break;
//luky			case 5:
			default:
				d_cloth->set("armor_prop/armor",3+random(3));
				break;
		}
		break;
	 
	 case 1: // ���ꥬ
		d_cloth->set_name(MAG"������T"NOR,({ "purple robe","robe" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",6+random(5));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",4+random(4));
				break;
			default:
				d_cloth->set("armor_prop/armor",3+random(3));
				break;
		}
		break;

	 case 2: // �ť�
		d_cloth->set_name(HIC"�Ŧ��_��"NOR,({ "blue cloth","cloth" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",7+random(4));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",5+random(4));
				break;
			default:
				d_cloth->set("armor_prop/armor",3+random(3));
				break;
		}
		break;
		
	 case 3: // �ȵ�
		d_cloth->set_name(HIM"�ȵ���"NOR,({ "argentine cloth","cloth" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",6+random(4));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",4+random(4));
				break;
			default:
				d_cloth->set("armor_prop/armor",2+random(4));
				break;
		}
		break;
	 
	 case 4: // ����
		d_cloth->set_name(HIW"�����m"NOR,({ "villosity dress","dress" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",4+random(3));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",3+random(3));
				break;
			default:
				d_cloth->set("armor_prop/armor",2+random(3));
				break;
		}
		break;
	 
	 case 5: // ������
		d_cloth->set_name(WHT"��������"NOR,({ "coarseness bombyx cloth","cloth" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",7+random(4));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",5+random(4));
				break;
			default:
				d_cloth->set("armor_prop/armor",3+random(4));
				break;
		}
		break;
	 
	 default: // �A�v(6)
		d_cloth->set_name(HIY"�A�T"NOR,({ "filamentus robe","robe" }));
		switch( c )
		{
			case 0:
				d_cloth->set("armor_prop/armor",5+random(4));
				break;
			case 3:
				d_cloth->set("armor_prop/armor",4+random(4));
				break;
			default:
				d_cloth->set("armor_prop/armor",3+random(4));
				break;
		}
		break;
	}
	
	if(!me) //�Z�O��delay���n�Ҽ{���a�_�u��quit
	{
	 return;
	}
	
	if(environment(me)!=environment(this_object())) //���a���}�F?
	{
		d_cloth->set("long",d_cloth->query("long")+"\n�o�O�M��"+me->name(1)+"�q���w�����C\n");
		d_cloth->move(environment(this_object()));
	 	me->delete_temp("spinner");
		me->delete_temp("giving_1");
		tell_object(me,"�A��M�Q��, ��~�q������A���Ӧn�F�a...\n");
		destruct(m);
		return;
	}
	
	message_vision("$n���F$N�@��"+d_cloth->name()+"�C\n",me,this_object());
	d_cloth->move(me);
	d_cloth->set("long",d_cloth->query("long")+"[�o�O�M��"+me->name(1)+"�q���w����"+d_cloth->name(1)+"�C]\n");
	me->delete_temp("spinner");
	me->delete_temp("giving_1");
	destruct(m);
	return;
}
