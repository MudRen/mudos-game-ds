#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIG"�ѻ��G���Y"NOR,({ "sky-two man","sky","man" }));
        set("long",
                "�L�O�@��өʩt�@�N�ƪ��H,�`���L�`�O���f����......\n"
                "�q�p�N���W�S���ʮ�P�W�H�����..�b28���ɫi���ѯT�s\n"
                "�N�ѯT����..�⮩�F�s���Z��:�ѯT�ٯ��y���k��P�����p����\n"
                "�æC�����H���ĤG���ȡC\n"
        );
        set("nickname",HIY"�t�v�����y"NOR);
        set("age",46);
        set("level",50);
        set("gender", "�k��");
        set("str",120);                  
        set("dex",90);                  
        set("con",100);                
        set("int",70);                  
        set("exp",29600);        
        set("combat_exp",6000);         
        set("evil",-10);  
        set_skill("blade",100);          
        set_skill("parry",100);          
        set_skill("dodge",100);  
        set_skill("perception",50);
        set_skill("darkfast-blade",100);
        set_skill("combat",100);     
        set("chat_chance",10);
        set("chat_msg", ({
 "�ѻ��G���Y�N�N�ݵۤ�W���M..�n��������и�",
   (: command("sigh") :),
(: command("exert darkfast-blade") :),
}) );
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
        (: command("exert darkfast-blade") :),
        (: command("wield blade") :),
}) );

    setup();
        carry_object(__DIR__"wp/wolf_blade")->wield();
        carry_object(__DIR__"eq/wolf_surcoat")->wear();
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
        {        
message("world:world1:vision", HIW"\n ����j�����G [ �ǻD�߮���H"HIY"�ѯT�ٯ��y"HIG"�ѻ��G���Y"NOR HIW"�ѵ��F"HIR + ob->name(1) + " "NOR HIW"�C ] \n\n"NOR, users());
        ob->add("popularity", 3); //�n��
 tell_object(ob,HIW"(�]���A�����F�ѻ��G�T�Y�A�ҥH�A�o��F 3 �I�n��C)\n"NOR);
}
        ::die();
        return;
}

