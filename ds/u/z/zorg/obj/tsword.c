#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name(HIW"�i"HIG"��"HIR"��"HIC"�C"HIW"�j"NOR, ({ "darksword","sword" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", ""HIW"�i"HIG"��"HIR"��"HIC"�C"HIW"�j"NOR"���C�b�W�x�z��"BLK"�`�¦�"NOR"�x����C\n");
                set("value", 20000); 
                set("no_sell", 1);
                set("no_put", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_get", 1);
                set("rigidity", 500);
                set("wield_msg", "$N�N��V�U�@��$n���`�ѳS�f�ƥX,�K�����o�̣x���t�{�@�����l,�C�b�W�x�z��"BLK"�`�¦�"NOR"�x����C\n");
                set("unwield_msg", "$N�N��W��$n���^�S���C\n");
        } 
                set("weapon_prop/bar",3);
                set("weapon_prop/bio",3);
                set("weapon_prop/wit",3);
                set("weapon_prop/sou",3);
                set("weapon_prop/tec",3);
                set("weapon_prop/str", 15) ;
                set("weapon_prop/con", 15) ;
                set("weapon_prop/int", 15) ;
                set("weapon_prop/dex", 15) ;
                set("weapon_prop/shield", 300) ;  
                set("weapon_prop/damage", 300) ; 
                set("weapon_prop/hit", 300) ;  
                set("weapon_prop/armor", 300) ;  
                set("weapon_prop/parry", 300) ;  
                set("weapon_prop/dodge", 300) ;
     init_sword(300);
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
int query_autoload() { return 1; }


