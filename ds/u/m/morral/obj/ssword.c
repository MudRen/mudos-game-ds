#include <weapon.h>
#include <ansi.h>

inherit SWORD;
void create()
{set_name(HIR"�����C"NOR,({"smash sword","sword","smash"}) );
set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("long",HIG"�o��C�p���W�Q�A�i���O�C�����~�C\n"NOR);
set("value",20000);
init_sword(1000);
                set("material", "blacksteel");
set("wield_msg","$N�q���I�ޥX$n�A�Q��n�ɱq$N�����W���o�X�ӡI\n");
set("unwield_msg", "$N�N�⤤��$n�p�ߦ��n�C\n");
}
setup();
}  
void attack(object me,object victim)
{
int damage,str,dex;

if( random(200)>=0)
    {
str =me->query("str");
dex=me->query("dex");
damage=1000+random(500*(str+dex));
        victim->receive_damage("hp", damage, me );
message_vision(HIY" �שR�@���I�I�I

                �y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR,victim);           
         return;    
  }
}             
