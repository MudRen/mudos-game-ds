#include <ansi.h>
inherit NPC;
void create()
{
        set_name("食人魚群",({"man-eating fish","fish"}) );
        set("long","這是一群食人魚，在牠嘴裡上下二排長了尖長的牙齒，十分嚇人。\n");
        set("race", "野獸");    
        set("unit","群");
        set("age",2);
        set("level",1);
        set("attitude", "aggressive");
        set("exp",10*random(120));

        set_skill("swim",50+random(20));
        set("limbs", ({ "頭部", "身體", "前鯕", "尾巴" }) ); //受攻部位
        set("verbs", ({ "bite" }) );                         //攻擊方式
        setup();
}
void die()
{
        int i;
        object ob,obj;
        obj=this_object();
        i=obj->query("die");
        obj->set("die",i+1);
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) return;
        if(obj->query("die")>9)
        {
          ::die();
        }
        else {
          message_vision("\n\n  其中一隻食人魚翻了過來, 浮到水面上, 抽慉了幾下...。\n",ob);
          message_vision("\n  食人魚死了。\n\n",ob);
          obj->set("hp",obj->query("max_hp"));
          obj->set("mp",obj->query("max_mp"));
          obj->set("ap",obj->query("max_ap"));
          obj->set("name",chinese_number(10-obj->query("die"))+"隻食人魚");
          kill_ob(ob);
        }
}
