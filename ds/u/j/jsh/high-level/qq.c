// V2.0 editor JS@DS 
// 2007.01.10        
//define PATHONE "/open/world1/tmr/area/square.c"
//define PATHTWO "/open/world1/cominging/area/boo-lin.c"
//define PATHTHREE "/open/world1/acme/area/hotel.c"
//void go_path(); 
inherit NPC;  
void create()
{
      set_name(HIW"���P�x��"NOR,({"sorsin man","man"}) );
      set("title",HIC"���ڰڡI�³J"NOR);   

      set("long",@LONG 
�����e�������Ǯ{�A�ƤQ�~��A�����⮩��F���P���q�A�N�e����
�U���Z�\�ķ|�e�q�C 
LONG    
        );
        set("race", "human");    
        set("unit","��");
        set("age",60);
      set("level",70+random(5));
        set("dex",120); 
        set("max_ap",10000); 
        set("max_hp",10000);
        set("combat_exp",9999999);     
        set("limbs", ({ "�Y��", "����","�ݳ�","�ⳡ","�}��" }) );      
        add("addition_armor",200);
        add("addition_damage",100);   
        add("addition_shield",100);
        set("chat_chance", 100);
        set("chat_msg", ({   
  //(: go_path() :),
 // (: random_move() :),
  (: command("wield sword") :),  
  (: command("exert moon_force recover") :),
  (: command("exert moon_force recover") :),
  (: command("exert moon_force recover") :),
}));
        set("chat_chance_combat", 13);
        set("chat_msg_combat", ({  
  //(: random_move() :),
  (: command("exert sorsin_force one") :), 
  (: command("exert sorsin_force two") :), 
  (: command("exert sorsin_force three") :), 
  (: command("exert sorsin_force final") :), 
  (: command("wield sword") :),   
  (: command("exert moon_force recover") :), 
  (: command("exert moon_force recover") :),
})); 
      set_skill("sorsin_force",100);     
      set_skill("force",100);     
      set_skill("moon_force",100);     
      set_skill("dodge",200);  
      set_skill("sorgi_sword",100);       
      set_skill("star-sword",100);      
      set_skill("sword",100);      
      set_skill("fogseven",100); 
    map_skill("sword","sorgi_sword");
    map_skill("dodge","fogseven");
   setup();
      carry_object(__DIR__"sword")->wield(); 
}   

/* 
void go_path()
{
     object me=this_object(); 
*/
int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;
  if(!random(8))
  {
    me->start_busy(1);
    target->add_busy(2);
    message_vision("\n$N"NOR"���_�C���A��W���C������W�@�h"HIW"�ե�"NOR"�A��M�ۤƬ��@�ʹs�K�D"HIC"�C��I"NOR"�I�I\n"NOR
     ,me);
    call_out("do_super",2,me); 
    return 1;
  }
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIC"��ոU�v�A�ҦV��ġA��꤭�Q���ؤ��I�@�@���}�I\n"NOR,me);
  message_vision("\n�A�L�B�i�k�A�u��Ө��o�}�ѯ�����I\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 300+random(200)-inv[i]->quert("armor");
      message_vision(HIW"�y�ڡI�z�uť��$N���@�n�G�s�A�Q�ƹD�C������.... "HIR"("+damage+")\n"NOR,inv[i]);
      message_vision(HIR"$N�Q�j�j���C�𥴭��F�ƦʤV����...\n"NOR,inv[i]);     // add buy JS 
      inv[i]->move("/open/world1/cominging/area/boo-lin.c");  // add by JS       
      inv[i]->receive_damage("hp", damage, me);
      if( inv[i]->query_con() > 90 )
        inv[i]->add_busy(1);
      else if( inv[i]->query_con() > 75 )
        inv[i]->add_busy(2);
      else
        inv[i]->add_busy(3);
      COMBAT_D->report_status(inv[i]); 
    }
    else
    {
      message_vision(HIC"\n$N�Q�j�j���C�����} .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  } 
       me->start_busy(1);
  return;
}
int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();
  ::receive_damage(type,cost,me);
  return 0;
}
void die()
{
   object ob,obj;
   obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                destruct(this_object());
                return;
        }
        message("world:world1:vision",
    HIR"\n�i��    ���j"+HIW "�e�������u ���P�x�� �v���Ѧb"+ob->name(1)+"����W�I\n\n"+NOR     
       ,users()); 
        message_vision("���P�x�����D�G�n�p�l�A���M�ॴ�ѧ�..���\n"
                       "�@�಴�A���P�x���N�]�������ܼv�F..\n",ob);  
        tell_object(ob,"�A�o�� 50000 exp\n");
        if( !objectp(this_object()->query_temp("weapon")) ) 
        this_object()->create(); // by alick
        this_object()->remove_all_killer(); // by tmr
        this_object()->receive_heal("hp",20000);
        this_object()->receive_heal("hp",20000); 
        ob->set("guild_rank",HIW"�Ƶ��s���Z�L�_�H"NOR);
        ob->add("popularity",10);   
        ob->add("exp",50000);
        switch(random(3))
        {  
           case 0: message("world:world1:vision",HIW"\n���P�x���X�{�b�¤ѼӪ���\n"NOR,users());
                   this_object()->move("/open/world1/tmr/area/square.c");
                   break; 
           case 1: message("world:world1:vision",HIW"\n���P�x���X�{�b�B�F������\n"NOR,users());
                    this_object()->move("/open/world1/cominging/area/boo-lin.c");
                   break;   
           case 2: message("world:world1:vision",HIW"\n���P�x���X�{�b�ѫ�����\n"NOR,users());
                   this_object()->move("/open/world1/acme/area/hotel.c");
                   break;  
        }
        return;
}

void start_busy() { return; }
void add_busy() { return; }

