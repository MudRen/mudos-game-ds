#include <ansi.h>
inherit NPC;
void create()
{
       set_name( "�p�Q" ,({ "lar ba master","master","ba" }) );
       set("title",HIC "�j������" NOR);
         set("long",@LONG
�p�Q�O�Ӯc�����j������,��Z�����j,�@�W�֦��H�ॴ�ѥL,�A��
�O�ݥL�N�Pı�ܤj�����O,���Aı�o�٬O�O�b�o�������n.
LONG    
);
         set("race", "�H��");    
         set("gender", "�k��");
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

HIR"\n�i�Z�L�ֳ��j"+HIC "�j������ "HIY"�p�Q "NOR"���b "+ob->name(1)+" ���⤤�C\n\n"+NOR
        ,users());


            ob->add("popularity",3); //�n��
         ::die();
         return;
}

