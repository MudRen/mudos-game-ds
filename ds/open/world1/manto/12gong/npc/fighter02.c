#include <ansi.h>
inherit NPC;
void create()
{
  set_name(HIW"�ջ�"NOR"���h", ({"silver fighter","fighter"}));
  set("long",@long

long);      
  set("gender", "�k��" );
  set("age",18);
 set("level",35+random(10));
  set("race","evil");
  set_skill("unarmed", 90);
        set_skill("cloudfist",100);
        set_skill("cloudsteps",100);
        map_skill("unarmed","cloudfist");
        map_skill("dodge","cloudsteps");
  add("max_mp", 2000);
  set_temp("apply/hit", 50);
  set_temp("apply/dodge", 50);
  set_temp("apply/damage",40);
  set_temp("apply/armor",30+random(5));
  setup();
  carry_object(__DIR__"wp/fist")->wield();
}
void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if( this_player()->query_temp("invis")>2 ) return;
  if( this_player()->query_temp("kill_12gong") ) this_object()->kill_ob(this_player());
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        if( !ob->query_temp("kill_12gong") ) ob->set_temp("kill_12gong", 1);
        ::die();
        return;
}
