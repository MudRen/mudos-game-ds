//updated by alickyuen on 26/12

inherit NPC;

void create()
{
	set_name("石像", ({"stone-statue","statue"}) );
	set("long", "一個石製的機器人，看起來很兇的樣子.\n");
	set("race","機器人");
	set("age", 24);
	set("level", 25);
set_skill("parry", 100);
set_skill("dodge", 100);
set("attitude", "peaceful");
	setup();
carry_object(__DIR__"eq/garmor.c")->wear();
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
 tell_object(ob,"  突然你仿佛聽到月影神像處有一些聲音。\n"
//"你得到了一點聲望！\n"
);
   //     ob->add("popularity",1); //聲望
ob->set_temp("killgoda",1);
//ob->delete_temp("readdia");
        ::die();
        //destruct(this_object());
        return;
}