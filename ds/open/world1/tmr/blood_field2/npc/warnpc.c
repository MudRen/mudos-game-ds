#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
    set_name("���~�s", ({ "young dragon", "dragon" }) );
    set("long", @LONG
�o�O�@���~�����p�s�A���b�o���񪱭A�C
LONG);
        set("race","dragon");
    set("title","��{�");
    set("gender", "male");
    set("age", 10);
    set("level",5);
    setup();
}

void die()
{
   object me;
   if( !me = query_temp("last_damage_from") )
        me = this_player(1);
   if( !me )
   {
     ::die();
     return;
   }
        command("war ... "+me->name(1) + "(" + me->query("id") +")...�L�����Z�H�I�I�]�פ��|��L�A���I�I�I");  
        load_object("/open/world1/tmr/blood_field2/map_25_24.c")->start_war();

  ::die();
  return;
}


