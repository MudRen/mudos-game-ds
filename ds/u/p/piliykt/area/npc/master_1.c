#include <ansi.h>
inherit NPC;
void create()
{
       set_name( "雷霸" ,({ "lar ba master","master","ba" }) );
       set("title",HIC "大內高手" NOR);
         set("long",@LONG
雷霸是皇宮中的大內高手,其武藝高強,世上少有人能打敗他,你光
是看他就感覺很大的壓力,讓你覺得還是別在這撒野的好.
LONG    
);
         set("race", "人類");    
         set("gender", "男性");
         set("age",45);
         set("level",45);
         add("addition_armor",110);
         add("addition_damage",160);
         set("str", 100);
         set("con", 99);
         set_skill("unarmed", 100);
         set_skill("force", 100);
         set_skill("dodge", 60);
         set_skill("parry", 80);
         set_skill("combat", 99);
         set_skill("perception", 40);
      
setup();
         carry_object(__DIR__"eq/armor_1.c")->wear();
         carry_object(__DIR__"eq/boots_1.c")->wear();
}
void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob ) 
         {
                 ::die();
                 return;
         }
         message("world:world1:vision",

HIR"\n【武林快報】"+HIC "大內高手 "HIY"雷霸 "NOR"死在 "+ob->name(1)+" 的手中。\n\n"+NOR
        ,users());


            ob->add("popularity",3); //聲望
         ::die();
         return;
}

