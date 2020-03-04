// red stone called master

#include <ansi.h>
inherit NPC;
void create()
{
  set_name("�z���H��", ({"bright doll","doll","bright"}) );
  set("long",@LONG 
�@�سz���������ͪ��A�~���N��H�@�ˡC
LONG
);
  set("race", "human");
  set("unit","��");
  set("age",300);
  set("level",50+random(7));  
  set("attitude", "aggressive"); 
  set("evil",2000);
  set("chat_chance", 13);
  set("chat_msg",({  
  (:random_move():),
  "�z���H����ӧ�h��.....�n�߳��\n",  
        }));
  setup();
  add_money("coin",1000+random(500));
} 
void init()
{       
        object ob;
        ::init();
        if( environment(this_player())->query("no_kill") ) return;
        if( environment(this_player())->query("no_fight") ) return;
        if(!this_object()->visible(this_player())) return;
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{ 
        //object me=this_player(); 
        object obj;
        if( !ob || environment(ob) != environment() ) return; 
        {
                        message_vision(HIR"\n�z���H�����D�G�K�K�K�K�I\n"+NOR,ob);
                        tell_object(ob,HIW"�@���H�G��M�л\\�b�A�����W�I�ϱo�A�L�k�ʼu�I\n"NOR); 
                        this_object()->kill_object(environment(ob)); 
                        ob->receive_damage("hp",200);  
                        ob->start_busy(2); 
                        obj=new(__DIR__"magma")->move(this_object()); 
                        obj=new(__DIR__"magma")->move(this_object());              
        }
}
int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*30) > tdex+tcon)
    {
      message_vision(HIW"\n$N�R�F�@�f�H�G�b"+target->name()+"�A�y���G�k�ˮ`�I\n"NOR,me,target);  
     target->receive_damage("hp",300+random(350), this_object());
      return 1; 
    }
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
  message("world:world1:vision", 
    HIY"\n�i�ǩ_�j"+HIW"�_�����z���H���Q"+ob->name()+"("+ob->query("id")+")�������F�I\n"+NOR,users());
  ob->add("popularity",4);
  switch( random(100) )
  {
    case  0..40: write("�z��㤰�򳣨S���C�I\n");
          break;
    case  41..80: write("�z���t�@�I�I�I�[�o�I\n");
          break;
    case  81..99: new(__DIR__"sword")->move(this_object()); 
                  write(HIY"�@��ǲ����F��q�z���H��������̯B�{�X��..\n"NOR);
          break;
  }
  ::die();
  return;
}

