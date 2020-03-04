inherit NPC;
void create()
{
	set_name("老鼠", ({"rat"}) );
	set("long", "會吱吱叫的老鼠，會四處跑的老鼠，繁延迅速的老鼠。\n");
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "尾巴", "腳"})); //受攻部位
	set("verbs", ({ "bite","claw"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 1);
	set("level",random(5));
	set("int",1);
	set("dex",10);
        set("chat_chance", 3);
        set("chat_msg", ({
             (: random_move :),
              }));
	set("env/wimpy", 50);
	setup();
}
void die()
{
        object ob,obj;
	int temp;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
	temp = ob->query_temp("police");
        if( !ob ) 
        {
                ::die();
                return;
        }
	if( ob->query_temp("police_area")!=1) return; 
	temp++;
	ob->set_temp("police",temp);
        ::die();
        return;
}