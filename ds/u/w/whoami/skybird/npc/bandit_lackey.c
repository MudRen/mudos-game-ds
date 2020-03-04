#include <ansi.h>
inherit NPC; 
void combat_ai();  
void identify(); 
string *show_msg = ({
HIC"�A�oı�|�P���H�ݧA���������G���Ǥ���K�K\n"NOR,
WHT"�j�a����A�o�X�޲������e�K�K�ݨӬO�Ӷ}�ȤF�K�K\n"NOR,
HIC"��A�o�{�ƺA����A�ǳƶ}�Ȫ��P�ɡA�q�I��Q�H��F�@�O�e�ҡA���۴N���F�L�h�K�K\n"NOR,
WHT"�A�b�b���b�����A����ť��o�̦b�Q�רǤ���K�K\n"NOR,
HIY"�p���o�ҡG�K�K�K���ѳo�ӳf��n�������K\n"NOR,
HIG"�p���o�A�G��L��h����D�A���L�������ַݧa�I"BLK"\n"NOR,
HIY"�p���o�ҡG�n�D�N�A�N�o���a��\n"NOR,
HIG"�p���o�A�G�o�˧ڭ̪�¾�����ӷ|�T�Ÿ��a�A�K�K�K\n"NOR, 
HIW+BLK"�A�@�C�}�����A�A�oı�A�w�g��F�@�ӧA�������{�Ѫ��a��F�K�K\n"NOR,});
void create()
{
 set_name("�p���o",({"bandit's lackey","lackey","bandit"}));
 set("long",@LONG  
�b�A���e���N�O�H�B���T�Q�U�s�s�D���ȤH���]���g��, ��
�D�D�Q�U�s�����g��U�U�����L��, ���o���O�k�H. �ݨӳo
�ӶǻD���D�ťިӭ�. 
LONG);

 set("title",YEL"�Q�U�s�s��"NOR);
 set("age",23+random(15));
 set("gender","�k��");
 set("level",25);  
 set("max_hp",8000+random(3000)); 
 set("max_ap",8000); 
 set("str",75+random(18)); 
 set("dex",75);  
 set("Merits/bar",5+random(3));  
 set("Merits/wit",5+random(3)); 
 set_temp("apply/damage",85+random(30)); 
 set_temp("apply/hit",15+random(30));
 set_skill("sword",80+random(15)); 
 set_skill("blade",80+random(15));
 set_skill("whip",80+random(15));
 set_skill("dagger",80+random(15));
 set_skill("hammer",80+random(15));
 set_skill("fork",80+random(15));
 set_skill("throwing",80+random(15));
 set_skill("dodge",70+random(15)); 
 set_skill("parry",70+random(15)); 
 set_skill("block",70+random(15));  
 set("can_speak", 1); 
 set_temp("Notwarnpc",1);
 setup(); 
/* 
 carry_object(__DIR__"silk_cloth")->wear();
 carry_object(__DIR__"eq/large_blade")->wield();
 carry_object("/open/world1/eq/moon_skirt")->wear();
*/
}

void init()
{
  object me=this_player(),ob=this_object();
 
  ::init(); 
  if ( !me->query("class1") ) return;
  if ( me->query_temp("invis") ) return;
  ob->kill_ob(me);
  me->kill_ob(ob);

} 
 
int talk_action()
{
        object me=this_player(),ob=this_object();

  if( me->query("gender") == "�k��" || me->is_fighting() || me->query("class1") ){
  command("say �p�٬O���ѨM�p�ۤv�����D�a..");
  } else if( me->query("gender") == "�k��" && !me->query("class1") ){
  command("hehe "+me->query("id"));
  ob->set_temp("kidnap",1);
  me->set_temp("block_msg/all",1);
  me->move(__DIR__"../bandit13");
  me->start_busy(20);
  me->add_temp("block",1);
  call_out("kidnap", 2, this_object());
  }

  return 1;
}

void kidnap()
{
  object me=this_player(),ob=this_object();
  int i=ob->query_temp("kidnap");
  string msg = show_msg[i-1];
  me->delete_temp("block_msg/all");
  write(msg);
  me->set_temp("block_msg/all",1);
  ob->add_temp("kidnap",1);
  if( i > 8 ) {
  delete_temp("kidnap"); 
  me->delete_temp("block_msg/all");
  return 0;
  }
  call_out("kidnap", 2);
  return 0;
}


