#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"�����p����"NOR,({ "left-small man","left","man" }));
        set("long",
                "�L�O�@�ӤQ���j�����H,���b���~�e�Ѧb�åЫ۪Ū���W,\n"
                "�ҥH�K��a�F�åЫ۪Ũ����åЫ۪ŭ��Φ����åЫ۪Ū�\n"
                " ���k��P�ѻ��G���Y�æC�����H���ĤG���ȡC\n"
        );
        set("nickname",HIR"�v���G�M�y"NOR);
        set("age",49);
        set("level",50);
        set("gender", "�k��");
        set("str",100);                  
        set("dex",80);                  
        set("con",130);                
        set("int",70);                  
        set("combat_exp",6000);         
        set("evil",-10);  
        set_skill("blade",100);          
        set_skill("parry",100);          
        set_skill("dodge",100);  
        set_skill("perception",50);
        set_skill("combat",100);    
        set_skill("left-blade",100);   
        set_skill("sky-air",100); 
        set("chat_chance",20);
        set("chat_msg", ({
 name()+"�h�h���ݵۤ�W���M�o�b�C\n",
 name()+"���بI��C\n",
 (: command("exert left-blade") :),
}) );
        set("chat_chance_combat",70);
        set("chat_msg_combat", ({
        (: command("exert left-blade") :),
        (: command("wield blade") :),
}) );

    setup();
        carry_object(__DIR__"wp/left_blade")->wield();
        carry_object(__DIR__"eq/left_surcoat")->wear();
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
message("world:world1:vision", HIW"\n ����j�����G [ �ǻD�߮���H"HIC"�v�����G�M�y "HIY"�����p����"NOR HIW"�ѵ��F"HIR + ob->name(1) + " "NOR HIW"�C ] \n\n"NOR, users());
        ob->add("popularity", 3); //�n��
 tell_object(ob,HIW"(�]���A�����F�����p�����A�ҥH�A�o��F 3 �I�n��C)\n"NOR);
}
        ::die();
        return;
}

