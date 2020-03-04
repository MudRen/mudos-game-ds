#include <ansi.h>
inherit NPC;
void create()
{
	set_name("盧賢",({"loo shang","shang","loo"}));
	set("long" ,
    "他就是平時幫著堂主雲天翔處理堂中大小事務的人, 此人武功\高強, 曾經\n"
    "是一個山寨的寨主, 但是他的臉上絲毫沒有霸氣. 聽說在許\多\年前, 他曾經和\n"
    "雲天翔交鋒過, 經過數十招後, 終於敗陣, 因而被雲天翔收服, 雲天翔當初也\n"
    "在創立向雲堂之初, 而盧賢便成為副堂主了.\n"
    );
	set("attitude", "friendly"); 
	set("level",35);
	set("age", 48);
	set("title",HIC"向雲堂"NOR"副堂主");
	set("class1","向雲堂");
	create_family("向雲堂",1,"副堂主");
	set("chat_chance",5);
	set("chat_msg",({"盧賢低著頭, 不知道在沉思什麼.",
			 (:command,"hmm":),
			 (:command,"say 這位朋友...呃.":),
			 (:command,"exert cloudblade":),
			 (:command,"exert cloudsteps":),
			 (:command,"exert cloudfist":)}));
	set("chat_chance_combat",80);
	set("chat_msg_combat",({(:command,"exert cloudblade":),
				(:command,"exert cloudforce refresh":)}));
	set_skill("unarmed",70);
	set_skill("blade",80);
	set_skill("dodge",85);
	set_skill("force",70);
	set_skill("parry",60);
	set_skill("cloudblade",85);
	set_skill("cloudfist",80);
	set_skill("cloudforce",60);
	set_skill("cloudsteps",80);
	set("guild_gifts",({3,4,6,7}));
	setup();
	carry_object(__DIR__"eq/boots")->wear();
	carry_object(__DIR__"eq/s_blade")->wield();
	carry_object(__DIR__"eq/cloth")->wear();
	carry_object(__DIR__"eq/gloves")->wear();
	set_heart_beat(1);
}
void heart_beat()
{
 object *enemy;
 object me;
 int damage,roll,a,b,d;
 int i,c,hp,max_hp;
 me=this_player();
 roll = random(16);
 if(me->is_fighting())
 {
  enemy = me->query_enemy();
  i = random(sizeof(enemy));
  enemy[i]=present(enemy[i],environment(me));
  c=enemy[i]->query_temp("apply/armor");
  max_hp=me->query("max_hp");
  hp=me->query("hp");
  if( me->is_fighting() && hp < (max_hp/2) && roll < 4)
  {
   if( roll > 2 )
   {
    damage=200+random(50)-c;
    if(damage < 50) damage=40+random(20);
    this_player()->add("ap",-30-random(10));
    message_vision(HIC"\n$N大喝: 看來你真是不要命了! 接我成名絕技 ------ \n\n"NOR+
                   "    『  "+HIY+"如    "+HIC+"雷    "+HIR+"貫    "+HIM+"耳    "+NOR+"  』！！\n\n"+
                   HIW"     驚天刀氣直向$n狂劈而去!!"+HIR+"  造成$n一處非常嚴重的劈傷!\n"NOR,me,enemy[i]);
    damage = COMBAT_D->Merits_damage(me,enemy[i],damage,"bar");
    enemy[i]->receive_damage("hp",damage,me);
    COMBAT_D->report_status(enemy[i],1);
    enemy[i]->add_busy(1);
    me->add_busy(2);
   }
   else if( roll < 3 )
   {
    this_player()->add("ap",-30-random(10));
    message_vision(HIC"\n$N大喝: 看來你真是不要命了! 接我成名絕技 ------ \n\n"NOR+
                   "    『  "+HIY+"如    "+HIC+"雷    "+HIR+"貫    "+HIM+"耳    "+NOR+"  』！！\n\n"+
                   HIW"     驚天刀氣直向$n狂劈而去!!"+CYN+"  但是$n翻身一轉, 避開了此殺招.\n"NOR,me,enemy[i]);
    me->add_busy(1);
   }
  }
 }
 ::heart_beat();
}

