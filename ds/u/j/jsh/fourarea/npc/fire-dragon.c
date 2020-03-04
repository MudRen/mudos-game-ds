#include <ansi.h>
inherit NPC;

void create()
{
             set_name(HIR" 火  龍"NOR,({"fire dragon","dragon"}) );        
             set("title",HIW"聖炎"NOR);             set("long",@LONG
火龍是聖炎潭裡的守護獸，千百年來駐守在此，身上有著解開
元素之謎的關鍵物品。
LONG    
        );
        set("race", "野獸");    
        set("unit","隻");
        set("age",1000+random(123));
          set("level",40);
        set("attitude", "heroism");    
        set("limbs", ({ "頭部", "腹部","胸部","巨爪","龍尾","背鱗" }) ); 
        set("verbs", ({ "bite","claw" }) );
        add("addition_armor",200);
        add("addition_damage",230);
        set("chat_chance_combat",50);
        set("chat_chance", 10);
        setup();
}
void die()
{
   object ob,obj;
   obj=new(__DIR__"obj/liver");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
   HIR"\n【 聖  炎  潭 】  "+ob->name(1)+"  取   得   火   龍   肝   了。\n\n"+NOR
        ,users());
        ob->add("popularity",3); //聲望
     message_vision( "$N"+HIR"發出了無言的怒火，在火炬的深處行成了一謎物 . . ." NOR ,this_object() );
     obj->move(environment(this_object() ) );
    obj=new(__DIR__"obj/liver");
        ::die();
        return;
}

