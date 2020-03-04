//�ⶳ�x �i�� Master -By Tmr 2002/1/24-

#include <ansi.h>

inherit NPC;

void do_heal();
varargs int receive_damage(string type, int damage, object who);

void create()
{
        set_name("��������",({"miao-jian bonze","bonze","miao-jian"}));
        set("gender", "�k��");
        set("long",@LONG
�����������ⶳ�x�e������A�����p���D�A�z�ڲ`�p�A���~�ɴ��]�t�ڷ|
�߱o������Ĥ@���ޡu�p�ӤE���v�A�ۦ���B�Z�G�D���������A�׬��X�H�F
��u�i�ơv���ҬɡC�M�ӡA�A�{�b���쪺�O�����׹D����ӯd�b�H��������
�A�]�O�p�Ӧ���窺����x���@�C
LONG
        );
        set("level",40);
        set("age",80);
        set("title","�@�k�Ϫ�");
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
		set_skill("jingang-finger",100);
        map_skill("unarmed","jingang-finger");
	    set("attitude", "aggressive");
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
					(:do_heal:), 
					(:do_heal:), 
		}) );        

		setup();
		carry_object(__DIR__"eq/armor")->wear();
		carry_object(__DIR__"eq/cloth")->wear();
		carry_object(__DIR__"eq/helmet")->wear();
		carry_object(__DIR__"eq/boots")->wear();
		carry_object(__DIR__"eq/hands")->wear();
        set_living_name("buddha-war-jingang");
}

// �԰�������
void do_heal()
{
	object me=this_object();
	if(me->query("hp") < me->query("max_hp")/2)
	{
		message_vision(HIG "$N�ϥX������]�������u�B�ѰҪ�ù�ءv�A����p�����t�I��F���W���U�Ӥ�媺�޹D�C\n" NOR,me);
		me->heal("hp",100);
		me->add_busy(1);
	} else {
		if(me->is_busy() ) return;
		if(me->query_temp("do_attack") ) return;
		message_vision(HIR "$N�⤤���F�ӡu��N����v��L�A�n�ɧ�ռ@�W�I�I\n" NOR,me);
		me->set_temp("do_attack",1);	// mark �קK�h������
		me->add_temp("apply/damage",50);
		me->add_temp("apply/hit",300);
			me->attack();
			me->attack();
		me->add_temp("apply/hit",-300);
		me->add_temp("apply/damage",-50);
		me->set_temp("do_attack",0);
	}

}

// �l���ˮ`
varargs int receive_damage(string type, int damage, object who)
{
        int val;

        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

		if(random(100)<30)
		{
			damage/=2;
			message_vision(HIY "$N���p��ꪺ�@������ƸѤF�j�b�ˮ`�C\n" NOR,this_object());

		}

		if(objectp(who) )
			::receive_damage(type,damage,who);
		else
			::receive_damage(type,damage,who);
		return damage;
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

        ob->add("popularity",2);
        ::die();

        return;
}
