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
                message_vision(HIC "龍象一聲怒吼，衝上來了幾步！！\n" NOR, this_object());
                set_temp("do_attack",1);    // mark 避免多次攻擊
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
        set_name(HIC "龍象" NOR,({"dragon elephant","dragon", "elephant", "5f_guard"}) );
        set("title",CYN "東方七宿" NOR);
        set("long",@LONG
二十八宿，是中國古代天文學家在觀測天象時，對日月運行
經過的區域的�甯P劃分、選定並標志的二十八個星群座。緯
書《尚書考靈曜》稱，「東方角、亢、氐、房、心、尾、箕
七宿，其形如龍，曰左青龍。南方井、鬼、柳、星、張、翼、
軫七宿，其形如鶉鳥，曰前朱雀。西方奎、婁、胃、昴、畢
、觜、參七宿，其形如虎，曰右白虎。北方斗、牛、女、虛
、危、室、壁七宿，其形如龜蛇，曰後玄武」。二十八宿星
官，各有名姓、服色和職掌。
LONG    
        );
        set("race", "beast");    
        set("unit","隻");
        set("age", 600);
        set("level", 45);
        set("attitude", "aggressive");
        set("attitude", "heroism");    
        set("limbs", ({ "頭部", "腹部","胸部","巨爪","龍尾","背鱗" }) ); 
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


