inherit NPC;

void create()
{
        set_name("鬼鵰",({"ghost chisel","chisel"}) );
        set("long",@LONG
一隻高約成人的大鳥，渾身羽毛淨做紫黑色，兩眼火紅似血，給人不
好惹的感覺。
LONG	
	);
        set("race", "野獸");    
        set("unit","隻");
        set("age",20);
        set("level",20);
        set("attitude", "heroism");    
        set("limbs", ({ "頭部", "腹部","胸部","巨爪","尾巴" }) ); 
        set("verbs", ({ "bite","claw" }) );
        setup();
	carry_object(__DIR__"obj/meat");
}
