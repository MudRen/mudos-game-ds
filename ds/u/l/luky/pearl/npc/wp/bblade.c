#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{set_name(HIR"�岪"NOR,({"blood blade","blade"}) );
set_weight(37000);//damage*50�N�O�ӪZ�������q
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("lone",
"�o�O�@�������ժ��_�M,�M�b�������@�Ӥp�p���M��,���G�u���o�M��,
�P�岪�����r�ۦX,���ժ��M�b���G�P��M�W�Q�������ŦX�C\n");
set("value",3700);//damage*5�N�O�ӪZ��������
set("blade",52);
                set("material", "blacksteel");

set("wield_msg",HIR"$N�N$n"+HIR"�Ѹy����X\n"NOR);
set("unequip_msg", HIR"$N�N$n"+HIR"�C�C��^�y���C\n"NOR);
init_blade(728);
}
setup();
}
int fail_eq(object me)
{
  return 0;
}
void attack(object me,object victim)
{
int damage,str;
if (this_player()->query("air")>50)
{
    if( random(300)> 200 )
{
if(this_player()->query("lck")>random(this_player()->query("level")*10))
if(this_player()->query("mp")>120)
{
str=this_player()->query_str();
damage=random(500)+700;
this_player()->add("mp",-70+random(50));

        victim->receive_damage("hp", damage, me );
message_vision(HIR"��M�岪�l��$N"+HIR"���大��\n"+
"�C�C�z�|�X�@�I�I�����⪺����C\n"+"���M���⪺����Ʀ��@���M����$N\n"
+HIR"$N"+HIR"�Ӥ��θ���---["+damage+"]�I�ˮ`\n"NOR,victim);
         return;
}
}
}
return;
}
