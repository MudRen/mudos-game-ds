#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIW+BLK"鳥人淫者"NOR, ({"rob"}) );
  set("long",@LONG
鳥中之王。
LONG
);
  set("gender", "男生");  
  set("race", "人類");
  set("age",20);
  set("level",1);
  set("attitude", "aggressive");
  set("evil",1000000);
    setup();

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
  message("world:world1:vision","\n\n\t"HIY"號稱"HIG"「風華瀟灑」「絕代鳥人」「Zmud 4.62」"HIY"的"BLK"暗夜淫者"NOR"(Rob)"HIY"，終於被消滅了！！\n\n\t"HIW+BLK"鳥人淫者"NOR"(Rob)"HIW"說道： "HIC"唉！.....鳥也有錯嗎？\n\t"HIW"洛"NOR"(Deaon)"HIW"："HIC"完全有錯，你說對不對啊？Ｄ頭？\n\t"HIW"Ｄ頭"NOR"(Dkfum)："HIC"沒錯沒錯，你說對不對阿？Exri、Piliykt？\n\t"HIW"牙膏與槍王齊口同聲說："HIC"鳥人就是鳥人，別解釋了Rob！！\n\n\t"HIW"這時"BLK"鳥人淫者"NOR"(Rob)"HIW"唱起了當時某人的成名曲："HIC"我是一隻小小小小鳥∼..然後就此安息了！！\n\n"NOR
       ,users());
  ob->add("popularity",500000);      
  
   ::die();
  return;
}

