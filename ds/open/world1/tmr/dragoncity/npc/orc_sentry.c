
#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
    set_name("�b�~�H��L", ({ "orc sentry", "orc", "sentry", "_CRUSH_BONE_ORC_" }) );

    set("long", @LONG
�b�~�H�A����e�t���A���ۤ@�i�u���y�A�L�O�ݩ�H���몺�p���o�C
LONG);

    set("title", HIW"�H����"NOR);
    set("gender", "male");
    set("age", 23);
        set("level",25);

    /* �ޯ�]�w */
    set_skill("dodge", 100);
    set_skill("axe", 100);
    set_skill("parry", 100);
    set_skill("unarmed", 100);

    setup();

    set_living_name("_CRUSH_BONE_ORC_");
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
   command("war ... "+me->name(1) + "(" + me->query("id") +")..�A...�H���j�x���|��L�A���I�I�I");  
        message_vision("$N�b�{�����e��۸H���몺�a��g�X�@�T�H���b...\n", this_object());
        load_object("/open/world1/tmr/crush_bone/map_23_4.c")->start_war();

  ::die();
  return;
}


