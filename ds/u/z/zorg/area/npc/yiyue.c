#include <ansi.h>
inherit NPC;

void create()
{
        set_name( "�ʤ�" , ({"yi yue","yi","yue","yiyue"}) );
        set("long",
"�A���e�O�@��R���F�𪺤k�ġA�o�]�٪����X���G���A�i�H�Pı�쥦���X�n�A
�Sı�o�o���@�Y�X�v�Y���Y�L�����b�A���y�W�ϧA���@�ص�۪��Pı�A
���ѱo�Ϫ��A�ߤU�@����M�C��A�յۥh�ݦo���y�A�A�u���b�䪺�y�J�A
�@���p���������A���M���v�ݤ��M���A����M�e���q�R���ۡC\n");       
        set("race", "�H��"); 
        set("gender", "�k��"); 
        set("age",17); 
        set("env/wimpy", 45);        
        set("attitude", "friendly");
        set("level", 12+random(5)+random(5));
        set("evil", -999);
        set("combat_exp",2500);
    set("chat_chance", 3 );  
  set("chat_msg", ({   
(: this_object(), "random_move" :),     //�|�ۤv����
"�ʤ�������ĤF�@�f��\n"
"�ʤ�H�H����A�@��\n" 
   }) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({ 
        (:command("say ..."):),
        (:command("angry"):),
        }) );
        setup(); 
        carry_object(__DIR__"eq/ring.c")->wear();
        carry_object(__DIR__"eq/boots.c")->wear();
}


