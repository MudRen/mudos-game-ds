#include <weapon.h>
#include <ansi.h>
#include <combat.h>

inherit SSERVER;
inherit GUN;
void create()
{       set_name(HIB"�׵����j"NOR,({"final gun","gun"}) );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("long",HIG"�o�O�@��׵��Z���C\n"NOR);
        set("value",100000);
        set("rigidity",10000);
        set("bullet_type","enegry");
        set("max_load",1000);
        init_gun(10000);
        set("material", "blacksteel");
        set("wield_msg","$N���X�@��$n, �ñN$n���O�I�˸m�Ѷ}�C\n");
        set("unwield_msg", "$N�N�⤤��$n�O�I�˸m�����C\n");
        setup();
        }
}
void attack(object me,object victim)
{
	int damage,hp,maxhp,mp;

  me=this_player();
  hp=me->query("hp");
  maxhp=me->query("max_hp");
  mp=me->query("mp");
 if ( hp > maxhp )
 { 
   damage=1000000+random(100) *(hp+mp);
  message_vision(HIR" �׵����j�l���F�Ҧ��O�q�A�g�X�W�Ť@���I�I�I
   �y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR,victim); 
  victim->receive_damage("hp", damage, me );
 return;    
 }
}