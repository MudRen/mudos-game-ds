#include <ansi.h>
#include <combat.h>

inherit ITEM;
#define DELAY 1

string *nuclear = ({
        "��������",
        "�׵��@��",
        "���O�@��",
        "���t����",
        "�¤���",
        "�R�ߤ���",
        "�|�ߤ@��",
        "������",
        "�Ʊ椧��",
        "�j���@�� ",
	});


string *color = ({
	MAG,
	HIG,
	HIY,
	HIW,
	HIC,
	HIR,
	});

string *shipname = ({
        HIY+"�O�ɱ� "+NOR,
        HIW+"�k�ԧQ "+NOR,
        HIG+"�L�_�� "+NOR,
        HIW+"�_��"+NOR,
        HIB+"��ù�� "+NOR,
        HIC+" ���h"+NOR,
        HIY+"���M "+NOR,
	});
int v = random(sizeof(nuclear));
int x = random(sizeof(color));

void create()
{
	set("long","�o�O�@�ǥѫe�ҥ���������y�����t�z��A�۫H�o�O�ѥ~�Ӫűo�Ӫ��C\n");
	set_name(HIC"�t�z��"NOR+shipname[random(sizeof(shipname))],({"spaceship","ship"}));
	set("no_get",1);
	set("no_drop",1);
	set("nuclear",999999999999999999999);
	set("count",100000000000000000000);
	set("bullet",50000000000000000000);
}

void init()
{
	add_action("launch_Nuclear","laiser");
	add_action("do_ascend","ascend");
	add_action("do_descend","descend");
	add_action("do_fly","flyto");
	add_action("do_shoot","shoot");
}

int do_ascend()
{
	object me;

	me=this_player();
	if(me->query_temp("marks/ascend"))
	return notify_fail("�A�w�g�b�t�z��C\n");
	message_vision("$N�i�J�F"+this_object()->name()+"���t�z��C\n",me);
	me->set_temp("marks/ascend",1);
	me->add_temp("apply/short",({me->short()+HIY"(��������"NOR+this_object()->name()+HIY")"NOR}));
	move(me);
	return 1;
}

int do_descend()
{
	object me;
	string *name;

	me=this_player();
	if(!me->query_temp("marks/ascend"))
	return notify_fail("�A�w�g���t�z��F�C\n");
	message_vision("$N�H��"+this_object()->name()+"���w���議�F�U�ӡC\n",me);
	me->delete_temp("marks/ascend");
	me->delete_temp("apply/short");
	move(environment(me));
	return 1;
}

int launch_Nuclear(string arg)
{
	string msg;
	int nu;
	object who,me;
	me = this_player();

	if(this_object()!=present(this_object(),this_player()) )
	return notify_fail("�A�å��r�p�Ӧt�z��C\n");

	if( !(nu = (int)this_object()->query("nuclear")) ) {
	write(this_object()->name()+"�Z���w�g�κɡC\n");
	return 1;
	}
	nu--;
	set("nuclear", nu);

	if(!arg) return notify_fail("�Щw�H���G�A�Q�H�֬��E�����ߡH�C\n");


	who = present(arg,environment(me));


	msg=HIR"�t�z��E�����w�w�}�ҡA"+HIW+"��Z���t�ζ}�l���I���Ǻ˷ǡI�I\n"NOR;
	message_vision(msg,me);
	message_vision(HIY"�y����w�}�l��J�D�ʾɯ��ơ��J�T�{�I\n\n"NOR,me);

	if(!who) who=find_living(arg);
	if(!who) {
	who=this_player();
	message_vision(HIR"�Ϣ�������I�I�Ϣ�������I�I���h�ؼСA���j�������o�g�I\n"NOR,me);
	return 0;
	}

	call_out("Nu_1",DELAY+2,me,who,arg);
	me->start_busy(3);
	return 1;
}

int Nu_1(object me,object who,string arg)
{
	message_vision(MAG"�o�̬O�Pĥ�Z���x�G�T�{�ҰʡA�E���o�g�}�l�I\n"NOR,me);
	message_vision(HIC"ĥ���^���G"HIR"�Ḁ̇[�ɤl���ǳƵo�g�I\n\n"NOR,me);
		message_vision(HIR"�Pĥ�Z���x�G�Ḁ̇[�ɤl�����"HIB""+color[x]+nuclear[v]+color[x]+"��T�{�I\n\n"NOR,me);

	tell_room(environment(who),
	HIG"���h�W�Ŭ�M�{�X�ܱj�j���� �A"MAG"�n���V�ӶV���񤣹��O�{�q�A���@�����u�H���t���Ӫ��ˤl�C\n\n"NOR);


	call_out("Nu_2",DELAY+5,me,who,arg);
	me->start_busy(5);
	return 1;

}

