#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"�i"HIG"��"HIR"��"HIY"��"HIC"�C"HIW"�j"NOR, ({ "darksword-spirit","sword","spiritsword" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", ""HIW"�i"HIG"��"HIR"��"HIY"��"HIC"�C"HIW"�j"NOR"���C�b�W�x�z��"BLK"�`�¦�"NOR"�x����C\n");
                set("value", 200000); 
                set("no_sell", 1);
                set("rigidity", 500);
                set("wield_msg", "$N�N��V�U�@��$n���`�ѳS�f�ƥX,�K�����o�̾�Ӫ��t�{�U��,���ª�ԣ�򳣬ݤ����C\n");
                set("unwield_msg", "$N�N��W��$n���^�S���C\n");
        } 
                set("weapon_prop/bar", 5);
                set("weapon_prop/bio", 5);
                set("weapon_prop/wit", 5);
                set("weapon_prop/sou", 5);
                set("weapon_prop/tec", 5);
                set("weapon_prop/str", 25) ;
                set("weapon_prop/con", 25) ;
                set("weapon_prop/int", 25) ;
                set("weapon_prop/dex", 25) ;
                set("weapon_prop/shield", 400) ;  
                set("weapon_prop/damage", 400) ; 
                set("weapon_prop/hit", 400) ;  
                set("weapon_prop/armor", 400) ;  
                set("weapon_prop/parry", 400) ;  
                set("weapon_prop/dodge", 400) ;
     init_sword(789);
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
int query_autoload() { return 1; }














