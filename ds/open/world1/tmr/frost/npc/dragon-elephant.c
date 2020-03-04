#include <ansi.h>
inherit NPC;

void kill_ob(object ob)
{
	object *guard;
	int i;
	if(!ob || ob==this_object()) return;
	::kill_ob(ob);

    guard = all_inventory(environment(this_object()));
	for(i=0;i<sizeof(guard);i++) {
		if( !guard[i]->id("5f_guard") ) continue;
		if( guard[i] == this_object() ) continue;
		if( guard[i]->is_killing(ob->id()) ) continue;

		// guard to kill
		guard[i]->kill_ob(ob);
	}
}

void combat_ai() {
                if( is_busy() ) return;
                if( query_temp("do_attack") ) return;
                message_vision(HIC "�s�H�@�n��q�A�ĤW�ӤF�X�B�I�I\n" NOR, this_object());
                set_temp("do_attack",1);    // mark �קK�h������
                add_temp("apply/damage",50);
                add_temp("apply/hit",300);
                        attack();
                        attack();
                add_temp("apply/hit",-300);
                add_temp("apply/damage",-50);
                delete_temp("do_attack");
}

void create()
{
        set_name(HIC "�s�H" NOR,({"dragon elephant","dragon", "elephant", "5f_guard"}) );
        set("title",CYN "�F��C�J" NOR);
        set("long",@LONG
�G�Q�K�J�A�O����j�N�Ѥ�Ǯa�b�[���ѶH�ɡA����B��
�g�L���ϰ쪺�ڬP�����B��w�üЧӪ��G�Q�K�ӬP�s�y�C�n
�ѡm�|�Ѧ��F�`�n�١A�u�F�訤�B���B�¡B�СB�ߡB���B��
�C�J�A��Φp�s�A�ꥪ�C�s�C�n�褫�B���B�h�B�P�B�i�B�l�B
�H�C�J�A��Φp�L���A��e�����C��諶�B���B�G�B���B��
�B�C�B�ѤC�J�A��Φp��A��k�ժ�C�_���B���B�k�B��
�B�M�B�ǡB���C�J�A��Φp�t�D�A���ȪZ�v�C�G�Q�K�J�P
�x�A�U���W�m�B�A��M¾�x�C
LONG    
        );
        set("race", "beast");    
        set("unit","��");
        set("age", 600);
        set("level", 45);
        set("attitude", "aggressive");
        set("attitude", "heroism");    
        set("limbs", ({ "�Y��", "����","�ݳ�","����","�s��","�I��" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_hp", 5000);
        add("addition_armor", 90);
        add("addition_damage", 80);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (:combat_ai:), 
          }) );        
        setup();
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
        set_temp("apply/damage",50);
        if(random(10)<8) carry_object(__DIR__"eq/dragon-elephant-wrists")->wear();
        else carry_object(__DIR__"eq/dragon-elephant-wrists2")->wear();
}


