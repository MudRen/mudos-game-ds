// fork.c
//#pragma save_binary
#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

int weapon_damage(string material,int weight);

void setup()
{
        ::setup();
        
        if( clonep(this_object()) ) return;
        set("skill_type", "fork");
        if( !query("actions") ) {
                set("actions", (: call_other, WEAPON_D, "query_action" :) );
                set("verbs", ({ "thrust" }) );
        }
}

varargs void init_fork(int damage, int flag)
{
        if(!this_object()->query("material"))
                this_object()->set("material","plant");
        damage += weapon_damage(query("material"),weight());
        set("weapon_prop/damage", damage);
        set("flag", (int)flag | POINTED);
        if(!query("limit_str")) set("limit_str",weight()/1500);
}

int weapon_damage(string material,int weight)
{
        return 0;

}

int is_weapon() { return 1; }

