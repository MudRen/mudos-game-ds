#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY "[����]"HIR"���s"HIW"�Ԥh" NOR , ({ "warrior","w" }) );
        set("race", "�H��");
        set("age", 40);
        set("level",20);
        set("long","
���e���o��ѥS���S�����A�e�j�����A�[�W
���Ӫ����Y�M�p�����Z�ҡA�H�έI���e�j�����l�A
�O�H�������ߡA���D�L�N�O�W�s�x�Ϊ��h�L�H\n");
        set_temp("apply/attack", 50);
        set_temp("apply/armor", 20);
        set_skill("unarmed",100);
        setup();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_ring.c")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_necklace.c")->wear();
        carry_object("/u/s/sopher/area/npc/npceq/dragon_plate.c")->wear();
}

void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "�y��")
        {
say("���s�Ԥh��A���D�G" HIY "�A�n!�w����{�W�s�x��!�C\n"NOR);
                command("smile" + me->query("id"));
        }else
         {
                say( HIW "���s�Ԥh���F���i�y�C \n" NOR );
                
      }   
}
