#include <ansi.h>

inherit NPC;

void create()
{
  set_name(HIW"�L�W�ѤH"NOR, ({"unnamed old-man","man","old","unnamed"}) );
  set("long",@LONG
�j�Ӫ��޲z���C
LONG
);
  set("race", "human");
  set("unit","��");
  set("age",54); 
  set("no_fight",1);  set("level",30); 
  set("chat_chance",4);
  set("chat_msg",({
  "�L�W�ѤH��:�ڨ{�l�n�j�� ~ ~ ! !\n",
  "�L�W�ѤH��:�z�i�H���ڪF��Y��,�ڷ|�H§���ت��C\n",
  "�L�W�ѤH�y�F�X�n�A����n�������n  . ..\n",
}));
set_skill("unarmed",50);
set_skill("staff",60);
set_skill("dodge",120);
set_skill("parry",70); 
setup();
carry_object(__DIR__"red-staff")->wield(); 
add_money("coin",200);
} 
int accept_object(object who,object ob)
{
object blade;

       if(ob->name()!="�C�Y")
  
       return 0; 
       else {
     
       if(this_object()->query_temp("give_blade"))
       {
       command("think �ڤw���z���H�F..�ӫ������o��O..?");
       command("think"+who->query("id"));
       command("say �n�a ! �ѤҴN�A�e�@�˺��_���A !");
       return 0;
} 
message_vision("$N���F�L�W�ѤH�@���C�Y\n",who,ob);
  command("�L�W�ѤH���_�F�C�Y�A�������Y�F�_��\n");
  command("smile"+who->query("id"));
  command("�L�W�ѤH��:���§A�A���M���O�ܹ��A���]���|���j�F\n");
  command("think"+who->query("id"));
  (: command("hmm"):);
  blade=new(__DIR__"blade");
  blade->move(who);
       set_temp("give_blade",1);
       start_busy(5);
//call_out("delay",600,this_object());
       return 1;
       }
}

void reset()
{
           int old;  
           if(!old) return; 
           set("chat_chance",5);
           set("chat_msg",({
           "�L�W�ѤH���{�l�S�j�F�_�Ӫ��ˤl...?\n",
           "�L�W�ѤH�ݵ۸��W���H�A��b�|�ۨ{�l�A�L�ڷL�͡A�����S�X���ݪ�����\n",
           }) );
             return 0; 
}