int Nu_2(object me,object who,string arg)
{
	mixed all;
	object room,a;
	int i;
	room = environment(who);
	all = all_inventory(room);

	message_vision(HIY"��T�ɯ�x�G�R���ؼС��̹q���޲z�зǭp��A�}�a�b�|200���T�{�C\n\n"NOR,me);

	tell_room(environment(who),
	HIR""+nuclear[v]+"�E����}�j��h��"+ who->query("name") +"�g�ӡC\n\n"
	HIY"�F���㪺�@�n���T�A"HIG"�E�����߱��_�@�}�������R�Ѥ��K�C\n\n"
	HIR"�X�G�b�P�@�ɶ��A���K���g���@�몺ŧ���]�S�F�o�@���Ŷ��C\n\n"
	HIW"�H�ۧA���骺���u�A�Ҧ��b�����H�]���@�L���|���b���趡���h�C\n\n"NOR);


	for(i = 0 ; i < sizeof(all) ; i++)
	{
	 a = all[i];
	 if(living(a))		//add by Luky
	 {
	   a->die();
	   CHANNEL_D->do_channel(this_player(),"rumor",
		sprintf("%s�b�Ḁ̇[�ɤl��"+nuclear[v]+"�ݻŪ��������U�A�L�ର�O�������b���K���I",a->name()));
	 }
	}
	return 1;
}

int do_fly(string arg) //����MH��teleport,�Q�ק令��p��upkeep....:P
{
	object who,me;
	int count1;


	if( this_object() != present(this_object(),this_player()) )
		return notify_fail("�A�å��r�p�Ӧt�z��C\n");

	if( !arg ) return notify_fail("�ɯ�x�Gĥ���A�Ы��w�����I�C\n");

	me=this_player();
	who = find_player(arg);
	if (!who) who = find_living(arg);
	if (!who) return notify_fail("�ɯ�x�Gĥ���A�Ы��w�����I�C\n");

	count1 = (int)this_object()->query("count");
	if( (count1 -= 4) < 0 ) {
		count1 += 4;
		set("count",count1);
		return notify_fail(this_object()->name()+"��q�w�g�����H�i�歸��C\n");
	}

	set("count",count1);
		message_vision("$N"HIW"�����ҰʡA�}�l��V�ɯ��I�C\n",this_object());
	tell_room(who,this_object()->name()+HIB"���V���a�A�w�찱�}�����C\n"NOR);
	me->move(environment(who));
	return 1;
}

int do_shoot(string act)
{
	string msg;
	object ob,target;

	ob = this_object();
	if( this_object() != present(this_object(),this_player()) )
	return notify_fail("�A�å��r�p��ĥ�C\n");

	if(ob->query("bullet")<=0) {
	write(this_object()->name()+"�j���Z���w�g�κɡC\n");
	return 1;
	}

	if( act ) target = present( act, environment(this_player()) );

	if(!target
	||	!target->is_character()
	|| target->is_corpse()
	||	target==this_player())
		return notify_fail("����Gĥ���A�Ы��w�g���ؼСC\n");

	msg = "$n"+HIR+"�p�F�}�l�����ؼк˷ǡA�ٱN�ؼФF��w"+HIY+"�O�@��"+HIR+"���t���u�����}�ҡC\n"NOR;
	message_vision(msg,target,ob);
	message_vision("$n"HIB"�W������A�}�l������"NOR"$N"HIY"�A�ǳƶ}�l�g���C\n"NOR,target,ob);

	call_out("shoot_2",DELAY+2,this_player(),target,ob,act);
	this_player()->start_busy(3);
	return 1;
}

int shoot_2(object me,object target,object ob,string act)
{
	string msg;
	int damage,i,bul,dp,pp,dx,nt,kr,cha;

	pp = COMBAT_D->skill_power(target, "parry", SKILL_USAGE_DEFENSE) ;
	dp = COMBAT_D->skill_power(target, "dodge", SKILL_USAGE_DEFENSE) ;
//	dx = target->query_attr("dex");	//
//	nt = target->query_attr("int");	//�Ѧ� /feature/attribut.c
//	kr = target->query_attr("kar");	//�o�̪��Ϊk�p�U���
	dx = target->query_dex();
	nt = target->query_int();

	cha = pp*2 +dp*2 +dx +nt +target->query_armor()*3;

	for(i=0; i<10; i++)
	{
	bul = (int)this_object()->query("bullet");
	if ( (bul -= 50+random(100) ) < 0 ) {
	bul += 50+random(100);
	set("bullet",bul);
	}  
	set("bullet",bul);

	damage = 500+random(500) -cha/3;

	if(ob->query("bullet") <= 0 ) 
	{
	message_vision("$n"HIW"�����u�ܥd��d�����T�ۡA��M�u�Ĥw�ӺɡC\n"NOR,target,ob);
	ob->set("bullet",0);
	break;
		}
	else{
	msg = HIY"����Q���a�g�X��"+(i+1)+"�K���u��"NOR;
	}
	if ( damage > 0) {
	msg +=HIR"$N"HIR"�A��g�Q�ӥX�C"HIR"(" + damage + ")\n" NOR;
		message_vision(msg,target,ob);
		target->receive_damage("hp", damage, me);	//fix by luky
		COMBAT_D->report_status(target);		//fix by luky
	}  else {
	msg +=HIW"�i�O���u�L�`�����b"NOR"$N"HIW"���W�C\n"NOR;
	message_vision(msg,target,ob);
		} 
	}
	me->start_busy(1);
	target->start_busy(1);
	return 1;
//	}
}
