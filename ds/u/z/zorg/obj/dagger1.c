#include <weapon.h>
#include <ansi.h>

inherit DAGGER ;
void create()
{
        set_name(HIW"�i"HIB"�Ť�"HIW"�j"NOR, ({"blue dagger","dagger" }) );
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", ""HIW"�i"HIB"�Ť�"HIW"�j"NOR"���P�b�W�x�z��"GRN"�H�H���Ŧ�"NOR"�����C\n");
                set("value", 20000); 
                set("no_sell", 1);
                set("rigidity", 500);
                set("wield_msg", "$N�N��V�U�@��$n���`�ѳS�f�ƥX,�@��H�Ŧ⪺�z���u�b�C\n");
                set("unwield_msg", "$N�N��W��$n���^�S���C\n");
        } 
                set("weapon_prop/bar",3);
                set("weapon_prop/bio",3);
                set("weapon_prop/wit",3);
                set("weapon_prop/sou",3);
                set("weapon_prop/tec",3);
                set("weapon_prop/str", 10) ;
                set("weapon_prop/con", 10) ;
                set("weapon_prop/int", 10) ;
                set("weapon_prop/dex", 10) ;
                set("weapon_prop/shield", 100) ;  
                set("weapon_prop/damage", 300) ; 
                set("weapon_prop/hit", 500) ;  
                set("weapon_prop/armor", 100) ;  
                set("weapon_prop/parry", 100) ;  
                set("weapon_prop/dodge", 100) ;
     init_dagger(250);
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
int query_autoload() { return 1; }


