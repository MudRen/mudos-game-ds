#include <weapon.h>
#include <ansi.h>

inherit SWORD;
void create()
{set_name(HIY"�j�ơE�`��§��"NOR,({"advanced fantasy sword","sword","advanced"}) );
set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
set("long",HIG"�o��C�p���W�Q�A�i���O�C�����~�A���Ӫ��`��§���٦n�C
�o��O�����~��������C�A�ӥB�N�N�۶ǡC�ǻ��}�ݪ̡ЦN�B��W�o��
�j���ɡA�⤤�����N�O�o�@��C�C���u�����@��w�g�����h�V�C\n"NOR);
set("value",20000);
set("sword",120);
init_sword(300);
                set("material", "blacksteel");
set("wield_msg","$N�q���I�ޥX$n�A�Q��n�ɱq$N�����W���o�X�ӡI\n");
set("unwield_msg", "$N�N�⤤��$n�p�ߦ��n�C\n");
}
setup();
}  
void attack(object me,object victim)
{
int damage,str,dex;

if( random(200)>80)
    {
str =me->query("str");
dex=me->query("dex");
damage=1000+random(50)*(str+dex);
        victim->receive_damage("hp", damage, me );
message_vision(HIY" �j�ơE�`��§�᩿�M���Ѫŭ��h�A���a�ۯ��t����
          
                   �V$N���h�I�I�I�y��$N"+damage+"�I���ˮ`�I�I�I�I\n"NOR,victim);           
         return;    
  }
}             
