#include <ansi2.h>
inherit NPC; 
int aa;
void create()
{
        set_name("����",({ "villager" }) );
        set("long","�@�ө~��b�y�����������A���G�`�`�X�h�y�ɪ��W�A���֥H�k�f�E\n");
        set("race","�H��");
        set("title",HIR"�y����"NOR);
        set("age",20+random(15));
        set("level",30+random(10));
        set("str",40+random(10)); 
        set("dex",random(30)+20);
        set("int",40); 
        set("addition_armor",100);
        set("addition_shield",100);        set("max_hp",6000+random(1500));
        set("attitude","friendly");
        set_skill("dodge",50+random(40));
        set_skill("unarmed",20+random(70));
        set_skill("parry",random(50)+30);
   setup();  
     for (aa=0;aa<3;aa++)
     { 
       switch( random(14) )
       {
        case 1: carry_object(__DIR__"eq/f_hat")->wear(); break;
        case 2: carry_object(__DIR__"eq/f_neck")->wear(); break;
        case 3: carry_object(__DIR__"eq/f_cloth")->wear(); break;
        case 4: carry_object(__DIR__"eq/f_armor")->wear(); break; 
        case 5: carry_object(__DIR__"eq/f_cloak")->wear(); break;
        case 6: carry_object(__DIR__"eq/f_wrists")->wear(); break;
        case 7: carry_object(__DIR__"eq/f_gloves")->wear(); break;
        case 8: carry_object(__DIR__"eq/f_ring")->wear(); break;
        case 9: carry_object(__DIR__"eq/f_waist")->wear(); break;
        case 10: carry_object(__DIR__"eq/f_pants")->wear(); break; 
        case 11: carry_object(__DIR__"eq/f_leg")->wear(); break;
        case 12: carry_object(__DIR__"eq/f_boots")->wear(); break;
       }
     } 
   add_money("coin",800+random(500));           
}

void init()
{     
   object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}


void greeting(object ob)
{
 object me = this_player();
 if ( !me || environment(me) != environment() ) return; 
 
   if ( !me->query("quest/ko_fox") ){
   command("sula " + me->query("id"));
   command("say �S�i�h�L���ު��H���t�ӧڭ��y�����O�H");
   } else if ( me->query("quest/ko_fox") >= 1000 ){
   command("wa");
   command("say �o��" + RANK_D->query_respect(ob) + "�u�O��²��A���F�o��h�����W�I" );    
   return;
   } else if ( me->query("quest/ko_fox") >= 10000 ){
   command("kneel " + me->query("id"));
   command("say �A�u�O�F�`�A��ѨM���o��h�����W�٦w�M�L�~�I" );    
   return;
   } if ( me->query_temp("ko_fox_nine") ){
   command("walileh "+me->query("id"));
   command("say �A..�~�M��ʦL�E��.." );     
   command("fear "+me->query("id"));    
   return;
   } 
}


