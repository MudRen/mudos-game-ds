#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�q�x",({"duan hong","duan","hong"}) );
        set("long",@LONG
�e�����C�t�A�����C�t�T������C�D�μC���̰����q�E
LONG);
        set("title",HIW"�e���C�t"NOR); 
        set("nickname","��C�s��");        
        set("age",40+random(5));
        set("level",80);
        set("gender","�k��");
        set("attitude", "peaceful");  
        set_skill("fogseven", 100+random(50)); 
        set_skill("dodge", 100+random(50)); 
        set_skill("unarmed", 100+random(50)); 
        set_skill("sword", 100+random(50)); 
        set_skill("star-sword", 100+random(50));
        set_skill("sorgi_sword", 100+random(50)); 
        set_skill("moon_force", 100+random(50)); 
        set_skill("sorsin_force", 100+random(50));
        set_skill("force", 100+random(50));
        map_skill("dodge","fogseven");
        map_skill("sword","star-sword");
        set("Merits/bar",8+random(10));
        set("int",175);
        set("addition_armor",50+random(100));
        set("Merits/wit",8+random(4));
        set("addition_damage",50+random(100));
        add("apply/hit",80+random(30));
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
                (: command ("exert moon-force shadow") :),
        }));
        setup();
}

varargs int receive_damage(string type, int damage, object who)
{
        int val;
        if(this_object()->is_fighting() ) {
        if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
        if( type!="hp" && type!="mp" && type!="ap" )
                error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
        if( objectp(who) && type=="hp") set_temp("last_damage_from", who);

                   damage/=10000;
                   message_vision(HIC"\n$N���K�몺����w�ͥͪ��N��է����ƸѡI�I\n" NOR,this_object());
                }

                if(objectp(who) )
                        ::receive_damage(type,damage,who);
                else
                        ::receive_damage(type,damage);
                return damage;
}

