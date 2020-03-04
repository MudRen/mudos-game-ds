#include <ansi2.h>

inherit NPC;

void do_super(object me);

void create()
{
     set_name(HBK "���s "HIR"�]��" NOR, ({ "nightbane dragon", "nightbane", "dragon", "_BLOOD_FIELD_NPC_", "_NIGHTBANE_" }) );
    set("long", @LONG
�]�׬O�@�����j�����s�A�������o�۶¦⪺���`�𮧡A�A�b�B�]�����a��
�e�A�A�u�y�L��i�]�תŬ}�������A��b�A�������B�{�ƦʴT�A������������
�A�u�~�ۧA�xŸ����A�}���o�n�A�u�Q�n���I���}�o�̡C�]�׬O��{�����
�D�A�λ�ۯ�W���U���ͪ��A�����I�J�o�ӾԳ����ĤH�A�@�߬O���L�j�C
LONG
        );

    set("title", HIM"��{��D"NOR);
      set("race", "dragon");
      set("gender","�k��");
    set("age", 1200);
    set("level", 60 );
    /* �԰��ʧ@ */
    set("chat_chance_combat", 50);
    set("attitude", "aggressive");
    set("max_hp", 40000);
    set("addition/bar", 15);
    set("addition/bio", 5);
    set("addition/wit", 15);
    set("addition_armor", 300);
    set("addition_hit", 250);
    set("addition_damage", 300);
    set("addition_shield", 300);
    setup();
    set_living_name("_NIGHTBANE_");
    if(random(100)<5)
        carry_object(__DIR__"obj/mask")->wear();
    else
        carry_object(__DIR__"obj/mask2")->wear();
}

void die()
{
       object ob;

        if( this_object()->query("pill") < 2 ) {
            message_vision(HIR"�@�D�벴�����~�ɴ��}�ӡA$N"HIR"������S��_���쥻���b�H�ҼˤF�C\n"NOR, this_object());
            set("hp", this_object()->query("max_hp"));
            add("pill", 1);
            return;
        }


        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

        message("world:world1:vision",
           HIR"\n�i���S���J�j"+name()+HIG"�b�{�����ڵo�X��q�A�w�Q"+HIG"�Գ��^���m"+ob->name(1)+"(" + ob->query("id") + ")�n�R����ǭ��Ϸ��A���餣�A�I�I\n\n" NOR
        ,users() );
        ob->add("popularity", 4);
        tell_object(ob,HIG"�A��o���I�n��C\n"NOR);

        ::die();

        return;
}


int special_attack(object me, object target, int hitchance)
{
        int dmg;
        if(!me) return 0;
        if( query_temp("special_attack") ) return 0;
        if( random(100) < 30) return 0;

        if( random(100) < 40)
        {

                message_vision(HIG"$N"HIG"�i�L�R�X�@�D�j�l��"HBK"�¦���"HIG"�A�������W$n"HIG"�I�I\n"NOR, me, target);
                dmg = this_object()->query_damage() - target->query_armor();
                if(dmg<1) dmg = 10;
                dmg = COMBAT_D->Merits_damage(me, target, dmg, "bio");
                target->receive_damage("hp", dmg, this_object());
            return 1;
        }

        // �s�����
        set_temp("special_attack", 1);
        message_vision("$N"HBK"���W�@�p���®�{�p�����m�a�A�b�|�g���a�W�j���}�ӡI�I\n"NOR, me);
        call_out("do_super", 1 + random(2) ,me);
       return 1;
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = me->query_enemy();
  delete_temp("special_attack");
  if(!inv) return;
  if(!me) return;

  message_vision( HIC"\n�|�g�@�}�̰ʡA"HBK"�]�׶®�"HIC"�N�p���F�뺩�ѻ\\�a��ŧ�ӡI�I\n"NOR, me);
  for(i=0;i<sizeof(inv);i++)
  {
          if( !environment(me) ) continue;
          if( !inv[i] || !environment(inv[i]) ) continue;
          if(environment(me) != environment(inv[i]) ) continue;

          damage = query_damage() + random(query_damage());
          if( inv[i]->is_busy())
                damage -= random(inv[i]->query_armor());
          else
                damage -= inv[i]->query_armor()/2 + random(inv[i]->query_armor()/2);

      damage = COMBAT_D->Merits_damage(me, inv[i], damage, "bio" );
      if(damage < 10 ) damage = 1 + random(9);
      message_vision(HIR"$N"HIR"�L�Ұ{�סA�಴���Q"HBK"�]�׶®�"HIR"���W�A�u��L�O�a�o�X���n�G�s�I�I"HIR"("+damage+")\n"NOR,inv[i]);
      damage = inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(1);
      COMBAT_D->report_status(inv[i]);
  }
  me->start_busy(2);
  return;
}

