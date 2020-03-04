#include <ansi.h>
inherit NPC;

void create() {
    set_name(HIY "���L" NOR,({"Yang goo","goo"}) );
    set
        ("title",HIC "�j��" NOR);
    set
        ("long",
                "�u���L�v�O�׫n�s�����H�ӥD�H���@�A�ͩʥ��H�A�]��������k����A\n"
                "�ϱo�L�֤F�k�u�C������s�{�_�J�A�ϦӪZ�\\�j�i�A���Z�L���@���@����C\n"
                "�ثe�P��v��d���p�s�k�@�_�P��A�]���X�칲�H�A�ͬ��Q���w�h�C\n"
        );
    set
        ("race", "human");
    set
        ("unit","��");
    set
        ("age", 38);
    set
        ("level", 45);
    set
        ("max_ap",6000);
    set
        ("max_hp",12000);
    set
        ("combat_exp",540000);
    set
        ("limbs", ( { "�Y��", "����","�ݳ�","�ⳡ","�}��"
                    }
                  ) );
    set
        ("chat_chance", 30);
    set
        ("chat_msg", ( {
                   (: command("exert ninning-force") :),
                               }
                             ));
    set
        ("chat_chance_combat", 50);
    set
        ("chat_msg_combat", ( {
                          (: command("exert heavy-sword") :),
                                          (: command("exert heavy-sword") :),
                                          (: command("exert heavy-sword") :),
                                          (: command("wield sword" ):),
                                          (: command("exert ninning-force heal") :),
                                          (: command("exert ninning-force heal") :),
                                      }
                                    ));

    set_skill("heavy-sword",100);
    set_skill("ninning-force",100);
    set_skill("anlan-fist",100);
    set_skill("force",100);
    setup();
    carry_object(__DIR__"sword")->wield();
      carry_object("/open/world1/moonhide/area/under/npc/obj/fire-fruit.c");
    carry_object(__DIR__"key");
	set_temp("apply/armor", 300);
	set_temp("apply/damage", 200);
}
int special_attack(object me,object target,int hitchance) {
    int tdex;
    if(!me || !target)
        return 0;
    // 30%���v�o�ʯS��
    if( random(100) < 70 )
        return 0;

    //tdex = target->query_dex();
    //tcon = target->query_con();

    //if(random(hitchance*20) > tdex+tcon) {
        message_vision(HIY"\n$N"+HIW"�y�⳱�����w�A���M�ϥX"HIB"�f�M�P��x"HIW"���u��ͨ��סv\n"
                        +HIW"$n�Q�ɶ��P����ƹD���p���x�l�A�@�D���O��@�D�ٱj�I\n"
                       +HIR"$n�Q�_�h�ƤQ�B�A�L�گݤf���O�ۤw���A��...\n\n"NOR, me, target);
         target->receive_damage("hp", query_damage()/2 + random(query_damage()), this_object());
        return 1;
	/*
    } else {
        message_vision(HIY"\n$N"+HIW"�H���֪��B�աA�H�֥��C....\n"
                       +HIG"�X�ۡI�@��"+HIC"�d��Y"+HIW"���V$n..\n"
                       +HIW"$n���p�Q�Ƥs�ˮ����O�q�H���I\n"
                       +HIR"�������j�A�R���嵷�A�Φ����СI\n\n"+NOR,me,target);
        target->receive_damage("hp",uery_damage()*3 + random(query_damage()), this_object());
        return 1;
    }
	*/
}
void die() {
    object ob;
    if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
    
if( !ob ) {
        ::die();
        return;
    }

    message("world:world1:vision",
              HIR"\n\n�i�����H�ӡj"+HIY " ��g�u����L�v ���L ���M�Q"+ob->name(1)+"�����F�I�I\n\n"+NOR
            ,users());
    ob->add("popularity",3);
    // �P�H�C�R
    if(ob->query_temp("gumu_sword")==2) {
        "/open/world1/tmr/gumu/xuanya.c"->open_sword();
        ob->delete_temp("gumu_sword");
        message_vision("�A�n��ı�o�N������_�����Ʊ��n�o�ͤF�C\n",ob);
    } else {
        ob->set_temp("gumu_sword", 1);
        }
//    message_vision( "$N"+HIR  "�r�R�F�@�f�A��A�Ⲵ��������"+HIW"�A���� . . . . �N����˦a�F . . "NOR ,this_object() );
    ::die();
    return;
}

