#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
    set_name("���ʪ��e��", ({ "unquiet skeleton", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
�o�O�@��G�ꪺ�e���A�������󳺵M�ٯਫ�ʡC�����Ŭ}����
���G����ۧA�A�㪺�S������ͮ�C
LONG);

    set("title",HIG"�L�����"NOR);
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
        command("war ... "+me->name(1) + "(" + me->query("id") +")..�R�R�R�I�I�I");  
        message_vision("�@�D�·ϱq$N�_�X�A��«�^��L����餤...\n", this_object());
        load_object("/open/world1/tmr/unquiet_manor/map_17_8.c")->start_war();

  ::die();
  return;
}

