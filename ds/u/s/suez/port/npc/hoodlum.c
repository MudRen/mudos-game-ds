inherit NPC;
#include <ansi.h>
void create()
{
       set_name("���}���l",({"hoodlum"}));
       set("long","�o�O�Ӧ�ˤ���A�������z�S�X�q�f�Τ������֦~�C\n");
       set("gender","�k��");
       set("age", 15+random(7));
       set("level", 1+random(5));

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("snort"):),
             }));

       set("chat_chance_combat",17);
       set("chat_msg_combat", ({
       (:command("grin"):)
        }) );
    
        setup(); 
       carry_object( __DIR__"wp/knife")->wield();
        carry_object( __DIR__"eq/cloth")->wear();         

}
void attack()    
{
        int hp,max_hp,temp ;
	temp = this_player()->query_temp("police");
        hp=this_object()->query("hp");
        max_hp=this_object()->query("max_hp");
        if(hp < max_hp/5)
	{
        	say (HIB"�֦~���������L�A�A����X���k���F�C\n"NOR); 
	        destruct(this_object());
		if( this_player()->query_temp("police_area")!=2) return; 
		temp = temp + 3;
		this_player()->set_temp("police",temp);
		return;
	}
        return ;
}
void die()
{
        object ob,obj;
	int temp,evil;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
	temp = ob->query_temp("police");
	evil = ob->query("evil");
        if( !ob ) 
        {
                ::die();
                return;
        }
	if( ob->query_temp("police_area")!=2) return; 
	temp = temp + 3;
	evil = evil + 10;
	ob->set_temp("police",temp);
	ob->set("evil",evil);
        say( ob->name()+" ����N�������F�C"  );  
        ::die();
        return;
}